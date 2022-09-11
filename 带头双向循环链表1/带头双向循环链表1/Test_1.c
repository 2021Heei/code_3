#include "DList.h"

void Test_1() {
	DLTNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);

	DListPushFront(plist, 10);
	DListPushFront(plist, 20);
	DListPushFront(plist, 30);
	DListPushFront(plist, 40);
	DListPrint(plist);

	DListPopBack(plist);
	DListPopBack(plist);
	DListPrint(plist);
	DListPopBack(plist);
	DListPopBack(plist);
	DListPrint(plist);

	/*DListPopFront(plist);
	DListPrint(plist);
	DListPopFront(plist);
	DListPrint(plist);
	DListPopFront(plist);
	DListPrint(plist);
	DListPopFront(plist);
	DListPrint(plist);
	DListPopFront(plist);
	DListPrint(plist);*/



	DListDestroy(plist);
	plist = NULL;
}

void Test_2() {
	DLTNode* plist = DListInit();
	DListPushBack(plist, 1);
	DListPushBack(plist, 2);
	DListPushBack(plist, 3);
	DListPushBack(plist, 4);
	DListPrint(plist);

	/*DLTNode* pos = DListFind(plist, 2);
	if (pos) {
		pos->data *= 100;
		DListPrint(plist);
	}*/

	DLTNode* pos = DListFind(plist, 2);
	if (pos) {
		DListInsert(pos, pos->data * 100);
		DListPrint(plist);
	}
	DListInsert(plist, 100);
	DListPrint(plist);

	DLTNode* pos2 = DListFind(plist, 2);
	if (pos2) {
		DListErase(pos2);
		DListPrint(plist);
	}

}

int main() {
	Test_1();
	//Test_2();

	return 0;
}