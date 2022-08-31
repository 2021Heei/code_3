#include "SeqList.h"


void test_1() {
	//测尾插与头插
	SL s;
	SLInit(&s);

	/*SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);

	SLPrint(&s);
	SLDestory(&s);*/

	SLInit(&s);


	SLPushFront(&s, 1);
	SLPushFront(&s, 2);
	SLPushFront(&s, 3);
	SLPushFront(&s, 4);
	SLPushFront(&s, 5);
	SLPushFront(&s, 6);
	SLPushFront(&s, 7);

	SLPrint(&s);

	SLDestory(&s);

}

void test_2() {
	//测头删尾删
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);

	SLPrint(&s);

	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	SLPopBack(&s);
	//SLPopBack(&s);
	//SLPopBack(&s);
	SLPrint(&s);


	SLDestory(&s);


	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);

	SLPrint(&s);

	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	SLPopFront(&s);
	/*SLPopFront(&s);
	SLPopFront(&s);*/

	SLPrint(&s);


	SLDestory(&s);

}

void test_3() {
	//查找与按下标插入数据
	SL s;
	SLInit(&s);

	/*SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);
	
	SLPrint(&s);

	int ret = FindSL(&s, 2);
	if (ret >= 0 && ret < s.size) {
		SLInsert(&s, ret, 200);
	}
	SLPrint(&s);

	ret = FindSL(&s, 1);
	if (ret >= 0 && ret < s.size) {
		SLInsert(&s, ret, 100);
	}
	SLInsert(&s, 100, 100);

	SLPrint(&s);*/

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);

	SLPrint(&s);

	int ret = FindSL(&s, 2);
	if (ret >= 0 && ret < s.size) {
		SLErase(&s, ret);
	}
	SLErase(&s, 100);

	SLPrint(&s);

	SLDestory(&s);
}

void test_4() {
	SL s;
	SLInit(&s);

	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	SLPushBack(&s, 6);
	SLPushBack(&s, 7);

	SLPrint(&s);
	SLModify(&s, 0, 10);
	SLModify(&s, 2, 30);
	SLModify(&s, 4, 50);
	SLModify(&s, 5, 60);

	SLPrint(&s);
	SLDestory(&s);

}

int main() {
	//test_1();
	//test_2();
	//test_3();
	test_4();
	return 0;
}