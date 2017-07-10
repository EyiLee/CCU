All: myCompilerTest.class

myCompilerTest.class: myCompilerTest.java myCompiler.tokens
	javac -cp antlr-3.5.2-complete.jar myCompilerTest.java myCompilerParser.java myCompilerLexer.java register.java

myCompiler.tokens: myCompiler.g
	java -cp antlr-3.5.2-complete.jar org.antlr.Tool myCompiler.g

clean:
	rm -f *.class *.tokens myCompiler.java myCompilerLexer.java myCompilerParser.java
