#include "Queue.h"

//初始化
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//销毁队列
void QueueDestroy(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}
	/*while (cur) {
		QNode* later = cur->next;
		free(cur);
		cur = later;
	}*/
}

//入队列
void QueuePush(Queue* pq, QDataType val) {
	assert(pq);
	//申请新节点，申请失败就退出程序
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode) {
		perror("QueuePush");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
	//链表尾插分为两种情况：
	//1.队头指针为空
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	//2.队头指针不为空
	else {
		//先链接前后节点，在更新尾节点
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	++pq->size;
}

//出队列
void QueuePop(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	//防止tail野指针
	if (pq->head == pq->tail) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
		del = NULL;
	}
	--pq->size;
}

//取队头数据
QDataType QueueHead(Queue* pq) {
	assert(pq);
	return pq->head->val;
}

//取队尾数据
QDataType QueueTail(Queue* pq) {
	assert(pq);
	return pq->tail->val;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//计算队列长度
int QueueSize(Queue* pq) {
	assert(pq);
	//遍历法，效率较低
	/*int n = 0;
	QNode* cur = pq->head;
	while (cur) {
		++n;
		cur = cur->next;
	}
	return n;*/

	/*直接在队列结构体里定义一个size，每次入队列或出队列同时改变size，
	使用时直接从结构体内返回即可*/
	return pq->size;
}