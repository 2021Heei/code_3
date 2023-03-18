#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>

using namespace std;

//bool contain(const string& s, const vector<string>& wordDict) {
//	for (int i = 0; i < wordDict.size(); i++) {
//		if (s == wordDict[i]) {
//			return true;
//		}
//	}
//	return false;
//}
//
//bool wordBreak(const string& s, const vector<string>& wordDict) {
//	bool* canBreak = new bool[s.size() + 1];
//	canBreak[0] = true;
//	for (int i = 1; i < s.size() + 1; i++) {
//		canBreak[i] = false;
//	}
//	for (int i = 1; i <= s.size(); i++) {
//
//		for (int j = 0; j < i; j++) {
//			if (canBreak[j] && contain(s.substr(j, i-j), wordDict)) {
//				canBreak[i] = true;
//				break;
//			}
//		}
//	}
//
//	return canBreak[s.size()];
//
//}
//
//int main() {
//	
//	vector<string> vs;
//	vs.push_back("ap");
//	vs.push_back("pe");
//	cout << wordBreak("appeap", vs) << endl;
//
//	return 0;
//}


//#include<iostream>
//using namespace std;
//class B
//{
//public:
//	B()
//	{
//		cout << "default constructor" << " " << endl;
//	}
//
//	~B()
//	{
//		cout << "destructed" << " " << endl;
//	}
//	B(int i) : data(i)
//	{
//		cout << "constructed by parameter" << data << " " <<endl;
//	}
//	B(const B& obj) {
//		data = obj.data;
//		cout << "拷贝构造" << endl;
//	}
//	B& operator=(const B& obj) {
//		data = obj.data;
//		cout << "赋值运算符重载" << endl;
//	}
//private: int data;
//};
//B Play(B b)
//{
//	return b;
//}
//int main(int argc, char* argv[])
//{
//	B temp = Play(5);
//	return 0;
//}

#include <iostream>
using namespace std;
class A
{
public:
	virtual void print()
	{
		cout << "A::print()" << "\n";
	}
};
class B : public A
{
public: virtual void print()
{
	cout << "B::print()" << "\n";
}
};
class C : public A
{
public: virtual void print()
{
	cout << "C::print()" << "\n";
}
};
void print(A a)
{
	a.print();
}
//int main()
//{
//	A a, * aa, * ab, * ac;
//	B b;
//	C c;
//	aa = &a;
//	ab = &b;
//	ac = &c;
//	a.print();
//	b.print();
//	c.print();
//	aa->print();
//	ab->print();
//	ac->print();
//	print(a);
//	print(b);
//	print(c);
//}