//#include "Date.h"
//
//void TestDate1() {
//	Date d1(2022,10,11);
//	//Date d2();//�뺯�����������˻���
//	/*Date d3(2022, 2, 2202002);
//	d3.Print();
//	Date d4(2022, 2, 220);
//	d4.Print();*/
//	/*Date d5(d1);
//	d5.Print();
//	Date d6 = d5;
//	d6.Print();*/
//	/*Date d7, d8, d9;
//	d7 = d8 = d9 = d1;
//	d7.Print();
//	d8.Print();
//	d9.Print();*/
//
//	Date d2(2022, 10, 11);
//	d2 + 40;//d2.operator(40); -> d2.operator(&d2, 40)
//	(d2 + 40).Print();
//	d2 += 40;
//	d2.Print();
//
//	//Date d3;
//	//-d3;
//}
//
//void TestDate2() {
//
//	Date d1(2022, 10, 12);
//	Date d2;
//
//	d2.Print();
//	d2 = d1;
//	d2.Print();
//
//	//Date d1(2022, 10, 11);
//	//Date d2(d1);	//�������죬һ��������ʼ����һ������Ҫ�����Ķ���
//	//Date d3 = d1;	//��������
//	//Date d4;
//	//d4 = d1;		//��ֵ���ء����ƿ������Ѵ��ڵ���������֮��Ŀ���
//	//d1.Print();
//	//d2.Print();
//	//d3.Print();
//	//d4.Print();
//	//��ֵ��������أ�
//	//Ϊʲô�����÷��أ� - ����һ�ο���
//	//Ϊʲô�����ó����ã� - ����һ�ο�������ʹ�÷���
//	//Ϊʲô����*this��������d�� 
//	//		- this�ǵ�һ���������൱�ڸ�ֵʱ����ֵ��d�ǵڶ����������൱�ڸ�ֵʱ����ֵ��
//	//		������ֵʱһ����ʽ�ķ���ֵ����ߵı�����
//	//Ϊʲô����ָ�����ڶ��������� - ʹ���鷳
//
//	/*Date d6, d7;
//	d6 = d7 = d2;
//	d6.Print();
//	d7.Print();*/
//}
//
//void TestSatck() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2;
//	st2.Push(10);
//	st2.Push(20);
//	st2.Push(30);
//
//	//st1 = st2;//Ĭ�ϸ�ֵ��������غ������ܹ����ջ�ĸ�ֵ������Ҫ�����ֶ�д
//	st1 = st2;//����Ϊʲô����realloc()��������free����malloc()???
//	//��Ϊ���������������ջ��������
//	//st1С��st2
//	//st1��st2�����൱
//	//st1����st2
//
//	//Stack st3;
//	////st3.Push(1);
//	//st3.Push(2);
//
//	//st3 = st3;//��ֹ�Լ����Լ���ֵ�������жϼ���
//
//	////myQueue��Date��operator= �������󣬲���Ҫ���ֶ�д��
//	//myQueue q1;
//	//q1.Push(1);
//	//q1.Push(2);
//	//myQueue q2;
//	//q2.Push(2);
//	//q2.Push(2);
//
//	//q1 = q2;
//
//}
//
//void TestDate3() {
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	int ret = d1 > d2;
//
//	(d1 + 1000).Print();
//	d2 += 10000;
//	d2.Print();
//	d1 += -20000;
//	d1.Print();*/
//
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	int ret = d1 > d2;
//
//	(d1 - 1000).Print();
//	d2 -= 10000;
//	d2.Print();
//	d1 -= -10000;
//	d1.Print();*/
//
//	//	ǰ�úͺ��ú�������������غͺ������أ�
//	//	���ö���һ��int������Ŀ������ǰ�����֣��ɱ��������ݣ����ɺ�������
//	//	�����������ͣ�ǰ������û���û�в��
//	//	�����Զ������ͣ�ǰ�ñȺ����������ο������캯���ĵ��ã����Ծ���ʹ��ǰ��++/--
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	d1.Print();
//	(++d1).Print();
//	d1.Print();
//
//	d2.Print();
//	(d2++).Print();
//	d2.Print();*/
//
//	/*Date d1(2022, 10, 11);
//	Date d2(2022, 10, 11);
//	d1.Print();
//	(--d1).Print();
//	d1.Print();
//
//	d2.Print();
//	(d2--).Print();
//	d2.Print();*/
//	
//	Date d1(2022, 10, 12);
//	Date d2(2020, 12, 28);
//	cout << (d1 < d2) << endl;
//	cout << d1 - d2 << endl;
//}
//
//void TestDate4() {
//	Date d1;
//	//cin >> d1;
//	//d1 >> cin;//�����������>> ���Ҳ���������
//
//	Date d2;
//	//cin >> d2;
//	//cin >> d2;// operator>>(cin, d2);
//	//d2 << cout;
//	cout << d2;
//}
//
//void TestDate5() {
//	Date d1;
//	cout << &d1 << endl;
//
//	/*const Date d2;
//	cout << &d2 << endl;*/
//}
////int main() {
////
////	//TestDate1();
////	//TestDate2();
////	//TestSatck();
////	//TestDate3();
////	//TestDate4();
////	TestDate5();
////	return 0;
////}



////////////////////////////////////////////////////////////////////////////////////////////////
//2022 - 10 - 13
//#include <iostream>
//#include <assert.h>
//using namespace std;



//��ʼ���б�
//class Date {
//public:
//	
//	////Ĭ�� ����
//	//Date(int year = 1, int month = 1, int day = 1) {
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	//��ʼ���б�
//	Date(int year = 1, int month = 1, int day = 1) :
//		_year(year)
//		, _month(month)
//		, _day(day) {
//
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Stack {
//public:
//	////�������ڳ�ʼ��
//	//Stack(int capacity = 4) {
//	//	_array = (int*)malloc(sizeof(int) * capacity);
//	//	_top = 0;
//	//	_capacity = capacity;
//	//	if (_array == nullptr) {
//	//		perror("Stack(int capacity = 4)");
//	//		exit(-1);
//	//	}
//	//	memset(_array, 0, sizeof(int) * _capacity);
//	//}
//	////��ʼ���б� - 1
//	//Stack(int capacity = 4)
//	//	:_array((int*)malloc(sizeof(int)*capacity))
//	//	,_top(0)
//	//	,_capacity(capacity){
//	//	if (_array == nullptr) {
//	//		perror("Stack(int capacity = 4)");
//	//		exit(-1);
//	//	}
//	//	memset(_array, 0, sizeof(int) * _capacity);
//	//}
//	//��ʼ���б� - 2 - �뺯�����ڳ�ʼ������ʹ�ã����ã�
//	Stack(int capacity = 4)
//		: _top(0)
//		, _capacity(capacity) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Stack(int capacity = 4)");
//			exit(-1);
//		}
//		memset(_array, 0, sizeof(int) * _capacity);
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};

//int main() {
//	Stack st;
//
//	return 0;
//}


//class A {
//public:
//	A(int n) 
//	:_a(10)
//	,_b(2233)
//	,_c(n){
//	}
//private:
//	const int _a;
//	int _b = 10;//ȱʡֵ
//	int& _c;
//};

//���캯������--��ʼ���б�
//���캯����ɳ�ʼ���Ĺ��ܿ��Է�Ϊ�����֣�
//1.��ʼ���б���е� �����ʼ��
//2.���캯�����ڵĶԳ�ʼ���б��Ѷ�������ĳ�ʼ��������˵��ֵ����
//
//ÿ�����Ա����Ĭ�ϣ���ʽ�ģ����ᾭ����ʼ���б�
//����Ҳ������ʽ���ڳ�ʼ���б���д��
//Ҳ����˵�����������ڳ�ʼ���б����Ƿ���ʽ�����Ա�������ж����ʼ������Ա���������ڳ�ʼ���б������ʼ��
//
//�������ʱ�����Ա�������� �����ʼ��
//ϸ�����Ա������ �����ʼ����
//���Ա������ �����ʼ�� �����ڳ�ʼ���б�׶�
//�����Ա�����ڳ�ʼ���б���� �����ʼ��
//���ڹ��캯���ڽ��е������Ա�����ĸ�ֵ��������Ҫ�Ĳ��������ڹ��캯���ڽ��еĲ��ܳ�֮Ϊ �����ʼ�� ��ֻ�ܽ�����ʼ��
// �Ͼ�һ�����Ա��������������ֻ�ܶ���һ��
// 
//������ͨ������˵���ڲ��ڳ�ʼ���б���ʽ�����ʼ�� �����ԣ���Ϊ��ͨ���� �����ʼ�� ֮�󻹿����ڹ��캯�����޸�
// 
//
//���ڶ���֮�󲻿��޸ĵı�����const���εġ����õģ���
//���Ǳ�����ʽ�ڳ�ʼ���б���ж����ʼ�����������ڹ��캯�����ڽ��г�ʼ�����ں������ڳ�Ϊ��ֵҲ��������
//��Ϊ���б������Ѿ��ڳ�ʼ���б����ʼ������
//
//�����Զ������ͣ���ʼ���б�ʱ����ø����͵�Ĭ�Ϲ��캯����
//�������û��Ĭ�Ϲ��캯�����Ǿ���Ҫ�ڳ�ʼ���б��ֶ��Ը��Զ������ͽ��ж����ʼ������Ȼ�ͻᱨ�������ǣ��Ҳ������Զ������͵�Ĭ�Ϲ��캯����

//int main() {
//	int x = 100;
//	A a1(x);
//	return 0;
//}

//class B {
//public:
//	/*B(int b=1)//ǿ���ȱʡĬ�Ϲ��캯��
//	:_b1(b){
//
//	}*/
//	B(int b)//���캯�����贫��
//		:_b1(b) {
//
//	}
//private:
//	int _b1;
//};
//
//class A {
//public:
//	/*A(int n)
//		:_a(10)
//		, _b(2233)
//		, _c(n) {
//	}*/
//	A(int n)
//		: _a(10)
//		, _b(2233)
//		, _c(n) 
//		, _d(1000){
//	}
//private:
//	const int _a;
//	int _b = 10;//ȱʡֵ
//	int& _c;
//	B _d;//�Զ�������
//};
//
//int main() {
//	int x = 233;
//	A a1(x);
//	return 0;
//}


//class A {
//public:
//	A(int a)
//	:_a1(a)
//	,_a2(_a1){}
//	void Print() {
//		cout << _a1 << " " << _a2 << endl;
//	}
//private:
//	int _a2;
//	int _a1;
//};
////��ʼ���б��� ����ʵ�ʶ����ʼ�� ��˳�������������˳����ͬ��Ҳ����˵����������˳������˱�����ʼ���б��ʼ����˳�򣬶����ʼ���б��б�����д��˳���޹�
////�������������ĵײ�ʵ���й�
//
//int main() {
//
//	A a(1);
//	a.Print();
//	return 0;
//}

//Aû��Ĭ�Ϲ���
//class A {
//public:
//	A(int a)
//		:_a1(a) {}
//private:
//	int _a1;
//};
//����B��Ķ���ʱ�����B��Ĭ�Ϲ��죬��B��Ĭ�Ϲ����ʼ���б�����A��Ĭ�Ϲ��죬��Aû��Ĭ�Ϲ��죬���Ա�����������û��B��Ĭ�Ϲ��캯����
//������B�Ķ��󲢲��ᱨ����Ϊû�е���B��Ĭ�Ϲ��죻
//class B {
//public:
//
//private:
//	A _aa;
//};
//
//int main() {
//
//	//A a(1);
//	//B b;
//	return 0;
//}
//���ڹ��캯���Ľ��飺
//����ʹ�ó�ʼ���б��ʼ��
// 
// 
//�ྡ���ṩĬ�Ϲ��죬�ر���ȫȱʡ��Ĭ�Ϲ���ʮ�ֺ���


//////////////////////////////////////////////////////////////////////////////////////////////////
//���������캯������ʽ����ת��
// C++98
// 
//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A a1(10);//����
//	A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+��������
//	//�ȼ���	const A tmp(10); A a2(tmp);
//
//	const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	//�ȼ���	const A tmp(100); const A a2(tmp);
//
//
//	//A a3(20);//����
//	//A a4 = a3;//��������
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�
//int main() {
//	A a1(10);//����
//	A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+�������� --->(�������Ż�) ֱ�ӹ���
//	//�ȼ���	const A tmp(10); A a2(tmp);
//
//	const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	//�ȼ���	const A tmp(100); const A& a2 = tmp;
//
//
//	A a4(20);//����
//	A a5 = a4;//��������
//	return 0;
//}


//class A {
//public:
//	explicit A(int a)
//		:_a(a) {
//		cout << "����: A(int a)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
////explicit�ؼ��ֽ�ֹ���캯����ص���ʽ����ת���ķ���
//int main() {
//	A a1(10);//����
//	//A a2 = 10;//explicit���κ��ֹ��ʽ����ת���ķ�����error
//
//	//const A& a3 = 100;//explicit���κ��ֹ��ʽ����ת���ķ�����error
//
//
//	A a4(20);//����
//	A a5 = a4;//��������
//	return 0;
//}
//


//#include <string>
//
//void push_back(const string& s) {
//	;
//}
//int main() {
//	string s1("hello");//����
//	string s2 = "hello";//��ʽ����ת����������ʱ����
//
//	push_back(s1);
//	push_back(s2);
//	push_back("hello");//�Ȳ���������ʱstring�������������ʱ�����ٱ�����
//	return 0;
//}


//�Ե��������캯��������ʽ����ת�����ƹ�--
// C++11
//������ҿ���ֻ��һ�������ѵĹ��캯������ʽ����ת��

//�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�

//class A {
//public:
//	A(int a = 1,int b = 1, int c = 1)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};


//explicit�ؼ������ζ�������캯������ֹ��ʽ����ת���ķ���
//class A {
//public:
//	explicit A(int a = 1, int b = 1, int c = 1)
//		:_a(a)
//		, _b(b)
//		, _c(c) {
//		cout << "����: A(int a = 1,int b = 1, int c = 1)" << endl;
//	}
//	A(A& a) {
//		cout << "��������: A(A& a)" << endl;
//		_a = a._a;
//		_b = a._b;
//		_c = a._c;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};

//int main() {
//	A a1(10, 20, 30);//����
//	A a2 = { 1,2,3 };//����+�������� --> �Ż�Ϊ ����
//	//�ӽ����˵��������ΪA a1(10,20,30) �ȼ��� A a2 = {1,2,3};
//
//	const A& a3 = { 1,2,3 };//����
//	return 0;
//}


//////////////////////////////////////////////////////////////////////
//static

//int Count = 0;
//
//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A a1(1);//����
//	A a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << Count << endl;//Count == 2
//
//	const A& a3 = 1;//����
//	cout << Count << endl;//Count == 3
//	return 0;
//}



//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	static int Count;//����
//private:
//	int _a;
//};
//
//int A::Count = 0;//�����ʼ��
//
////��ֵ����
//void Func1(A a) {
//	;
//}
////��ֵ����
//A Func2() {
//	A a(1);
//	return a;
//}
////�����ô���
//void Func3(A& a) {
//	;
//}
////�����÷��� - �����������
//A& Func4() {
//	A a(1);
//	return a;
//}
////�����÷���
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//����
//	A a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << A::Count << endl;//Count == 2
//
//	const A& a3 = 1;//����
//	cout << A::Count << endl;//Count == 3
//
//	Func1(a1);
//	cout << A::Count << endl;//Count == 4
//	Func2();
//	cout << A::Count << endl;//Count == 6
//	Func3(a1);
//	cout << A::Count << endl;//Count == 6
//	Func4();
//	cout << A::Count << endl;//Count == 7
//	Func5();
//	cout << A::Count << endl;//Count == 8
//
//	//��̬��Count �������κ�һ������Count�ھ�̬��ֻ��һ�ݣ��κ�һ�������ܷ��ʵ�Count
//	//���������������ֻ��˵��Count������A���е�Count�������õ������ͣ������Ƕ�����
//	//�����Ա�����ǳ�����
//	cout << a1.Count << endl;
//	A* ptr = &a1;
//	cout << ptr->Count << endl;
//	ptr = nullptr;
//	cout << ptr->Count << endl;
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//����
//};
//
//int A::Count = 0;//�����ʼ��
//
////��ֵ����
//void Func1(A a) {
//	;
//}
////��ֵ����
//A Func2() {
//	A a(1);
//	return a;
//}
////�����ô���
//void Func3(A& a) {
//	;
//}
////�����÷��� - �����������
//A& Func4() {
//	A a(1);
//	return a;
//}
////�����÷���
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//����
//	A a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << a1.GetCount() << endl;//Count == 2
//
//	const A& a3 = 1;//����
//	cout << a1.GetCount() << endl;//Count == 3
//
//	Func1(a1);
//	cout << a1.GetCount() << endl;//Count == 4
//	Func2();
//	cout << a1.GetCount() << endl;//Count == 6
//	Func3(a1);
//	cout << a1.GetCount() << endl;//Count == 6
//	Func4();
//	cout << a1.GetCount() << endl;//Count == 7
//	Func5();
//	cout << a1.GetCount() << endl;//Count == 8
//	return 0;
//}

//class A {
//public:
//	A(int a)
//		:_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		Count++;
//		_a = a._a;
//	}
//	//��̬��Ա����ֻ�ܵ��þ�̬ ��Ա�����ͺ��������ܵ��÷Ǿ�̬ ��Ա�����ͺ���
//	//��̬��Ա����һ��;�̬��Ա�������ʹ��
//	static int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//����
//};
//
//int A::Count = 0;//�����ʼ��
//
////��ֵ����
//void Func1(A a) {
//	;
//}
////��ֵ����
//A Func2() {
//	A a(1);
//	return a;
//}
////�����ô���
//void Func3(A& a) {
//	;
//}
////�����÷��� - �����������
//A& Func4() {
//	A a(1);
//	return a;
//}
////�����÷���
//A& Func5() {
//	static A a(1);
//	return a;
//}
//int main() {
//	A a1(1);//����
//	A a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << a1.GetCount() << endl;//Count == 2
//
//	const A& a3 = 1;//����
//	cout << A::GetCount() << endl;//Count == 3
//
//	Func1(a1);
//	cout << A::GetCount() << endl;//Count == 4
//	Func2();
//	cout << A::GetCount() << endl;//Count == 6
//	Func3(a1);
//	cout << A::GetCount() << endl;//Count == 6
//	Func4();
//	cout << A::GetCount() << endl;//Count == 7
//	Func5();
//	cout << A::GetCount() << endl;//Count == 8
//	return 0;
//}

//Ӱ���������ڵ�����
/*
static���Σ��ھ�̬��
	�ֲ������������ڱ�Ϊ���������ڼ䣻
	ȫ�ֱ�����������Ϊ���������ڼ䣬��Ӱ��ȫ�ֱ������������ԣ�ʹ��ȫ�ֱ���ֻ���ڱ��ļ��б��ҵ��������ڱ��ļ�
ȫ����
	�ھ�̬�������������ڼ�
�ֲ���
	��ջ�����ӽ���ֲ���ʼ�������ֲ���Ϊֹ
��̬����Ŀռ�
	�ڶ���
������
	�ڳ�����������ֵ���������������ڼ�

*/


//Ҫ�����ֻ����ջ�ϴ���
//class A {
//public:
//	static A GetObj(int a) {
//		A aa1(a);
//		return aa1;
//	}
//private:
//	A(int a)
//		:_a(a) {
//	}
//private:
//	int _a;
//};
//
//int main() {
//	/*static A a1(1);
//	A a2(1);
//	A* a3 = new A;*/
//
//	A a4 = A::GetObj(1);
//	return 0;
//}


//��Ԫ���� - friend
//class A {
//public:
//	friend int GetA(A& a);
//	A(int a = 1)
//		:_a(a) {}
//private:
//	int _a;
//};
//
//int GetA(A& a) {
//	return a._a;
//}
//int main() {
//	A a1(10);
//	cout << GetA(a1) << endl;
//	return 0;
//}

//��Ԫ��
//class A {
//public:
//	friend class B;
//	A(int a = 1)
//		:_a(a) {}
//private:
//	int _a;
//};
//
//class B {
//public:
//	B(int b)
//		:_b(b){}
//	int Add(A& a) {
//		return _b + a._a;
//	}
//private:
//	int _b;
//};
//
//int main() {
//	A a1(10);
//	B b1(20);
//	cout << b1.Add(a1) << endl;
//	return 0;
//}

////������
//class A {
//public:
//	static int x;
//	A(int a = 1)
//		:_a(a){}
//	class B {
//	public:
//		B(int b = 1)
//			:_b(b){}
//		//��B�����ܹ����ʵ�A���˽�г�Ա
//		void GetA(const A& a) {
//			cout << a._a << endl;
//			cout << x << endl;
//		}
//	private:
//		int _b;
//	};
//private:
//	int _a;
//};
//int A::x = 0;
//
////B����A�����У����Ƿ���B���ܵ�A����ͷ����޶���������
//// ������ʵ��Ƕ�׶��壬��A��δ������B����A����B�໥����
////����B����������A����Ԫ�࣬���Է��ʵ�A���κγ�Ա
//
//int main() {
//	cout << sizeof(A) << endl;
//	cout << sizeof(A::B) << endl;
//	return 0;
//}


//��������
//class A {
//public:
//	A(int a = 1)
//		:_a(a){}
//	void Print() {
//		cout << _a << endl;
//	}
//private:
//	int _a;
//};
//
//
//int main() {
//	//��������
//	A a1;
//	A a2(10);
//	A a3 = 10;
//	//A a4();//error
//
//	//��������
//	//��������ֻ��һ�У�һ�����ò��󣬵���ʱ�Ƚ����ã�
//	A();
//	A(10);
//
//	//����������;,�Ż��������Ա�������ò���
//	//ԭ����ֻΪ�˵������ں�����������A����a
//	A a(20);
//	a.Print();
//	//�Ż�
//	A().Print();
//	A(10).Print();
//	return 0;
//}


//���������Ż� -- ��Ҫ��ס
// 
//���������漰��Ĺ���Ϳ������������Ĳ�����ܻ�����Ż���ʡȥ�м�ĳ�����裬���Ч�ʣ�
//���Ҫ��������������󴴽�ʱ���������������������ͬ���Ĺ���
//��Щ�Ż���Ȼ���ڲ�Ӱ����ȷ�Ե�ǰ�� �½��е�

//class A {
//public:
//	A(int a = 1)
//		:_a(a){
//		cout << "���캯��: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "��������: A(const A& a)" << endl;
//		_a = a._a;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//void Func1(A a) {
//	;
//}
//A Func2() {
//	A a(10);
//	return a;
//}
////��ֵ�ļ����Ż�
//A Func3() {
//	//A a(10);
//	return A(10);
//}
//int main() {
//	//�� ���������������캯������ʽ����ת�� ���ܵ��Ż�
//	//A a1 = 10;//����+�������� --> ����
//
//	//�� ����ʱ ���ܵ��Ż�
//	//A a2(10);
//	//Func1(a2);//�ȹ����ڿ�������
//
//	//Func1(A(10));//�ȹ����ٿ������� --> ֱ�ӹ���
//
//	//�� ��������ʱ ���ܵ��Ż�
//	//Func2();//����+��������
//	//A ret = Func2();//����+��������+�������� --> ����+��������
//	
//	////�·��������޷��Ż�
//	//A _ret;
//	//_ret = Func2();//����+����+��������
//
//	//��ֵ���ؼ����Ż�
//	A ret = Func3();//����+��������+�������� --> ����
//}


// 






