//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <stdbool.h>
//#include <windows.h>
//
////������
////�Ƚ��ȳ�
////��β������ͷ��
//
////��װΪ�ṹ��
//typedef int QEDataType;
//typedef struct QNode{
//	QEDataType val;
//	struct QNode* next;
//}QNode;
//
////��װΪ����
//typedef struct Queue {
//	QNode* head;
//	QNode* tail;
//	int size;
//}Queue;
//
////��ʼ������
//void QueueInit(Queue* pq);
//
////���ٶ���
//void QueueDestroy(Queue* pq);
//
////��β�����
//void QueuePush(Queue* pq, QEDataType val);
//
////��ͷ������
//void QueuePop(Queue* pq);
//
////ȡ��ͷ����
//QEDataType QueueHead(Queue* pq);
//
////ȡ��β����
//QEDataType QueueTail(Queue* pq);
//
////�ж϶����Ƿ�Ϊ��
//bool QueueEmpty(Queue* pq);
//
////�������Ԫ�ظ���
//int QueueSize(Queue* pq);