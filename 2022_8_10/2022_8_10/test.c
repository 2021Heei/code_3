#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

extern Add(int x, int y);

int main() {
	int a = 10;
	int b = 5;
	int sum = Add(a, b);
	printf("%d\n", sum);

	return 0;
}