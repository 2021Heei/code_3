//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	A(int a = 0):_a(a){}
//	void displayA() {
//		cout << "_a" << endl;
//	}
//private:
//	int _a;
//};
//
//class B :public A {
//public:
//	B(int a = 0, int b = 1)
//		:A(a), _b(b) {}
//	void displayB() {
//		displayA();
//		cout << "_b" << endl;
//	}
//private:
//	int _b;
//};
//
//int main() {
//	B b;
//	b.displayA();
//	cout << endl;
//	b.displayB();
//	return 0;
//}

#include<iostream>
#include<string>
using namespace std;
class 	Manager
{
public:
	Manager(int id, string name, string department) :id(id), name(name), department(department) {}
	void display()
	{
		cout << id << endl;
		cout << name << endl;
		cout << department << endl;
	}
protected:
	int id;
	string name;
	string department;
};
class Employee :public Manager
{
public:
	Employee(int id1, string name1, string department1,
		int id2, string name2, string department2,string sex, int age) 
		:Manager(id2, name2, department2)
		, M1(id1, name1, department1)
	{
		this->sex = sex;
		this->age = age;
	}
	//���������Ϣ M1
	void show_Manager()
	{
		M1.display();
	}
	//��ʾְ����Ϣ�����������������Ϣ���������display���������ֱ��ʹ��cout���
	void show()
	{
		display();
		cout << sex << endl;
		cout << age << endl << endl;
	}
protected:
	string sex;//ְ���Ա�
	int age;//ְ������
	Manager M1;//����
};
int main()
{
	Employee e(1001, "����", "����", 
				2001, "ְ��", "���Ա", 
				"��", 30);
	e.show_Manager();
	e.show();
	return 0;
}