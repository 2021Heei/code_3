#include "SeqList.h"

//初始化
void SLInit(SL* psl) {
	assert(psl);
	psl->data = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//打印
void SLPrint(const SL* psl) {
	assert(psl);
	for (int i = 0; i < psl->size; ++i) {
		printf("%d ", psl->data[i]);
	}
	printf("\n");
}

//销毁
void SLDestroy(SL* psl) {
	assert(psl);
	free(psl->data);
	psl->data = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

//检查容量并扩容
void SLCheckCapacity(SL* psl) {
	if (psl->size == psl->capacity) {
		int newcapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->data, sizeof(SLDataType) * newcapacity);
		if (tmp == NULL) {
			return;
		}
		psl->data = tmp;
		psl->capacity = newcapacity;
	}
}

//头插尾插 头删尾删
void SLPushBack(SL* psl, SLDataType x) {
	//assert(psl);
	////检查容量并扩容
	//SLCheckCapacity(psl);
	//psl->data[psl->size] = x;
	//++psl->size;
	SLInsert(psl, psl->size, x);
}

void SLPushFront(SL* psl, SLDataType x) {
	/*assert(psl);
	SLCheckCapacity(psl);

	for (int i = psl->size; i > 0; --i) {
		psl->data[i] = psl->data[i - 1];
	}
	psl->data[0] = x;
	++psl->size;*/
	SLInsert(psl, 0, x);
}

void SLPopBack(SL* psl) {
	assert(psl);
	assert(psl->size > 0);
	//
	/*if (psl->size == 0) {
		return;
	}*/
	--psl->size;
}

void SLPopFront(SL* psl) {
	assert(psl);
	assert(psl->size > 0);
	/*
	if(psl->size == 0){
		return;
	}
	*/
	for (int i = 0; i < psl->size - 1; ++i) {
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;
}

//查找，找到返回下标，否则返回-1
int SLFind(SL* psl, SLDataType x) {
	assert(psl);
	
	for (int i = 0; i < psl->size; ++i) {
		if (psl->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//指定pos位置插入数据x
void SLInsert(SL* psl, size_t pos, SLDataType x){
	assert(psl);
	assert(pos <= psl->size);
	SLCheckCapacity(psl);

	for(int i=psl->size; i > pos; --i){
		psl->data[i] = psl->data[i - 1];
	}
	psl->data[pos] = x;
	++psl->size;
}

//指定pos位置删除数据x
void SLErase(SL* psl, size_t pos) {
	assert(psl);
	assert(pos < psl->size);

	for (int i = pos; i < psl->size - 1; ++i) {
		psl->data[i] = psl->data[i + 1];
	}
	--psl->size;
}

//指定pos位置并修改数据
void SLModify(SL* psl, size_t pos, SLDataType x) {
	assert(psl);
	assert(pos < psl->size);
	psl->data[pos] = x;
}