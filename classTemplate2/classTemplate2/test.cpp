#include "class.h"


int main() {

	A<int> a1(10);
	A<int> a2(20);
	a1.Print();
	a1 = a2;
	a1.Print();
	return 0;
}