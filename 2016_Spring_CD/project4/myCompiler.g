grammar myCompiler;

options {
    language = Java;
}

@header {
    // import packages here.
    import java.util.HashMap;
    import java.util.ArrayList;
}

@members {
    boolean TRACEON = false;
    HashMap<String,Integer> symtab = new HashMap<String,Integer>();
    int labelCount = 0;

	  /*
    public enum TypeInfo {
    StringConstant,
    Integer,
		Float,
		Unknown,
		No_Exist,
		Error
    }
    */

    /* attr_type:
       1 => integer,
       2 => float,
       3 => string,
       4 => char,
       -1 => do not exist,
       -2 => error
     */
     
    List<String> DataCode = new ArrayList<String>();
    List<String> TextCode = new ArrayList<String>();
 
    public static register reg = new register(0, 10);
    
    /*
     * Output prologue.
     */
    void prologue(String id)
    {
    }
    
    /*
     * Output epilogue.
     */
    void epilogue()
    {
    }
    
    
    /* Generate a new label */
    String newLabel()
    {
       labelCount ++;
       return (new String("L")) + Integer.toString(labelCount);
    } 
    
    
    public List<String> getDataCode()
    {
       return DataCode;
    }
    
    public List<String> getTextCode()
    {
       return TextCode;
    }
}


program
    : INT MAIN '(' ')' '{'
    {
		TextCode.add("main:");
	}
	declarations statements functions '}'
    ;


functions
    : function functions
    |
    ;
				  
function
    : type Identifier '(' ')' '{'
      {
         /* output function prologue */
         prologue($Identifier.text);
      }
      l_declarations statements '}'
      {
	     if (TRACEON) System.out.println("type Identifier () {declarations statements}");
		 /* output function epilogue */	  
	     epilogue();
	  }
	;


/* global declaraction */
declarations
    :
	  type Identifier ';' declarations
      { 
	    if (TRACEON) System.out.println("declarations: type Identifier : declarations");
		if (symtab.containsKey($Identifier.text)) {
		    System.out.println("Type Error: " + $Identifier.getLine() + ": Redeclared identifier.");
	    } else {
			/* Add ID and its attr_type into the symbol table. */
			symtab.put($Identifier.text, $type.attr_type);	   
	    }
		
		/* code generation */
		switch($type.attr_type) {
		case 1: /* Type: integer, size=> 4 bytes */
		        DataCode.add($Identifier.text + ":\t.word\t0");
				break;
		case 2: /* Type: float, size=> 4 bytes */
		        DataCode.add($Identifier.text + ":\t.word\t0");
				break;
		case 4: /* Type: char, size=> 1 byte */
		        DataCode.add($Identifier.text + ":\t.byte\t0");
		        break;
		default:
		}
	  }
    | { if (TRACEON) System.out.println("declarations: ");}
    ;


l_declarations
    :
    type Identifier ';' l_declarations
    {
      /* If you want to handle local variables, fix it. */ 
    }
    | 
    ;


type returns [int attr_type]
    : INT   { if (TRACEON) System.out.println("type: INT");  $attr_type=1; }
    | FLOAT { if (TRACEON) System.out.println("type: FLOAT");  $attr_type=2; }
    | CHAR { if (TRACEON) System.out.println("type: CHAR");  $attr_type=4; }
    ;

statements: statement statements
    |
    ;
		
statement returns [int attr_type]
    : Identifier '=' a = arith_expression ';'
	  { 
	    if (symtab.containsKey($Identifier.text)) {
	       $attr_type = symtab.get($Identifier.text);
	    } else {
           /* Add codes to report and handle this error */

	       $attr_type = -2;
	    }
		  
	    /*if ($attr_type != $arith_expression.attr_type) {
           System.out.println("Type Error: " + $arith_expression.start.getLine() + ": Type mismatch for the two silde operands in an assignment statement.");
		   $attr_type = -2;
	    }*/
		
		/* code generation */
		switch( $attr_type ) {
			case 1:
		    		TextCode.add("\tsw\t" + "\$t" + $a.reg_num + ", " + $Identifier.text);
		    		break;
		    case 2:
		    		TextCode.add("\tsw\t" + "\$t" + $a.reg_num + ", " + $Identifier.text);
		    		break;
			case 4:
		    		TextCode.add("\tsb\t" + "\$t" + $a.reg_num + ", " + $Identifier.text);
		    		break;
		    default:
		}
		reg.set($a.reg_num);
	  }
    | IF '(' arith_expression ')'
    {
      String labeltrue = newLabel();
      String labelfalse = newLabel();
      TextCode.add("\tbne\t" + "\$t" + $arith_expression.reg_num + ", " + "\$zero" + ", " + labeltrue);
      TextCode.add("\tj\t" + labelfalse);
      TextCode.add(labeltrue + ":");
	}
	if_then_statements
	{
      TextCode.add(labelfalse + ":");
	}
    | PRINTF_INT func_argument
    {
      /* code generation */
      TextCode.add("\tlw\t" + "\$s0, " + $func_argument.label);
      TextCode.add("\tjal\tprintf_int");
	}
	| (PRINTF | PRINTF_STR) func_argument
	{
      /* code generation */
      TextCode.add("\tla\t" + "\$s0, " + $func_argument.label);
      TextCode.add("\tjal\tprintf_str");
	}
    | Identifier func_argument
    {
      /* code generation */
      int reg_num = reg.get();
      TextCode.add("\tla\t" + "\$t" + reg_num + ", " + $func_argument.label);
      TextCode.add("\tjal\t" + $Identifier.text);
      reg.set(reg_num);
    }
    ;


func_argument returns [String label]
    : '(' ')' ';'
      {
         /* handle function calls here. */
      }
    | '(' a = arith_expression 
      {
         /* handle function calls here. */
         if ($a.attr_type == 3) { // handle string type.
            $label = newLabel();
            DataCode.add(label + ":\t .asciiz " + $a.str);
         } else {
         	$label = $a.str;
		 	reg.set($a.reg_num);
		 }
      }
	        ( ',' arith_expression )*
	    ')' ';' 
    ;

	
arith_expression returns [int attr_type, int reg_num, String str]
	: a = multExpr
	      {
	         $attr_type = $a.attr_type;
	         $reg_num = $a.reg_num;
	         $str = $a.str;
	      }
    ( '+' b = multExpr
	      { 
	         if ($a.attr_type != $b.attr_type) {
	            System.out.println("Type Error: " + $a.start.getLine() + ": Type mismatch for the operator + in an expression.");
		        $attr_type = -2;
		     }
		  
		     /* code generation */
             TextCode.add("\tadd\t" + "\$t" + $reg_num + ", \$t" + $reg_num + ", \$t" + $b.reg_num);
             reg.set($b.reg_num);
          }
	| '-' c = multExpr
		  { 
	         if ($a.attr_type != $c.attr_type) {
	            System.out.println("Type Error: " + $a.start.getLine() + ": Type mismatch for the operator + in an expression.");
		        $attr_type = -2;
		     }
		  
		     /* code generation */
             TextCode.add("\tsub\t" + "\$t" + $reg_num + ", \$t" + $reg_num + ", \$t" + $c.reg_num);
             reg.set($c.reg_num);
          }
	)*
	;

	
multExpr returns [int attr_type, int reg_num, String str]
	: a = signExpr 
	  { 
	     $attr_type = $a.attr_type;
	     $reg_num = $a.reg_num;
	     $str = $a.str;
	  }
      ( '*' b = signExpr
	      { 
	         if ($a.attr_type != $b.attr_type) {
	            System.out.println("Type Error: " + $a.start.getLine() + ": Type mismatch for the operator + in an expression.");
		        $attr_type = -2;
		     }
		  
		     /* code generation */
             TextCode.add("\tmult\t" + "\$t" + $reg_num + ", \$t" + $b.reg_num);
             TextCode.add("\tmflo\t" + "\$t" + $reg_num);
             reg.set($b.reg_num);
          }
      | '/' c = signExpr
		  { 
	         if ($a.attr_type != $c.attr_type) {
	            System.out.println("Type Error: " + $a.start.getLine() + ": Type mismatch for the operator + in an expression.");
		        $attr_type = -2;
		     }
		  
		     /* code generation */
             TextCode.add("\tdiv\t" + "\$t" + $reg_num + ", \$t" + $c.reg_num);
             TextCode.add("\tmflo\t" + "\$t" + $reg_num);
             reg.set($c.reg_num);
          }
	  )*
	;


signExpr returns [int attr_type, int reg_num, String str]
	: primaryExpr
	  { 
	     $attr_type = $primaryExpr.attr_type;
	     $reg_num = $primaryExpr.reg_num;
	     $str = $primaryExpr.str;
	  }
	| '-' primaryExpr
	;


primaryExpr returns [int attr_type, int reg_num, String str]
    : Integer_constant
      { 
         $attr_type = 1;
         $str = $Integer_constant.text;
         
         /* code generation */
         $reg_num = reg.get();  /* get an register */
         TextCode.add("\tli\t" + "\$t" + $reg_num + ", " + $Integer_constant.text);
      }
    | Floating_point_constant { $attr_type = 2; }
    | STRING_LITERAL { $attr_type = 3; $str = $STRING_LITERAL.text; }
    | CHAR_SET
      { 
      	 $attr_type = 4;
      	 $str = $CHAR_SET.text; 

         /* code generation */
         $reg_num = reg.get();  /* get an register */
         TextCode.add("\tli\t" + "\$t" + $reg_num + ", " + $CHAR_SET.text);

      }
    | Identifier
      {
         $attr_type = symtab.get($Identifier.text);
         $str = $Identifier.text;
         
         /* code generation */
         $reg_num = reg.get(); /* get an register */
         TextCode.add("\tlw\t" + "\$t" + $reg_num + ", " + $Identifier.text);
      }
	  | '(' arith_expression ')' { $attr_type = $arith_expression.attr_type; }
    ;

	
if_then_statements
	: statement
	| '{' statements '}'
	;

	
/* description of the tokens */
FLOAT:'float';
INT:'int';
VOID: 'void';
CHAR: 'char';
IF: 'if';
MAIN: 'main';
PRINTF: 'printf';
PRINTF_INT: 'printf_int';
PRINTF_STR: 'printf_str';

Identifier:('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*;
Integer_constant:'0'..'9'+;
Floating_point_constant:'0'..'9'+ '.' '0'..'9'+;

STRING_LITERAL
    :  '"' ( EscapeSequence | ~('\\'|'"') )* '"'
    ;

CHAR_SET
	: '\'' ('a'..'z'|'A'..'Z') '\''
	;

fragment
EscapeSequence
    :   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
    ;


WS:( ' ' | '\t' | '\r' | '\n' ) {$channel=HIDDEN;};
COMMENT:'/*' .* '*/' {$channel=HIDDEN;};
