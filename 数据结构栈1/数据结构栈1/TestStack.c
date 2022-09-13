#include "Stack.h"

void TestStack() {
	ST s;
	StackInit(&s);
	StackPush(&s, 1);
	printf("StackSize:%d\n",StackSize(&s));
	StackPush(&s, 2);
	printf("StackSize:%d\n", StackSize(&s));
	StackPush(&s, 3);
	printf("StackSize:%d\n", StackSize(&s));
	StackPush(&s, 4);
	printf("StackSize:%d\n", StackSize(&s));

	while (!StackEmpty(&s)) {
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	printf("StackSize:%d\n", StackSize(&s));

	StackDestroy(&s);
}

//int main() {
//	TestStack();
//
//	return 0;
//}