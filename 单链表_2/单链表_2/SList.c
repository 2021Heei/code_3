#include "SList.h"

//数据输出到控制台
void SListPrint(SLNode* phead) {
	while (phead) {
		printf("%d ", phead->data);
		phead = phead->next;
	}
	printf("\n");
}

//销毁单链表
void SListDestroy(SLNode** pphead) {
	assert(pphead);
	SLNode* cur = *pphead;
	while (cur) {
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	*pphead = NULL;
}

SLNode* BuyNode(SLTDataType x) {
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (!newnode) {
		perror("newnode\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
}

//头插尾插 头删尾删
void SListPushBack(SLNode** pphead, SLTDataType x) {
	assert(pphead);
	SLNode* newnode = BuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		SLNode* cur = *pphead;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = newnode;
	}
}

void SListPushFront(SLNode** pphead, SLTDataType x) {
	assert(pphead);
	SLNode* newnode = BuyNode(x);
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		newnode->next = *pphead;
		*pphead = newnode;
	}
}

void SListPopBack(SLNode** pphead) {
	assert(pphead);
	assert(*pphead);//为空时不能删了
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		////法1
		//SLNode* cur = *pphead;
		//while (cur->next->next) {
		//	cur = cur->next;
		//}
		//free(cur->next);
		//cur->next = NULL;

		//法2
		SLNode* prev = NULL;
		SLNode* cur = *pphead;
		while (cur->next) {
			prev = cur;
			cur = cur->next;
		}
		free(cur);
		//cur = NULL;
		prev->next = NULL;
	}
}

void SListPopFront(SLNode** pphead) {
	assert(pphead);
	assert(*pphead);
	if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLNode* cur = *pphead;
		*pphead = cur->next;
		free(cur);
		//cur == NULL;
	}
}

//查找数据，找到返回所在节点的地址
SLNode* SListFind(SLNode* phead, SLTDataType x) {
	SLNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//在pos节点之前插入数据
void SListInsert(SLNode** pphead, SLNode* pos, SLTDataType x) {
	assert(pphead);
	assert(*pphead);//单链表为空查不到，强力提醒
	////温柔提醒
	//if (*pphead == NULL) {
	//	return;
	//}
	////法1：遍历链表找到pos前一个再插入
	//if ((*pphead) == pos) {
	//	SLNode* newnode = BuyNode(x);
	//	newnode->next = *pphead;
	//	*pphead = newnode;
	//}
	//else {
	//	SLNode* prev = *pphead;
	//	//找pos前一个位置
	//	while (prev->next != pos) {
	//		prev = prev->next;
	//		//如果prev为NULL，说明遍历完链表也没找到pos，传参错误，暴力检查
	//		assert(prev);
	//	}
	//	SLNode* newnode = BuyNode(x);
	//	newnode->next = pos;
	//	prev->next = newnode;
	//}

	//法2：狸猫换太子，插入到pos后面，在交换两个节点的值
	//这种方法不涉及头指针，更不会改变头指针的值，相比法1减少了对头指针参数的使用
	SLNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
	int tmp = pos->data;
	pos->data = newnode->data;
	newnode->data = tmp;
}


//在pos节点之后插入数据
void SListInsertAfter(SLNode* pos, SLTDataType x) {
	SLNode* newnode = BuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos节点
void SListErase(SLNode** pphead, SLNode* pos) {
	assert(pphead);
	if (*pphead == pos) {
		//头插数据
		SListPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos) {
			prev = prev->next;
			assert(prev);//prev为NULL时说明遍历完链表了，但没有找到pos，说明pos传错了
		}
		SLNode* tmp = pos;
		prev -> next = pos->next;
		//free(tmp);
		//tmp = NULL;把局部变量tmp置为NULL对主调函数的pos无任何影响，调用者应该自己手动置NULL
	}
}
//删除pos节点之后的节点
void SListEraseAfter(SLNode* pos) {
	//pos不为空
	assert(pos);
	//pos->next也不为空
	assert(pos->next);
	SLNode* tmp = pos->next;
	pos->next = tmp->next;
	free(tmp);
	//把局部变量tmp置为NULL对主调函数的pos无任何影响，调用者应该自己手动置NULL
	//tmp = NULL;
}