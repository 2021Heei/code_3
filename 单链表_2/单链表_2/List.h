//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
//
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
////初始化哨兵头结点
//void SListInit(SLNode* pguard);
//
////数据输出到控制台
//void SListPrint(SLNode* pguard);
//
////销毁单链表
//void SListDestroy(SLNode* pguard);
//
////申请一个新节点
//SLNode* BuyNode(SLTDataType x);
//
////头插尾插 头删尾删
//void SListPushBack(SLNode* pguard, SLTDataType x);
//void SListPushFront(SLNode* pguard, SLTDataType x);
//void SListPopBack(SLNode* pguard);
//void SListPopFront(SLNode* pguard);
//
////查找数据，找到返回所在节点的地址
//SLNode* SListFind(SLNode* pguard, SLTDataType x);
//
////删除pos节点
//void SListErase(SLNode* pguard, SLNode* pos);
//
//int SListLength(SLNode* pguard);
//
//void SListSort(SLNode* pguard);
//
//void Insert(SLTDataType val);