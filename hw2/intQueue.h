class IntQueue {
public:
	bool isemptyq();
	bool isfullq();
	void enQueue(int val);
	int deQueue();
	int peek();
private:
	int* localQueue;
	int maxsize;
	int head;
	int tail;
	int count;
};
