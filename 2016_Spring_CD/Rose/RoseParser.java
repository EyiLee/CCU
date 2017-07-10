// Generated from Rose.g by ANTLR 4.5.3
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class RoseParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.5.3", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		Begin=1, Declare=2, Else=3, End=4, Exit=5, For=6, If=7, In=8, Integer=9, 
		Is=10, Loop=11, Procedure=12, Read=13, Then=14, Write=15, Colon=16, DotDot=17, 
		Semi=18, Plus=19, Minus=20, Star=21, Div=22, Mod=23, Equal=24, NotEqual=25, 
		Greater=26, GreaterEqual=27, Less=28, LessEqual=29, AndAnd=30, OrOr=31, 
		Not=32, Assign=33, LeftParen=34, RightParen=35, Identifier=36, Constant=37, 
		Whitespace=38, LineComment=39;
	public static final int
		RULE_token = 0;
	public static final String[] ruleNames = {
		"token"
	};

	private static final String[] _LITERAL_NAMES = {
		null, "'begin'", "'declare'", "'else'", "'end'", "'exit'", "'for'", "'if'", 
		"'in'", "'integer'", "'is'", "'loop'", "'procedure'", "'read'", "'then'", 
		"'write'", "':'", "'..'", "';'", "'+'", "'-'", "'*'", "'/'", "'%'", "'='", 
		"'<>'", "'>'", "'>='", "'<'", "'<='", "'&&'", "'||'", "'!'", "':='", "'('", 
		"')'"
	};
	private static final String[] _SYMBOLIC_NAMES = {
		null, "Begin", "Declare", "Else", "End", "Exit", "For", "If", "In", "Integer", 
		"Is", "Loop", "Procedure", "Read", "Then", "Write", "Colon", "DotDot", 
		"Semi", "Plus", "Minus", "Star", "Div", "Mod", "Equal", "NotEqual", "Greater", 
		"GreaterEqual", "Less", "LessEqual", "AndAnd", "OrOr", "Not", "Assign", 
		"LeftParen", "RightParen", "Identifier", "Constant", "Whitespace", "LineComment"
	};
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Rose.g"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public RoseParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}
	public static class TokenContext extends ParserRuleContext {
		public List<TerminalNode> Begin() { return getTokens(RoseParser.Begin); }
		public TerminalNode Begin(int i) {
			return getToken(RoseParser.Begin, i);
		}
		public List<TerminalNode> Declare() { return getTokens(RoseParser.Declare); }
		public TerminalNode Declare(int i) {
			return getToken(RoseParser.Declare, i);
		}
		public List<TerminalNode> Else() { return getTokens(RoseParser.Else); }
		public TerminalNode Else(int i) {
			return getToken(RoseParser.Else, i);
		}
		public List<TerminalNode> End() { return getTokens(RoseParser.End); }
		public TerminalNode End(int i) {
			return getToken(RoseParser.End, i);
		}
		public List<TerminalNode> Exit() { return getTokens(RoseParser.Exit); }
		public TerminalNode Exit(int i) {
			return getToken(RoseParser.Exit, i);
		}
		public List<TerminalNode> For() { return getTokens(RoseParser.For); }
		public TerminalNode For(int i) {
			return getToken(RoseParser.For, i);
		}
		public List<TerminalNode> If() { return getTokens(RoseParser.If); }
		public TerminalNode If(int i) {
			return getToken(RoseParser.If, i);
		}
		public List<TerminalNode> In() { return getTokens(RoseParser.In); }
		public TerminalNode In(int i) {
			return getToken(RoseParser.In, i);
		}
		public List<TerminalNode> Integer() { return getTokens(RoseParser.Integer); }
		public TerminalNode Integer(int i) {
			return getToken(RoseParser.Integer, i);
		}
		public List<TerminalNode> Is() { return getTokens(RoseParser.Is); }
		public TerminalNode Is(int i) {
			return getToken(RoseParser.Is, i);
		}
		public List<TerminalNode> Loop() { return getTokens(RoseParser.Loop); }
		public TerminalNode Loop(int i) {
			return getToken(RoseParser.Loop, i);
		}
		public List<TerminalNode> Procedure() { return getTokens(RoseParser.Procedure); }
		public TerminalNode Procedure(int i) {
			return getToken(RoseParser.Procedure, i);
		}
		public List<TerminalNode> Read() { return getTokens(RoseParser.Read); }
		public TerminalNode Read(int i) {
			return getToken(RoseParser.Read, i);
		}
		public List<TerminalNode> Then() { return getTokens(RoseParser.Then); }
		public TerminalNode Then(int i) {
			return getToken(RoseParser.Then, i);
		}
		public List<TerminalNode> Write() { return getTokens(RoseParser.Write); }
		public TerminalNode Write(int i) {
			return getToken(RoseParser.Write, i);
		}
		public List<TerminalNode> Colon() { return getTokens(RoseParser.Colon); }
		public TerminalNode Colon(int i) {
			return getToken(RoseParser.Colon, i);
		}
		public List<TerminalNode> DotDot() { return getTokens(RoseParser.DotDot); }
		public TerminalNode DotDot(int i) {
			return getToken(RoseParser.DotDot, i);
		}
		public List<TerminalNode> Semi() { return getTokens(RoseParser.Semi); }
		public TerminalNode Semi(int i) {
			return getToken(RoseParser.Semi, i);
		}
		public List<TerminalNode> Plus() { return getTokens(RoseParser.Plus); }
		public TerminalNode Plus(int i) {
			return getToken(RoseParser.Plus, i);
		}
		public List<TerminalNode> Minus() { return getTokens(RoseParser.Minus); }
		public TerminalNode Minus(int i) {
			return getToken(RoseParser.Minus, i);
		}
		public List<TerminalNode> Star() { return getTokens(RoseParser.Star); }
		public TerminalNode Star(int i) {
			return getToken(RoseParser.Star, i);
		}
		public List<TerminalNode> Div() { return getTokens(RoseParser.Div); }
		public TerminalNode Div(int i) {
			return getToken(RoseParser.Div, i);
		}
		public List<TerminalNode> Mod() { return getTokens(RoseParser.Mod); }
		public TerminalNode Mod(int i) {
			return getToken(RoseParser.Mod, i);
		}
		public List<TerminalNode> Equal() { return getTokens(RoseParser.Equal); }
		public TerminalNode Equal(int i) {
			return getToken(RoseParser.Equal, i);
		}
		public List<TerminalNode> NotEqual() { return getTokens(RoseParser.NotEqual); }
		public TerminalNode NotEqual(int i) {
			return getToken(RoseParser.NotEqual, i);
		}
		public List<TerminalNode> Greater() { return getTokens(RoseParser.Greater); }
		public TerminalNode Greater(int i) {
			return getToken(RoseParser.Greater, i);
		}
		public List<TerminalNode> GreaterEqual() { return getTokens(RoseParser.GreaterEqual); }
		public TerminalNode GreaterEqual(int i) {
			return getToken(RoseParser.GreaterEqual, i);
		}
		public List<TerminalNode> Less() { return getTokens(RoseParser.Less); }
		public TerminalNode Less(int i) {
			return getToken(RoseParser.Less, i);
		}
		public List<TerminalNode> LessEqual() { return getTokens(RoseParser.LessEqual); }
		public TerminalNode LessEqual(int i) {
			return getToken(RoseParser.LessEqual, i);
		}
		public List<TerminalNode> AndAnd() { return getTokens(RoseParser.AndAnd); }
		public TerminalNode AndAnd(int i) {
			return getToken(RoseParser.AndAnd, i);
		}
		public List<TerminalNode> OrOr() { return getTokens(RoseParser.OrOr); }
		public TerminalNode OrOr(int i) {
			return getToken(RoseParser.OrOr, i);
		}
		public List<TerminalNode> Not() { return getTokens(RoseParser.Not); }
		public TerminalNode Not(int i) {
			return getToken(RoseParser.Not, i);
		}
		public List<TerminalNode> Assign() { return getTokens(RoseParser.Assign); }
		public TerminalNode Assign(int i) {
			return getToken(RoseParser.Assign, i);
		}
		public List<TerminalNode> LeftParen() { return getTokens(RoseParser.LeftParen); }
		public TerminalNode LeftParen(int i) {
			return getToken(RoseParser.LeftParen, i);
		}
		public List<TerminalNode> RightParen() { return getTokens(RoseParser.RightParen); }
		public TerminalNode RightParen(int i) {
			return getToken(RoseParser.RightParen, i);
		}
		public List<TerminalNode> Identifier() { return getTokens(RoseParser.Identifier); }
		public TerminalNode Identifier(int i) {
			return getToken(RoseParser.Identifier, i);
		}
		public List<TerminalNode> Constant() { return getTokens(RoseParser.Constant); }
		public TerminalNode Constant(int i) {
			return getToken(RoseParser.Constant, i);
		}
		public List<TerminalNode> Whitespace() { return getTokens(RoseParser.Whitespace); }
		public TerminalNode Whitespace(int i) {
			return getToken(RoseParser.Whitespace, i);
		}
		public List<TerminalNode> LineComment() { return getTokens(RoseParser.LineComment); }
		public TerminalNode LineComment(int i) {
			return getToken(RoseParser.LineComment, i);
		}
		public TokenContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_token; }
		@Override
		public void enterRule(ParseTreeListener listener) {
			if ( listener instanceof RoseListener ) ((RoseListener)listener).enterToken(this);
		}
		@Override
		public void exitRule(ParseTreeListener listener) {
			if ( listener instanceof RoseListener ) ((RoseListener)listener).exitToken(this);
		}
	}

	public final TokenContext token() throws RecognitionException {
		TokenContext _localctx = new TokenContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_token);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(5);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Begin) | (1L << Declare) | (1L << Else) | (1L << End) | (1L << Exit) | (1L << For) | (1L << If) | (1L << In) | (1L << Integer) | (1L << Is) | (1L << Loop) | (1L << Procedure) | (1L << Read) | (1L << Then) | (1L << Write) | (1L << Colon) | (1L << DotDot) | (1L << Semi) | (1L << Plus) | (1L << Minus) | (1L << Star) | (1L << Div) | (1L << Mod) | (1L << Equal) | (1L << NotEqual) | (1L << Greater) | (1L << GreaterEqual) | (1L << Less) | (1L << LessEqual) | (1L << AndAnd) | (1L << OrOr) | (1L << Not) | (1L << Assign) | (1L << LeftParen) | (1L << RightParen) | (1L << Identifier) | (1L << Constant) | (1L << Whitespace) | (1L << LineComment))) != 0)) {
				{
				{
				setState(2);
				_la = _input.LA(1);
				if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << Begin) | (1L << Declare) | (1L << Else) | (1L << End) | (1L << Exit) | (1L << For) | (1L << If) | (1L << In) | (1L << Integer) | (1L << Is) | (1L << Loop) | (1L << Procedure) | (1L << Read) | (1L << Then) | (1L << Write) | (1L << Colon) | (1L << DotDot) | (1L << Semi) | (1L << Plus) | (1L << Minus) | (1L << Star) | (1L << Div) | (1L << Mod) | (1L << Equal) | (1L << NotEqual) | (1L << Greater) | (1L << GreaterEqual) | (1L << Less) | (1L << LessEqual) | (1L << AndAnd) | (1L << OrOr) | (1L << Not) | (1L << Assign) | (1L << LeftParen) | (1L << RightParen) | (1L << Identifier) | (1L << Constant) | (1L << Whitespace) | (1L << LineComment))) != 0)) ) {
				_errHandler.recoverInline(this);
				} else {
					consume();
				}
				}
				}
				setState(7);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static final String _serializedATN =
		"\3\u0430\ud6d1\u8206\uad2d\u4417\uaef1\u8d80\uaadd\3)\13\4\2\t\2\3\2\7"+
		"\2\6\n\2\f\2\16\2\t\13\2\3\2\2\2\3\2\2\3\3\2\3)\n\2\7\3\2\2\2\4\6\t\2"+
		"\2\2\5\4\3\2\2\2\6\t\3\2\2\2\7\5\3\2\2\2\7\b\3\2\2\2\b\3\3\2\2\2\t\7\3"+
		"\2\2\2\3\7";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}