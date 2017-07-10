// $ANTLR 3.5.2 myChecker.g 2016-05-30 21:33:24

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings("all")
public class myCheckerLexer extends Lexer {
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
	// delegators
	public Lexer[] getDelegates() {
		return new Lexer[] {};
	}

	public myCheckerLexer() {} 
	public myCheckerLexer(CharStream input) {
		this(input, new RecognizerSharedState());
	}
	public myCheckerLexer(CharStream input, RecognizerSharedState state) {
		super(input,state);
	}
	@Override public String getGrammarFileName() { return "myChecker.g"; }

	// $ANTLR start "T__16"
	public final void mT__16() throws RecognitionException {
		try {
			int _type = T__16;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:2:7: ( '(' )
			// myChecker.g:2:9: '('
			{
			match('('); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__16"

	// $ANTLR start "T__17"
	public final void mT__17() throws RecognitionException {
		try {
			int _type = T__17;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:3:7: ( ')' )
			// myChecker.g:3:9: ')'
			{
			match(')'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__17"

	// $ANTLR start "T__18"
	public final void mT__18() throws RecognitionException {
		try {
			int _type = T__18;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:4:7: ( '*' )
			// myChecker.g:4:9: '*'
			{
			match('*'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__18"

	// $ANTLR start "T__19"
	public final void mT__19() throws RecognitionException {
		try {
			int _type = T__19;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:5:7: ( '+' )
			// myChecker.g:5:9: '+'
			{
			match('+'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__19"

	// $ANTLR start "T__20"
	public final void mT__20() throws RecognitionException {
		try {
			int _type = T__20;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:6:7: ( '-' )
			// myChecker.g:6:9: '-'
			{
			match('-'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__20"

	// $ANTLR start "T__21"
	public final void mT__21() throws RecognitionException {
		try {
			int _type = T__21;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:7:7: ( '/' )
			// myChecker.g:7:9: '/'
			{
			match('/'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__21"

	// $ANTLR start "T__22"
	public final void mT__22() throws RecognitionException {
		try {
			int _type = T__22;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:8:7: ( ';' )
			// myChecker.g:8:9: ';'
			{
			match(';'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__22"

	// $ANTLR start "T__23"
	public final void mT__23() throws RecognitionException {
		try {
			int _type = T__23;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:9:7: ( '=' )
			// myChecker.g:9:9: '='
			{
			match('='); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__23"

	// $ANTLR start "T__24"
	public final void mT__24() throws RecognitionException {
		try {
			int _type = T__24;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:10:7: ( '{' )
			// myChecker.g:10:9: '{'
			{
			match('{'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__24"

	// $ANTLR start "T__25"
	public final void mT__25() throws RecognitionException {
		try {
			int _type = T__25;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:11:7: ( '}' )
			// myChecker.g:11:9: '}'
			{
			match('}'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "T__25"

	// $ANTLR start "FLOAT"
	public final void mFLOAT() throws RecognitionException {
		try {
			int _type = FLOAT;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:126:6: ( 'float' )
			// myChecker.g:126:7: 'float'
			{
			match("float"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "FLOAT"

	// $ANTLR start "INT"
	public final void mINT() throws RecognitionException {
		try {
			int _type = INT;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:127:4: ( 'int' )
			// myChecker.g:127:5: 'int'
			{
			match("int"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "INT"

	// $ANTLR start "DOUBLE"
	public final void mDOUBLE() throws RecognitionException {
		try {
			int _type = DOUBLE;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:128:7: ( 'double' )
			// myChecker.g:128:8: 'double'
			{
			match("double"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "DOUBLE"

	// $ANTLR start "CHAR"
	public final void mCHAR() throws RecognitionException {
		try {
			int _type = CHAR;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:129:5: ( 'char' )
			// myChecker.g:129:6: 'char'
			{
			match("char"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "CHAR"

	// $ANTLR start "MAIN"
	public final void mMAIN() throws RecognitionException {
		try {
			int _type = MAIN;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:130:5: ( 'main' )
			// myChecker.g:130:7: 'main'
			{
			match("main"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "MAIN"

	// $ANTLR start "VOID"
	public final void mVOID() throws RecognitionException {
		try {
			int _type = VOID;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:131:5: ( 'void' )
			// myChecker.g:131:7: 'void'
			{
			match("void"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "VOID"

	// $ANTLR start "IF"
	public final void mIF() throws RecognitionException {
		try {
			int _type = IF;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:132:3: ( 'if' )
			// myChecker.g:132:5: 'if'
			{
			match("if"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "IF"

	// $ANTLR start "Identifier"
	public final void mIdentifier() throws RecognitionException {
		try {
			int _type = Identifier;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:134:11: ( ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )* )
			// myChecker.g:134:12: ( 'a' .. 'z' | 'A' .. 'Z' | '_' ) ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
			{
			if ( (input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
				input.consume();
			}
			else {
				MismatchedSetException mse = new MismatchedSetException(null,input);
				recover(mse);
				throw mse;
			}
			// myChecker.g:134:36: ( 'a' .. 'z' | 'A' .. 'Z' | '0' .. '9' | '_' )*
			loop1:
			while (true) {
				int alt1=2;
				int LA1_0 = input.LA(1);
				if ( ((LA1_0 >= '0' && LA1_0 <= '9')||(LA1_0 >= 'A' && LA1_0 <= 'Z')||LA1_0=='_'||(LA1_0 >= 'a' && LA1_0 <= 'z')) ) {
					alt1=1;
				}

				switch (alt1) {
				case 1 :
					// myChecker.g:
					{
					if ( (input.LA(1) >= '0' && input.LA(1) <= '9')||(input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
						input.consume();
					}
					else {
						MismatchedSetException mse = new MismatchedSetException(null,input);
						recover(mse);
						throw mse;
					}
					}
					break;

				default :
					break loop1;
				}
			}

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Identifier"

	// $ANTLR start "Integer_constant"
	public final void mInteger_constant() throws RecognitionException {
		try {
			int _type = Integer_constant;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:135:17: ( ( '0' .. '9' )+ )
			// myChecker.g:135:18: ( '0' .. '9' )+
			{
			// myChecker.g:135:18: ( '0' .. '9' )+
			int cnt2=0;
			loop2:
			while (true) {
				int alt2=2;
				int LA2_0 = input.LA(1);
				if ( ((LA2_0 >= '0' && LA2_0 <= '9')) ) {
					alt2=1;
				}

				switch (alt2) {
				case 1 :
					// myChecker.g:
					{
					if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
						input.consume();
					}
					else {
						MismatchedSetException mse = new MismatchedSetException(null,input);
						recover(mse);
						throw mse;
					}
					}
					break;

				default :
					if ( cnt2 >= 1 ) break loop2;
					EarlyExitException eee = new EarlyExitException(2, input);
					throw eee;
				}
				cnt2++;
			}

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Integer_constant"

	// $ANTLR start "Floating_point_constant"
	public final void mFloating_point_constant() throws RecognitionException {
		try {
			int _type = Floating_point_constant;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:136:24: ( ( '0' .. '9' )+ '.' ( '0' .. '9' )+ )
			// myChecker.g:136:25: ( '0' .. '9' )+ '.' ( '0' .. '9' )+
			{
			// myChecker.g:136:25: ( '0' .. '9' )+
			int cnt3=0;
			loop3:
			while (true) {
				int alt3=2;
				int LA3_0 = input.LA(1);
				if ( ((LA3_0 >= '0' && LA3_0 <= '9')) ) {
					alt3=1;
				}

				switch (alt3) {
				case 1 :
					// myChecker.g:
					{
					if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
						input.consume();
					}
					else {
						MismatchedSetException mse = new MismatchedSetException(null,input);
						recover(mse);
						throw mse;
					}
					}
					break;

				default :
					if ( cnt3 >= 1 ) break loop3;
					EarlyExitException eee = new EarlyExitException(3, input);
					throw eee;
				}
				cnt3++;
			}

			match('.'); 
			// myChecker.g:136:39: ( '0' .. '9' )+
			int cnt4=0;
			loop4:
			while (true) {
				int alt4=2;
				int LA4_0 = input.LA(1);
				if ( ((LA4_0 >= '0' && LA4_0 <= '9')) ) {
					alt4=1;
				}

				switch (alt4) {
				case 1 :
					// myChecker.g:
					{
					if ( (input.LA(1) >= '0' && input.LA(1) <= '9') ) {
						input.consume();
					}
					else {
						MismatchedSetException mse = new MismatchedSetException(null,input);
						recover(mse);
						throw mse;
					}
					}
					break;

				default :
					if ( cnt4 >= 1 ) break loop4;
					EarlyExitException eee = new EarlyExitException(4, input);
					throw eee;
				}
				cnt4++;
			}

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Floating_point_constant"

	// $ANTLR start "WS"
	public final void mWS() throws RecognitionException {
		try {
			int _type = WS;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:138:3: ( ( ' ' | '\\t' | '\\r' | '\\n' ) )
			// myChecker.g:138:4: ( ' ' | '\\t' | '\\r' | '\\n' )
			{
			if ( (input.LA(1) >= '\t' && input.LA(1) <= '\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
				input.consume();
			}
			else {
				MismatchedSetException mse = new MismatchedSetException(null,input);
				recover(mse);
				throw mse;
			}
			_channel=HIDDEN;
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "WS"

	// $ANTLR start "COMMENT"
	public final void mCOMMENT() throws RecognitionException {
		try {
			int _type = COMMENT;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// myChecker.g:139:8: ( '/*' ( . )* '*/' )
			// myChecker.g:139:9: '/*' ( . )* '*/'
			{
			match("/*"); 

			// myChecker.g:139:14: ( . )*
			loop5:
			while (true) {
				int alt5=2;
				int LA5_0 = input.LA(1);
				if ( (LA5_0=='*') ) {
					int LA5_1 = input.LA(2);
					if ( (LA5_1=='/') ) {
						alt5=2;
					}
					else if ( ((LA5_1 >= '\u0000' && LA5_1 <= '.')||(LA5_1 >= '0' && LA5_1 <= '\uFFFF')) ) {
						alt5=1;
					}

				}
				else if ( ((LA5_0 >= '\u0000' && LA5_0 <= ')')||(LA5_0 >= '+' && LA5_0 <= '\uFFFF')) ) {
					alt5=1;
				}

				switch (alt5) {
				case 1 :
					// myChecker.g:139:14: .
					{
					matchAny(); 
					}
					break;

				default :
					break loop5;
				}
			}

			match("*/"); 

			_channel=HIDDEN;
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "COMMENT"

	@Override
	public void mTokens() throws RecognitionException {
		// myChecker.g:1:8: ( T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | FLOAT | INT | DOUBLE | CHAR | MAIN | VOID | IF | Identifier | Integer_constant | Floating_point_constant | WS | COMMENT )
		int alt6=22;
		alt6 = dfa6.predict(input);
		switch (alt6) {
			case 1 :
				// myChecker.g:1:10: T__16
				{
				mT__16(); 

				}
				break;
			case 2 :
				// myChecker.g:1:16: T__17
				{
				mT__17(); 

				}
				break;
			case 3 :
				// myChecker.g:1:22: T__18
				{
				mT__18(); 

				}
				break;
			case 4 :
				// myChecker.g:1:28: T__19
				{
				mT__19(); 

				}
				break;
			case 5 :
				// myChecker.g:1:34: T__20
				{
				mT__20(); 

				}
				break;
			case 6 :
				// myChecker.g:1:40: T__21
				{
				mT__21(); 

				}
				break;
			case 7 :
				// myChecker.g:1:46: T__22
				{
				mT__22(); 

				}
				break;
			case 8 :
				// myChecker.g:1:52: T__23
				{
				mT__23(); 

				}
				break;
			case 9 :
				// myChecker.g:1:58: T__24
				{
				mT__24(); 

				}
				break;
			case 10 :
				// myChecker.g:1:64: T__25
				{
				mT__25(); 

				}
				break;
			case 11 :
				// myChecker.g:1:70: FLOAT
				{
				mFLOAT(); 

				}
				break;
			case 12 :
				// myChecker.g:1:76: INT
				{
				mINT(); 

				}
				break;
			case 13 :
				// myChecker.g:1:80: DOUBLE
				{
				mDOUBLE(); 

				}
				break;
			case 14 :
				// myChecker.g:1:87: CHAR
				{
				mCHAR(); 

				}
				break;
			case 15 :
				// myChecker.g:1:92: MAIN
				{
				mMAIN(); 

				}
				break;
			case 16 :
				// myChecker.g:1:97: VOID
				{
				mVOID(); 

				}
				break;
			case 17 :
				// myChecker.g:1:102: IF
				{
				mIF(); 

				}
				break;
			case 18 :
				// myChecker.g:1:105: Identifier
				{
				mIdentifier(); 

				}
				break;
			case 19 :
				// myChecker.g:1:116: Integer_constant
				{
				mInteger_constant(); 

				}
				break;
			case 20 :
				// myChecker.g:1:133: Floating_point_constant
				{
				mFloating_point_constant(); 

				}
				break;
			case 21 :
				// myChecker.g:1:157: WS
				{
				mWS(); 

				}
				break;
			case 22 :
				// myChecker.g:1:160: COMMENT
				{
				mCOMMENT(); 

				}
				break;

		}
	}


	protected DFA6 dfa6 = new DFA6(this);
	static final String DFA6_eotS =
		"\6\uffff\1\25\4\uffff\6\21\1\uffff\1\35\3\uffff\2\21\1\41\4\21\2\uffff"+
		"\1\21\1\47\1\uffff\5\21\1\uffff\1\21\1\56\1\57\1\60\1\61\1\21\4\uffff"+
		"\1\63\1\uffff";
	static final String DFA6_eofS =
		"\64\uffff";
	static final String DFA6_minS =
		"\1\11\5\uffff\1\52\4\uffff\1\154\1\146\1\157\1\150\1\141\1\157\1\uffff"+
		"\1\56\3\uffff\1\157\1\164\1\60\1\165\1\141\2\151\2\uffff\1\141\1\60\1"+
		"\uffff\1\142\1\162\1\156\1\144\1\164\1\uffff\1\154\4\60\1\145\4\uffff"+
		"\1\60\1\uffff";
	static final String DFA6_maxS =
		"\1\175\5\uffff\1\52\4\uffff\1\154\1\156\1\157\1\150\1\141\1\157\1\uffff"+
		"\1\71\3\uffff\1\157\1\164\1\172\1\165\1\141\2\151\2\uffff\1\141\1\172"+
		"\1\uffff\1\142\1\162\1\156\1\144\1\164\1\uffff\1\154\4\172\1\145\4\uffff"+
		"\1\172\1\uffff";
	static final String DFA6_acceptS =
		"\1\uffff\1\1\1\2\1\3\1\4\1\5\1\uffff\1\7\1\10\1\11\1\12\6\uffff\1\22\1"+
		"\uffff\1\25\1\26\1\6\7\uffff\1\23\1\24\2\uffff\1\21\5\uffff\1\14\6\uffff"+
		"\1\16\1\17\1\20\1\13\1\uffff\1\15";
	static final String DFA6_specialS =
		"\64\uffff}>";
	static final String[] DFA6_transitionS = {
			"\2\23\2\uffff\1\23\22\uffff\1\23\7\uffff\1\1\1\2\1\3\1\4\1\uffff\1\5"+
			"\1\uffff\1\6\12\22\1\uffff\1\7\1\uffff\1\10\3\uffff\32\21\4\uffff\1\21"+
			"\1\uffff\2\21\1\16\1\15\1\21\1\13\2\21\1\14\3\21\1\17\10\21\1\20\4\21"+
			"\1\11\1\uffff\1\12",
			"",
			"",
			"",
			"",
			"",
			"\1\24",
			"",
			"",
			"",
			"",
			"\1\26",
			"\1\30\7\uffff\1\27",
			"\1\31",
			"\1\32",
			"\1\33",
			"\1\34",
			"",
			"\1\36\1\uffff\12\22",
			"",
			"",
			"",
			"\1\37",
			"\1\40",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"\1\42",
			"\1\43",
			"\1\44",
			"\1\45",
			"",
			"",
			"\1\46",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"",
			"\1\50",
			"\1\51",
			"\1\52",
			"\1\53",
			"\1\54",
			"",
			"\1\55",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			"\1\62",
			"",
			"",
			"",
			"",
			"\12\21\7\uffff\32\21\4\uffff\1\21\1\uffff\32\21",
			""
	};

	static final short[] DFA6_eot = DFA.unpackEncodedString(DFA6_eotS);
	static final short[] DFA6_eof = DFA.unpackEncodedString(DFA6_eofS);
	static final char[] DFA6_min = DFA.unpackEncodedStringToUnsignedChars(DFA6_minS);
	static final char[] DFA6_max = DFA.unpackEncodedStringToUnsignedChars(DFA6_maxS);
	static final short[] DFA6_accept = DFA.unpackEncodedString(DFA6_acceptS);
	static final short[] DFA6_special = DFA.unpackEncodedString(DFA6_specialS);
	static final short[][] DFA6_transition;

	static {
		int numStates = DFA6_transitionS.length;
		DFA6_transition = new short[numStates][];
		for (int i=0; i<numStates; i++) {
			DFA6_transition[i] = DFA.unpackEncodedString(DFA6_transitionS[i]);
		}
	}

	protected class DFA6 extends DFA {

		public DFA6(BaseRecognizer recognizer) {
			this.recognizer = recognizer;
			this.decisionNumber = 6;
			this.eot = DFA6_eot;
			this.eof = DFA6_eof;
			this.min = DFA6_min;
			this.max = DFA6_max;
			this.accept = DFA6_accept;
			this.special = DFA6_special;
			this.transition = DFA6_transition;
		}
		@Override
		public String getDescription() {
			return "1:1: Tokens : ( T__16 | T__17 | T__18 | T__19 | T__20 | T__21 | T__22 | T__23 | T__24 | T__25 | FLOAT | INT | DOUBLE | CHAR | MAIN | VOID | IF | Identifier | Integer_constant | Floating_point_constant | WS | COMMENT );";
		}
	}

}
