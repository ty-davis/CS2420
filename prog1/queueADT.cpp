#include "queueADT.h"
#include <iostream>
#include <stdexcept>

template <class Type>
queueADT<Type>::queueADT(int size) : maxsize(size), head(0), tail(0), count(0) {
	lq = new Type[maxsize];
}

template <class Type>
bool queueADT<Type>::isEmpty() {
	return count == 0;
}

template <class Type>
bool queueADT<Type>::isFull() {
	return count == maxsize;
}

template <class Type>
Type queueADT<Type>::deQueue() {
	if (isEmpty()) {
		throw std::runtime_error("Queue is empty. Cannot dequeue.");
	}
	Type value = lq[head];
	head = (head + 1) % maxsize;
	count --;
	return value;
}

template <class Type>
void queueADT<Type>::enQueue(Type item) {

}

template <class Type>
Type queueADT<Type>::peek() {
	
}
