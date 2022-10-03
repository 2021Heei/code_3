//#include <stdio.h>
//
//void Print1(struct A* p) {
//	p->a = p->b = 1;
//	printf("%d %d\n", p->a, p->b);
//}
//struct A {
//	int a;
//	int b;
//};
//
//void Print2(struct A* p) {
//	p->a = p->b = 2;
//	printf("%d %d\n", p->a, p->b);
//}
//
//int main() {
//	struct A A1;
//	//Print1(&A1);//error
//	Print2(&A1);//true
//	return 0;
//}