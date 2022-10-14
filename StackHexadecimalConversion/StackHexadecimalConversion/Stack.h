#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char STDataType;
typedef struct Stack {
	STDataType* data;
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* pst);

//销毁栈
void StackDestroy(ST* pst);

//入栈
void StackPush(ST* pst, STDataType val);

//出栈
void StackPop(ST* pst);

//取出栈顶元素
STDataType StackTop(ST* pst);

//判断栈是否是空
bool StackEmpty(ST* pst);

//返回栈的大小
int StackSize(ST* pst);

