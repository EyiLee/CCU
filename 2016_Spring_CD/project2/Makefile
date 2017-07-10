All: testParser.class

testParser.class: myparser.java
	javac -cp antlr-3.5.2-complete.jar testParser.java myparserParser.java myparserLexer.java

myparser.java: myparser.g
	java -cp antlr-3.5.2-complete.jar org.antlr.Tool myparser.g

clean:
	rm -f *.class *.tokens myparser.java
