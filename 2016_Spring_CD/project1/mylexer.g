lexer grammar mylexer;

options {
	language = Java;
}


fragment Nondigit: 'a'..'z' | 'A'..'Z' | '_';
fragment Digit: '0'..'9';

Int : 'int';
Char : 'char';
Float : 'float';
Double : 'double';
Void : 'void';

If : 'if';
Else : 'else';

For : 'for';
While : 'while';
Switch : 'switch';
Case : 'case';
Continue : 'continue';
Break : 'break';
Default : 'default';
Return : 'return';
Null : 'NULL';

Identifier : Nondigit (Nondigit | Digit)*;
Pointer : ('*')+ Identifier;
Reference : ('&')+ Identifier;
Constant : (Digit)+;
Whitespace : (' ' | '\t' | '\r' | '\n')+ {skip();} ;


LeftParen : '(';
RightParen : ')';
LeftBracket : '[';
RightBracket : ']';
LeftBrace : '{';
RightBrace : '}';
Less : '<';
LessEqual : '<=';
Greater : '>';
GreaterEqual : '>=';
LeftShift : '<<';
RightShift : '>>';
Plus : '+';
PlusPlus : '++';
Minus : '-';
MinusMinus : '--';
Star : '*';
Div : '/';
Mod : '%';
And : '&';
Or : '|';
AndAnd : '&&';
OrOr : '||';
Caret : '^';
Not : '!';
Colon : ':';
Semi : ';';
Comma : ',';
Assign : '=';
StarAssign : '*=';
DivAssign : '/=';
ModAssign : '%=';
PlusAssign : '+=';
MinusAssign : '-=';
LeftShiftAssign : '<<=';
RightShiftAssign : '>>=';
AndAssign : '&=';
XorAssign : '^=';
OrAssign : '|=';
Equal : '==';
NotEqual : '!=';

Arrow : '->';
Dot : '.';

PoundSign: '#';
Quote: '\'';
DoubleQuote: '\"';
Backslash: '\\';
Comment: '/*' | '*/' | '//';
