#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//������
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//��װΪ�ڵ�
typedef int QDataType;
typedef struct QueueNode {
	QDataType val;
	struct QueueNode* next;
}QNode;

//��װ�ڵ�ָ��Ϊ
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//��ʼ��
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestroy(Queue* pq);

//�����
void QueuePush(Queue* pq, QDataType val);

//������
void QueuePop(Queue* pq);

//ȡ��ͷ����
QDataType QueueHead(Queue* pq);

//ȡ��β����
QDataType QueueTail(Queue* pq);

//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//������г���
int QueueSize(Queue* pq);

