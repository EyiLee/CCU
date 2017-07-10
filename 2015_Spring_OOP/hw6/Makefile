All: hw6.out

hw6.out: hw6.o MyShape.o
	g++ -Wall -O3 hw6.o MyShape.o -o hw6.out
hw6.o: hw6.cpp MyShape.cpp MyShape.hpp
	g++ -Wall -O3 -c hw6.cpp
MyShape.o: MyShape.cpp MyShape.hpp
	g++ -Wall -O3 -c MyShape.cpp
clean:
	rm -f hw6.out *.o
