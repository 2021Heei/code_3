#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>


//线性表的单链表存储结构：结点结构及自定义数据类型
typedef int SLDataType;
typedef struct SeqList {
	SLDataType val;
	struct SeqList* next;
}ListNode, * LinkList;

//头插
void CreateListFromHead(LinkList& L, int n);

//尾插
void CreateListFromTail(LinkList& L, int n);

//输出
void PrintList(LinkList L);

//销毁
void DestroyList(LinkList& L);


//主函数
void main() {
	int n; //表长
	LinkList L = NULL;
	printf("请输入要建立的线性表的长度:\n");
	scanf("%d", &n);
	//头插法建立单链表
	printf("\n开始头插法建单链表，请逆序输入线性表的各元素...\n");
	CreateListFromHead(L, n);
	printf("下面输出刚建立的线性表中元素:\n");
	PrintList(L);
	DestroyList(L);

	printf("\n");
	printf("请输入要建立的线性表的长度:\n");
	scanf("%d", &n);
	//尾插法建立单链表
	printf("\n开始尾插法建单链表，请顺序输入线性表的各元素...\n");
	CreateListFromTail(L, n);
	printf("下面输出刚建立的线性表中元素:\n");
	PrintList(L);
	DestroyList(L);
}

//申请一个新节点
ListNode* GetNewNode(SLDataType val) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("GetNewNode");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
}

//头插
void CreateListFromHead(LinkList& L, int n) {
	LinkList head = L;
	while (n--) {
		int val = 0;
		scanf("%d", &val);
		ListNode* newnode = GetNewNode(val);
		//链表为空特殊处理
		if (head == NULL) {
			head = newnode;
		}
		else {
			newnode->next = head;
			head = newnode;
		}
	}
	L = head;
}

//尾插
void CreateListFromTail(LinkList& L, int n) {
	LinkList head = L;
	while (n--) {
		int val = 0;
		scanf("%d", &val);
		ListNode* newnode = GetNewNode(val);
		//链表为空特殊处理
		if (head == NULL) {
			head = newnode;
		}
		else {
			//找尾
			ListNode* tail = head;
			while (tail->next) {
				tail = tail->next;
			}
			tail->next = newnode;
		}
	}
	L = head;
}

//输出
void PrintList(LinkList L) {
	LinkList cur = L;
	while (cur) {
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//销毁
void DestroyList(LinkList& L) {
	LinkList cur = L;
	while (cur) {
		LinkList del = cur;
		cur = cur->next;
		free(del);
	}
	L = NULL;
}