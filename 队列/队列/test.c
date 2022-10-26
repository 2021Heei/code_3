#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//链队列
//先进先出
//队尾进，队头出

//封装为结构体
typedef int QEDataType;
typedef struct QNode {
	QEDataType val;
	struct QNode* next;
}QNode;

//封装为队列
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//队尾入队列
void QueuePush(Queue* pq, QEDataType val);

//队头出数据
void QueuePop(Queue* pq);

//取队头数据
QEDataType QueueHead(Queue* pq);

//取队尾数据
QEDataType QueueTail(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//计算队列元素个数
int QueueSize(Queue* pq);

int main() {
	Queue q;
	QueueInit(&q);
	int n;
	printf("请输入入队元素个数>");
	scanf("%d", &n);
	printf("请输入%d个元素>", n);
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		QueuePush(&q, val);
	}
	printf("请输入出队元素个数>");
	scanf("%d", &n);
	while (n-- && !QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	printf("\n出队剩余元素\n");
	while (!QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 0;
}

//初始化队列
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
	pq->head = pq->tail = NULL;
	pq->size = 0;
}


//队尾入队列
void QueuePush(Queue* pq, QEDataType val) {
	assert(pq);
	//开新节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode) {
		perror("malloc file");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;

	//队头指针为空或不为空
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	++pq->size;
}

//队头出数据
void QueuePop(Queue* pq) {
	assert(pq);
	//是最后一个节点，队尾指针需要特殊处理一下
	if (pq->head->next == NULL) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QNode* del = pq->head;
		pq->head = pq->head->next;
		free(del);
	}
	--pq->size;
}

//取队头数据
QEDataType QueueHead(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->val;
}

//取队尾数据
QEDataType QueueTail(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty);
	return pq->tail->val;
}

//判断队列是否为空
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//计算队列元素个数
int QueueSize(Queue* pq) {
	assert(pq);
	return pq->size;
}