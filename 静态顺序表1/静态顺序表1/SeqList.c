#include "SeqList.h"

//初始化顺序表
void SLInit(SL* phead) {
	assert(phead);
	memset(phead, 0, sizeof(SL));
}

//输出顺序表
void SLPrint(const SL* phead) {
	assert(phead);
	for (int i = 0; i < phead->size; ++i) {
		printf("%d ", phead->data[i]);
	}
	printf("\n");
}

//销毁顺序表
void SLDestroy(SL* phead) {
	assert(phead);
	phead->size = 0;
	memset(phead, 0, sizeof(SL));
}

//头插尾插 头删尾删
void SLPushBack(SL* phead, SLDataType x) {
	assert(phead);
	//暴力检查，当顺序表已经满时，尝试增加数据的操作会导致报错
	assert(phead->size < INITCAPACITY);
	phead->data[phead->size] = x;
	++phead->size;

}

void SLPushFront(SL* phead, SLDataType x) {
	assert(phead);
	//暴力检查，当顺序表已经满时，尝试增加数据的操作会导致报错
	assert(phead->size < INITCAPACITY);
	for (int i = phead->size; i > 0; --i) {
		phead->data[i] = phead->data[i - 1];
	}
	phead->data[0] = x;
	phead->size++;
}

void SLPopBack(SL* phead) {
	assert(phead);
	//暴力检查，当顺序表已经为空时，在尝试进行删除操作将会报错
	assert(phead->size > 0);
	--phead->size;
}

void SLPopFront(SL* phead) {
	assert(phead);
	//暴力检查，当顺序表已经为空时，在尝试进行删除操作将会报错
	assert(phead->size > 0);
	for (int i = 0; i < phead->size - 1; ++i) {
		phead->data[i] = phead->data[i + 1];
	}
	--phead->size;
}


//查找元素,找到就返回下标，否则返回-1
int SLFind(const SL* phead, SLDataType x) {
	assert(phead);
	for (int i = 0; i < phead->size; ++i) {
		if (phead->data[i] == x) {
			return i;
		}
	}
	return -1;
}

//修改pos位置元素
void SLModify(SL* phead, size_t pos, SLDataType x) {
	assert(phead);
	//暴力检查，当传入的下标越界时就报错
	assert(pos < phead->size);
	phead->data[pos] = x;
}

//在pos位置前增加一个数据元素
void SLInsert(SL* phead, size_t pos, SLDataType x) {
	assert(phead);
	//暴力检查，当传入的下标越界时就报错
	assert(pos <= phead->size && phead->size < INITCAPACITY);
	for (int i = phead->size; i > pos; --i) {
		phead->data[i] = phead->data[i - 1];
	}
	phead->data[pos] = x;
	++phead->size;
}

//删除pos位置的数据
void SLErase(SL* phead, size_t pos) {
	assert(phead);
	for (int i = pos; i < phead->size - 1; ++i) {
		phead->data[i] = phead->data[i + 1];
	}
	--phead->size;
}

//使用接口SLInsert()、SLErase()的头插尾插、头删尾删

void SLPushBack2(SL* phead, SLDataType x) {
	SLInsert(phead, phead->size, x);
}

void SLPushFront2(SL* phead, SLDataType x) {
	SLInsert(phead, 0, x);
}

void SLPopBack2(SL* phead) {
	SLErase(phead, phead->size - 1);
}

void SLPopFront2(SL* phead) {
	SLErase(phead, 0);
}