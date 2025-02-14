#include "sortedListADT.h"
#include <iostream>

int main() {
	std::cout << "This is my test baby yeah:\n";	

	sortedListADT<int> myList;

	myList.insertElement(1);
	myList.insertElement(10);
	myList.insertElement(5);

	myList.printInOrder();
	myList.printRevOrder();

	std::cout << myList.front() << '\n';
	std::cout << myList.back() << '\n';

	std::cout << myList.search(5) << '\n';
	std::cout << myList.search(3) << '\n';

	std::cout << "START HERE\n";
	myList.removeElement(5);
	myList.printInOrder();

	std::cout << "--------------\n";
	myList.insertElement(4);
	myList.insertElement(8);
	myList.insertElement(10);
	myList.insertElement(3);
	myList.insertElement(57);
	myList.insertElement(-2);
	myList.insertElement(-100);

	myList.printInOrder();
	std::cout << "--------------\n";

	std::cout << "Destroying list\n";
	myList.destroyList();
	myList.printInOrder();
	std::cout << myList.isEmpty() << '\n';
}
