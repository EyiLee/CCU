CXX=g++
CXXFLAGS= -Wall -O3

all: hw2.out

hw2.out: hw2.o func.o
	$(CXX) $(CXXFLAGS) hw2.o func.o -o hw2.out
hw2.o: hw2.cpp func.hpp
	$(CXX) $(CXXFLAGS) -c hw2.cpp
func.o: func.cpp func.hpp
	$(CXX) $(CXXFLAGS) -c func.cpp
clean:
	rm -rf hw2.out hw2.o func.o

.PHONY: clean
