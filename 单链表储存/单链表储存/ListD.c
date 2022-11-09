#include "ListD.h"

DLTNode* DListInit() {
	DLTNode* guard = (DLTNode*)malloc(sizeof(DLTNode));
	if (!guard) {
		perror("DListInit");
		exit(-1);
	}
	guard->next = guard;
	guard->prev = guard;
	return guard;
}

//���������������
void DListPrint(DLTNode* phead) {
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur != phead) {
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//��������,һ��ָ����߶���ָ�붼����,ֻ����һ��ָ����ͷָ����Ҫ���ⲿ���ÿ�
void DListDestroy(DLTNode* phead) {
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur != phead) {
		DLTNode* later = cur->next;
		free(cur);
		cur = later;
	}
	free(phead);
	//phead = NULL;
	//�ⲿͷָ����Ҫ���������ⲿ��NULL
}

//����һ���½ڵ�
DLTNode* BuyDLTNode(DLTDataType x) {
	DLTNode* newnode = (DLTNode*)malloc(sizeof(DLTNode));
	if (!newnode) {
		perror("BuyDLTNode");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = newnode->prev = NULL;
	return newnode;
}

//ͷ��β�� ͷɾβɾ
void DListPushBack(DLTNode* phead, DLTDataType x) {
	assert(phead);
	/*DLTNode* newnode = BuyDLTNode(x);
	DLTNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;*/
	DListInsert(phead, x);
}

void DListPushFront(DLTNode* phead, DLTDataType x) {
	assert(phead);
	DLTNode* newnode = BuyDLTNode(x);
	//����1
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;

	////������
	//DLTNode* first = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//
	//newnode->next = first;
	//first->prev = newnode;

	//������
	//DListInsert(phead->next, x);
}

bool DListEmpty(DLTNode* phead) {
	assert(phead);
	return phead->next == phead;
}

void DListPopBack(DLTNode* phead) {
	assert(phead);
	DLTNode* tail = phead->prev;
	DLTNode* last = tail->prev;
	last->next = phead;
	phead->prev = last;
	free(tail);
	//DListErase(phead->prev);
}

void DListPopFront(DLTNode* phead) {
	assert(phead);
	assert(!DListEmpty(phead));
	DLTNode* first = phead->next;
	DLTNode* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
	//first = NULL;	
	DListErase(phead->next);
}

//�������ݲ����ؽڵ��ַ
DLTNode* DListFind(DLTNode* phead, DLTDataType x) {
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//��pos�ڵ����һ���ڵ�
void DListInsert(DLTNode* pos, DLTDataType x) {
	assert(pos);
	DLTNode* newnode = BuyDLTNode(x);
	DLTNode* last = pos->prev;
	last->next = newnode;
	newnode->prev = last;
	newnode->next = pos;
	pos->prev = newnode;
}

//ɾ��pos�ڵ�
void DListErase(DLTNode* pos) {
	assert(pos);
	DLTNode* last = pos->prev;
	DLTNode* later = pos->next;
	last->next = later;
	later->prev = last;
	free(pos);
	//pos = NULL;
}

int DListLength(DLTNode* phead) {
	assert(phead);
	DLTNode* cur = phead->next;
	int cnt = 0;
	while (cur != phead) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

void SListSort(DLTNode* pguard) {
	assert(pguard);
	int count1 = DListLength(pguard);
	int count2 = 0;
	DLTNode* cur, * next;
	for (int i = 0; i < count1; ++i) {
		cur = pguard->next;
		next = cur->next;
		count2 = count1 - i - 1;
		while (count2--) {
			if (cur->data > next->data) {
				//���ݽ���
				DLTDataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
			}
			cur = next;
			next = next->next;
		}
	}
}