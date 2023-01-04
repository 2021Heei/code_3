#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode {
	SLTDataType data;
	struct SList* next;
}SLTNode;

//输出
void SListPrint(SLTNode* phead);

//销毁
void SListDestroy(SLTNode** pphead);

//头插尾插 头删尾删
void SListPushFront(SLTNode** pphead, SLTDataType x);
void SListPushBack(SLTNode** pphead, SLTDataType x);
void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

//查找，不改变传入的头指针plist，可以不使用二级指针
SLTNode* SListFind(SLTNode* phead, SLTDataType x);

//在pos节点前插入一个新节点,只有一个结点时需要改变头指针plist，故需要二级指针
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);

//在pos节点后插入一个新节点
//关于传入的是结点地址，接受的是结构体指针，指向了结点
void SListInsertAfter(SLTNode* pos, SLTDataType x);

//删除pos节点
void SListErase(SLTNode** pphead, SLTNode* pos);

//删除pos结点的后一个结点
void SListEraseAfter(SLTNode* pos);

//修改pos节点的数据

