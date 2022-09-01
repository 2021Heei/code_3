#ifndef __SEQLIST__H__
#define __SEQLIST__H__
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int SLDataType;

//封装顺序表结构体类型
typedef struct SeqList{
	SLDataType *data;
	int size;
	int capacity;
}SL;

//初始化
void SLInit(SL* psl);

//打印
void SLPrint(const SL* psl);

//销毁
void SLDestroy(SL* psl);

//检查容量并扩容
void SLCheckCapacity(SL* psl);

//头插尾插 头删尾删
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);

//查找，找到返回下标，否则返回-1
int SLFind(SL* psl, size_t pos);

//指定pos位置插入数据x
void SLInsert(SL* psl, size_t pos, SLDataType x);

//指定pos位置删除数据x
void SLErase(SL* psl, size_t pos);

//指定pos位置并修改数据
void SLModify(SL* psl, size_t pos, SLDataType x);

#endif
