// $ANTLR 3.5.2 mylexer.g 2016-05-13 18:02:08

import org.antlr.runtime.*;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;

@SuppressWarnings("all")
public class mylexer extends Lexer {
	public static final int EOF=-1;
	public static final int And=4;
	public static final int AndAnd=5;
	public static final int AndAssign=6;
	public static final int Arrow=7;
	public static final int Assign=8;
	public static final int Backslash=9;
	public static final int Break=10;
	public static final int Caret=11;
	public static final int Case=12;
	public static final int Char=13;
	public static final int Colon=14;
	public static final int Comma=15;
	public static final int Comment=16;
	public static final int Constant=17;
	public static final int Continue=18;
	public static final int Default=19;
	public static final int Digit=20;
	public static final int Div=21;
	public static final int DivAssign=22;
	public static final int Dot=23;
	public static final int Double=24;
	public static final int DoubleQuote=25;
	public static final int Else=26;
	public static final int Equal=27;
	public static final int Float=28;
	public static final int For=29;
	public static final int Greater=30;
	public static final int GreaterEqual=31;
	public static final int Identifier=32;
	public static final int If=33;
	public static final int Int=34;
	public static final int LeftBrace=35;
	public static final int LeftBracket=36;
	public static final int LeftParen=37;
	public static final int LeftShift=38;
	public static final int LeftShiftAssign=39;
	public static final int Less=40;
	public static final int LessEqual=41;
	public static final int Minus=42;
	public static final int MinusAssign=43;
	public static final int MinusMinus=44;
	public static final int Mod=45;
	public static final int ModAssign=46;
	public static final int Nondigit=47;
	public static final int Not=48;
	public static final int NotEqual=49;
	public static final int Null=50;
	public static final int Or=51;
	public static final int OrAssign=52;
	public static final int OrOr=53;
	public static final int Plus=54;
	public static final int PlusAssign=55;
	public static final int PlusPlus=56;
	public static final int Pointer=57;
	public static final int PoundSign=58;
	public static final int Quote=59;
	public static final int Reference=60;
	public static final int Return=61;
	public static final int RightBrace=62;
	public static final int RightBracket=63;
	public static final int RightParen=64;
	public static final int RightShift=65;
	public static final int RightShiftAssign=66;
	public static final int Semi=67;
	public static final int Star=68;
	public static final int StarAssign=69;
	public static final int Switch=70;
	public static final int Void=71;
	public static final int While=72;
	public static final int Whitespace=73;
	public static final int XorAssign=74;

	// delegates
	// delegators
	public Lexer[] getDelegates() {
		return new Lexer[] {};
	}

	public mylexer() {} 
	public mylexer(CharStream input) {
		this(input, new RecognizerSharedState());
	}
	public mylexer(CharStream input, RecognizerSharedState state) {
		super(input,state);
	}
	@Override public String getGrammarFileName() { return "mylexer.g"; }

	// $ANTLR start "Nondigit"
	public final void mNondigit() throws RecognitionException {
		try {
			// mylexer.g:8:18: ( 'a' .. 'z' | 'A' .. 'Z' | '_' )
			// mylexer.g:
			{
			if ( (input.LA(1) >= 'A' && input.LA(1) <= 'Z')||input.LA(1)=='_'||(input.LA(1) >= 'a' && input.LA(1) <= 'z') ) {
				input.consume();
			}
			else {
				MismatchedSetException mse = new MismatchedSetException(null,input);
				recover(mse);
				throw mse;
			}
			}

		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Nondigit"

	// $ANTLR start "Digit"
	public final void mDigit() throws RecognitionException {
		try {
			// mylexer.g:9:15: ( '0' .. '9' )
			// mylexer.g:
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

		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Digit"

	// $ANTLR start "Int"
	public final void mInt() throws RecognitionException {
		try {
			int _type = Int;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:11:5: ( 'int' )
			// mylexer.g:11:7: 'int'
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
	// $ANTLR end "Int"

	// $ANTLR start "Char"
	public final void mChar() throws RecognitionException {
		try {
			int _type = Char;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:12:6: ( 'char' )
			// mylexer.g:12:8: 'char'
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
	// $ANTLR end "Char"

	// $ANTLR start "Float"
	public final void mFloat() throws RecognitionException {
		try {
			int _type = Float;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:13:7: ( 'float' )
			// mylexer.g:13:9: 'float'
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
	// $ANTLR end "Float"

	// $ANTLR start "Double"
	public final void mDouble() throws RecognitionException {
		try {
			int _type = Double;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:14:8: ( 'double' )
			// mylexer.g:14:10: 'double'
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
	// $ANTLR end "Double"

	// $ANTLR start "Void"
	public final void mVoid() throws RecognitionException {
		try {
			int _type = Void;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:15:6: ( 'void' )
			// mylexer.g:15:8: 'void'
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
	// $ANTLR end "Void"

	// $ANTLR start "If"
	public final void mIf() throws RecognitionException {
		try {
			int _type = If;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:17:4: ( 'if' )
			// mylexer.g:17:6: 'if'
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
	// $ANTLR end "If"

	// $ANTLR start "Else"
	public final void mElse() throws RecognitionException {
		try {
			int _type = Else;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:18:6: ( 'else' )
			// mylexer.g:18:8: 'else'
			{
			match("else"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Else"

	// $ANTLR start "For"
	public final void mFor() throws RecognitionException {
		try {
			int _type = For;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:20:5: ( 'for' )
			// mylexer.g:20:7: 'for'
			{
			match("for"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "For"

	// $ANTLR start "While"
	public final void mWhile() throws RecognitionException {
		try {
			int _type = While;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:21:7: ( 'while' )
			// mylexer.g:21:9: 'while'
			{
			match("while"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "While"

	// $ANTLR start "Switch"
	public final void mSwitch() throws RecognitionException {
		try {
			int _type = Switch;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:22:8: ( 'switch' )
			// mylexer.g:22:10: 'switch'
			{
			match("switch"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Switch"

	// $ANTLR start "Case"
	public final void mCase() throws RecognitionException {
		try {
			int _type = Case;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:23:6: ( 'case' )
			// mylexer.g:23:8: 'case'
			{
			match("case"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Case"

	// $ANTLR start "Continue"
	public final void mContinue() throws RecognitionException {
		try {
			int _type = Continue;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:24:10: ( 'continue' )
			// mylexer.g:24:12: 'continue'
			{
			match("continue"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Continue"

	// $ANTLR start "Break"
	public final void mBreak() throws RecognitionException {
		try {
			int _type = Break;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:25:7: ( 'break' )
			// mylexer.g:25:9: 'break'
			{
			match("break"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Break"

	// $ANTLR start "Default"
	public final void mDefault() throws RecognitionException {
		try {
			int _type = Default;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:26:9: ( 'default' )
			// mylexer.g:26:11: 'default'
			{
			match("default"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Default"

	// $ANTLR start "Return"
	public final void mReturn() throws RecognitionException {
		try {
			int _type = Return;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:27:8: ( 'return' )
			// mylexer.g:27:10: 'return'
			{
			match("return"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Return"

	// $ANTLR start "Null"
	public final void mNull() throws RecognitionException {
		try {
			int _type = Null;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:28:6: ( 'NULL' )
			// mylexer.g:28:8: 'NULL'
			{
			match("NULL"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Null"

	// $ANTLR start "Identifier"
	public final void mIdentifier() throws RecognitionException {
		try {
			int _type = Identifier;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:30:12: ( Nondigit ( Nondigit | Digit )* )
			// mylexer.g:30:14: Nondigit ( Nondigit | Digit )*
			{
			mNondigit(); 

			// mylexer.g:30:23: ( Nondigit | Digit )*
			loop1:
			while (true) {
				int alt1=2;
				int LA1_0 = input.LA(1);
				if ( ((LA1_0 >= '0' && LA1_0 <= '9')||(LA1_0 >= 'A' && LA1_0 <= 'Z')||LA1_0=='_'||(LA1_0 >= 'a' && LA1_0 <= 'z')) ) {
					alt1=1;
				}

				switch (alt1) {
				case 1 :
					// mylexer.g:
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

	// $ANTLR start "Pointer"
	public final void mPointer() throws RecognitionException {
		try {
			int _type = Pointer;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:31:9: ( ( '*' )+ Identifier )
			// mylexer.g:31:11: ( '*' )+ Identifier
			{
			// mylexer.g:31:11: ( '*' )+
			int cnt2=0;
			loop2:
			while (true) {
				int alt2=2;
				int LA2_0 = input.LA(1);
				if ( (LA2_0=='*') ) {
					alt2=1;
				}

				switch (alt2) {
				case 1 :
					// mylexer.g:31:12: '*'
					{
					match('*'); 
					}
					break;

				default :
					if ( cnt2 >= 1 ) break loop2;
					EarlyExitException eee = new EarlyExitException(2, input);
					throw eee;
				}
				cnt2++;
			}

			mIdentifier(); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Pointer"

	// $ANTLR start "Reference"
	public final void mReference() throws RecognitionException {
		try {
			int _type = Reference;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:32:11: ( ( '&' )+ Identifier )
			// mylexer.g:32:13: ( '&' )+ Identifier
			{
			// mylexer.g:32:13: ( '&' )+
			int cnt3=0;
			loop3:
			while (true) {
				int alt3=2;
				int LA3_0 = input.LA(1);
				if ( (LA3_0=='&') ) {
					alt3=1;
				}

				switch (alt3) {
				case 1 :
					// mylexer.g:32:14: '&'
					{
					match('&'); 
					}
					break;

				default :
					if ( cnt3 >= 1 ) break loop3;
					EarlyExitException eee = new EarlyExitException(3, input);
					throw eee;
				}
				cnt3++;
			}

			mIdentifier(); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Reference"

	// $ANTLR start "Constant"
	public final void mConstant() throws RecognitionException {
		try {
			int _type = Constant;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:33:10: ( ( Digit )+ )
			// mylexer.g:33:12: ( Digit )+
			{
			// mylexer.g:33:12: ( Digit )+
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
					// mylexer.g:
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
	// $ANTLR end "Constant"

	// $ANTLR start "Whitespace"
	public final void mWhitespace() throws RecognitionException {
		try {
			int _type = Whitespace;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:34:12: ( ( ' ' | '\\t' | '\\r' | '\\n' )+ )
			// mylexer.g:34:14: ( ' ' | '\\t' | '\\r' | '\\n' )+
			{
			// mylexer.g:34:14: ( ' ' | '\\t' | '\\r' | '\\n' )+
			int cnt5=0;
			loop5:
			while (true) {
				int alt5=2;
				int LA5_0 = input.LA(1);
				if ( ((LA5_0 >= '\t' && LA5_0 <= '\n')||LA5_0=='\r'||LA5_0==' ') ) {
					alt5=1;
				}

				switch (alt5) {
				case 1 :
					// mylexer.g:
					{
					if ( (input.LA(1) >= '\t' && input.LA(1) <= '\n')||input.LA(1)=='\r'||input.LA(1)==' ' ) {
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
					if ( cnt5 >= 1 ) break loop5;
					EarlyExitException eee = new EarlyExitException(5, input);
					throw eee;
				}
				cnt5++;
			}

			skip();
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Whitespace"

	// $ANTLR start "LeftParen"
	public final void mLeftParen() throws RecognitionException {
		try {
			int _type = LeftParen;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:37:11: ( '(' )
			// mylexer.g:37:13: '('
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
	// $ANTLR end "LeftParen"

	// $ANTLR start "RightParen"
	public final void mRightParen() throws RecognitionException {
		try {
			int _type = RightParen;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:38:12: ( ')' )
			// mylexer.g:38:14: ')'
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
	// $ANTLR end "RightParen"

	// $ANTLR start "LeftBracket"
	public final void mLeftBracket() throws RecognitionException {
		try {
			int _type = LeftBracket;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:39:13: ( '[' )
			// mylexer.g:39:15: '['
			{
			match('['); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "LeftBracket"

	// $ANTLR start "RightBracket"
	public final void mRightBracket() throws RecognitionException {
		try {
			int _type = RightBracket;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:40:14: ( ']' )
			// mylexer.g:40:16: ']'
			{
			match(']'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "RightBracket"

	// $ANTLR start "LeftBrace"
	public final void mLeftBrace() throws RecognitionException {
		try {
			int _type = LeftBrace;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:41:11: ( '{' )
			// mylexer.g:41:13: '{'
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
	// $ANTLR end "LeftBrace"

	// $ANTLR start "RightBrace"
	public final void mRightBrace() throws RecognitionException {
		try {
			int _type = RightBrace;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:42:12: ( '}' )
			// mylexer.g:42:14: '}'
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
	// $ANTLR end "RightBrace"

	// $ANTLR start "Less"
	public final void mLess() throws RecognitionException {
		try {
			int _type = Less;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:43:6: ( '<' )
			// mylexer.g:43:8: '<'
			{
			match('<'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Less"

	// $ANTLR start "LessEqual"
	public final void mLessEqual() throws RecognitionException {
		try {
			int _type = LessEqual;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:44:11: ( '<=' )
			// mylexer.g:44:13: '<='
			{
			match("<="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "LessEqual"

	// $ANTLR start "Greater"
	public final void mGreater() throws RecognitionException {
		try {
			int _type = Greater;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:45:9: ( '>' )
			// mylexer.g:45:11: '>'
			{
			match('>'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Greater"

	// $ANTLR start "GreaterEqual"
	public final void mGreaterEqual() throws RecognitionException {
		try {
			int _type = GreaterEqual;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:46:14: ( '>=' )
			// mylexer.g:46:16: '>='
			{
			match(">="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "GreaterEqual"

	// $ANTLR start "LeftShift"
	public final void mLeftShift() throws RecognitionException {
		try {
			int _type = LeftShift;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:47:11: ( '<<' )
			// mylexer.g:47:13: '<<'
			{
			match("<<"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "LeftShift"

	// $ANTLR start "RightShift"
	public final void mRightShift() throws RecognitionException {
		try {
			int _type = RightShift;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:48:12: ( '>>' )
			// mylexer.g:48:14: '>>'
			{
			match(">>"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "RightShift"

	// $ANTLR start "Plus"
	public final void mPlus() throws RecognitionException {
		try {
			int _type = Plus;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:49:6: ( '+' )
			// mylexer.g:49:8: '+'
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
	// $ANTLR end "Plus"

	// $ANTLR start "PlusPlus"
	public final void mPlusPlus() throws RecognitionException {
		try {
			int _type = PlusPlus;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:50:10: ( '++' )
			// mylexer.g:50:12: '++'
			{
			match("++"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "PlusPlus"

	// $ANTLR start "Minus"
	public final void mMinus() throws RecognitionException {
		try {
			int _type = Minus;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:51:7: ( '-' )
			// mylexer.g:51:9: '-'
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
	// $ANTLR end "Minus"

	// $ANTLR start "MinusMinus"
	public final void mMinusMinus() throws RecognitionException {
		try {
			int _type = MinusMinus;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:52:12: ( '--' )
			// mylexer.g:52:14: '--'
			{
			match("--"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "MinusMinus"

	// $ANTLR start "Star"
	public final void mStar() throws RecognitionException {
		try {
			int _type = Star;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:53:6: ( '*' )
			// mylexer.g:53:8: '*'
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
	// $ANTLR end "Star"

	// $ANTLR start "Div"
	public final void mDiv() throws RecognitionException {
		try {
			int _type = Div;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:54:5: ( '/' )
			// mylexer.g:54:7: '/'
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
	// $ANTLR end "Div"

	// $ANTLR start "Mod"
	public final void mMod() throws RecognitionException {
		try {
			int _type = Mod;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:55:5: ( '%' )
			// mylexer.g:55:7: '%'
			{
			match('%'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Mod"

	// $ANTLR start "And"
	public final void mAnd() throws RecognitionException {
		try {
			int _type = And;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:56:5: ( '&' )
			// mylexer.g:56:7: '&'
			{
			match('&'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "And"

	// $ANTLR start "Or"
	public final void mOr() throws RecognitionException {
		try {
			int _type = Or;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:57:4: ( '|' )
			// mylexer.g:57:6: '|'
			{
			match('|'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Or"

	// $ANTLR start "AndAnd"
	public final void mAndAnd() throws RecognitionException {
		try {
			int _type = AndAnd;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:58:8: ( '&&' )
			// mylexer.g:58:10: '&&'
			{
			match("&&"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "AndAnd"

	// $ANTLR start "OrOr"
	public final void mOrOr() throws RecognitionException {
		try {
			int _type = OrOr;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:59:6: ( '||' )
			// mylexer.g:59:8: '||'
			{
			match("||"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "OrOr"

	// $ANTLR start "Caret"
	public final void mCaret() throws RecognitionException {
		try {
			int _type = Caret;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:60:7: ( '^' )
			// mylexer.g:60:9: '^'
			{
			match('^'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Caret"

	// $ANTLR start "Not"
	public final void mNot() throws RecognitionException {
		try {
			int _type = Not;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:61:5: ( '!' )
			// mylexer.g:61:7: '!'
			{
			match('!'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Not"

	// $ANTLR start "Colon"
	public final void mColon() throws RecognitionException {
		try {
			int _type = Colon;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:62:7: ( ':' )
			// mylexer.g:62:9: ':'
			{
			match(':'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Colon"

	// $ANTLR start "Semi"
	public final void mSemi() throws RecognitionException {
		try {
			int _type = Semi;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:63:6: ( ';' )
			// mylexer.g:63:8: ';'
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
	// $ANTLR end "Semi"

	// $ANTLR start "Comma"
	public final void mComma() throws RecognitionException {
		try {
			int _type = Comma;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:64:7: ( ',' )
			// mylexer.g:64:9: ','
			{
			match(','); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Comma"

	// $ANTLR start "Assign"
	public final void mAssign() throws RecognitionException {
		try {
			int _type = Assign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:65:8: ( '=' )
			// mylexer.g:65:10: '='
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
	// $ANTLR end "Assign"

	// $ANTLR start "StarAssign"
	public final void mStarAssign() throws RecognitionException {
		try {
			int _type = StarAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:66:12: ( '*=' )
			// mylexer.g:66:14: '*='
			{
			match("*="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "StarAssign"

	// $ANTLR start "DivAssign"
	public final void mDivAssign() throws RecognitionException {
		try {
			int _type = DivAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:67:11: ( '/=' )
			// mylexer.g:67:13: '/='
			{
			match("/="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "DivAssign"

	// $ANTLR start "ModAssign"
	public final void mModAssign() throws RecognitionException {
		try {
			int _type = ModAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:68:11: ( '%=' )
			// mylexer.g:68:13: '%='
			{
			match("%="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "ModAssign"

	// $ANTLR start "PlusAssign"
	public final void mPlusAssign() throws RecognitionException {
		try {
			int _type = PlusAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:69:12: ( '+=' )
			// mylexer.g:69:14: '+='
			{
			match("+="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "PlusAssign"

	// $ANTLR start "MinusAssign"
	public final void mMinusAssign() throws RecognitionException {
		try {
			int _type = MinusAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:70:13: ( '-=' )
			// mylexer.g:70:15: '-='
			{
			match("-="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "MinusAssign"

	// $ANTLR start "LeftShiftAssign"
	public final void mLeftShiftAssign() throws RecognitionException {
		try {
			int _type = LeftShiftAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:71:17: ( '<<=' )
			// mylexer.g:71:19: '<<='
			{
			match("<<="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "LeftShiftAssign"

	// $ANTLR start "RightShiftAssign"
	public final void mRightShiftAssign() throws RecognitionException {
		try {
			int _type = RightShiftAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:72:18: ( '>>=' )
			// mylexer.g:72:20: '>>='
			{
			match(">>="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "RightShiftAssign"

	// $ANTLR start "AndAssign"
	public final void mAndAssign() throws RecognitionException {
		try {
			int _type = AndAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:73:11: ( '&=' )
			// mylexer.g:73:13: '&='
			{
			match("&="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "AndAssign"

	// $ANTLR start "XorAssign"
	public final void mXorAssign() throws RecognitionException {
		try {
			int _type = XorAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:74:11: ( '^=' )
			// mylexer.g:74:13: '^='
			{
			match("^="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "XorAssign"

	// $ANTLR start "OrAssign"
	public final void mOrAssign() throws RecognitionException {
		try {
			int _type = OrAssign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:75:10: ( '|=' )
			// mylexer.g:75:12: '|='
			{
			match("|="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "OrAssign"

	// $ANTLR start "Equal"
	public final void mEqual() throws RecognitionException {
		try {
			int _type = Equal;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:76:7: ( '==' )
			// mylexer.g:76:9: '=='
			{
			match("=="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Equal"

	// $ANTLR start "NotEqual"
	public final void mNotEqual() throws RecognitionException {
		try {
			int _type = NotEqual;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:77:10: ( '!=' )
			// mylexer.g:77:12: '!='
			{
			match("!="); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "NotEqual"

	// $ANTLR start "Arrow"
	public final void mArrow() throws RecognitionException {
		try {
			int _type = Arrow;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:79:7: ( '->' )
			// mylexer.g:79:9: '->'
			{
			match("->"); 

			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Arrow"

	// $ANTLR start "Dot"
	public final void mDot() throws RecognitionException {
		try {
			int _type = Dot;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:80:5: ( '.' )
			// mylexer.g:80:7: '.'
			{
			match('.'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Dot"

	// $ANTLR start "PoundSign"
	public final void mPoundSign() throws RecognitionException {
		try {
			int _type = PoundSign;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:82:10: ( '#' )
			// mylexer.g:82:12: '#'
			{
			match('#'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "PoundSign"

	// $ANTLR start "Quote"
	public final void mQuote() throws RecognitionException {
		try {
			int _type = Quote;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:83:6: ( '\\'' )
			// mylexer.g:83:8: '\\''
			{
			match('\''); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Quote"

	// $ANTLR start "DoubleQuote"
	public final void mDoubleQuote() throws RecognitionException {
		try {
			int _type = DoubleQuote;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:84:12: ( '\\\"' )
			// mylexer.g:84:14: '\\\"'
			{
			match('\"'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "DoubleQuote"

	// $ANTLR start "Backslash"
	public final void mBackslash() throws RecognitionException {
		try {
			int _type = Backslash;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:85:10: ( '\\\\' )
			// mylexer.g:85:12: '\\\\'
			{
			match('\\'); 
			}

			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Backslash"

	// $ANTLR start "Comment"
	public final void mComment() throws RecognitionException {
		try {
			int _type = Comment;
			int _channel = DEFAULT_TOKEN_CHANNEL;
			// mylexer.g:86:8: ( '/*' | '*/' | '//' )
			int alt6=3;
			int LA6_0 = input.LA(1);
			if ( (LA6_0=='/') ) {
				int LA6_1 = input.LA(2);
				if ( (LA6_1=='*') ) {
					alt6=1;
				}
				else if ( (LA6_1=='/') ) {
					alt6=3;
				}

				else {
					int nvaeMark = input.mark();
					try {
						input.consume();
						NoViableAltException nvae =
							new NoViableAltException("", 6, 1, input);
						throw nvae;
					} finally {
						input.rewind(nvaeMark);
					}
				}

			}
			else if ( (LA6_0=='*') ) {
				alt6=2;
			}

			else {
				NoViableAltException nvae =
					new NoViableAltException("", 6, 0, input);
				throw nvae;
			}

			switch (alt6) {
				case 1 :
					// mylexer.g:86:10: '/*'
					{
					match("/*"); 

					}
					break;
				case 2 :
					// mylexer.g:86:17: '*/'
					{
					match("*/"); 

					}
					break;
				case 3 :
					// mylexer.g:86:24: '//'
					{
					match("//"); 

					}
					break;

			}
			state.type = _type;
			state.channel = _channel;
		}
		finally {
			// do for sure before leaving
		}
	}
	// $ANTLR end "Comment"

	@Override
	public void mTokens() throws RecognitionException {
		// mylexer.g:1:8: ( Int | Char | Float | Double | Void | If | Else | For | While | Switch | Case | Continue | Break | Default | Return | Null | Identifier | Pointer | Reference | Constant | Whitespace | LeftParen | RightParen | LeftBracket | RightBracket | LeftBrace | RightBrace | Less | LessEqual | Greater | GreaterEqual | LeftShift | RightShift | Plus | PlusPlus | Minus | MinusMinus | Star | Div | Mod | And | Or | AndAnd | OrOr | Caret | Not | Colon | Semi | Comma | Assign | StarAssign | DivAssign | ModAssign | PlusAssign | MinusAssign | LeftShiftAssign | RightShiftAssign | AndAssign | XorAssign | OrAssign | Equal | NotEqual | Arrow | Dot | PoundSign | Quote | DoubleQuote | Backslash | Comment )
		int alt7=69;
		alt7 = dfa7.predict(input);
		switch (alt7) {
			case 1 :
				// mylexer.g:1:10: Int
				{
				mInt(); 

				}
				break;
			case 2 :
				// mylexer.g:1:14: Char
				{
				mChar(); 

				}
				break;
			case 3 :
				// mylexer.g:1:19: Float
				{
				mFloat(); 

				}
				break;
			case 4 :
				// mylexer.g:1:25: Double
				{
				mDouble(); 

				}
				break;
			case 5 :
				// mylexer.g:1:32: Void
				{
				mVoid(); 

				}
				break;
			case 6 :
				// mylexer.g:1:37: If
				{
				mIf(); 

				}
				break;
			case 7 :
				// mylexer.g:1:40: Else
				{
				mElse(); 

				}
				break;
			case 8 :
				// mylexer.g:1:45: For
				{
				mFor(); 

				}
				break;
			case 9 :
				// mylexer.g:1:49: While
				{
				mWhile(); 

				}
				break;
			case 10 :
				// mylexer.g:1:55: Switch
				{
				mSwitch(); 

				}
				break;
			case 11 :
				// mylexer.g:1:62: Case
				{
				mCase(); 

				}
				break;
			case 12 :
				// mylexer.g:1:67: Continue
				{
				mContinue(); 

				}
				break;
			case 13 :
				// mylexer.g:1:76: Break
				{
				mBreak(); 

				}
				break;
			case 14 :
				// mylexer.g:1:82: Default
				{
				mDefault(); 

				}
				break;
			case 15 :
				// mylexer.g:1:90: Return
				{
				mReturn(); 

				}
				break;
			case 16 :
				// mylexer.g:1:97: Null
				{
				mNull(); 

				}
				break;
			case 17 :
				// mylexer.g:1:102: Identifier
				{
				mIdentifier(); 

				}
				break;
			case 18 :
				// mylexer.g:1:113: Pointer
				{
				mPointer(); 

				}
				break;
			case 19 :
				// mylexer.g:1:121: Reference
				{
				mReference(); 

				}
				break;
			case 20 :
				// mylexer.g:1:131: Constant
				{
				mConstant(); 

				}
				break;
			case 21 :
				// mylexer.g:1:140: Whitespace
				{
				mWhitespace(); 

				}
				break;
			case 22 :
				// mylexer.g:1:151: LeftParen
				{
				mLeftParen(); 

				}
				break;
			case 23 :
				// mylexer.g:1:161: RightParen
				{
				mRightParen(); 

				}
				break;
			case 24 :
				// mylexer.g:1:172: LeftBracket
				{
				mLeftBracket(); 

				}
				break;
			case 25 :
				// mylexer.g:1:184: RightBracket
				{
				mRightBracket(); 

				}
				break;
			case 26 :
				// mylexer.g:1:197: LeftBrace
				{
				mLeftBrace(); 

				}
				break;
			case 27 :
				// mylexer.g:1:207: RightBrace
				{
				mRightBrace(); 

				}
				break;
			case 28 :
				// mylexer.g:1:218: Less
				{
				mLess(); 

				}
				break;
			case 29 :
				// mylexer.g:1:223: LessEqual
				{
				mLessEqual(); 

				}
				break;
			case 30 :
				// mylexer.g:1:233: Greater
				{
				mGreater(); 

				}
				break;
			case 31 :
				// mylexer.g:1:241: GreaterEqual
				{
				mGreaterEqual(); 

				}
				break;
			case 32 :
				// mylexer.g:1:254: LeftShift
				{
				mLeftShift(); 

				}
				break;
			case 33 :
				// mylexer.g:1:264: RightShift
				{
				mRightShift(); 

				}
				break;
			case 34 :
				// mylexer.g:1:275: Plus
				{
				mPlus(); 

				}
				break;
			case 35 :
				// mylexer.g:1:280: PlusPlus
				{
				mPlusPlus(); 

				}
				break;
			case 36 :
				// mylexer.g:1:289: Minus
				{
				mMinus(); 

				}
				break;
			case 37 :
				// mylexer.g:1:295: MinusMinus
				{
				mMinusMinus(); 

				}
				break;
			case 38 :
				// mylexer.g:1:306: Star
				{
				mStar(); 

				}
				break;
			case 39 :
				// mylexer.g:1:311: Div
				{
				mDiv(); 

				}
				break;
			case 40 :
				// mylexer.g:1:315: Mod
				{
				mMod(); 

				}
				break;
			case 41 :
				// mylexer.g:1:319: And
				{
				mAnd(); 

				}
				break;
			case 42 :
				// mylexer.g:1:323: Or
				{
				mOr(); 

				}
				break;
			case 43 :
				// mylexer.g:1:326: AndAnd
				{
				mAndAnd(); 

				}
				break;
			case 44 :
				// mylexer.g:1:333: OrOr
				{
				mOrOr(); 

				}
				break;
			case 45 :
				// mylexer.g:1:338: Caret
				{
				mCaret(); 

				}
				break;
			case 46 :
				// mylexer.g:1:344: Not
				{
				mNot(); 

				}
				break;
			case 47 :
				// mylexer.g:1:348: Colon
				{
				mColon(); 

				}
				break;
			case 48 :
				// mylexer.g:1:354: Semi
				{
				mSemi(); 

				}
				break;
			case 49 :
				// mylexer.g:1:359: Comma
				{
				mComma(); 

				}
				break;
			case 50 :
				// mylexer.g:1:365: Assign
				{
				mAssign(); 

				}
				break;
			case 51 :
				// mylexer.g:1:372: StarAssign
				{
				mStarAssign(); 

				}
				break;
			case 52 :
				// mylexer.g:1:383: DivAssign
				{
				mDivAssign(); 

				}
				break;
			case 53 :
				// mylexer.g:1:393: ModAssign
				{
				mModAssign(); 

				}
				break;
			case 54 :
				// mylexer.g:1:403: PlusAssign
				{
				mPlusAssign(); 

				}
				break;
			case 55 :
				// mylexer.g:1:414: MinusAssign
				{
				mMinusAssign(); 

				}
				break;
			case 56 :
				// mylexer.g:1:426: LeftShiftAssign
				{
				mLeftShiftAssign(); 

				}
				break;
			case 57 :
				// mylexer.g:1:442: RightShiftAssign
				{
				mRightShiftAssign(); 

				}
				break;
			case 58 :
				// mylexer.g:1:459: AndAssign
				{
				mAndAssign(); 

				}
				break;
			case 59 :
				// mylexer.g:1:469: XorAssign
				{
				mXorAssign(); 

				}
				break;
			case 60 :
				// mylexer.g:1:479: OrAssign
				{
				mOrAssign(); 

				}
				break;
			case 61 :
				// mylexer.g:1:488: Equal
				{
				mEqual(); 

				}
				break;
			case 62 :
				// mylexer.g:1:494: NotEqual
				{
				mNotEqual(); 

				}
				break;
			case 63 :
				// mylexer.g:1:503: Arrow
				{
				mArrow(); 

				}
				break;
			case 64 :
				// mylexer.g:1:509: Dot
				{
				mDot(); 

				}
				break;
			case 65 :
				// mylexer.g:1:513: PoundSign
				{
				mPoundSign(); 

				}
				break;
			case 66 :
				// mylexer.g:1:523: Quote
				{
				mQuote(); 

				}
				break;
			case 67 :
				// mylexer.g:1:529: DoubleQuote
				{
				mDoubleQuote(); 

				}
				break;
			case 68 :
				// mylexer.g:1:541: Backslash
				{
				mBackslash(); 

				}
				break;
			case 69 :
				// mylexer.g:1:551: Comment
				{
				mComment(); 

				}
				break;

		}
	}


	protected DFA7 dfa7 = new DFA7(this);
	static final String DFA7_eotS =
		"\1\uffff\13\14\1\uffff\1\74\1\100\10\uffff\1\103\1\106\1\111\1\115\1\117"+
		"\1\121\1\124\1\126\1\130\3\uffff\1\132\5\uffff\1\14\1\134\16\14\4\uffff"+
		"\1\153\4\uffff\1\155\2\uffff\1\157\25\uffff\1\160\1\uffff\4\14\1\165\11"+
		"\14\6\uffff\1\177\1\u0080\2\14\1\uffff\2\14\1\u0085\1\u0086\4\14\1\u008b"+
		"\2\uffff\1\14\1\u008d\2\14\2\uffff\1\u0090\1\14\1\u0092\1\14\1\uffff\1"+
		"\14\1\uffff\1\u0095\1\14\1\uffff\1\u0097\1\uffff\1\u0098\1\14\1\uffff"+
		"\1\u009a\2\uffff\1\u009b\2\uffff";
	static final String DFA7_eofS =
		"\u009c\uffff";
	static final String DFA7_minS =
		"\1\11\1\146\1\141\1\154\1\145\1\157\1\154\1\150\1\167\1\162\1\145\1\125"+
		"\1\uffff\1\52\1\46\10\uffff\1\74\1\75\1\53\1\55\1\52\4\75\3\uffff\1\75"+
		"\5\uffff\1\164\1\60\1\141\1\163\1\156\1\157\1\162\1\165\1\146\1\151\1"+
		"\163\2\151\1\145\1\164\1\114\4\uffff\1\46\4\uffff\1\75\2\uffff\1\75\25"+
		"\uffff\1\60\1\uffff\1\162\1\145\1\164\1\141\1\60\1\142\1\141\1\144\1\145"+
		"\1\154\1\164\1\141\1\165\1\114\6\uffff\2\60\1\151\1\164\1\uffff\1\154"+
		"\1\165\2\60\1\145\1\143\1\153\1\162\1\60\2\uffff\1\156\1\60\1\145\1\154"+
		"\2\uffff\1\60\1\150\1\60\1\156\1\uffff\1\165\1\uffff\1\60\1\164\1\uffff"+
		"\1\60\1\uffff\1\60\1\145\1\uffff\1\60\2\uffff\1\60\2\uffff";
	static final String DFA7_maxS =
		"\1\175\1\156\4\157\1\154\1\150\1\167\1\162\1\145\1\125\1\uffff\2\172\10"+
		"\uffff\1\75\1\76\1\75\1\76\2\75\1\174\2\75\3\uffff\1\75\5\uffff\1\164"+
		"\1\172\1\141\1\163\1\156\1\157\1\162\1\165\1\146\1\151\1\163\2\151\1\145"+
		"\1\164\1\114\4\uffff\1\172\4\uffff\1\75\2\uffff\1\75\25\uffff\1\172\1"+
		"\uffff\1\162\1\145\1\164\1\141\1\172\1\142\1\141\1\144\1\145\1\154\1\164"+
		"\1\141\1\165\1\114\6\uffff\2\172\1\151\1\164\1\uffff\1\154\1\165\2\172"+
		"\1\145\1\143\1\153\1\162\1\172\2\uffff\1\156\1\172\1\145\1\154\2\uffff"+
		"\1\172\1\150\1\172\1\156\1\uffff\1\165\1\uffff\1\172\1\164\1\uffff\1\172"+
		"\1\uffff\1\172\1\145\1\uffff\1\172\2\uffff\1\172\2\uffff";
	static final String DFA7_acceptS =
		"\14\uffff\1\21\2\uffff\1\24\1\25\1\26\1\27\1\30\1\31\1\32\1\33\11\uffff"+
		"\1\57\1\60\1\61\1\uffff\1\100\1\101\1\102\1\103\1\104\20\uffff\1\63\1"+
		"\105\1\22\1\46\1\uffff\1\72\1\23\1\51\1\35\1\uffff\1\34\1\37\1\uffff\1"+
		"\36\1\43\1\66\1\42\1\45\1\67\1\77\1\44\1\64\1\47\1\65\1\50\1\54\1\74\1"+
		"\52\1\73\1\55\1\76\1\56\1\75\1\62\1\uffff\1\6\16\uffff\1\53\1\70\1\40"+
		"\1\71\1\41\1\1\4\uffff\1\10\11\uffff\1\2\1\13\4\uffff\1\5\1\7\4\uffff"+
		"\1\20\1\uffff\1\3\2\uffff\1\11\1\uffff\1\15\2\uffff\1\4\1\uffff\1\12\1"+
		"\17\1\uffff\1\16\1\14";
	static final String DFA7_specialS =
		"\u009c\uffff}>";
	static final String[] DFA7_transitionS = {
			"\2\20\2\uffff\1\20\22\uffff\1\20\1\37\1\47\1\45\1\uffff\1\34\1\16\1\46"+
			"\1\21\1\22\1\15\1\31\1\42\1\32\1\44\1\33\12\17\1\40\1\41\1\27\1\43\1"+
			"\30\2\uffff\15\14\1\13\14\14\1\23\1\50\1\24\1\36\1\14\1\uffff\1\14\1"+
			"\11\1\2\1\4\1\6\1\3\2\14\1\1\10\14\1\12\1\10\2\14\1\5\1\7\3\14\1\25\1"+
			"\35\1\26",
			"\1\52\7\uffff\1\51",
			"\1\54\6\uffff\1\53\6\uffff\1\55",
			"\1\56\2\uffff\1\57",
			"\1\61\11\uffff\1\60",
			"\1\62",
			"\1\63",
			"\1\64",
			"\1\65",
			"\1\66",
			"\1\67",
			"\1\70",
			"",
			"\1\73\4\uffff\1\72\15\uffff\1\71\3\uffff\32\73\4\uffff\1\73\1\uffff"+
			"\32\73",
			"\1\75\26\uffff\1\76\3\uffff\32\77\4\uffff\1\77\1\uffff\32\77",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"\1\102\1\101",
			"\1\104\1\105",
			"\1\107\21\uffff\1\110",
			"\1\112\17\uffff\1\113\1\114",
			"\1\72\4\uffff\1\72\15\uffff\1\116",
			"\1\120",
			"\1\123\76\uffff\1\122",
			"\1\125",
			"\1\127",
			"",
			"",
			"",
			"\1\131",
			"",
			"",
			"",
			"",
			"",
			"\1\133",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\135",
			"\1\136",
			"\1\137",
			"\1\140",
			"\1\141",
			"\1\142",
			"\1\143",
			"\1\144",
			"\1\145",
			"\1\146",
			"\1\147",
			"\1\150",
			"\1\151",
			"\1\152",
			"",
			"",
			"",
			"",
			"\1\77\32\uffff\32\77\4\uffff\1\77\1\uffff\32\77",
			"",
			"",
			"",
			"",
			"\1\154",
			"",
			"",
			"\1\156",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"",
			"\1\161",
			"\1\162",
			"\1\163",
			"\1\164",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\166",
			"\1\167",
			"\1\170",
			"\1\171",
			"\1\172",
			"\1\173",
			"\1\174",
			"\1\175",
			"\1\176",
			"",
			"",
			"",
			"",
			"",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0081",
			"\1\u0082",
			"",
			"\1\u0083",
			"\1\u0084",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0087",
			"\1\u0088",
			"\1\u0089",
			"\1\u008a",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"",
			"",
			"\1\u008c",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u008e",
			"\1\u008f",
			"",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0091",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0093",
			"",
			"\1\u0094",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0096",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"\1\u0099",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"",
			"",
			"\12\14\7\uffff\32\14\4\uffff\1\14\1\uffff\32\14",
			"",
			""
	};

	static final short[] DFA7_eot = DFA.unpackEncodedString(DFA7_eotS);
	static final short[] DFA7_eof = DFA.unpackEncodedString(DFA7_eofS);
	static final char[] DFA7_min = DFA.unpackEncodedStringToUnsignedChars(DFA7_minS);
	static final char[] DFA7_max = DFA.unpackEncodedStringToUnsignedChars(DFA7_maxS);
	static final short[] DFA7_accept = DFA.unpackEncodedString(DFA7_acceptS);
	static final short[] DFA7_special = DFA.unpackEncodedString(DFA7_specialS);
	static final short[][] DFA7_transition;

	static {
		int numStates = DFA7_transitionS.length;
		DFA7_transition = new short[numStates][];
		for (int i=0; i<numStates; i++) {
			DFA7_transition[i] = DFA.unpackEncodedString(DFA7_transitionS[i]);
		}
	}

	protected class DFA7 extends DFA {

		public DFA7(BaseRecognizer recognizer) {
			this.recognizer = recognizer;
			this.decisionNumber = 7;
			this.eot = DFA7_eot;
			this.eof = DFA7_eof;
			this.min = DFA7_min;
			this.max = DFA7_max;
			this.accept = DFA7_accept;
			this.special = DFA7_special;
			this.transition = DFA7_transition;
		}
		@Override
		public String getDescription() {
			return "1:1: Tokens : ( Int | Char | Float | Double | Void | If | Else | For | While | Switch | Case | Continue | Break | Default | Return | Null | Identifier | Pointer | Reference | Constant | Whitespace | LeftParen | RightParen | LeftBracket | RightBracket | LeftBrace | RightBrace | Less | LessEqual | Greater | GreaterEqual | LeftShift | RightShift | Plus | PlusPlus | Minus | MinusMinus | Star | Div | Mod | And | Or | AndAnd | OrOr | Caret | Not | Colon | Semi | Comma | Assign | StarAssign | DivAssign | ModAssign | PlusAssign | MinusAssign | LeftShiftAssign | RightShiftAssign | AndAssign | XorAssign | OrAssign | Equal | NotEqual | Arrow | Dot | PoundSign | Quote | DoubleQuote | Backslash | Comment );";
		}
	}

}
