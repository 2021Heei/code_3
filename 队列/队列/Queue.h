//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <windows.h>
//
////链队列
////先进先出
////队尾进，队头出
//
////封装为结构体
//typedef int QEDataType;
//typedef struct QNode{
//	QEDataType val;
//	struct QNode* next;
//}QNode;
//
////封装为队列
//typedef struct Queue {
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
////初始化队列
//void QueueInit(Queue* pq);
//
////销毁队列
//void QueueDestroy(Queue* pq);
//
////队尾入队列
//void QueuePush(Queue* pq, QEDataType val);
//
////队头出数据
//void QueuePop(Queue* pq);
//
////取队头数据
//QEDataType QueueHead(Queue* pq);
//
////取队尾数据
//QEDataType QueueTail(Queue* pq);
//
////判断队列是否为空
//bool QueueEmpty(Queue* pq);
//
////计算队列元素个数
//int QueueSize(Queue* pq);