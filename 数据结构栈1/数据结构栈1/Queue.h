#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
//后进后出
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

//封装为节点
typedef int QDataType;
typedef struct QueueNode {
	QDataType val;
	struct QueueNode* next;
}QNode;

//封装节点指针为
typedef struct Queue {
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);

//入队列
void QueuePush(Queue* pq, QDataType val);

//出队列
void QueuePop(Queue* pq);

//取队头数据
QDataType QueueHead(Queue* pq);

//取队尾数据
QDataType QueueTail(Queue* pq);

//判断队列是否为空
bool QueueEmpty(Queue* pq);

//计算队列长度
int QueueSize(Queue* pq);

