#include "Stack.h"
//初始化
void StackInit(ST* pst) {
	assert(pst);
	pst->data = NULL;
	pst->top = pst->capacity = 0;
}

//销毁栈
void StackDestroy(ST* pst) {
	assert(pst);
	free(pst->data);
	pst->top = pst->capacity = 0;
}

//入栈
void StackPush(ST* pst, STDataType val) {
	assert(pst);
	//扩容
	if (pst->top == pst->capacity) {
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType) * newCapacity);
		if (!tmp) {
			perror("StackPush");
		}
		pst->data = tmp;
		pst->capacity = newCapacity;
	}
	pst->data[pst->top] = val;
	++pst->top;
}

//出栈
void StackPop(ST* pst) {
	assert(pst);
	assert(!StackEmpty(pst));
	--pst->top;
}

//取出栈顶元素
STDataType StackTop(ST* pst) {
	assert(pst);
	return pst->data[pst->top - 1];
}

//判断栈是否是空
bool StackEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;
}

//返回栈的大小
int StackSize(ST* pst) {
	assert(pst);
	return pst->top;
}
