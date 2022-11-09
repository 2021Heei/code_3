//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
////本程序大部分通过二级指针实现单向、不循环、无头节点(无哨兵头)的链表
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//
//typedef int SLTDataType;
////节点类型
//typedef struct SListNode {
//	SLTDataType data;
//	struct SListNode* next;
//}SLNode;
//
//
////数据输出到控制台
//void SListPrint(SLNode* phead);
//
////销毁单链表
//void SListDestroy(SLNode** pphead);
//
////申请一个新节点
//SLNode* BuyNode(SLTDataType x);
//
////头插尾插 头删尾删
//void SListPushBack(SLNode** pphead, SLTDataType x);
//void SListPushFront(SLNode** pphead, SLTDataType x);
//void SListPopBack(SLNode** pphead);
//void SListPopFront(SLNode** pphead);
//
////查找数据，找到返回所在节点的地址
//SLNode* SListFind(SLNode* phead, SLTDataType x);
//
////在pos节点之前插入数据
//void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x);
//
////在pos节点之后插入数据
//void SListInsertAfter(SLNode* pos, SLTDataType x);
//
////删除pos节点
//void SListErase(SLNode** pphead, SLNode* pos);
//
////删除pos节点之后的节点
//void SListEraseAfter(SLNode* pos);