#include "Stack.h"

char* HexadecimalConversion(int n, int d) {
	Stack st;
	StackInit(&st);
	while (n) {
		char ch = n % d + '0';
		StackPush(&st, ch);
		n /= d;
	}
	char* ret = (char*)malloc(sizeof(char) * st.top);
	int i = 0;
	while (!StackEmpty(&st)) {
		ret[i++] = StackTop(&st);
		StackPop(&st);
	}

	StackDestroy(&st);
	return ret;
}

int main() {

	int n, d;
	scanf("%d %d", &n, &d);
	char* ret = HexadecimalConversion(n, d);
	printf("ret: %s\n", ret);
	free(ret);
	ret = NULL;
	return 0;
}

