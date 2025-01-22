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

	queueADT<std::string> queueStr = queueADT<std::string>(4);
	queueStr.enQueue("Hi there");
	queueStr.enQueue("What's up?");
	std::string returned = queueStr.deQueue();
	std::cout << "Received: " << returned;
}
