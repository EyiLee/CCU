all:hw1.out hw1.class

hw1.out:hw1.o
	g++ -Wall -O3 hw1.o -o hw1.out
hw1.o:hw1.cpp
	g++ -Wall -c -O3 hw1.cpp
hw1.class:hw1.java Mul.java
	javac hw1.java Mul.java
clean:
	rm -rf hw1.o hw1.out hw1.class Mul.class
