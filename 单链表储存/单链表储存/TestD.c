#include "ListD.h"

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
	SListSort(pguard);
	printf("从小到大排序后>");
	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));


	printf("请输入要查找的数据>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
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
	SListSort(pguard);
	printf("从小到大排序后>");
	DListPrint(pguard);
	printf("链表的长度为> %d\n", DListLength(pguard));


	printf("请输入要查找的数据>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("查找成功!\n");
	}
	else {
		printf("链表中不存在%d!\n", val);
	}
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