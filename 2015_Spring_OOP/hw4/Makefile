All: hw4.out

hw4.out: hw4.o List.o LnList.o Node.o
	g++ -Wall -O3 hw4.o List.o LnList.o Node.o -o hw4.out
hw4.o: hw4.cpp
	g++ -Wall -O3 -c hw4.cpp
List.o: List.cpp List.hpp
	g++ -Wall -O3 -c List.cpp
LnList.o: LnList.cpp LnList.hpp
	g++ -Wall -O3 -c LnList.cpp
Node.o: Node.cpp Node.hpp
	g++ -Wall -O3 -c Node.cpp
clean:
	rm -f hw4.out *.o
