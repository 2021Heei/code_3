#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

class A {
public:
	A(int a = 0)
		:_a(a) {

	}
	~A() {
		delete this;
		//this = nullptr;
	}
private:
	int _a;
};
int main() {
	A a(10);

	return 0;
}