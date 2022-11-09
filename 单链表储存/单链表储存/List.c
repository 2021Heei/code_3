#include "List.h"

void SListInit(SLNode* pguard) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	pguard->next = NULL;
}

//数据输出到控制台
void SListPrint(SLNode* pguard) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	SLNode* cur = pguard->next;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//销毁单链表
void SListDestroy(SLNode* pguard) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	SLNode* cur = pguard->next;
	while (cur) {
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pguard->next = NULL;
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
void SListPushBack(SLNode* pguard, SLTDataType x) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	SLNode* newnode = BuyNode(x);
	SLNode* cur = pguard;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = newnode;
}

void SListPushFront(SLNode* pguard, SLTDataType x) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	SLNode* newnode = BuyNode(x);
	newnode->next = pguard->next;
	pguard->next = newnode;
}

void SListPopBack(SLNode* pguard) {
	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
	assert(pguard);
	//暴力检查
	assert(pguard->next);
	//温柔检查
	//if(*pguard->next == NULL){
	//    return;   
	//}

	//法2
	SLNode* cur = pguard;
	while (cur->next->next) {
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListPopFront(SLNode* pguard) {
	assert(pguard);
	//暴力检查
	assert(pguard->next);
	//温柔检查
	//if(pguard->next == NULL){
	//    return;   
	//}

	SLNode* del = pguard->next;
	pguard->next = del->next;
	free(del);
	//del == NULL;	
}

//查找数据，找到返回所在节点的地址
SLNode* SListFind(SLNode* pguard, SLTDataType x) {
	assert(pguard);
	SLNode* cur = pguard->next;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

//删除pos节点
void SListErase(SLNode* pguard, SLNode* pos) {
	assert(pguard);
	SLNode* prev = pguard;
	while (prev->next != pos) {
		prev = prev->next;
		assert(prev);//prev为NULL时说明遍历完链表了，但没有找到pos，说明pos传错了
	}
	prev->next = pos->next;
	free(pos);
	//pos = NULL;把局部变量tmp置为NULL对主调函数的pos无任何影响，调用者应该自己手动置NULL
}

int SListLength(SLNode* pguard) {
	assert(pguard);
	SLNode* cur = pguard->next;
	int cnt = 0;
	while (cur) {
		cnt++;
		cur = cur->next;
	}
	return cnt;
}

void SListSort(SLNode* pguard) {
	assert(pguard);
	int count1 = SListLength(pguard);
	int count2 = 0;
	SLNode *cur, *next;
	for (int i = 0; i < count1; ++i) {
		cur = pguard->next;
		next = cur->next;
		count2 = count1 - i - 1;
		while (count2--) {
			if (cur->data > next->data) {
				//交换
				SLTDataType tmp = cur->data;
				cur->data = next->data;
				next->data = tmp;
			}
			cur = next;
			next = next->next;
		}
	}
}