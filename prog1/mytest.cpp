#include "queueADT.h"

int main() {
	queueADT<int> queue = queueADT<int>(5);
	printf(queue.isEmpty() ? "Empty\n" : "Not empty\n");
	queue.enQueue(5);
	queue.enQueue(7);
	printf(queue.isEmpty() ? "Empty\n" : "Not empty\n");
	printf("%d\n", queue.peek());
	queue.deQueue();
	printf("%d\n", queue.peek());
}
