All: hw5.out

hw5.out: hw5.o Fraction.o
	g++ -Wall -O3 hw5.o Fraction.o -o hw5.out
hw5.o: hw5.cpp Fraction.cpp Fraction.h
	g++ -Wall -O3 -c hw5.cpp
Fraction.o: Fraction.cpp Fraction.h
	g++ -Wall -O3 -c Fraction.cpp
clean:
	rm -f hw5.out *.o
