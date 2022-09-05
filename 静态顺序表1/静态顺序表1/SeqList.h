#pragma once
#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

#define INITCAPACITY 1000//容量
typedef int SLDataType;

typedef struct SeqList {
	SLDataType data[INITCAPACITY];
	int size;//静态顺序表大小
}SL;

//初始化顺序表
void SLInit(SL* phead);

//输出顺序表
void SLPrint(const SL* phead);

//销毁顺序表
void SLDestroy(SL* phead);


//头插尾插 头删尾删
void SLPushBack(SL* phead, SLDataType x);
void SLPushFront(SL* phead, SLDataType x);
void SLPopBack(SL* phead);
void SLPopFront(SL* phead);

//查找pos位置元素,找到就返回下标，否则返回-1
int SLFind(const SL* phead, SLDataType x);

//修改pos位置元素
void SLModify(SL* phead, size_t pos, SLDataType x);

//在pos位置前增加一个数据元素
void SLInsert(SL* phead, size_t pos, SLDataType x);

//删除pos位置的数据
void SLErase(SL* phead, size_t pos);

//使用接口SLInsert()、SLErase()的头插尾插、头删尾删
void SLPushBack2(SL* phead, SLDataType x);
void SLPushFront2(SL* phead, SLDataType x);
void SLPopBack2(SL* phead);
void SLPopFront2(SL* phead);