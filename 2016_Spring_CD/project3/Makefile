All: myCheckerTest.class

myCheckerTest.class: myChecker.java
	javac -cp antlr-3.5.2-complete.jar myCheckerTest.java myCheckerParser.java myCheckerLexer.java

myChecker.java: myChecker.g
	java -cp antlr-3.5.2-complete.jar org.antlr.Tool myChecker.g

clean:
	rm -f *.class *.tokens myChecker.java
