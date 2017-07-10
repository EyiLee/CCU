import org.antlr.runtime.ANTLRFileStream;
import org.antlr.runtime.CharStream;
import org.antlr.runtime.Token;


public class testLexer {
	public static void main(String[] args) {
		CharStream input = new ANTLRFileStream(args[0]);
		myC lexer = new myC(input);
		Token token = lexer.nextToken();
		while (token.getType() != -1) {  // -1 is EOF.
			System.out.println("Token: " + token.getType() + " " + token.getText());
			token = lexer.nextToken();
		}
	}
}
