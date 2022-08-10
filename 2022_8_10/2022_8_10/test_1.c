//#include "test_2.h"
//
////int main() {
////
////	int i = 0;
////	for (i = 0; i < 10; i++) {
////		printf("file: %s line: %d date: %s time: %s i = %d\n",
////			__FILE__,__LINE__,__DATE__,__TIME__,i);
////	}
////
////	return 0;
////}
////#define DEBUG_PRINT printf("file:%s\tline:%d\t\
////                            date:%s\ttime:%s\n", \
////                            __FILE__,__LINE__, \
////                            __DATE__,__TIME__)
////int main() {
////
////	/*if (__STDC__ == 1) {
////		printf("YES!\n");
////	}
////	else {
////		printf("NO!\n");
////	}*/
////	DEBUG_PRINT;
////	return 0;
////}
//
////#define SQUARE(x) x * x
////
////int main() {
////	printf("%d\n", SQUARE(5));
////	printf("%d\n", SQUARE(2 + 3));
////
////	return 0;
////}
//
//
////#define DOUBLE(x) (x) + (x)
////
////int main() {
////	printf("%d\n", 2 * DOUBLE(5));
////	printf("%d\n", 2 * (DOUBLE(5)));
////	return 0;
////}
//
////int main() {
////	printf("hello world!\n");
////	printf("hello" " world!\n");
////	return 0;
////}
//
////#define PRINT(x, FORMAT) printf("The num of "#x " is " FORMAT"\n", x)
////int main() {
////	int a = 10;
////	PRINT(a, "%d");
////	double b = 10;
////	PRINT(b, "%lf");
////	PRINT(10, "%lf");
////
////
////	return 0;
////}
//
////#define LINK(member_1, member_2) member_1##member_2
////
////int main() {
////	int helloworld = 10;
////	printf("%d\n", LINK(hello, world));
////	return 0;
////}
//
////#define MAX(a,b) ( (a) > (b) ? (a) : (b) )
////
////int main() {
////	int x = 5;
////	int y = 4;
////	int max = MAX(x++, y++);
////	printf("x:%d \ny:%d \nmax:%d\n", x, y, max);
////	return 0;
////}
//
////#include <stdlib.h>
////
////#define MALLOC(num,type) (type*)malloc(num*sizeof(type))
////int main() {
////	int* p1 = MALLOC(10, int);
////	char* p2 = MALLOC(10, char);
////	free(p1);
////	p1 = NULL;
////	free(p2);
////	p2 = NULL;
////	return 0;
////}
//
////#define M 100
////int main() {
////	printf("%d\n", M);
////#undef M
////#define M 200
////
////	printf("%d\n", M);
////	return 0;
////}
//
////#define M 0
////
////#define M 100
////
////int main() {
////#if M
////	printf("%d\n", M);
////#endif
////#if 0
////	printf("%d\n", M);
////#endif
////	return 0;
////}
//
////#define M 5
////
////int main() {
////
////#if M > 5
////	printf(">\n");
////#elif M == 5
////	printf("==\n");
////#else
////	printf("<\n");
////#endif
////
////	return 0;
////}
//
//#define M 10
//
//int main() {
//#if defined M
//	printf("%d\n", M);
//#endif
//
//#if !defined M
//	printf("%d\n", 5);
//#endif
//
//#ifdef M
//	printf("%d\n", M);
//#endif
//
//#ifndef M
//	printf("%d\n", 15);
//#endif
//	return 0;
//}