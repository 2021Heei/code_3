#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stddef.h>
#define OFFSETOF(type, member) (size_t)( &( ( ( type* )0 ) -> member) )

struct S {
	int a;//0~3
	char b;//4
	//5
	short c;//6~7
};
int main() {
	printf("%d\n", offsetof(struct S, a));
	printf("%d\n", offsetof(struct S, b));
	printf("%d\n", offsetof(struct S, c));
	
	printf("%d\n", OFFSETOF(struct S, a));
	printf("%d\n", OFFSETOF(struct S, b));
	printf("%d\n", OFFSETOF(struct S, c));

	return 0;
}