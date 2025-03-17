# makefile for program 03

prog03: prog03.o GeneralHashFunctions.o
	g++ -o prog03 prog03.o GeneralHashFunctions.o

prog03.o: prog03.cpp GeneralHashFunctions.h sortedListADT.h
	g++ -c prog03.cpp

GeneralHashFunctions.o: GeneralHashFunctions.cpp GeneralHashFunctions.h
	g++ -c GeneralHashFunctions.cpp

clean:
	rm prog03 *.o
