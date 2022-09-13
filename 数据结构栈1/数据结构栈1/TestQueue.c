#include "Queue.h"

void TestQueue() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	printf("size:%d\n", QueueSize(&q));

	while (!QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestroy(&q);
}

int main() {
	TestQueue();

	return 0;
}