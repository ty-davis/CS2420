# makefile for program sorted list ADT

p2test: p2test.o person.o
	g++ -o p2test p2test.o person.o

p2test.o: p2test.cpp person.h sortedListADT.cpp sortedListADT.h
	g++ -c p2test.cpp

person.o: person.h person.cpp
	g++ -c person.cpp


clean:
	rm p2test *.o
