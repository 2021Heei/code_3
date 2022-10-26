#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//������
//�Ƚ��ȳ�
//��β������ͷ��

//��װΪ�ṹ��
typedef int QEDataType;
typedef struct QNode {
	QEDataType val;
	struct QNode* next;
}QNode;

//��װΪ����
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//��ʼ������
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//��β�����
void QueuePush(Queue* pq, QEDataType val);

//��ͷ������
void QueuePop(Queue* pq);

//ȡ��ͷ����
QEDataType QueueHead(Queue* pq);

//ȡ��β����
QEDataType QueueTail(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//�������Ԫ�ظ���
int QueueSize(Queue* pq);

int main() {
	Queue q;
	QueueInit(&q);
	int n;
	printf("���������Ԫ�ظ���>");
	scanf("%d", &n);
	printf("������%d��Ԫ��>", n);
	for (int i = 0; i < n; ++i) {
		int val;
		scanf("%d", &val);
		QueuePush(&q, val);
	}
	printf("���������Ԫ�ظ���>");
	scanf("%d", &n);
	while (n-- && !QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	printf("\n����ʣ��Ԫ��\n");
	while (!QueueEmpty(&q)) {
		printf("%d ", QueueHead(&q));
		QueuePop(&q);
	}
	QueueDestroy(&q);
	return 0;
}

//��ʼ������
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

//���ٶ���
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


//��β�����
void QueuePush(Queue* pq, QEDataType val) {
	assert(pq);
	//���½ڵ�
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode) {
		perror("malloc file");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;

	//��ͷָ��Ϊ�ջ�Ϊ��
	if (pq->head == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	++pq->size;
}

//��ͷ������
void QueuePop(Queue* pq) {
	assert(pq);
	//�����һ���ڵ㣬��βָ����Ҫ���⴦��һ��
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

//ȡ��ͷ����
QEDataType QueueHead(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->val;
}

//ȡ��β����
QEDataType QueueTail(Queue* pq) {
	assert(pq);
	assert(!QueueEmpty);
	return pq->tail->val;
}

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL && pq->tail == NULL;
}

//�������Ԫ�ظ���
int QueueSize(Queue* pq) {
	assert(pq);
	return pq->size;
}