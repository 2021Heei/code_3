#include "SeqList.h"


void test_1() {
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);

	SLPrint(&s);

	SLDestroy(&s);


	SLInit(&s);


	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 7);

	SLPrint(&s);

	SLDestroy(&s);
}


void test_2() {
	SL s;
	SLInit(&s);
	
	/*SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);*/

	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 7);

	SLPrint(&s);

	
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);

	SLPrint(&s);

	SLDestroy(&s);

	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);

	SLPrint(&s);


	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);

	SLPrint(&s);


}

void test_3() {
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);

	SLPrint(&s);
	
	int ret = SLFind(&s, 2);
	if (ret >= 0 && ret < s.size) {
		SLInsert(&s, ret, s.data[ret] * 10);
	}
	SLPrint(&s);

	int ret2 = SLFind(&s, 2);
	if (ret2 >= 0 && ret2 < s.size) {
		SLErase(&s, ret2);
	}

	SLPrint(&s);

	int ret3 = SLFind(&s, 4);
	if (ret3 >= 0 && ret3 < s.size) {
		SLModify(&s, ret3, s.data[ret3] * 100);
	}

	SLPrint(&s);
	

	SLDestroy(&s);

}


int main() {
	test_1();
	//test_2();
	//test_3();

	return 0;
}