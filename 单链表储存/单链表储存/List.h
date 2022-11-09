#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
/*
*	带头结点的单链表
*	函数接口设计为接受头结点的地址
*	实现思路：在main函数内部定义局部头结点变量，每次取局部头结点变量地址传入函数接口
*	功能：头插法和尾插法创建单链表；
*		  单链表元素排序
*		  在单链表中查找元素，找到就返回节点指针，否则返回NULL
*		  删除节点元素
*		  得到链表长度
*		  销毁单链表
*		  
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLTDataType;
//节点类型
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLNode;

//初始化哨兵头结点
void SListInit(SLNode* pguard);

//数据输出到控制台
void SListPrint(SLNode* pguard);

//销毁单链表
void SListDestroy(SLNode* pguard);

//申请一个新节点
SLNode* BuyNode(SLTDataType x);

//头插尾插 头删尾删
void SListPushBack(SLNode* pguard, SLTDataType x);
void SListPushFront(SLNode* pguard, SLTDataType x);
void SListPopBack(SLNode* pguard);
void SListPopFront(SLNode* pguard);

//查找数据，找到返回所在节点的地址
SLNode* SListFind(SLNode* pguard, SLTDataType x);

//删除pos节点
void SListErase(SLNode* pguard, SLNode* pos);

//链表长度
int SListLength(SLNode* pguard);

//链表排序 - 从小到大
void SListSort(SLNode* pguard);