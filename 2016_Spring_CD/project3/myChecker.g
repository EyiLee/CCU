grammar myChecker;

@header {
    import java.util.HashMap;
}

@members {
    boolean TRACEON = true;
    HashMap<String,Integer> symtab = new HashMap<String,Integer>();

	/*
    public enum TypeInfo {
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
       3 => double,
       4 => char,
       5 => void,
       -1 => do not exist,
       -2 => error
     */	   
}

program
	: VOID MAIN '(' ')' '{' declarations statements '}'
     { if (TRACEON) System.out.println("VOID MAIN () {declarations statements}"); }
	;

declarations
	: type Identifier ';' declarations
     {
	   if (TRACEON) System.out.println("declarations: type Identifier : declarations");
	 
  	   if (symtab.containsKey($Identifier.text)) {
		   System.out.println("Type Error: " + $Identifier.getLine() + ": Redeclared identifier.");
	   } else {
		   symtab.put($Identifier.text, $type.attr_type);	   
	   }
	 }
	| { if (TRACEON) System.out.println("declarations: "); }
	;

type returns [int attr_type]
	: INT { if (TRACEON) System.out.println("type: INT");  $attr_type = 1; }
	| FLOAT { if (TRACEON) System.out.println("type: FLOAT");  $attr_type = 2; }
	| DOUBLE { if (TRACEON) System.out.println("type: DOUBLE");  $attr_type = 3; }
	| CHAR { if (TRACEON) System.out.println("type: CHAR");  $attr_type = 4; }
	| VOID { if (TRACEON) System.out.println("type: VOID");  $attr_type = 5; }
	;

statements
	:statement statements
	|
	;

arith_expression returns [int attr_type]
	: a = multExpr { $attr_type = $a.attr_type; }
      ( '+' b = multExpr
	    { if ($a.attr_type != $b.attr_type) {
			  System.out.println("Type Error: " + $a.start.getLine() + ": Type mismatch for the operator + in an expression.");
		      $attr_type = -2;
		  }
        }
	  | '-' c = multExpr
	  )*
	;

multExpr returns [int attr_type]
	: a = signExpr { $attr_type = $a.attr_type; }
      ( '*' signExpr
      | '/' signExpr
	  )*
	;

signExpr returns [int attr_type]
	: primaryExpr { $attr_type = $primaryExpr.attr_type; }
	| '-' primaryExpr { $attr_type = $primaryExpr.attr_type; }
	;
		  
primaryExpr returns [int attr_type] 
	: Integer_constant        { $attr_type = 1; }
	| Floating_point_constant { $attr_type = 2; }
	| Identifier 
	{
		if (symtab.containsKey($Identifier.text)) {
			$attr_type = symtab.get($Identifier.text);
		}
	}
	| '(' arith_expression ')' { $attr_type = $arith_expression.attr_type; }
    ;

statement returns [int attr_type]
	: Identifier '=' arith_expression ';'
	 {
	   if (symtab.containsKey($Identifier.text)) {
	       $attr_type = symtab.get($Identifier.text);
	   } else {
		   System.out.println("Type Error: " + $Identifier.getLine() + ": Undeclared identifier.");
	       $attr_type = -2;
		   return $attr_type;
	   }
		
	   if ($attr_type != $arith_expression.attr_type) {
           System.out.println("Type Error: " + $arith_expression.start.getLine() + ": Type mismatch for the two silde operands in an assignment statement.");
		   $attr_type = -2;
       }
	 }
	| IF '(' arith_expression ')' if_then_statements
	;

if_then_statements
	: statement
	| '{' statements '}'
	;

		   
/* ====== description of the tokens ====== */
FLOAT:'float';
INT:'int';
DOUBLE:'double';
CHAR:'char';
MAIN: 'main';
VOID: 'void';
IF: 'if';

Identifier:('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*;
Integer_constant:'0'..'9'+;
Floating_point_constant:'0'..'9'+ '.' '0'..'9'+;

WS:( ' ' | '\t' | '\r' | '\n' ) {$channel=HIDDEN;};
COMMENT:'/*' .* '*/' {$channel=HIDDEN;};
