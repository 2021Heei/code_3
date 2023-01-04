//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <assert.h>
//#include <stdlib.h>
//#include <windows.h>
//
//typedef int SLTDataType;
////节点类型
//typedef struct SListNode {
//	SLTDataType data;
//	struct SListNode* next;
//}SLNode;
//
////初始化哨兵头结点
//void SListInit(SLNode* pguard);
////数据输出到控制台
//void SListPrint(SLNode* pguard);
////销毁单链表
//void SListDestroy(SLNode* pguard);
////申请一个新节点
//SLNode* BuyNode(SLTDataType x);
////头插尾插 头删尾删
//void SListPushBack(SLNode* pguard, SLTDataType x);
//void SListPushFront(SLNode* pguard, SLTDataType x);
//void SListPopBack(SLNode* pguard);
//void SListPopFront(SLNode* pguard);
////查找数据，找到返回所在节点的地址
//SLNode* SListFind(SLNode* pguard, SLTDataType x);
////删除pos节点
//void SListErase(SLNode* pguard, SLNode* pos);
//int SListLength(SLNode* pguard);
//void SListSort(SLNode* pguard);
//void Insert(SLTDataType val);
//
//
//void BackInsert() {
//	printf("尾插法创建链表并进行相关操作>\n");
//	SLNode guard;
//	SListInit(&guard);
//	int n = 0, val = 0;
//	printf("请输入要尾插的数据个数>");
//	scanf("%d", &n);
//	printf("请输入要尾插的%d个数据，以空格分隔>", n);
//
//	while (n--) {
//		scanf("%d", &val);
//		SListPushBack(&guard, val);
//	}
//	SListPrint(&guard);
//	printf("尾插创建的链表成功\n");
//
//	printf("请输入要插入的数据>");
//	scanf("%d", &val);
//	Insert(&guard, val);
//	printf("插入成功，链表为>");
//
//	SListPrint(&guard);
//	printf("链表的长度为> %d\n", SListLength(&guard));
//
//
//	printf("请输入要查找的数据>");
//	scanf("%d", &val);
//	SLNode* ret = SListFind(&guard, val);
//	if (ret) {
//		printf("查找成功!\n");
//
//		printf("是否删除元素(y/n)>");
//		char option = 0;
//		getchar();
//		while (scanf("%c", &option) != EOF) {
//			if (option == 'y' || option == 'Y') {
//				SListErase(&guard, ret);
//				printf("删除成功!\n");
//				break;
//			}
//			else if (option == 'n' || option == 'N') {
//				break;
//			}
//			else {
//				printf("输入错误，请重新输入>");
//			}
//			getchar();
//		}
//	}
//	else {
//		printf("链表中不存在%d!\n", val);
//	}
//
//	printf("链表元素>");
//	SListPrint(&guard);
//	printf("链表的长度为> %d\n", SListLength(&guard));
//	SListDestroy(&guard);
//	printf("尾插创建的链表销毁成功!\n");
//	printf("\n");
//	printf("\n");
//}
//
//void FrontInsert() {
//	printf("头插法创建链表并进行相关操作>\n");
//	SLNode guard;
//	SListInit(&guard);
//	int n = 0, val = 0;
//	printf("请输入要头插的数据个数>");
//	scanf("%d", &n);
//	printf("请输入要头插的%d个数据，以空格分隔>", n);
//
//	while (n--) {
//		scanf("%d", &val);
//		SListPushFront(&guard, val);
//	}
//	SListPrint(&guard);
//	printf("头插创建的链表成功\n");
//	printf("请输入要插入的数据>");
//	scanf("%d", &val);
//	Insert(&guard, val);
//	printf("插入成功，链表为>");
//
//	SListPrint(&guard);
//	printf("链表的长度为> %d\n", SListLength(&guard));
//
//
//	printf("请输入要查找的数据>");
//	scanf("%d", &val);
//	SLNode* ret = SListFind(&guard, val);
//	if (ret) {
//		printf("查找成功!\n");
//
//		printf("是否删除元素(y/n)>");
//		char option = 0;
//		getchar();
//		while (scanf("%c", &option) != EOF) {
//			if (option == 'y' || option == 'Y') {
//				SListErase(&guard, ret);
//				printf("删除成功!\n");
//				break;
//			}
//			else if (option == 'n' || option == 'N') {
//				break;
//			}
//			else {
//				printf("输入错误，请重新输入>");
//			}
//			getchar();
//		}
//	}
//	else {
//		printf("链表中不存在%d!\n", val);
//	}
//
//	printf("链表元素>");
//	SListPrint(&guard);
//	printf("链表的长度为> %d\n", SListLength(&guard));
//	SListDestroy(&guard);
//	printf("头插创建的链表销毁成功!\n");
//}
//
//
//int main() {
//	//尾插法
//	BackInsert();
//	//头插法
//	FrontInsert();
//	
//	return 0;
//}
//
//void SListInit(SLNode* pguard) {
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
//	assert(pguard);
//	pguard->next = NULL;
//}
//
////数据输出到控制台
//void SListPrint(SLNode* pguard) {
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
//	assert(pguard);
//	SLNode* cur = pguard->next;
//	while (cur) {
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}
//
////销毁单链表
//void SListDestroy(SLNode* pguard) {
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
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
////头插尾插 头删尾删
//void SListPushBack(SLNode* pguard, SLTDataType x) {
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
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
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
//	assert(pguard);
//	SLNode* newnode = BuyNode(x);
//	newnode->next = pguard->next;
//	pguard->next = newnode;
//}
//
//void SListPopBack(SLNode* pguard) {
//	//哨兵头节点一定存在，其地址一定不为NULL。如果是NULL，说明哨兵头节点错误
//	assert(pguard);
//	//暴力检查
//	assert(pguard->next);
//	//温柔检查
//	//if(*pguard->next == NULL){
//	//    return;   
//	//}
//
//	//法2
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
//	//暴力检查
//	assert(pguard->next);
//	//温柔检查
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
////查找数据，找到返回所在节点的地址
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
////删除pos节点
//void SListErase(SLNode* pguard, SLNode* pos) {
//	assert(pguard);
//	SLNode* prev = pguard;
//	while (prev->next != pos) {
//		prev = prev->next;
//		assert(prev);//prev为NULL时说明遍历完链表了，但没有找到pos，说明pos传错了
//	}
//	prev->next = pos->next;
//	free(pos);
//	//pos = NULL;把局部变量tmp置为NULL对主调函数的pos无任何影响，调用者应该自己手动置NULL
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
//				//交换
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
