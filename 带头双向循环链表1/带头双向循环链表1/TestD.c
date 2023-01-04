#define _CRT_SECURE_NO_WARNINGS 1
//带头双向循环链表
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int DLTDataType;
typedef struct DListNode {
	DLTDataType data;
	struct DListNode* next;
	struct DListNdoe* prev;
}DLTNode;

//初始化
//void DListInit(DLTNode** pphead);
DLTNode* DListInit();
//遍历链表，输出数据
void DListPrint(DLTNode* phead);
//销毁链表,一级指针或者二级指针都可以,只不过一级指针下头指针需要在外部被置空
void DListDestroy(DLTNode* phead);
//头插尾插 头删尾删
void DListPushBack(DLTNode* phead, DLTDataType x);
void DListPushFront(DLTNode* phead, DLTDataType x);
void DListPopBack(DLTNode* phead);
void DListPopFront(DLTNode* phead);
//查找数据并返回节点地址
DLTNode* DListFind(DLTNode* phead, DLTDataType x);
//在pos节点插入一个节点
void DListInsert(DLTNode* pos, DLTDataType x);
//删除pos节点
void DListErase(DLTNode* pos);
int DListLength(DLTNode* phead);
void SListSort(DLTNode* pguard);
void Insert(DLTNode* pguard, DLTDataType x);

void BackInsert() {
	printf("尾插法创建链表并进行相关操作>\n");
	DLTNode* pguard = DListInit();
	int n = 0, val = 0;
	printf("请输入要尾插的数据个数>");
	scanf("%d", &n);
	printf("请输入要尾插的%d个数据，以空格分隔>", n);
	while (n--) {
		scanf("%d", &val);
		DListPushBack(pguard, val);
	}
	DListPrint(pguard);
	printf("尾插创建的链表成功\n");

	printf("请输入要插入的数据>");
	scanf("%d", &val);
	Insert(pguard, val);
	printf("插入成功，链表为>");

	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));


	printf("请输入要查找的数据>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");

		printf("是否删除元素(y/n)>");
		char option = 0;
		getchar();
		while (scanf("%c", &option) != EOF) {
			if (option == 'y' || option == 'Y') {
				DListErase(ret);
				printf("删除成功!\n");
				break;
			}
			else if (option == 'n' || option == 'N') {
				break;
			}
			else {
				printf("输入错误，请重新输入>");
			}
			getchar();
		}
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
	
	printf("链表元素>");
	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));
	DListDestroy(pguard);
	pguard = NULL;
	printf("尾插创建的链表销毁成功!\n");
	printf("\n");
	printf("\n");
}

void FrontInsert() {
	printf("头插法创建链表并进行相关操作>\n");
	DLTNode* pguard = DListInit();
	int n = 0, val = 0;
	printf("请输入要头插的数据个数>");
	scanf("%d", &n);
	printf("请输入要头插的%d个数据，以空格分隔>", n);

	while (n--) {
		scanf("%d", &val);
		DListPushFront(pguard, val);
	}
	DListPrint(pguard);
	printf("头插创建的链表成功\n");

	printf("请输入要插入的数据>");
	scanf("%d", &val);
	Insert(pguard, val);
	printf("插入成功，链表为>");

	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));


	printf("请输入要查找的数据>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");

		printf("是否删除元素(y/n)>");
		char option = 0;
		getchar();
		while (scanf("%c", &option) != EOF) {
			if (option == 'y' || option == 'Y') {
				DListErase(ret);
				printf("删除成功!\n");
				break;
			}
			else if (option == 'n' || option == 'N') {
				break;
			}
			else {
				printf("输入错误，请重新输入>");
			}
			getchar();
		}
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
	
	printf("链表元素>");
	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));
	DListDestroy(pguard);
	pguard = NULL;
	printf("头插创建的链表销毁成功!\n");
	printf("\n");
	printf("\n");
}

int main() {
	//尾插法
	BackInsert();
	//头插法
	FrontInsert();
	return 0;
}

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
		printf("%d ", cur->data);
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
	while (cur != phead) {
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

void Insert(DLTNode* pguard, DLTDataType x) {
	DListPushBack(pguard, x);
	SListSort(pguard);
}
