#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

//#define N 100
//typedef int STDataType;
//struct Stack {
//	STDataType data[N];
//	int pop;
//};
typedef int STDataType;
typedef struct Stack {
	STDataType* data;
	int top;
	int capacity;
}ST;

//��ʼ��
void StackInit(ST* pst);

//����ջ
void StackDestroy(ST* pst);

//��ջ
void StackPush(ST* pst, STDataType val);

//��ջ
void StackPop(ST* pst);

//ȡ��ջ��Ԫ��
STDataType StackTop(ST* pst);

//�ж�ջ�Ƿ��ǿ�
bool StackEmpty(ST* pst);

//����ջ�Ĵ�С
int StackSize(ST* pst);
