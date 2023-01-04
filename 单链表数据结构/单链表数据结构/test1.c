#define _CRT_SECURE_NO_WARNINGS 1
//��ͷ˫��ѭ������
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

//��ʼ��
//void DListInit(DLTNode** pphead);
DLTNode* DListInit();
//���������������
void DListPrint(DLTNode* phead);
//��������,һ��ָ����߶���ָ�붼����,ֻ����һ��ָ����ͷָ����Ҫ���ⲿ���ÿ�
void DListDestroy(DLTNode* phead);
//ͷ��β�� ͷɾβɾ
void DListPushBack(DLTNode* phead, DLTDataType x);
void DListPushFront(DLTNode* phead, DLTDataType x);
void DListPopBack(DLTNode* phead);
void DListPopFront(DLTNode* phead);
//�������ݲ����ؽڵ��ַ
DLTNode* DListFind(DLTNode* phead, DLTDataType x);
//��pos�ڵ����һ���ڵ�
void DListInsert(DLTNode* pos, DLTDataType x);
void DListEraseIndex(DLTNode* pguard, int index);
//ɾ��pos�ڵ�
void DListErase(DLTNode* pos);
int DListLength(DLTNode* phead);
void DListSort(DLTNode* pguard);
void DInsert(DLTNode* pguard, DLTDataType x);



DLTNode* DBackInsert() {
	printf("β�巨��������������ز���>\n");
	DLTNode* pguard = DListInit();
	int n = 0, val = 0;
	printf("������Ҫβ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫβ���%d�����ݣ��Կո�ָ�>", n);
	while (n--) {
		scanf("%d", &val);
		DListPushBack(pguard, val);
	}
	DListPrint(pguard);
	printf("β�崴��������ɹ�\n");
	return pguard;
}

DLTNode* DFrontInsert() {
	printf("ͷ�巨��������������ز���>\n");
	DLTNode* pguard = DListInit();
	int n = 0, val = 0;
	printf("������Ҫͷ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫͷ���%d�����ݣ��Կո�ָ�>", n);

	while (n--) {
		scanf("%d", &val);
		DListPushFront(pguard, val);
	}
	DListPrint(pguard);
	printf("ͷ�崴��������ɹ�\n");
	return pguard;
}

typedef int SLTDataType;
//�ڵ�����
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;
}SLNode;


//��ʼ���ڱ�ͷ���
void SListInit(SLNode* pguard);
//�������������̨
void SListPrint(SLNode* pguard);
//���ٵ�����
void SListDestroy(SLNode* pguard);
//����һ���½ڵ�
SLNode* BuyNode(SLTDataType x);
//ͷ��β�� ͷɾβɾ
void SListPushBack(SLNode* pguard, SLTDataType x);
void SListPushFront(SLNode* pguard, SLTDataType x);
void SListPopBack(SLNode* pguard);
void SListPopFront(SLNode* pguard);
//�������ݣ��ҵ��������ڽڵ�ĵ�ַ
SLNode* SListFind(SLNode* pguard, SLTDataType x);
//ɾ��pos�ڵ�
void SListErase(SLNode* pguard, SLNode* pos);
void SListEraseIndex(SLNode* pguard, int index);
int SListLength(SLNode* pguard);
void SListSort(SLNode* pguard);
void SInsert(SLTDataType val);


void SBackInsert(SLNode* pguard) {
	printf("β�巨��������������ز���>\n");
	SListInit(pguard);
	int n = 0, val = 0;
	printf("������Ҫβ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫβ���%d�����ݣ��Կո�ָ�>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushBack(pguard, val);
	}
	SListPrint(pguard);
	printf("β�崴��������ɹ�\n");
}

void SFrontInsert(SLNode* pguard) {
	printf("ͷ�巨��������������ز���>\n");
	SListInit(pguard);
	int n = 0, val = 0;
	printf("������Ҫͷ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫͷ���%d�����ݣ��Կո�ָ�>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushFront(pguard, val);
	}
	SListPrint(pguard);
	printf("ͷ�崴��������ɹ�\n");
}

void menu1() {
	system("cls");
	printf("******************************************\n");
	printf("****     1.������      2.˫������     ****\n");
	printf("****          0.�˳�����              ****\n");
	printf("******************************************\n");
}

void menu2() {
	system("cls");
	printf("**********************************************\n");
	printf("****     1.ͷ�巨        2.β�巨         ****\n");
	printf("****     3.��������      4.����           ****\n");
	printf("****     5.ɾ��          6.������       ****\n");
	printf("****     7.��������      8.�������Ԫ��   ****\n");
	printf("****          0.������һ��                ****\n");
	printf("**********************************************\n");
}

void menu3() {
	system("cls");
	printf("**********************************************\n");
	printf("****     1.ͷ�巨        2.β�巨         ****\n");
	printf("****     3.��������      4.����           ****\n");
	printf("****     5.ɾ��          6.������       ****\n");
	printf("****     7.��������      8.�������Ԫ��   ****\n");
	printf("****          0.������һ��                ****\n");
	printf("**********************************************\n");
}
void InsertS(SLNode* pguard) {
	int val;
	printf("������Ҫ���������>");
	scanf("%d", &val);
	SInsert(pguard, val);
	printf("����ɹ�");
}
void FindS(SLNode* pguard) {
	int val;
	printf("������Ҫ���ҵ�����>");
	scanf("%d", &val);
	SLNode* ret = SListFind(pguard, val);
	if (ret) {
		printf("���ҳɹ�!\n");
	}
	else {
		printf("�����в�����%d!\n", val);
	}
}
void EraseS(SLNode* pguard) {
	printf("������Ҫɾ����Ԫ��λ��>");
	int index;
	scanf("%d", &index);
	SListEraseIndex(pguard, index);
	printf("ɾ���ɹ�!\n");
}
void Smenu() {
	int option;
	SLNode guard;
	guard.next = NULL;
	do {
		getchar();
		system("pause");
		menu2();
		printf("���������ѡ��>");
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
			printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
			break;
		case 7:
			SListDestroy(&guard);
			printf("�������ٳɹ�!\n");
			break;
		case 8:
			SListPrint(&guard);
			break;
		case 0:
			printf("������һ��\n");
			break;
		default:
			printf("�����������������>");
			break;
		}
	} while (option);
}

void InsertD(DLTNode* pguard) {
	printf("������Ҫ���������>");
	int val;
	scanf("%d", &val);
	DInsert(pguard, val);
	printf("����ɹ�");
}

void FindD(DLTNode* pguard) {
	printf("������Ҫ���ҵ�����>");
	int val;
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("���ҳɹ�!\n");
	}
	else {
		printf("�����в�����%d!\n", val);
	}
}

void EraseD(DLTNode* pguard) {
	printf("������Ҫɾ����Ԫ��λ��>");
	int index;
	scanf("%d", &index);
	DListEraseIndex(pguard, index);
	printf("ɾ���ɹ�!\n");
}

void Dmenu() {
	int option;
	DLTNode* pguard = NULL;

	do {
		getchar();
		system("pause");
		menu3();
		printf("���������ѡ��>");
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
			printf("����ĳ���Ϊ> %d\n", DListLength(pguard));
			break;
		case 7:
			DListDestroy(pguard);
			printf("�������ٳɹ�!\n");
			break;
		case 8:
			DListPrint(pguard);
			break;
		case 0:
			printf("������һ��\n");
			break;
		default:
			printf("�����������������>");
			break;
		}
	} while (option);
}
int main() {
	int option;
	do {
		menu1();
		printf("���������ѡ��>");
		scanf("%d", &option);
		switch (option) {
		case 1:
			Smenu();
			break;
		case 2:
			Dmenu();
			break;
		case 0:
			printf("�����˳�\n");
			break;
		default:
			printf("�����������������>");
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

//���������������
void DListPrint(DLTNode* phead) {
	assert(phead);
	DLTNode* cur = phead->next;
	while (cur && cur != phead) {
		printf("%d ", cur->data);
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
	while (cur != phead) {
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


//ɾ��indexλ��
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
		printf("��λ�ò�����");
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

void DInsert(DLTNode* pguard, DLTDataType x) {
	DListPushBack(pguard, x);
	DListSort(pguard);
}



void SListInit(SLNode* pguard) {
	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
	assert(pguard);
	pguard->next = NULL;
}

//�������������̨
void SListPrint(SLNode* pguard) {
	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
	assert(pguard);
	SLNode* cur = pguard->next;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//���ٵ�����
void SListDestroy(SLNode* pguard) {
	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
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

//ͷ��β�� ͷɾβɾ
void SListPushBack(SLNode* pguard, SLTDataType x) {
	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
	assert(pguard);
	SLNode* newnode = BuyNode(x);
	SLNode* cur = pguard;
	while (cur->next) {
		cur = cur->next;
	}
	cur->next = newnode;
}

void SListPushFront(SLNode* pguard, SLTDataType x) {
	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
	assert(pguard);
	SLNode* newnode = BuyNode(x);
	newnode->next = pguard->next;
	pguard->next = newnode;
}

void SListPopBack(SLNode* pguard) {
	assert(pguard);
	//�������
	assert(pguard->next);

	//��2
	SLNode* cur = pguard;
	while (cur->next->next) {
		cur = cur->next;
	}
	free(cur->next);
	cur->next = NULL;
}

void SListPopFront(SLNode* pguard) {
	assert(pguard);
	//�������
	assert(pguard->next);

	SLNode* del = pguard->next;
	pguard->next = del->next;
	free(del);
	//del == NULL;	
}

//�������ݣ��ҵ��������ڽڵ�ĵ�ַ
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

//ɾ��pos�ڵ�
void SListErase(SLNode* pguard, SLNode* pos) {
	assert(pguard);
	SLNode* prev = pguard;
	while (prev->next != pos) {
		prev = prev->next;
		assert(prev);//prevΪNULLʱ˵�������������ˣ���û���ҵ�pos��˵��pos������
	}
	prev->next = pos->next;
	free(pos);
	//pos = NULL;�Ѿֲ�����tmp��ΪNULL������������pos���κ�Ӱ�죬������Ӧ���Լ��ֶ���NULL
}

//ɾ��indexλ��
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
		printf("��λ�ò�����");
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
				//����
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
