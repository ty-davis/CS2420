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
		printf("error: Queue is empty. Cannot dequeue.\n");
		return 0;
		throw std::runtime_error("Queue is empty. Cannot dequeue.");
	}
	Type value = lq[head];
	head = (head + 1) % maxsize;
	count --;
	return value;
}

template <class Type>
void queueADT<Type>::enQueue(Type item) {
	if (isFull()) {
		printf("error: Queue is full. Cannot enqueue.\n");
		return;
		// throw std::runtime_error("Queue is full. Cannot enqueue.\n");
	}
	lq[tail] = item;
	tail = (tail + 1) % maxsize;
	count ++;
}

template <class Type>
Type queueADT<Type>::peek() {
	if (isEmpty()) {
		printf("error: Cannot peek the empty queue.\n");
		return 0;
	}
	return lq[head];
}
