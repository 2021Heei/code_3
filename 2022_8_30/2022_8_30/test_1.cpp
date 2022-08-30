#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdlib>

int main() {
	/*int val = 10;
	int& refval = val;
	std::cout << refval << std::endl;*/
	/*int i = 0, & r1 = i;
	double d = 0, & r2 = d;
	r2 = 3.14159;
	r2 = r1;
	i = r2;
	r1 = d;*/
	/*int i, & ri = i;
	i = 5;
	ri = 10;
	std::cout << i << "\n" << ri << std::endl;*/
	/*int i = 10, & ri = i;
	int* pi = &i;
	int* ppi = &ri;
	std::cout << pi << "\n" << ppi << std::endl;*/
	/*int i = 0;
	int* p1 = nullptr;
	int* p2 = 0;
	int* p3 = NULL;*/
	int i = 0;
	std::cout << i << std::endl;
	int* p;
	int*& r = p;
	r = &i;
	*r = 10;
	std::cout << i << std::endl;
	return 0;
}