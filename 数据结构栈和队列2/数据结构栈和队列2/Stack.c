#include "Stack.h"

//初始化
void StackInit(Stack* pst) {
	assert(pst);
	pst->pdata = NULL;
	pst->top = pst->capacity = 0;//栈顶初始为0
}

//销毁栈
void StackDestroy(Stack* pst) {
	assert(pst);
	free(pst->pdata);
	pst->top = pst->capacity = 0;
}

//打印栈，栈消失
void StackPrint(Stack* pst) {
	assert(pst);
	while (!StackEmpty(pst)) {
		printf("%d ", StackTop(pst));
		StackPop(pst);
	}
	printf("\n");
}

//入栈
void StackPush(Stack* pst, STDataType val) {
	assert(pst);
	//检查扩容
	if (pst->top == pst->capacity) {
		int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->pdata, sizeof(STDataType) * newCapacity);
		if(!tmp){
			perror("realloc file");
			exit(-1);
		}
		pst->pdata = tmp;
		pst->capacity = newCapacity;
	}
	pst->pdata[pst->top] = val;
	++pst->top;
}

//出栈
void StackPop(Stack* pst) {
	assert(pst);
	assert(!StackEmpty(pst));
	--pst->top;
}

//取栈顶元素
STDataType StackTop(Stack* pst) {
	assert(pst);
	assert(!StackEmpty(&pst));
	return pst->pdata[pst->top - 1];
}

//判断栈是否为空
bool StackEmpty(Stack* pst) {
	assert(pst);
	return pst->top == 0;
}

//计算栈的大小
int StackSize(Stack* pst) {
	assert(pst);
	return pst->top;
}