#include "Stack.h"

//��ʼ��
void StackInit(Stack* pst) {
	assert(pst);
	pst->pdata = NULL;
	pst->top = pst->capacity = 0;//ջ����ʼΪ0
}

//����ջ
void StackDestroy(Stack* pst) {
	assert(pst);
	free(pst->pdata);
	pst->top = pst->capacity = 0;
}

//��ӡջ��ջ��ʧ
void StackPrint(Stack* pst) {
	assert(pst);
	while (!StackEmpty(pst)) {
		printf("%d ", StackTop(pst));
		StackPop(pst);
	}
	printf("\n");
}

//��ջ
void StackPush(Stack* pst, STDataType val) {
	assert(pst);
	//�������
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

//��ջ
void StackPop(Stack* pst) {
	assert(pst);
	assert(!StackEmpty(pst));
	--pst->top;
}

//ȡջ��Ԫ��
STDataType StackTop(Stack* pst) {
	assert(pst);
	assert(!StackEmpty(&pst));
	return pst->pdata[pst->top - 1];
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(Stack* pst) {
	assert(pst);
	return pst->top == 0;
}

//����ջ�Ĵ�С
int StackSize(Stack* pst) {
	assert(pst);
	return pst->top;
}