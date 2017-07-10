import org.antlr.runtime.*;
import java.util.ArrayList;
import java.util.List;

public class myCompilerTest {
	public static void main(String[] args) throws Exception {

      CharStream input = new ANTLRFileStream(args[0]);
      myCompilerLexer lexer = new myCompilerLexer(input);
      CommonTokenStream tokens = new CommonTokenStream(lexer);
 
      myCompilerParser parser = new myCompilerParser(tokens);
      parser.program();
      
      /* Output data section */
	  List<String> data_code = parser.getDataCode();
	  
	  System.out.println("\n.data");
	  for(int i=0; i < data_code.size(); i++)
	    	System.out.println(data_code.get(i));

	  
	  /* Output text section */
	  List<String> text_code = parser.getTextCode();
	  
	  System.out.println("\n.text");
	  for(int i=0; i < text_code.size(); i++)
	    	System.out.println(text_code.get(i));
	  System.out.println("\tli\t$v0, 10");
	  System.out.println("\tsyscall\n");

	  /* built-in printf_int */
	  System.out.println("printf_int:");
	  System.out.println("\tmove\t$a0, $s0");
	  System.out.println("\tli\t$v0, 1");
	  System.out.println("\tsyscall");
	  System.out.println("\tjr\t$ra\n");

	  /* built-in printf_str */
	  System.out.println("printf_str:");
	  System.out.println("\tmove\t$a0, $s0");
	  System.out.println("\tli\t$v0, 4");
	  System.out.println("\tsyscall");
	  System.out.println("\tjr\t$ra\n");

	}
}
