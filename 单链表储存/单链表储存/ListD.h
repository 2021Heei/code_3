#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
*	待头结点的单链表
*	函数接口设计为接受头结点的地址
*	实现思路：在main函数内部定义局部头结点指针变量，头结点由一个初始化函数完动态申请，成功就返回头结点地址，失败返回NULL；每次传入函数接口的是局部节点指针变量
*	功能：头插法和尾插法创建单链表；
*		  单链表元素排序
*		  在单链表中查找元素，找到就返回节点指针，否则返回NULL
*		  删除节点元素
*		  得到链表长度
*		  销毁单链表
*
*/

//带头双向循环链表
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DLTDataType;
typedef struct DListNode {
	DLTDataType data;
	struct DListNode* next;
	struct DListNdoe* prev;
}DLTNode;

//初始化
DLTNode* DListInit();

//遍历链表，输出数据
void DListPrint(DLTNode* phead);

//销毁链表,一级指针或者二级指针都可以,只不过一级指针下头指针需要在外部被置空
void DListDestroy(DLTNode* phead);

//头插尾插 头删尾删
void DListPushBack(DLTNode* phead, DLTDataType x);
void DListPushFront(DLTNode* phead, DLTDataType x);
void DListPopBack(DLTNode* phead);
void DListPopFront(DLTNode* phead);

//查找数据并返回节点地址
DLTNode* DListFind(DLTNode* phead, DLTDataType x);

//在pos节点插入一个节点
void DListInsert(DLTNode* pos, DLTDataType x);

//删除pos节点
void DListErase(DLTNode* pos);

//双向链表的长度
int DListLength(DLTNode* phead);

//链表元素排序 - 从小到大
void SListSort(DLTNode* pguard);