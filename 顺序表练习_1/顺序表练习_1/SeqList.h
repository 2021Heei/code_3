//条件编译
#ifndef __SEQLIST__H__
#define __SEQLIST__H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//动态顺序表
#define SIZE_INIT 2			//初始化表的大小
#define CAPACITY_INIT 2		//初始化容量
#define MULTIPLE 2			//扩容的倍数
typedef int SLDataType;

typedef struct SeqList {
	SLDataType *data;//
	int size;//当前表的大小
	int capacity;//表的容量
}SL;

//初始化
void SLInit(SL* psl);

//销毁顺序表
void SLDestory(SL* psl);

//打印顺序表
void SLPrint(const SL* psl);

//检查容量并扩容
void SLCheckCapacity(SL* psl);

//尾插尾删 头插头删
void SLPushBack(SL* psl, SLDataType x);
void SLPushFront(SL* psl, SLDataType x);
void SLPopBack(SL* psl);
void SLPopFront(SL* psl);


//查找,找到返回下标，否则返回-1
int FindSL(const SL* psl, SLDataType x);

//在pos位置插入x
void SLInsert(SL* psl, size_t pos, SLDataType x);

//删除pos位置的值
void SLErase(SL* psl, size_t pos);

//修改pos位置的值
void SLModify(SL* psl, size_t pos);
#endif
