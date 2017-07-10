grammar myparser;

options {
	language = Java;
}

prog
	: stat+
	;

stat
	: expr Whitespace
	| expr
	;

expr
	: a=(Identifier | Reference | Pointer | Constant) {System.out.println($a.text);}
	| declaration {System.out.println($declaration.s);}
	| assignment {System.out.println($assignment.s);}
	| statement 
	| block
	;

statement
	: ifstatement {System.out.println($ifstatement.s);}
	;

ifstatement returns [String s]
@init {s = "ifstatement = if(";}
	: If '(' a=conditionexpr ')' {s += $a.s + ")";} Whitespace? '{' regularexpr* '}'
	;

conditionexpr returns [String s]
	: a=(Identifier | Reference | Pointer | Constant) {s = $a.text;} b=unaryOperator {s += " " + $b.s;} c=(Identifier | Reference | Pointer | Constant) {s += " " + $c.text;}
	;

regularexpr
	: declaration {System.out.println($declaration.s);}
	| assignment {System.out.println($assignment.s);}
	;

declaration returns [String s]
@init {s = "declaration = ";}
	: type {s += $type.s + " ";} a=(Identifier | Reference | Pointer) {s += $a.text;} (';' | ',')?
	| type {s += $type.s + " ";} a=(Identifier | Reference | Pointer) {s += $a.text + " ";} b=assignmentOprator {s += $b.s + " ";} c=(Identifier  | Reference  | Pointer  | Constant) {s += $c.text;} (';' | ',')?
	| type {s += $type.s + " ";} a=(Identifier | Reference | Pointer) {s += $a.text + "[";} '[' c=(Identifier | Reference | Pointer | Constant) ']' {s += $c.text + "]";} (';' | ',')?
	;

assignment returns [String s]
@init {s = "assignment = ";}
	: a=(Identifier | Reference | Pointer) {s += $a.text + " ";} b=assignmentOprator {s +=$b.s + " ";} c=(Identifier | Reference | Pointer | Constant) {s += $c.text;} (';' | ',')?
	;

block
	: '{' | '}' | '(' | ')'
	;

type returns [String s]
	: a=(Int | Char | Float | Double | Void) {s = $a.text;}
	;

assignmentOprator returns [String s]
	: a=(Assign | StarAssign | DivAssign | ModAssign | PlusAssign | MinusAssign | LeftShiftAssign | RightShiftAssign | AndAssign | XorAssign | OrAssign) {s = $a.text;}
	;

unaryOperator returns [String s]
	: a=(Less | LessEqual | Greater | GreaterEqual | AndAnd | OrOr | Not | Equal | NotEqual) {s = $a.text;}
	;


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
