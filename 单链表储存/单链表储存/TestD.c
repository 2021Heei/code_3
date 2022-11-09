#include "ListD.h"

void BackInsert() {
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
	SListSort(pguard);
	printf("��С���������>");
	DListPrint(pguard);
	printf("����ĳ���Ϊ> %d\n", DListLength(pguard));


	printf("������Ҫ���ҵ�����>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("���ҳɹ�!\n");
	}
	else {
		printf("�����в�����%d!\n", val);
	}
	printf("�Ƿ�ɾ��Ԫ��(y/n)>");
	char option = 0;
	getchar();
	while (scanf("%c", &option) != EOF) {
		if (option == 'y' || option == 'Y') {
			DListErase(ret);
			printf("ɾ���ɹ�!\n");
			break;
		}
		else if (option == 'n' || option == 'N') {
			break;
		}
		else {
			printf("�����������������>");
		}
		getchar();
	}
	printf("����Ԫ��>");
	DListPrint(pguard);
	printf("����ĳ���Ϊ> %d\n", DListLength(pguard));
	DListDestroy(pguard);
	pguard = NULL;
	printf("β�崴�����������ٳɹ�!\n");
	printf("\n");
	printf("\n");
}

void FrontInsert() {
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
	SListSort(pguard);
	printf("��С���������>");
	DListPrint(pguard);
	printf("����ĳ���Ϊ> %d\n", DListLength(pguard));


	printf("������Ҫ���ҵ�����>");
	scanf("%d", &val);
	DLTNode* ret = DListFind(pguard, val);
	if (ret) {
		printf("���ҳɹ�!\n");
	}
	else {
		printf("�����в�����%d!\n", val);
	}
	printf("�Ƿ�ɾ��Ԫ��(y/n)>");
	char option = 0;
	getchar();
	while (scanf("%c", &option) != EOF) {
		if (option == 'y' || option == 'Y') {
			DListErase(ret);
			printf("ɾ���ɹ�!\n");
			break;
		}
		else if (option == 'n' || option == 'N') {
			break;
		}
		else {
			printf("�����������������>");
		}
		getchar();
	}
	printf("����Ԫ��>");
	DListPrint(pguard);
	printf("����ĳ���Ϊ> %d\n", DListLength(pguard));
	DListDestroy(pguard);
	pguard = NULL;
	printf("ͷ�崴�����������ٳɹ�!\n");
	printf("\n");
	printf("\n");
}

int main() {
	//β�巨
	BackInsert();
	//ͷ�巨
	FrontInsert();
	return 0;
}