#include "SList.h"

void Test_1() {
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SListPushFront(&plist, 10);
	SListPushFront(&plist, 20);
	SListPushFront(&plist, 30);
	SListPushFront(&plist, 40);
	SListPrint(plist);

	SListDestroy(&plist);

}

void Test_2() {
	SLNode* plist = NULL;
	//SListPushBack(&plist, 1);
	//SListPushBack(&plist, 2);
	//SListPushBack(&plist, 3);
	//SListPushBack(&plist, 4);
	//SListPrint(plist);

	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);
	///*SListPopBack(&plist);
	//SListPrint(plist);
	//SListPopBack(&plist);
	//SListPrint(plist);*/

	//SListDestroy(&plist);

	plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
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

	SListDestroy(&plist);
}
void Test_3() {
	SLNode* plist = NULL;
	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPrint(plist);

	SLNode* ret = SListFind(plist, 2);
	if (ret) {
		ret->data = ret->data * 10;
		SListPrint(plist);
	}
	SLNode* pos = SListFind(plist, 1);
	if (pos) {
		SListInsert(&plist, pos, pos->data*100);
		SListPrint(plist);
	}

	SLNode* pos2 = SListFind(plist, 4);
	if (pos2) {
		SListInsertAfter(pos2, pos2->data * 1000);
		SListPrint(plist);
	}

	/*SLNode* pos3 = SListFind(plist, 4);
	if (pos3) {
		SListErase(&plist, pos3);
		SListPrint(plist);
	}*/

	SLNode* pos4 = SListFind(plist, 4);
	if (pos4) {
		SListEraseAfter(pos4);
		SListPrint(plist);
	}

	SListDestroy(&plist);

}

int main() {
	//Test_1();
	//Test_2();
	//Test_3();

	return 0;
}