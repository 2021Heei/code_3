//#pragma once
//#define _CRT_SECURE_NO_WARNINGS 1
////带头双向循环链表
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <stdbool.h>
//
//typedef int DLTDataType;
//typedef struct DListNode {
//	DLTDataType data;
//	struct DListNode* next;
//	struct DListNdoe* prev;
//}DLTNode;
//
////初始化
////void DListInit(DLTNode** pphead);
//DLTNode* DListInit();
//
////遍历链表，输出数据
//void DListPrint(DLTNode* phead);
//
////销毁链表,一级指针或者二级指针都可以,只不过一级指针下头指针需要在外部被置空
//void DListDestroy(DLTNode* phead);
//
////头插尾插 头删尾删
//void DListPushBack(DLTNode* phead, DLTDataType x);
//void DListPushFront(DLTNode* phead, DLTDataType x);
//void DListPopBack(DLTNode* phead);
//void DListPopFront(DLTNode* phead);
//
////查找数据并返回节点地址
//DLTNode* DListFind(DLTNode* phead, DLTDataType x);
//
////在pos节点插入一个节点
//void DListInsert(DLTNode* pos, DLTDataType x);
//
////删除pos节点
//void DListErase(DLTNode* pos);
//
//int DListLength(DLTNode* phead);