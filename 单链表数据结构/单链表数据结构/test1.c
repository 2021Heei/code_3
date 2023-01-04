#define _CRT_SECURE_NO_WARNINGS 1
//带头双向循环链表
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

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
void DListEraseIndex(DLTNode* pguard, int index);
//删除pos节点
void DListErase(DLTNode* pos);
int DListLength(DLTNode* phead);
void DListSort(DLTNode* pguard);
void DInsert(DLTNode* pguard, DLTDataType x);



DLTNode* DBackInsert() {
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
	return pguard;
}

DLTNode* DFrontInsert() {
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
	return pguard;
}

typedef int SLTDataType;
//节点类型
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLNode;


//初始化哨兵头结点
void SListInit(SLNode* pguard);
//数据输出到控制台
void SListPrint(SLNode* pguard);
//销毁单链表
void SListDestroy(SLNode* pguard);
//申请一个新节点
SLNode* BuyNode(SLTDataType x);
//头插尾插 头删尾删
void SListPushBack(SLNode* pguard, SLTDataType x);
void SListPushFront(SLNode* pguard, SLTDataType x);
void SListPopBack(SLNode* pguard);
void SListPopFront(SLNode* pguard);
//查找数据，找到返回所在节点的地址
SLNode* SListFind(SLNode* pguard, SLTDataType x);
//删除pos节点
void SListErase(SLNode* pguard, SLNode* pos);
void SListEraseIndex(SLNode* pguard, int index);
int SListLength(SLNode* pguard);
void SListSort(SLNode* pguard);
void SInsert(SLTDataType val);


void SBackInsert(SLNode* pguard) {
	printf("尾插法创建链表并进行相关操作>\n");
	SListInit(pguard);
	int n = 0, val = 0;
	printf("请输入要尾插的数据个数>");
	scanf("%d", &n);
	printf("请输入要尾插的%d个数据，以空格分隔>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushBack(pguard, val);
	}
	SListPrint(pguard);
	printf("尾插创建的链表成功\n");
}

void SFrontInsert(SLNode* pguard) {
	printf("头插法创建链表并进行相关操作>\n");
	SListInit(pguard);
	int n = 0, val = 0;
	printf("请输入要头插的数据个数>");
	scanf("%d", &n);
	printf("请输入要头插的%d个数据，以空格分隔>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushFront(pguard, val);
	}
	SListPrint(pguard);
	printf("头插创建的链表成功\n");
}

void menu1() {
	system("cls");
	printf("******************************************\n");
	printf("****     1.单链表      2.双向链表     ****\n");
	printf("****          0.退出程序              ****\n");
	printf("******************************************\n");
}

void menu2() {
	system("cls");
	printf("**********************************************\n");
	printf("****     1.头插法        2.尾插法         ****\n");
	printf("****     3.插入数据      4.查找           ****\n");
	printf("****     5.删除          6.链表长度       ****\n");
	printf("****     7.销毁链表      8.输出链表元素   ****\n");
	printf("****          0.返回上一级                ****\n");
	printf("**********************************************\n");
}

void menu3() {
	system("cls");
	printf("**********************************************\n");
	printf("****     1.头插法        2.尾插法         ****\n");
	printf("****     3.插入数据      4.查找           ****\n");
	printf("****     5.删除          6.链表长度       ****\n");
	printf("****     7.销毁链表      8.输出链表元素   ****\n");
	printf("****          0.返回上一级                ****\n");
	printf("**********************************************\n");
}
void InsertS(SLNode* pguard) {
	int val;
	printf("请输入要插入的数据>");
	scanf("%d", &val);
	SInsert(pguard, val);
	printf("插入成功");
}
void FindS(SLNode* pguard) {
	int val;
	printf("请输入要查找的数据>");
	scanf("%d", &val);
	SLNode* ret = SListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
}
void EraseS(SLNode* pguard) {
	printf("请输入要删除的元素位置>");
	int index;
	scanf("%d", &index);
	SListEraseIndex(pguard, index);
	printf("删除成功!\n");
}
void Smenu() {
	int option;
	SLNode guard;
	guard.next = NULL;
	do {
		getchar();
		system("pause");
		menu2();
		printf("请输入你的选择>");
		scanf("%d", &option);
		switch (option) {
		case 1:
			SFrontInsert(&guard);
			break;
		case 2:
			SBackInsert(&guard);
			break;
		case 3:
			InsertS(&guard);
			break;
		case 4:
			FindS(&guard);
			break;
		case 5:
			EraseS(&guard);
			break;
		case 6:
			printf("链表的长度为> %d\n", SListLength(&guard));
			break;
		case 7:
			SListDestroy(&guard);
			printf("链表销毁成功!\n");
			break;
		case 8:
			SListPrint(&guard);
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("输入错误，请重新输入>");
			break;
		}
	} while (option);
}

void InsertD(DLTNode* pguard) {
	printf("请输入要插入的数据>");
	int val;
	scanf("%d", &val);
	DInsert(pguard, val);
	printf("插入成功");
}

void FindD(DLTNode* pguard) {
	printf("请输入要查找的数据>");
	int val;
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
}

void EraseD(DLTNode* pguard) {
	printf("请输入要删除的元素位置>");
	int index;
	scanf("%d", &index);
	DListEraseIndex(pguard, index);
	printf("删除成功!\n");
}

void Dmenu() {
	int option;
	DLTNode* pguard = NULL;

	do {
		getchar();
		system("pause");
		menu3();
		printf("请输入你的选择>");
		scanf("%d", &option);
		switch (option) {
		case 1:
			pguard = DFrontInsert();
			break;
		case 2:
			pguard = DBackInsert();
			break;
		case 3:
			InsertD(pguard);
			break;
		case 4:
			FindD(pguard);
			break;
		case 5:
			EraseD(pguard);
			break;
		case 6:
			printf("链表的长度为> %d\n", DListLength(pguard));
			break;
		case 7:
			DListDestroy(pguard);
			printf("链表销毁成功!\n");
			break;
		case 8:
			DListPrint(pguard);
			break;
		case 0:
			printf("返回上一级\n");
			break;
		default:
			printf("输入错误，请重新输入>");
			break;
		}
	} while (option);
}
int main() {
	int option;
	do {
		menu1();
		printf("请输入你的选择>");
		scanf("%d", &option);
		switch (option) {
		case 1:
			Smenu();
			break;
		case 2:
			Dmenu();
			break;
		case 0:
			printf("程序退出\n");
			break;
		default:
			printf("输入错误，请重新输入>");
			break;
		}
	} while (option);
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
	while (cur && cur != phead) {
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


//删除index位置
void DListEraseIndex(DLTNode* pguard, int index) {
	assert(pguard);
	DLTNode* prev = pguard;
	int length = DListLength(pguard);
	if (index >= 0 && index < length) {
		while (index--) {
			prev = prev->next;
		}
		DLTNode* tmp = prev->next;
		prev->next = tmp->next;
		free(tmp);
	}
	else {
		printf("该位置不存在");
	}
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

void DListSort(DLTNode* pguard) {
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

void DInsert(DLTNode* pguard, DLTDataType x) {
	DListPushBack(pguard, x);
	DListSort(pguard);
}



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
	assert(pguard);
	//暴力检查
	assert(pguard->next);

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

//删除index位置
void SListEraseIndex(SLNode* pguard, int index) {
	assert(pguard);
	SLNode* prev = pguard;
	int length = SListLength(pguard);
	if (index >= 0 && index < length) {
		while (index--) {
			prev = prev->next;
		}
		SLNode* tmp = prev->next;
		prev->next = tmp->next;
		free(tmp);
	}
	else {
		printf("该位置不存在");
	}
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
	SLNode* cur, * next;
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

void SInsert(SLNode* pguard, SLTDataType val) {
	SListPushBack(pguard, val);
	SListSort(pguard);
}
