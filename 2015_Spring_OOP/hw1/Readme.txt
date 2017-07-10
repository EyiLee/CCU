#hw1 Multitions
id = 402410078
name = 李佳祥
email = sdses9001@gmail.com
develpment-environment = csie*.cs.ccu.edu.tw
description:
	1.first we type "make" in command line ,and we'll get four files
	"hw1.out" ,"hw1.o" ,"hw1.class" ,"Mul.class"
	then we have bulid our cpp & java program
	2.run	#cpp:
		type "./hw1.out" to start the program
	3.run	#java:
		type "java hw1" to start the program
	4.when see the msg "Enter the number followed by the order : " ,type the input
	by rule [integer][signs]
	5.then we'll get an answer for the input, when the input is illegal you'll get an error msg
test-input(for cpp & java):
	2464588 3		//normal input
	2147483699 2	//integer is too large
	341341 0		//sign number is too less
	28362 5			//sign number is too large
	912734 9		//sign number is too large
