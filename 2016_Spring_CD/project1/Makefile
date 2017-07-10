All: testLexer.class

testLexer.class: mylexer.java
	javac -cp antlr-3.5.2-complete.jar *.java

mylexer.java: mylexer.g
	java -cp antlr-3.5.2-complete.jar org.antlr.Tool mylexer.g

clean:
	rm -f *.class *.tokens mylexer.java
