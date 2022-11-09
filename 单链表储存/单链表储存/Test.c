#include "List.h"

void BackInsert() {
	printf("β�巨��������������ز���>\n");
	SLNode guard;
	SListInit(&guard);
	int n = 0, val = 0;
	printf("������Ҫβ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫβ���%d�����ݣ��Կո�ָ�>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushBack(&guard, val);
	}
	SListPrint(&guard);
	printf("β�崴��������ɹ�\n");
	SListSort(&guard);
	printf("��С���������>");
	SListPrint(&guard);
	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));


	printf("������Ҫ���ҵ�����>");
	scanf("%d", &val);
	SLNode* ret = SListFind(&guard, val);
	if (ret) {
		printf("���ҳɹ�!\n");
	}
	else {
		printf("�����в�����%d!\n", val);
	}
	printf("�Ƿ�ɾ��Ԫ��(y/n)>");
	char option = 0;
	getchar();
	while(scanf("%c", &option) != EOF) {
		if (option == 'y' || option == 'Y') {
			SListErase(&guard, ret);
			printf("ɾ���ɹ�!\n");
			break;
		}
		else if(option == 'n' || option == 'N'){
			break;
		}
		else {
			printf("�����������������>");
		}
		getchar();
	}
	printf("����Ԫ��>");
	SListPrint(&guard);
	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
	SListDestroy(&guard);
	printf("β�崴�����������ٳɹ�!\n");
	printf("\n");
	printf("\n");
}

void FrontInsert() {
	printf("ͷ�巨��������������ز���>\n");
	SLNode guard;
	SListInit(&guard);
	int n = 0, val = 0;
	printf("������Ҫͷ������ݸ���>");
	scanf("%d", &n);
	printf("������Ҫͷ���%d�����ݣ��Կո�ָ�>", n);

	while (n--) {
		scanf("%d", &val);
		SListPushFront(&guard, val);
	}
	SListPrint(&guard);
	printf("ͷ�崴��������ɹ�\n");
	SListSort(&guard);
	printf("��С���������>");
	SListPrint(&guard);
	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));


	printf("������Ҫ���ҵ�����>");
	scanf("%d", &val);
	SLNode* ret = SListFind(&guard, val);
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
			SListErase(&guard, ret);
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
	SListPrint(&guard);
	printf("����ĳ���Ϊ> %d\n", SListLength(&guard));
	SListDestroy(&guard);
	printf("ͷ�崴�����������ٳɹ�!\n");
}

int main() {
	//β�巨
	BackInsert();
	//ͷ�巨
	FrontInsert();
	return 0;
}