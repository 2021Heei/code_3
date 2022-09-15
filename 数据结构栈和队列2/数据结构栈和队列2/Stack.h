#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//����ȳ�
//˳���ջ
typedef int STDataType;
typedef struct Stack {
	STDataType* pdata;
	int top;//ջ��
	int capacity;
}Stack;

//��ʼ��
void StackInit(Stack* pst);

//����ջ
void StackDestroy(Stack* pst);

//��ӡջ��ջ��ʧ
void StackPrint(Stack* pst);

//��ջ
void StackPush(Stack* pst, STDataType val);

//��ջ
void StackPop(Stack* pst);

//ȡջ��Ԫ��
STDataType StackTop(Stack* pst);

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* pst);

//����ջ�Ĵ�С
int StackSize(Stack* pst);