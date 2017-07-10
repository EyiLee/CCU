all: hw3.out

hw3.out: hw3.o coins.o
	g++ -Wall -O3 hw3.o coins.o -o hw3.out
hw3.o: hw3.cpp coins.hpp
	g++ -Wall -O3 -c hw3.cpp
coins.o: coins.cpp coins.hpp
	g++ -Wall -O3 -c coins.cpp
clean:
	rm -rf hw3.out hw3.o coins.o
