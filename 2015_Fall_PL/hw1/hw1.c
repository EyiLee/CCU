#include <ctype.h>
#include <stdio.h>

/* the tokens as an enumerated type */
typedef enum {
	TT_PLUS,
	TT_TIMES,
	TT_LPAREN,
	TT_RPAREN,
	TT_EOL,
	TT_NUMBER,
	TT_ERROR
} TokenType;

int numVal; /* computed numeric value of a NUMBER token */
int currChar; /* current character */

TokenType getToken(){
	while (currChar == ' ') /* skip blanks */
		currChar = getchar();
	if (isdigit(currChar)) { /* recognize a NUMBER token */
		numVal = 0;
		while (isdigit(currChar)) {
			/* compute numeric value */
			numVal = 10 * numVal + currChar - '0';
			currChar = getchar();
		}
		return TT_NUMBER;
	}
	else{ /* recognize a special symbol */
		switch (currChar) {
			case '(': return TT_LPAREN; break;
			case ')': return TT_RPAREN; break;
			case '+': return TT_PLUS; break;
			case '*': return TT_TIMES; break;
			case '\n': return TT_EOL; break;
			default: return TT_ERROR; break;
		}
	}
}

int main(){
	TokenType token;
	currChar = getchar();
	do {
		token = getToken();
		switch (token){
			case TT_PLUS: printf("TT_PLUS\n"); break;
			case TT_TIMES: printf("TT_TIMES\n"); break;
			case TT_LPAREN: printf("TT_LPAREN\n"); break;
			case TT_RPAREN: printf("TT_RPAREN\n"); break;
			case TT_EOL: printf("TT_EOL\n"); break;
			case TT_NUMBER: printf("TT_NUMBER: %d\n", numVal); break;
			case TT_ERROR: printf("TT_ERROR: %c\n", currChar); break;
		}
		currChar = getchar();
	} while (token != TT_EOL);
	return 0;
}
