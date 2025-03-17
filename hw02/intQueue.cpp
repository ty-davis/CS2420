#include "intQueue.h"
#include <iostream>


IntQueue::IntQueue(int size) {
	head = 0;
	tail = 0;
	count = 0;
	maxsize = size;
	localQueue = new int[maxsize];
}

bool IntQueue::isemptyq() {
	return count == 0;
}

bool IntQueue::isfullq() {
	return count == maxsize;
}

void IntQueue::enQueue(int val) {
	if (isfullq()) {
		printf("The queue is full. Cannot enqueue.\n");
		return;
	}
	localQueue[tail] = val;
	tail = (tail + 1) % maxsize;
	count++;
}

int IntQueue::deQueue() {
	if (isemptyq()) {
		printf("The queue is empty. Cannot dequeue.\n");
		return 0;
	}

	head = (head + 1) % maxsize;
	count--;
	return localQueue[head-1];
}

int IntQueue::peek() {
	if (isemptyq()) {
		printf("The queue is empty. Cannot peek.\n");
		return 0;
	}

	return localQueue[head];
}
