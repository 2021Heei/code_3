#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>


//���Ա�ĵ�����洢�ṹ�����ṹ���Զ�����������
typedef int SLDataType;
typedef struct SeqList {
	SLDataType val;
	struct SeqList* next;
}ListNode, * LinkList;

//ͷ��
void CreateListFromHead(LinkList& L, int n);

//β��
void CreateListFromTail(LinkList& L, int n);

//���
void PrintList(LinkList L);

//����
void DestroyList(LinkList& L);


//������
void main() {
	int n; //��
	LinkList L = NULL;
	printf("������Ҫ���������Ա�ĳ���:\n");
	scanf("%d", &n);
	//ͷ�巨����������
	printf("\n��ʼͷ�巨���������������������Ա�ĸ�Ԫ��...\n");
	CreateListFromHead(L, n);
	printf("��������ս��������Ա���Ԫ��:\n");
	PrintList(L);
	DestroyList(L);

	printf("\n");
	printf("������Ҫ���������Ա�ĳ���:\n");
	scanf("%d", &n);
	//β�巨����������
	printf("\n��ʼβ�巨����������˳���������Ա�ĸ�Ԫ��...\n");
	CreateListFromTail(L, n);
	printf("��������ս��������Ա���Ԫ��:\n");
	PrintList(L);
	DestroyList(L);
}

//����һ���½ڵ�
ListNode* GetNewNode(SLDataType val) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode == NULL) {
		perror("GetNewNode");
		exit(-1);
	}
	newnode->val = val;
	newnode->next = NULL;
}

//ͷ��
void CreateListFromHead(LinkList& L, int n) {
	LinkList head = L;
	while (n--) {
		int val = 0;
		scanf("%d", &val);
		ListNode* newnode = GetNewNode(val);
		//����Ϊ�����⴦��
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

//β��
void CreateListFromTail(LinkList& L, int n) {
	LinkList head = L;
	while (n--) {
		int val = 0;
		scanf("%d", &val);
		ListNode* newnode = GetNewNode(val);
		//����Ϊ�����⴦��
		if (head == NULL) {
			head = newnode;
		}
		else {
			//��β
			ListNode* tail = head;
			while (tail->next) {
				tail = tail->next;
			}
			tail->next = newnode;
		}
	}
	L = head;
}

//���
void PrintList(LinkList L) {
	LinkList cur = L;
	while (cur) {
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

//����
void DestroyList(LinkList& L) {
	LinkList cur = L;
	while (cur) {
		LinkList del = cur;
		cur = cur->next;
		free(del);
	}
	L = NULL;
}