#include "SList.h"

void Test_1() {
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPrint(plist);

}

void Test_2() {
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPrint(plist);

}

void Test_3() {
	SLTNode* plist = NULL;

	SListPushFront(&plist, 1);
	SListPushFront(&plist, 2);
	SListPushFront(&plist, 3);
	SListPushFront(&plist, 4);
	SListPushFront(&plist, 5);
	SListPrint(plist);

	/*SLTNode* pos = SListFind(plist, 3);
	if (pos) {
		printf("´æÔÚ\n");
		pos->data *= 100;
	}
	else {
		printf("²»´æÔÚ\n");
	}
	SListPrint(plist);*/

	//SLTNode* pos = SListFind(plist, 3);
	//if (pos) {
	//	SListInsert(&plist, pos, (pos->data)*10);
	//}
	//SListPrint(plist);

	/*SLTNode* pos2 = SListFind(plist, 3);
	if (pos2) {
		SListInsertAfter(pos2, (pos2->data) * 20);
	}
	SListPrint(plist);*/

	/*SLTNode* pos3 = SListFind(plist, 3);
	if (pos3) {
		SListErase(&plist, pos3);
	}
	SListPrint(plist);*/

	SLTNode* pos4 = SListFind(plist, 3);
	if (pos4) {
		SListEraseAfter(pos4);
	}
	SListPrint(plist);


	SListDestroy(&plist);

	

}

int main() {
	//Test_1();
	//Test_2();
	Test_3();


	return 0;
}