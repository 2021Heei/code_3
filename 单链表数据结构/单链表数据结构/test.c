//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <windows.h>
//
//typedef int SLTDataType;
////�ڵ�����
//typedef struct SListNode {
//	SLTDataType data;
//	struct SListNode* next;
//}SLNode;
//
////��ʼ���ڱ�ͷ���
//void SListInit(SLNode* pguard);
////�������������̨
//void SListPrint(SLNode* pguard);
////���ٵ�����
//void SListDestroy(SLNode* pguard);
////����һ���½ڵ�
//SLNode* BuyNode(SLTDataType x);
////ͷ��β�� ͷɾβɾ
//void SListPushBack(SLNode* pguard, SLTDataType x);
//void SListPushFront(SLNode* pguard, SLTDataType x);
//void SListPopBack(SLNode* pguard);
//void SListPopFront(SLNode* pguard);
////�������ݣ��ҵ��������ڽڵ�ĵ�ַ
//SLNode* SListFind(SLNode* pguard, SLTDataType x);
////ɾ��pos�ڵ�
//void SListErase(SLNode* pguard, SLNode* pos);
//int SListLength(SLNode* pguard);
//void SListSort(SLNode* pguard);
//void Insert(SLTDataType val);
//
//
//void BackInsert() {
//	printf("β�巨��������������ز���>\n");
//	SLNode guard;
//	SListInit(&guard);
//	int n = 0, val = 0;
//	printf("������Ҫβ������ݸ���>");
//	scanf("%d", &n);
//	printf("������Ҫβ���%d�����ݣ��Կո�ָ�>", n);
//
//	while (n--) {
//		scanf("%d", &val);
//		SListPushBack(&guard, val);
//	}
//	SListPrint(&guard);
//	printf("β�崴��������ɹ�\n");
//
//	printf("������Ҫ���������>");
//	scanf("%d", &val);
//	Insert(&guard, val);
//	printf("����ɹ�������Ϊ>");
//
//	SListPrint(&guard);
//	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
//
//
//	printf("������Ҫ���ҵ�����>");
//	scanf("%d", &val);
//	SLNode* ret = SListFind(&guard, val);
//	if (ret) {
//		printf("���ҳɹ�!\n");
//
//		printf("�Ƿ�ɾ��Ԫ��(y/n)>");
//		char option = 0;
//		getchar();
//		while (scanf("%c", &option) != EOF) {
//			if (option == 'y' || option == 'Y') {
//				SListErase(&guard, ret);
//				printf("ɾ���ɹ�!\n");
//				break;
//			}
//			else if (option == 'n' || option == 'N') {
//				break;
//			}
//			else {
//				printf("�����������������>");
//			}
//			getchar();
//		}
//	}
//	else {
//		printf("�����в�����%d!\n", val);
//	}
//
//	printf("����Ԫ��>");
//	SListPrint(&guard);
//	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
//	SListDestroy(&guard);
//	printf("β�崴�����������ٳɹ�!\n");
//	printf("\n");
//	printf("\n");
//}
//
//void FrontInsert() {
//	printf("ͷ�巨��������������ز���>\n");
//	SLNode guard;
//	SListInit(&guard);
//	int n = 0, val = 0;
//	printf("������Ҫͷ������ݸ���>");
//	scanf("%d", &n);
//	printf("������Ҫͷ���%d�����ݣ��Կո�ָ�>", n);
//
//	while (n--) {
//		scanf("%d", &val);
//		SListPushFront(&guard, val);
//	}
//	SListPrint(&guard);
//	printf("ͷ�崴��������ɹ�\n");
//	printf("������Ҫ���������>");
//	scanf("%d", &val);
//	Insert(&guard, val);
//	printf("����ɹ�������Ϊ>");
//
//	SListPrint(&guard);
//	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
//
//
//	printf("������Ҫ���ҵ�����>");
//	scanf("%d", &val);
//	SLNode* ret = SListFind(&guard, val);
//	if (ret) {
//		printf("���ҳɹ�!\n");
//
//		printf("�Ƿ�ɾ��Ԫ��(y/n)>");
//		char option = 0;
//		getchar();
//		while (scanf("%c", &option) != EOF) {
//			if (option == 'y' || option == 'Y') {
//				SListErase(&guard, ret);
//				printf("ɾ���ɹ�!\n");
//				break;
//			}
//			else if (option == 'n' || option == 'N') {
//				break;
//			}
//			else {
//				printf("�����������������>");
//			}
//			getchar();
//		}
//	}
//	else {
//		printf("�����в�����%d!\n", val);
//	}
//
//	printf("����Ԫ��>");
//	SListPrint(&guard);
//	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
//	SListDestroy(&guard);
//	printf("ͷ�崴�����������ٳɹ�!\n");
//}
//
//
//int main() {
//	//β�巨
//	BackInsert();
//	//ͷ�巨
//	FrontInsert();
//	
//	return 0;
//}
//
//void SListInit(SLNode* pguard) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	pguard->next = NULL;
//}
//
////�������������̨
//void SListPrint(SLNode* pguard) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	SLNode* cur = pguard->next;
//	while (cur) {
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
//
////���ٵ�����
//void SListDestroy(SLNode* pguard) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	SLNode* cur = pguard->next;
//	while (cur) {
//		SLNode* next = cur->next;
//		free(cur);
//		cur = next;
//	}
//	pguard->next = NULL;
//}
//
//SLNode* BuyNode(SLTDataType x) {
//	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
//	if (!newnode) {
//		perror("newnode\n");
//		exit(-1);
//	}
//	newnode->data = x;
//	newnode->next = NULL;
//}
//
////ͷ��β�� ͷɾβɾ
//void SListPushBack(SLNode* pguard, SLTDataType x) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	SLNode* newnode = BuyNode(x);
//	SLNode* cur = pguard;
//	while (cur->next) {
//		cur = cur->next;
//	}
//	cur->next = newnode;
//}
//
//void SListPushFront(SLNode* pguard, SLTDataType x) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	SLNode* newnode = BuyNode(x);
//	newnode->next = pguard->next;
//	pguard->next = newnode;
//}
//
//void SListPopBack(SLNode* pguard) {
//	//�ڱ�ͷ�ڵ�һ�����ڣ����ַһ����ΪNULL�������NULL��˵���ڱ�ͷ�ڵ����
//	assert(pguard);
//	//�������
//	assert(pguard->next);
//	//������
//	//if(*pguard->next == NULL){
//	//    return;   
//	//}
//
//	//��2
//	SLNode* cur = pguard;
//	while (cur->next->next) {
//		cur = cur->next;
//	}
//	free(cur->next);
//	cur->next = NULL;
//}
//
//void SListPopFront(SLNode* pguard) {
//	assert(pguard);
//	//�������
//	assert(pguard->next);
//	//������
//	//if(pguard->next == NULL){
//	//    return;   
//	//}
//
//	SLNode* del = pguard->next;
//	pguard->next = del->next;
//	free(del);
//	//del == NULL;	
//}
//
////�������ݣ��ҵ��������ڽڵ�ĵ�ַ
//SLNode* SListFind(SLNode* pguard, SLTDataType x) {
//	assert(pguard);
//	SLNode* cur = pguard->next;
//	while (cur) {
//		if (cur->data == x) {
//			return cur;
//		}
//		cur = cur->next;
//	}
//	return NULL;
//}
//
////ɾ��pos�ڵ�
//void SListErase(SLNode* pguard, SLNode* pos) {
//	assert(pguard);
//	SLNode* prev = pguard;
//	while (prev->next != pos) {
//		prev = prev->next;
//		assert(prev);//prevΪNULLʱ˵�������������ˣ���û���ҵ�pos��˵��pos������
//	}
//	prev->next = pos->next;
//	free(pos);
//	//pos = NULL;�Ѿֲ�����tmp��ΪNULL������������pos���κ�Ӱ�죬������Ӧ���Լ��ֶ���NULL
//}
//
//int SListLength(SLNode* pguard) {
//	assert(pguard);
//	SLNode* cur = pguard->next;
//	int cnt = 0;
//	while (cur) {
//		cnt++;
//		cur = cur->next;
//	}
//	return cnt;
//}
//
//void SListSort(SLNode* pguard) {
//	assert(pguard);
//	int count1 = SListLength(pguard);
//	int count2 = 0;
//	SLNode* cur, * next;
//	for (int i = 0; i < count1; ++i) {
//		cur = pguard->next;
//		next = cur->next;
//		count2 = count1 - i - 1;
//		while (count2--) {
//			if (cur->data > next->data) {
//				//����
//				SLTDataType tmp = cur->data;
//				cur->data = next->data;
//				next->data = tmp;
//			}
//			cur = next;
//			next = next->next;
//		}
//	}
//}
//
//void Insert(SLNode* pguard, SLTDataType val) {
//	SListPushBack(pguard, val);
//	SListSort(pguard);
//}
