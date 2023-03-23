#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

template<typename Type>

Type Max(const Type& a, const Type& b)

{

	cout << "This is Max<Type>" << endl;

	return a > b ? a : b;

}

template<>

int Max<int>(const int& a, const int& b)

{

	cout << "This is Max<int>" << endl;

	return a > b ? a : b;

}

template<>

char Max<char>(const char& a, const char& b)

{

	cout << "This is Max<char>" << endl;

	return a > b ? a : b;

}

int Max(const int& a, const int& b)

{

	cout << "This is Max" << endl;

	return a > b ? a : b;

}





class A

{

public:

	virtual void f()

	{

		cout << "A::f()" << endl;

	}

};



class B : public A

{

private:

	virtual void f()

	{

		cout << "B::f()" << endl;

	}

};







int main(int argc, char* argv[])

{

	A* pa = (A*)new B;

	pa->f();

	return 0;

}