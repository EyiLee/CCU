// $ANTLR 3.5.2 myChecker.g 2016-05-30 21:33:24

    import java.util.HashMap;


import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings("all")
public class myCheckerParser extends Parser {
	public static final String[] tokenNames = new String[] {
		"<invalid>", "<EOR>", "<DOWN>", "<UP>", "CHAR", "COMMENT", "DOUBLE", "FLOAT", 
		"Floating_point_constant", "IF", "INT", "Identifier", "Integer_constant", 
		"MAIN", "VOID", "WS", "'('", "')'", "'*'", "'+'", "'-'", "'/'", "';'", 
		"'='", "'{'", "'}'"
	};
	public static final int EOF=-1;
	public static final int T__16=16;
	public static final int T__17=17;
	public static final int T__18=18;
	public static final int T__19=19;
	public static final int T__20=20;
	public static final int T__21=21;
	public static final int T__22=22;
	public static final int T__23=23;
	public static final int T__24=24;
	public static final int T__25=25;
	public static final int CHAR=4;
	public static final int COMMENT=5;
	public static final int DOUBLE=6;
	public static final int FLOAT=7;
	public static final int Floating_point_constant=8;
	public static final int IF=9;
	public static final int INT=10;
	public static final int Identifier=11;
	public static final int Integer_constant=12;
	public static final int MAIN=13;
	public static final int VOID=14;
	public static final int WS=15;

	// delegates
	public Parser[] getDelegates() {
		return new Parser[] {};
	}

	// delegators


	public myCheckerParser(TokenStream input) {
		this(input, new RecognizerSharedState());
	}
	public myCheckerParser(TokenStream input, RecognizerSharedState state) {
		super(input, state);
	}

	@Override public String[] getTokenNames() { return myCheckerParser.tokenNames; }
	@Override public String getGrammarFileName() { return "myChecker.g"; }


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



	// $ANTLR start "program"
	// myChecker.g:32:1: program : VOID MAIN '(' ')' '{' declarations statements '}' ;
	public final void program() throws RecognitionException {
		try {
			// myChecker.g:33:2: ( VOID MAIN '(' ')' '{' declarations statements '}' )
			// myChecker.g:33:4: VOID MAIN '(' ')' '{' declarations statements '}'
			{
			match(input,VOID,FOLLOW_VOID_in_program23); 
			match(input,MAIN,FOLLOW_MAIN_in_program25); 
			match(input,16,FOLLOW_16_in_program27); 
			match(input,17,FOLLOW_17_in_program29); 
			match(input,24,FOLLOW_24_in_program31); 
			pushFollow(FOLLOW_declarations_in_program33);
			declarations();
			state._fsp--;

			pushFollow(FOLLOW_statements_in_program35);
			statements();
			state._fsp--;

			match(input,25,FOLLOW_25_in_program37); 
			 if (TRACEON) System.out.println("VOID MAIN () {declarations statements}"); 
			}

		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "program"



	// $ANTLR start "declarations"
	// myChecker.g:37:1: declarations : ( type Identifier ';' declarations |);
	public final void declarations() throws RecognitionException {
		Token Identifier1=null;
		int type2 =0;

		try {
			// myChecker.g:38:2: ( type Identifier ';' declarations |)
			int alt1=2;
			int LA1_0 = input.LA(1);
			if ( (LA1_0==CHAR||(LA1_0 >= DOUBLE && LA1_0 <= FLOAT)||LA1_0==INT||LA1_0==VOID) ) {
				alt1=1;
			}
			else if ( (LA1_0==IF||LA1_0==Identifier||LA1_0==25) ) {
				alt1=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 1, 0, input);
				throw nvae;
			}

			switch (alt1) {
				case 1 :
					// myChecker.g:38:4: type Identifier ';' declarations
					{
					pushFollow(FOLLOW_type_in_declarations55);
					type2=type();
					state._fsp--;

					Identifier1=(Token)match(input,Identifier,FOLLOW_Identifier_in_declarations57); 
					match(input,22,FOLLOW_22_in_declarations59); 
					pushFollow(FOLLOW_declarations_in_declarations61);
					declarations();
					state._fsp--;


						   if (TRACEON) System.out.println("declarations: type Identifier : declarations");
						 
					  	   if (symtab.containsKey((Identifier1!=null?Identifier1.getText():null))) {
							   System.out.println("Type Error: " + Identifier1.getLine() + ": Redeclared identifier.");
						   } else {
							   symtab.put((Identifier1!=null?Identifier1.getText():null), type2);	   
						   }
						 
					}
					break;
				case 2 :
					// myChecker.g:48:4: 
					{
					 if (TRACEON) System.out.println("declarations: "); 
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "declarations"



	// $ANTLR start "type"
	// myChecker.g:51:1: type returns [int attr_type] : ( INT | FLOAT | DOUBLE | CHAR | VOID );
	public final int type() throws RecognitionException {
		int attr_type = 0;


		try {
			// myChecker.g:52:2: ( INT | FLOAT | DOUBLE | CHAR | VOID )
			int alt2=5;
			switch ( input.LA(1) ) {
			case INT:
				{
				alt2=1;
				}
				break;
			case FLOAT:
				{
				alt2=2;
				}
				break;
			case DOUBLE:
				{
				alt2=3;
				}
				break;
			case CHAR:
				{
				alt2=4;
				}
				break;
			case VOID:
				{
				alt2=5;
				}
				break;
			default:
				NoViableAltException nvae =
					new NoViableAltException("", 2, 0, input);
				throw nvae;
			}
			switch (alt2) {
				case 1 :
					// myChecker.g:52:4: INT
					{
					match(input,INT,FOLLOW_INT_in_type88); 
					 if (TRACEON) System.out.println("type: INT");  attr_type = 1; 
					}
					break;
				case 2 :
					// myChecker.g:53:4: FLOAT
					{
					match(input,FLOAT,FOLLOW_FLOAT_in_type95); 
					 if (TRACEON) System.out.println("type: FLOAT");  attr_type = 2; 
					}
					break;
				case 3 :
					// myChecker.g:54:4: DOUBLE
					{
					match(input,DOUBLE,FOLLOW_DOUBLE_in_type102); 
					 if (TRACEON) System.out.println("type: DOUBLE");  attr_type = 3; 
					}
					break;
				case 4 :
					// myChecker.g:55:4: CHAR
					{
					match(input,CHAR,FOLLOW_CHAR_in_type109); 
					 if (TRACEON) System.out.println("type: CHAR");  attr_type = 4; 
					}
					break;
				case 5 :
					// myChecker.g:56:4: VOID
					{
					match(input,VOID,FOLLOW_VOID_in_type116); 
					 if (TRACEON) System.out.println("type: VOID");  attr_type = 5; 
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return attr_type;
	}
	// $ANTLR end "type"



	// $ANTLR start "statements"
	// myChecker.g:59:1: statements : ( statement statements |);
	public final void statements() throws RecognitionException {
		try {
			// myChecker.g:60:2: ( statement statements |)
			int alt3=2;
			int LA3_0 = input.LA(1);
			if ( (LA3_0==IF||LA3_0==Identifier) ) {
				alt3=1;
			}
			else if ( (LA3_0==25) ) {
				alt3=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 3, 0, input);
				throw nvae;
			}

			switch (alt3) {
				case 1 :
					// myChecker.g:60:3: statement statements
					{
					pushFollow(FOLLOW_statement_in_statements128);
					statement();
					state._fsp--;

					pushFollow(FOLLOW_statements_in_statements130);
					statements();
					state._fsp--;

					}
					break;
				case 2 :
					// myChecker.g:62:2: 
					{
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "statements"


	public static class arith_expression_return extends ParserRuleReturnScope {
		public int attr_type;
	};


	// $ANTLR start "arith_expression"
	// myChecker.g:64:1: arith_expression returns [int attr_type] : a= multExpr ( '+' b= multExpr | '-' c= multExpr )* ;
	public final myCheckerParser.arith_expression_return arith_expression() throws RecognitionException {
		myCheckerParser.arith_expression_return retval = new myCheckerParser.arith_expression_return();
		retval.start = input.LT(1);

		ParserRuleReturnScope a =null;
		ParserRuleReturnScope b =null;
		ParserRuleReturnScope c =null;

		try {
			// myChecker.g:65:2: (a= multExpr ( '+' b= multExpr | '-' c= multExpr )* )
			// myChecker.g:65:4: a= multExpr ( '+' b= multExpr | '-' c= multExpr )*
			{
			pushFollow(FOLLOW_multExpr_in_arith_expression152);
			a=multExpr();
			state._fsp--;

			 retval.attr_type = (a!=null?((myCheckerParser.multExpr_return)a).attr_type:0); 
			// myChecker.g:66:7: ( '+' b= multExpr | '-' c= multExpr )*
			loop4:
			while (true) {
				int alt4=3;
				int LA4_0 = input.LA(1);
				if ( (LA4_0==19) ) {
					alt4=1;
				}
				else if ( (LA4_0==20) ) {
					alt4=2;
				}

				switch (alt4) {
				case 1 :
					// myChecker.g:66:9: '+' b= multExpr
					{
					match(input,19,FOLLOW_19_in_arith_expression164); 
					pushFollow(FOLLOW_multExpr_in_arith_expression170);
					b=multExpr();
					state._fsp--;

					 if ((a!=null?((myCheckerParser.multExpr_return)a).attr_type:0) != (b!=null?((myCheckerParser.multExpr_return)b).attr_type:0)) {
								  System.out.println("Type Error: " + (a!=null?(a.start):null).getLine() + ": Type mismatch for the operator + in an expression.");
							      retval.attr_type = -2;
							  }
					        
					}
					break;
				case 2 :
					// myChecker.g:72:6: '-' c= multExpr
					{
					match(input,20,FOLLOW_20_in_arith_expression184); 
					pushFollow(FOLLOW_multExpr_in_arith_expression190);
					c=multExpr();
					state._fsp--;

					}
					break;

				default :
					break loop4;
				}
			}

			}

			retval.stop = input.LT(-1);

		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return retval;
	}
	// $ANTLR end "arith_expression"


	public static class multExpr_return extends ParserRuleReturnScope {
		public int attr_type;
	};


	// $ANTLR start "multExpr"
	// myChecker.g:76:1: multExpr returns [int attr_type] : a= signExpr ( '*' signExpr | '/' signExpr )* ;
	public final myCheckerParser.multExpr_return multExpr() throws RecognitionException {
		myCheckerParser.multExpr_return retval = new myCheckerParser.multExpr_return();
		retval.start = input.LT(1);

		int a =0;

		try {
			// myChecker.g:77:2: (a= signExpr ( '*' signExpr | '/' signExpr )* )
			// myChecker.g:77:4: a= signExpr ( '*' signExpr | '/' signExpr )*
			{
			pushFollow(FOLLOW_signExpr_in_multExpr215);
			a=signExpr();
			state._fsp--;

			 retval.attr_type = a; 
			// myChecker.g:78:7: ( '*' signExpr | '/' signExpr )*
			loop5:
			while (true) {
				int alt5=3;
				int LA5_0 = input.LA(1);
				if ( (LA5_0==18) ) {
					alt5=1;
				}
				else if ( (LA5_0==21) ) {
					alt5=2;
				}

				switch (alt5) {
				case 1 :
					// myChecker.g:78:9: '*' signExpr
					{
					match(input,18,FOLLOW_18_in_multExpr227); 
					pushFollow(FOLLOW_signExpr_in_multExpr229);
					signExpr();
					state._fsp--;

					}
					break;
				case 2 :
					// myChecker.g:79:9: '/' signExpr
					{
					match(input,21,FOLLOW_21_in_multExpr239); 
					pushFollow(FOLLOW_signExpr_in_multExpr241);
					signExpr();
					state._fsp--;

					}
					break;

				default :
					break loop5;
				}
			}

			}

			retval.stop = input.LT(-1);

		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return retval;
	}
	// $ANTLR end "multExpr"



	// $ANTLR start "signExpr"
	// myChecker.g:83:1: signExpr returns [int attr_type] : ( primaryExpr | '-' primaryExpr );
	public final int signExpr() throws RecognitionException {
		int attr_type = 0;


		int primaryExpr3 =0;
		int primaryExpr4 =0;

		try {
			// myChecker.g:84:2: ( primaryExpr | '-' primaryExpr )
			int alt6=2;
			int LA6_0 = input.LA(1);
			if ( (LA6_0==Floating_point_constant||(LA6_0 >= Identifier && LA6_0 <= Integer_constant)||LA6_0==16) ) {
				alt6=1;
			}
			else if ( (LA6_0==20) ) {
				alt6=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 6, 0, input);
				throw nvae;
			}

			switch (alt6) {
				case 1 :
					// myChecker.g:84:4: primaryExpr
					{
					pushFollow(FOLLOW_primaryExpr_in_signExpr262);
					primaryExpr3=primaryExpr();
					state._fsp--;

					 attr_type = primaryExpr3; 
					}
					break;
				case 2 :
					// myChecker.g:85:4: '-' primaryExpr
					{
					match(input,20,FOLLOW_20_in_signExpr269); 
					pushFollow(FOLLOW_primaryExpr_in_signExpr271);
					primaryExpr4=primaryExpr();
					state._fsp--;

					 attr_type = primaryExpr4; 
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return attr_type;
	}
	// $ANTLR end "signExpr"



	// $ANTLR start "primaryExpr"
	// myChecker.g:88:1: primaryExpr returns [int attr_type] : ( Integer_constant | Floating_point_constant | Identifier | '(' arith_expression ')' );
	public final int primaryExpr() throws RecognitionException {
		int attr_type = 0;


		Token Identifier5=null;
		ParserRuleReturnScope arith_expression6 =null;

		try {
			// myChecker.g:89:2: ( Integer_constant | Floating_point_constant | Identifier | '(' arith_expression ')' )
			int alt7=4;
			switch ( input.LA(1) ) {
			case Integer_constant:
				{
				alt7=1;
				}
				break;
			case Floating_point_constant:
				{
				alt7=2;
				}
				break;
			case Identifier:
				{
				alt7=3;
				}
				break;
			case 16:
				{
				alt7=4;
				}
				break;
			default:
				NoViableAltException nvae =
					new NoViableAltException("", 7, 0, input);
				throw nvae;
			}
			switch (alt7) {
				case 1 :
					// myChecker.g:89:4: Integer_constant
					{
					match(input,Integer_constant,FOLLOW_Integer_constant_in_primaryExpr293); 
					 attr_type = 1; 
					}
					break;
				case 2 :
					// myChecker.g:90:4: Floating_point_constant
					{
					match(input,Floating_point_constant,FOLLOW_Floating_point_constant_in_primaryExpr307); 
					 attr_type = 2; 
					}
					break;
				case 3 :
					// myChecker.g:91:4: Identifier
					{
					Identifier5=(Token)match(input,Identifier,FOLLOW_Identifier_in_primaryExpr314); 

							if (symtab.containsKey((Identifier5!=null?Identifier5.getText():null))) {
								attr_type = symtab.get((Identifier5!=null?Identifier5.getText():null));
							}
						
					}
					break;
				case 4 :
					// myChecker.g:97:4: '(' arith_expression ')'
					{
					match(input,16,FOLLOW_16_in_primaryExpr323); 
					pushFollow(FOLLOW_arith_expression_in_primaryExpr325);
					arith_expression6=arith_expression();
					state._fsp--;

					match(input,17,FOLLOW_17_in_primaryExpr327); 
					 attr_type = (arith_expression6!=null?((myCheckerParser.arith_expression_return)arith_expression6).attr_type:0); 
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return attr_type;
	}
	// $ANTLR end "primaryExpr"



	// $ANTLR start "statement"
	// myChecker.g:100:1: statement returns [int attr_type] : ( Identifier '=' arith_expression ';' | IF '(' arith_expression ')' if_then_statements );
	public final int statement() throws RecognitionException {
		int attr_type = 0;


		Token Identifier7=null;
		ParserRuleReturnScope arith_expression8 =null;

		try {
			// myChecker.g:101:2: ( Identifier '=' arith_expression ';' | IF '(' arith_expression ')' if_then_statements )
			int alt8=2;
			int LA8_0 = input.LA(1);
			if ( (LA8_0==Identifier) ) {
				alt8=1;
			}
			else if ( (LA8_0==IF) ) {
				alt8=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 8, 0, input);
				throw nvae;
			}

			switch (alt8) {
				case 1 :
					// myChecker.g:101:4: Identifier '=' arith_expression ';'
					{
					Identifier7=(Token)match(input,Identifier,FOLLOW_Identifier_in_statement347); 
					match(input,23,FOLLOW_23_in_statement349); 
					pushFollow(FOLLOW_arith_expression_in_statement351);
					arith_expression8=arith_expression();
					state._fsp--;

					match(input,22,FOLLOW_22_in_statement353); 

						   if (symtab.containsKey((Identifier7!=null?Identifier7.getText():null))) {
						       attr_type = symtab.get((Identifier7!=null?Identifier7.getText():null));
						   } else {
							   System.out.println("Type Error: " + Identifier7.getLine() + ": Undeclared identifier.");
						       attr_type = -2;
							   return attr_type;
						   }
							
						   if (attr_type != (arith_expression8!=null?((myCheckerParser.arith_expression_return)arith_expression8).attr_type:0)) {
					           System.out.println("Type Error: " + (arith_expression8!=null?(arith_expression8.start):null).getLine() + ": Type mismatch for the two silde operands in an assignment statement.");
							   attr_type = -2;
					       }
						 
					}
					break;
				case 2 :
					// myChecker.g:116:4: IF '(' arith_expression ')' if_then_statements
					{
					match(input,IF,FOLLOW_IF_in_statement362); 
					match(input,16,FOLLOW_16_in_statement364); 
					pushFollow(FOLLOW_arith_expression_in_statement366);
					arith_expression();
					state._fsp--;

					match(input,17,FOLLOW_17_in_statement368); 
					pushFollow(FOLLOW_if_then_statements_in_statement370);
					if_then_statements();
					state._fsp--;

					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
		return attr_type;
	}
	// $ANTLR end "statement"



	// $ANTLR start "if_then_statements"
	// myChecker.g:119:1: if_then_statements : ( statement | '{' statements '}' );
	public final void if_then_statements() throws RecognitionException {
		try {
			// myChecker.g:120:2: ( statement | '{' statements '}' )
			int alt9=2;
			int LA9_0 = input.LA(1);
			if ( (LA9_0==IF||LA9_0==Identifier) ) {
				alt9=1;
			}
			else if ( (LA9_0==24) ) {
				alt9=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 9, 0, input);
				throw nvae;
			}

			switch (alt9) {
				case 1 :
					// myChecker.g:120:4: statement
					{
					pushFollow(FOLLOW_statement_in_if_then_statements381);
					statement();
					state._fsp--;

					}
					break;
				case 2 :
					// myChecker.g:121:4: '{' statements '}'
					{
					match(input,24,FOLLOW_24_in_if_then_statements386); 
					pushFollow(FOLLOW_statements_in_if_then_statements388);
					statements();
					state._fsp--;

					match(input,25,FOLLOW_25_in_if_then_statements390); 
					}
					break;

			}
		}
		catch (RecognitionException re) {
			reportError(re);
			recover(input,re);
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "if_then_statements"

	// Delegated rules



	public static final BitSet FOLLOW_VOID_in_program23 = new BitSet(new long[]{0x0000000000002000L});
	public static final BitSet FOLLOW_MAIN_in_program25 = new BitSet(new long[]{0x0000000000010000L});
	public static final BitSet FOLLOW_16_in_program27 = new BitSet(new long[]{0x0000000000020000L});
	public static final BitSet FOLLOW_17_in_program29 = new BitSet(new long[]{0x0000000001000000L});
	public static final BitSet FOLLOW_24_in_program31 = new BitSet(new long[]{0x0000000002004ED0L});
	public static final BitSet FOLLOW_declarations_in_program33 = new BitSet(new long[]{0x0000000002000A00L});
	public static final BitSet FOLLOW_statements_in_program35 = new BitSet(new long[]{0x0000000002000000L});
	public static final BitSet FOLLOW_25_in_program37 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_type_in_declarations55 = new BitSet(new long[]{0x0000000000000800L});
	public static final BitSet FOLLOW_Identifier_in_declarations57 = new BitSet(new long[]{0x0000000000400000L});
	public static final BitSet FOLLOW_22_in_declarations59 = new BitSet(new long[]{0x00000000000044D0L});
	public static final BitSet FOLLOW_declarations_in_declarations61 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_INT_in_type88 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_FLOAT_in_type95 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_DOUBLE_in_type102 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_CHAR_in_type109 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_VOID_in_type116 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_statement_in_statements128 = new BitSet(new long[]{0x0000000000000A00L});
	public static final BitSet FOLLOW_statements_in_statements130 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_multExpr_in_arith_expression152 = new BitSet(new long[]{0x0000000000180002L});
	public static final BitSet FOLLOW_19_in_arith_expression164 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_multExpr_in_arith_expression170 = new BitSet(new long[]{0x0000000000180002L});
	public static final BitSet FOLLOW_20_in_arith_expression184 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_multExpr_in_arith_expression190 = new BitSet(new long[]{0x0000000000180002L});
	public static final BitSet FOLLOW_signExpr_in_multExpr215 = new BitSet(new long[]{0x0000000000240002L});
	public static final BitSet FOLLOW_18_in_multExpr227 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_signExpr_in_multExpr229 = new BitSet(new long[]{0x0000000000240002L});
	public static final BitSet FOLLOW_21_in_multExpr239 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_signExpr_in_multExpr241 = new BitSet(new long[]{0x0000000000240002L});
	public static final BitSet FOLLOW_primaryExpr_in_signExpr262 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_20_in_signExpr269 = new BitSet(new long[]{0x0000000000011900L});
	public static final BitSet FOLLOW_primaryExpr_in_signExpr271 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_Integer_constant_in_primaryExpr293 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_Floating_point_constant_in_primaryExpr307 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_Identifier_in_primaryExpr314 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_16_in_primaryExpr323 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_arith_expression_in_primaryExpr325 = new BitSet(new long[]{0x0000000000020000L});
	public static final BitSet FOLLOW_17_in_primaryExpr327 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_Identifier_in_statement347 = new BitSet(new long[]{0x0000000000800000L});
	public static final BitSet FOLLOW_23_in_statement349 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_arith_expression_in_statement351 = new BitSet(new long[]{0x0000000000400000L});
	public static final BitSet FOLLOW_22_in_statement353 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_IF_in_statement362 = new BitSet(new long[]{0x0000000000010000L});
	public static final BitSet FOLLOW_16_in_statement364 = new BitSet(new long[]{0x0000000000111900L});
	public static final BitSet FOLLOW_arith_expression_in_statement366 = new BitSet(new long[]{0x0000000000020000L});
	public static final BitSet FOLLOW_17_in_statement368 = new BitSet(new long[]{0x0000000001000A00L});
	public static final BitSet FOLLOW_if_then_statements_in_statement370 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_statement_in_if_then_statements381 = new BitSet(new long[]{0x0000000000000002L});
	public static final BitSet FOLLOW_24_in_if_then_statements386 = new BitSet(new long[]{0x0000000002000A00L});
	public static final BitSet FOLLOW_statements_in_if_then_statements388 = new BitSet(new long[]{0x0000000002000000L});
	public static final BitSet FOLLOW_25_in_if_then_statements390 = new BitSet(new long[]{0x0000000000000002L});
}
