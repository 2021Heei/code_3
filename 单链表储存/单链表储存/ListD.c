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

//遍历链表，输出数据
void DListPrint(DLTNode* phead) {
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur != phead) {
		printf("%d<==>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//销毁链表,一级指针或者二级指针都可以,只不过一级指针下头指针需要在外部被置空
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
	//外部头指针需要调用者在外部置NULL
}

//申请一个新节点
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

//头插尾插 头删尾删
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
	//方法1
	newnode->next = phead->next;
	phead->next->prev = newnode;
	phead->next = newnode;
	newnode->prev = phead;

	////方法二
	//DLTNode* first = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//
	//newnode->next = first;
	//first->prev = newnode;

	//方法三
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

//查找数据并返回节点地址
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

//在pos节点插入一个节点
void DListInsert(DLTNode* pos, DLTDataType x) {
	assert(pos);
	DLTNode* newnode = BuyDLTNode(x);
	DLTNode* last = pos->prev;
	last->next = newnode;
	newnode->prev = last;
	newnode->next = pos;
	pos->prev = newnode;
}

//删除pos节点
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
				//数据交换
				DLTDataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
			}
			cur = next;
			next = next->next;
		}
	}
}