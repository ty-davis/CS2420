/* this is a quick test program for the linked list queue provided 
 * in homework 4.
 */
#include <iostream>

using namespace std;

#include "llque.h"

int main(void) {
	
	int i, j, k; // don't know if I will use these
	
	// create the list
	llque<int> myintQ;
	
	cout << "Test isEmpty... should be true ";
	if (myintQ.isEmpty()) {
		cout << "pass\n";
	} else { 
		cout << "FAIL\n";
	}
	cout << "Try peeking an empty linked list:\n";
	myintQ.peek();
	
	cout << "Test enqueue for '3', value returned from peek: ";
	myintQ.enQueue(3);
	cout << myintQ.peek() << "  ";
	if (myintQ.peek() != 3) {
		cout << "FAIL\n";
	} else {
		cout << "pass\n";
	}
	myintQ.deQueue();

	int moreInts[] = { 1, 5, -10, 1000, 1200309213, -120939021 };
	cout << "Testing with more ints:\n";
	cout << "Enqueueing all the numbers:\n";
	for (i = 0; i < sizeof(moreInts)/sizeof(int); i++) {
		cout << moreInts[i] << "  ";
		myintQ.enQueue(moreInts[i]);
	}
	cout << "\n";

	cout << "Test if it's full, it really shouldn't be.\n";
	cout << "Is it full? " << myintQ.isFull() << "\n";

	cout << "Dequeue in order:\n";
	for (i = 0; i < sizeof(moreInts)/sizeof(int); i++) {
		int tmp = myintQ.deQueue();
		cout << tmp << "  ";
		if (tmp != moreInts[i]) {
			cout << "FAIL\n";
		} else {
			cout << "pass\n";
		}
	}


	cout << "Trying dequeue-ing too many times, should happen twice:\n";
	for (i = 0; i < 2; i++) {
		int tmp = myintQ.deQueue();
	}

	cout << "Try with other data types:\n";
	cout << "FLOATS!\n";
	llque<float> floatQ;

	float someFloats[] = {1., 2., -0.5, 100., 3.1415926535898, 1.092301/5.234092 };
	for (i = 0; i < sizeof(someFloats)/sizeof(int); i++) {
		cout << someFloats[i] << "  ";
		floatQ.enQueue(someFloats[i]);
	}

	cout << "\nDequeue in order:\n";
	for (i = 0; i < sizeof(someFloats)/sizeof(int); i++) {
		float tmp = floatQ.deQueue();
		cout << tmp << "  ";
		if (tmp != someFloats[i]) {
			cout << "FAIL\n";
		} else {
			cout << "pass\n";
		}
	}
	

	cout << "String!\n";
	llque<string> strQ;

	string someStrs[] = {"Hi there", "What's up?", "WSU Rocks!", "Go cats!"};

	for (const string& str : someStrs) {
		strQ.enQueue(str);
		cout << str << " - ";
	}

	cout << "\nDequeue in order:\n";
	for (const string& str : someStrs) {
		string tmp = strQ.deQueue();
		cout << tmp << "  ";
		if (tmp != str) {
			cout << "FAIL\n";
		} else {
			cout << "pass\n";
		}
	}
	
	cout << "Test the copy constructor.\n";
	strQ.enQueue("Stop");
	strQ.enQueue("in");
	strQ.enQueue("the");
	strQ.enQueue("name");
	strQ.enQueue("of");
	strQ.enQueue("love");

	llque<string> newStrQ = llque(strQ);
	cout << "Test contents of newStrQ, should read 'Stop in the name of love':\n";
	while (!newStrQ.isEmpty()) {
		cout << newStrQ.deQueue() << " ";
	}
	cout << "\n";

	cout << "Try destroying then accessing the linked list:\n";
	strQ.enQueue("You can't see me");
	strQ.destroyllq();
	cout << "Should error out here:\n";
	cout << strQ.peek() << "\n";

	
	return 0;
}
