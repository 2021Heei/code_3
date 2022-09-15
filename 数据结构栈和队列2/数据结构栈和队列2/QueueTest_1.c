#include "Queue.h"

void test1() {
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	//��ӡ����
	while (!QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	printf("\n");

	
	
	QueueDestroy(&q);



}

int main() {
	test1();

	return 0;
}