#include "Stack.h"
char* HexConversion(int n, int d);

int main() {

	int N, d;
	printf("请输入整数N和d>\n");
	scanf("%d %d", &N, &d);
	char* ret = HexConversion(N, d);
	printf("ret: %s\n", ret);
	free(ret);
	ret = NULL;
	return 0;
}

char* HexConversion(int n, int d) {
	Stack st;
	StackInit(&st);
	while (n) {
		char ch = n % d + '0';
		StackPush(&st, ch);
		n /= d;
	}
	char* ret = (char*)malloc(sizeof(char) * (st.top+1));
	ret[st.top] = '\0';
	int i = 0;
	while (!StackEmpty(&st)) {
		ret[i++] = StackTop(&st);
		StackPop(&st);
	}

	StackDestroy(&st);
	return ret;
}