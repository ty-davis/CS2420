#include <iostream>		/* general I/O streams */
#include <fstream>		/* file I/O */
#include <iomanip>		/* I/O formatting commands */
#include "GeneralHashFunctions.h"  // library of hash functions from 
						// https://www.partow.net/programming/hashfunctions/
#include "sortedListADT.h"

using namespace std;	// needed because I'm lazy and don't feel like adding std:: to everything

#define TABSIZE 211

int main() {
	string filename = "";	// used to capture the input file name
	string inputStr = "";	// general input string
	int i, j;				// loop control variables
	ifstream inFile; 		// Input text file
	unsigned int hashVal;	// hash value returned by the function
	
	sortedListADT<string> hashTab[TABSIZE]; // initialize hash table

	/*
	 * Open the data file, should be text strings
	 */
	cout << "Please enter the name of the data file to read: ";
	cin >> filename;	// file to write to
	
	inFile.open(filename);
	if (!inFile) {
		cerr << "Unable to open input file, exiting!\n";
		exit(1);		// input file failure
	}
	
	/* 
	 * Read in the input file, count the number of strings read
	 */
	while(getline(inFile,inputStr)){  // read a line from the file
		hashVal = BKDRHash(inputStr);   //***** Compute the hash. I've chosen the BKDRHash
		hashTab[hashVal % 211].insertElement(inputStr); // make sure the hash value is within the hash table size
	} // strings read in and hash collisions counted
	
	for (i=0; i < TABSIZE; i++) {
		cout << i << " - "; // see where in the hash table the linked list is saved
		if (hashTab[i].isEmpty()) {
			cout << "\n";
		}
		hashTab[i].printInOrder(); // print each linked list in the hash table to show that they are not in order
	}

}
