/* 
 * sortedListADT.cpp
 * Ty Davis - 2/13/2025
 * 
 * Implementation of the sortedListADT class.
 *
 */

#include <iostream>

// overload the assignment operator for a sorted list
template <class Type>
const sortedListADT<Type>& sortedListADT<Type>::operator=(const sortedListADT<Type> & otherList) {
	if (this != &otherList) {
		destroyList();
		copyList(otherList);
	}
	return *this;

}

// isEmpty determines whether the list is empty or not
template <class Type>
bool sortedListADT<Type>::isEmpty() const {
	return numElements == 0;
}

// return true if searchItem is in the list
template <class Type>
bool sortedListADT<Type>::search(const Type& searchElem) const {
	nodeType<Type> *current = first;
	while (current != nullptr) {
		if (current->value == searchElem)
			return true;
		current = current->next;
	}
	return false;
}

// removeElement searches for the element passed as a parameter
// and removes it from the list if present, printing a message
// if it is not found
template <class Type>
void sortedListADT<Type>::removeElement(const Type& remElem) {
	nodeType<Type> *current = first;
	while (current != nullptr) {
		if (current->value == remElem) {
			break;
		}
		current = current->next;
	}

	if (current == nullptr) {
		std::cout << "Error: The element " << remElem << " was not found in the list.\n";
		return;
	} else if (current == first) { // remove the first element
		first = current->next;
		first->prev = nullptr;
		delete current;
		numElements--;
		return;
	} else if (current == last) { // remove the last element
		last = current->prev;
		last->next = nullptr;
		delete current;
		numElements--;
		return;
	}

	// element found in the middle
	nodeType<Type> *prevElement = current->prev;
	nodeType<Type> *nextElement = current->next;

	prevElement->next = nextElement;
	nextElement->prev = prevElement;
	delete current;
	numElements--;
	return;
}

// insertElement puts the element at its sorted position in the 
// list using the friend function for comparison
template <class Type>	
void sortedListADT<Type>::insertElement(const Type& newElem) {
	if (isEmpty()) {
		// inserting the first element
		nodeType<Type> *newNode = new nodeType<Type>;
		newNode->value = newElem;
		newNode->next = nullptr;
		newNode->prev = nullptr;

		first = newNode;
		last = newNode;
		numElements ++;
		return;
	}
	nodeType<Type> *current = first;
	while (!(current->value >= newElem)) {
		current = current->next;

		// don't want to dereference the nullptr, so break now
		if (current == nullptr)
			break;
	}

	if (current == first) {
		// new node
		nodeType<Type> *newNode = new nodeType<Type>;
		newNode->value = newElem;
		newNode->next = current;
		newNode->prev = nullptr;

		// current node
		current->prev = newNode;

		// sortedList
		first = newNode;
		numElements++;
		return;
	} else if (current == nullptr) {
		nodeType<Type> *newNode = new nodeType<Type>;
		newNode->value = newElem;
		newNode->next = nullptr;
		newNode->prev = last;

		// last node
		last->next = newNode;

		// sortedList
		last = newNode;
		numElements++;
		return;
	}

	// new node in middle of list
	nodeType<Type> *newNode = new nodeType<Type>;
	newNode->value = newElem;
	newNode->next = current;
	newNode->prev = current->prev;

	nodeType<Type> *newNodeLast = current->prev;
	// current node
	current->prev = newNode;
	// node before new node
	newNodeLast->next = newNode;
	numElements++;
	return;
}

// front() returns the value of the first element in the list
template <class Type>
Type sortedListADT<Type>::front() const {
	Type temp;
	if (isEmpty()) {
		std::cout << "Error: List is empty.\n";
		return temp;
	}
	temp = first->value;
	return temp;
}

// front() returns the value of the first element in the list
template <class Type>
Type sortedListADT<Type>::back() const {
	Type temp;
	if (isEmpty()) {
		std::cout << "Error: List is empty.\n";
		return temp;
	}
	temp = last->value;
	return temp;
}

// prints the sorted list in order from first to last
template <class Type>
void sortedListADT<Type>::printInOrder() const {
	nodeType<Type> *current = first;
	while (current != nullptr) {
		std::cout << current->value << '\n';
		current = current->next;
	}
}

// prints the sorted list in reverse order from last to first
template <class Type>
void sortedListADT<Type>::printRevOrder() const {
	nodeType<Type> *current = last;
	while (current != nullptr) {
		std::cout << current->value << '\n';
		current = current->prev;
	}
}

// delete all nodes in the list and set first=last=NULL and
// numElements=0
template <class Type>
void sortedListADT<Type>::destroyList() {
	nodeType<Type> *current = first;
	while (current != nullptr) {
		nodeType<Type> *next = current->next;
		delete current;
		current = next;
	}

	// initial values
	first = nullptr;
	last = nullptr;
	numElements = 0;
}

// default constructor for the sorted list, which is implemneted with a
// doubly linked list
template <class Type>
sortedListADT<Type>::sortedListADT() {
	first = nullptr;
	last = nullptr;
	numElements = 0;
}

// copy constructor for sorted list to create a copy of the list
template <class Type>
sortedListADT<Type>::sortedListADT(const sortedListADT<Type>& otherList) {
	destroyList();
	copyList(otherList);
}

// destructor to delete all the nodes from the list and reset
// the first, last, and numElements values
template <class Type>
sortedListADT<Type>::~sortedListADT() {
	destroyList();
}

// used to implement the assignment operator
template <class Type>
void sortedListADT<Type>::copyList(const sortedListADT<Type>& otherList) {
	nodeType<Type> *current = otherList.first;
	while (current != nullptr) {
		insertElement(current->value);
		current = current->next;
	}
}

