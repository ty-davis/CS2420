#include "intQueue.h"
#include <iostream>

#define MAXSIZE 5
int main() {

	IntQueue myq = IntQueue(MAXSIZE);

	// do all of the tests twice on the same queue to make sure
	// head and tail are working correctly
	for (int _ = 0; _ < 2; _++) {
		// test peeking with an empty queue
		std::cout << myq.peek() << '\n';

		// test adding too many items to the queue
		for (int i = 0; i < MAXSIZE + 1; i++) {
			std::cout << "Enqueue-ing: " << i << '\n';
			myq.enQueue(i);
		}

		// test removing too many items from the queue
		for (int i = 0; i < MAXSIZE + 1; i++) {
			std::cout << "Dequeued: " << myq.deQueue() << '\n';
		}
	}

	return 0;
}
