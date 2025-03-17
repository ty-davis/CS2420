class IntQueue {
public:
	// constructor
	IntQueue(int);

	// boundary checks
	bool isemptyq();
	bool isfullq();

	// managing the queue
	void enQueue(int);
	int deQueue();

	// in case you want to see what's at the front
	int peek();

private:
	// private variables
	int* localQueue;
	int maxsize;
	int head;
	int tail;
	int count;
};
