#include <iostream>

// contstructor that initializes the queue with the size "maxsize"
template <class Type>
queueADT<Type>::queueADT(int size) : maxsize(size), head(0), tail(0), count(0) {
	lq = new Type[maxsize];
}

// return True if the queue is empty
template <class Type>
bool queueADT<Type>::isEmpty() {
	return count == 0;
}

// return True if the queue is full according to "maxsize"
template <class Type>
bool queueADT<Type>::isFull() {
	return count == maxsize;
}

// returns the item from the head of the queue unless it is empty
template <class Type>
Type queueADT<Type>::deQueue() {
	Type value = Type();
	if (isEmpty()) {
		printf("error: Queue is empty. Cannot dequeue.\n");
	} else {
		value = lq[head];
		// update the head and don't overflow
		head = (head + 1) % maxsize;
		count--;
	}
	return value;
}

// takes an item and puts it onto the queue
template <class Type>
void queueADT<Type>::enQueue(Type item) {
	if (isFull()) {
		printf("error: Queue is full. Cannot enqueue.\n");
		return;
	}
	lq[tail] = item;

	// update the tail for the next item and don't overflow
	tail = (tail + 1) % maxsize;
	count++;
}

// returns the item at the head of the queue, but leaves it there, unless the queue is empty
template <class Type>
Type queueADT<Type>::peek() {
	if (isEmpty()) {
		printf("error: Cannot peek the empty queue.\n");
		return Type();
	}
	return lq[head];
}
