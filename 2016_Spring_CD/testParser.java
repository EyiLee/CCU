import org.antlr.runtime.*;

public class testmylexer {
    public static void main(String[] args) throws Exception
    {
        CharStream input = new ANTLRFileStream(args[0]);
        mylexerLexer lexer = new mylexerLexer(input);
        CommonTokenStream tokens = new CommonTokenStream(lexer);
	
        mylexerParser parser = new mylexerParser(tokens);
        parser.expr();
    }
}

