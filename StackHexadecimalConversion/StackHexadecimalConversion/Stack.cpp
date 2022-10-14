#include "Stack.h"
//��ʼ��
void StackInit(ST* pst) {
	assert(pst);
	pst->data = NULL;
	pst->top = pst->capacity = 0;
}

//����ջ
void StackDestroy(ST* pst) {
	assert(pst);
	free(pst->data);
	pst->top = pst->capacity = 0;
}

//��ջ
void StackPush(ST* pst, STDataType val) {
	assert(pst);
	//����
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

//��ջ
void StackPop(ST* pst) {
	assert(pst);
	assert(!StackEmpty(pst));
	--pst->top;
}

//ȡ��ջ��Ԫ��
STDataType StackTop(ST* pst) {
	assert(pst);
	return pst->data[pst->top - 1];
}

//�ж�ջ�Ƿ��ǿ�
bool StackEmpty(ST* pst) {
	assert(pst);
	return pst->top == 0;
}

//����ջ�Ĵ�С
int StackSize(ST* pst) {
	assert(pst);
	return pst->top;
}
