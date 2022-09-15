#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//后进先出
//顺序表栈
typedef int STDataType;
typedef struct Stack {
	STDataType* pdata;
	int top;//栈顶
	int capacity;
}Stack;

//初始化
void StackInit(Stack* pst);

//销毁栈
void StackDestroy(Stack* pst);

//打印栈，栈消失
void StackPrint(Stack* pst);

//入栈
void StackPush(Stack* pst, STDataType val);

//出栈
void StackPop(Stack* pst);

//取栈顶元素
STDataType StackTop(Stack* pst);

//判断栈是否为空
bool StackEmpty(Stack* pst);

//计算栈的大小
int StackSize(Stack* pst);