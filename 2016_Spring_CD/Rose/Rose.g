grammar Rose;

token: (
    Begin|Declare|Else|End|Exit|For|If|In|Integer|Is|Loop|Procedure|Read|Then|Write|
    Colon|DotDot|Semi|Plus|Minus|Star|Div|Mod|Equal|NotEqual|Greater|GreaterEqual|Less|LessEqual|
    AndAnd|OrOr|Not|Assign|LeftParen|RightParen|Identifier|Constant|Whitespace|LineComment
)*;

Begin: 'begin';
Declare: 'declare';
Else: 'else';
End: 'end';
Exit: 'exit';
For: 'for';
If: 'if';
In: 'in';
Integer: 'integer';
Is: 'is';
Loop: 'loop';
Procedure: 'procedure';
Read: 'read';
Then: 'then';
Write: 'write';

Colon: ':';
DotDot: '..';
Semi: ';';

Plus: '+';
Minus: '-';
Star: '*';
Div: '/';
Mod: '%';

Equal: '=';
NotEqual: '<>';
Greater: '>';
GreaterEqual: '>=';
Less: '<';
LessEqual: '<=';

AndAnd: '&&';
OrOr: '||';
Not: '!';
Assign: ':=';

LeftParen: '(';
RightParen: ')';

fragment Zero: [0];
fragment Digit: [0-9];
fragment NonzeroDigit: [1-9];
fragment Nondigit: [A-Z_];

Identifier: Nondigit (Nondigit | Digit)*;

Constant: Zero | (NonzeroDigit Digit*);

Whitespace: [ \t\n\r]+ -> skip;

LineComment: '//' ~[\r\n]* -> skip;

