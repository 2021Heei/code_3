#include "SeqList.h"



void Test_1() {
	SL slist;
	SLInit(&slist);

	SLPushBack(&slist, 1);
	SLPushBack(&slist, 2);
	SLPushBack(&slist, 3);
	SLPushBack(&slist, 4);
	SLPrint(&slist);

	SLPushFront(&slist, 10);
	SLPushFront(&slist, 20);
	SLPushFront(&slist, 30);
	SLPushFront(&slist, 40);
	SLPrint(&slist);

	SLDestroy(&slist);
}

void Test_2() {
	SL slist;
	SLInit(&slist);

	SLPushBack(&slist, 1);
	SLPushBack(&slist, 2);
	SLPushBack(&slist, 3);
	SLPushBack(&slist, 4);
	SLPrint(&slist);

	SLPopBack(&slist);
	SLPrint(&slist);
	SLPopBack(&slist);
	SLPrint(&slist);
	SLPopBack(&slist);
	SLPrint(&slist);

	SLDestroy(&slist);

	SLInit(&slist);

	SLPushBack(&slist, 1);
	SLPushBack(&slist, 2);
	SLPushBack(&slist, 3);
	SLPushBack(&slist, 4);
	SLPrint(&slist);

	SLPopFront(&slist);
	SLPrint(&slist);
	SLPopFront(&slist);
	SLPrint(&slist);
	SLPopFront(&slist);
	SLPrint(&slist);

	SLDestroy(&slist);

}


void Test_3() {
	SL slist;
	SLInit(&slist);

	SLPushBack(&slist, 1);
	SLPushBack(&slist, 2);
	SLPushBack(&slist, 3);
	SLPushBack(&slist, 4);
	SLPrint(&slist);

	/*int ret = SLFind(&slist, 2);
	if (ret) {
		SLModify(&slist, ret, 100 * slist.data[ret]);
		SLPrint(&slist);
	}*/
	/*int ret = SLFind(&slist, 3);
	if (ret) {
		SLInsert(&slist, ret, slist.data[ret] * 100);
		SLPrint(&slist);
	}*/
	int ret = SLFind(&slist, 3);
	if (ret) {
		SLErase(&slist, ret);
		SLPrint(&slist);
	}


	SLDestroy(&slist);
}


void Test_4() {
	SL slist;
	SLInit(&slist);

	SLPushBack2(&slist, 1);
	SLPushBack2(&slist, 2);
	SLPushBack2(&slist, 3);
	SLPushBack2(&slist, 4);
	SLPrint(&slist);

	SLPushFront2(&slist, 10);
	SLPushFront2(&slist, 20);
	SLPushFront2(&slist, 30);
	SLPushFront2(&slist, 40);
	SLPrint(&slist);

	SLDestroy(&slist);
}


void Test_5() {
	SL slist;
	SLInit(&slist);

	SLPushBack2(&slist, 1);
	SLPushBack2(&slist, 2);
	SLPushBack2(&slist, 3);
	SLPushBack2(&slist, 4);
	SLPrint(&slist);

	SLPopBack2(&slist);
	SLPrint(&slist);
	SLPopBack2(&slist);
	SLPrint(&slist);
	SLPopBack2(&slist);
	SLPrint(&slist);

	SLDestroy(&slist);

	SLInit(&slist);

	SLPushBack2(&slist, 1);
	SLPushBack2(&slist, 2);
	SLPushBack2(&slist, 3);
	SLPushBack2(&slist, 4);
	SLPrint(&slist);

	SLPopFront2(&slist);
	SLPrint(&slist);
	SLPopFront2(&slist);
	SLPrint(&slist);
	SLPopFront2(&slist);
	SLPrint(&slist);

	SLDestroy(&slist);

}


int main() {
	//Test_1();
	//Test_2();
	//Test_3();
	//Test_4();
	Test_5();


}