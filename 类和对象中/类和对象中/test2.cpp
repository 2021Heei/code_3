//#include "Date.h"



//int main() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2;
//	st2.Push(10);
//	st2.Push(20);
//	st2.Push(30);
//
//	st1 = st2;
//}

//int main() {
//	//myQueue��Date��operator= �������󣬲���Ҫ���ֶ�д��
//	myQueue q1;
//	q1.Push(1);
//	q1.Push(2);
//	myQueue q2;
//	q2.Push(2);
//	q2.Push(2);
//
//	q1 = q2;
//	return 0;
//}

//int main() {
//
//	myQueue q1;
//	q1.Push(1);
//	q1.Push(2);
//	myQueue q2;
//	q2.Push(10);
//	q2.Push(20);
//
//	q1 = q2;
//	return 0;
//}

//class Date
//{
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print()
//	{
//		cout << "Print()" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//	void Print() const
//	{
//		cout << "Print()const" << endl;
//		cout << "year:" << _year << endl;
//		cout << "month:" << _month << endl;
//		cout << "day:" << _day << endl;
//	}
//private:
//	int _year; // ��
//	int _month; // ��
//	int _day; // ��
//};
//
//int main() {
//	Date d1(2022, 1, 13);
//	d1.Print();
//	cout << endl;
//	const Date d2(1970, 1, 1);
//	d2.Print();
//	return 0;
//}

//int main() {
//	/*Date d1;
//	cout << &d1 << endl;*/
//
//	const Date d2;
//	cout << &d2 << endl;
//}

//int main() {
//
//	const Date d2;
//	cout << &d2 << endl;
//}

//////////////////////////////////////////////////////////////////////////////////////////////////////
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

#include <iostream>
#include <assert.h>
using namespace std;

//class Date {
//public:
//	//Ĭ�� ����
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		,_month(month)
//		,_day(day){
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//	int* _p;
//};
//
//int main() {
//
//	Date d;
//	return 0;
//}


//class A {
//public:
//	A(int a = 0) 
//		:_a(a)
//		,_a(a){
//	}
//private:
//	int _a;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class B {
//public:
//	B(int b = 1) :_b(b){
//		cout << "���캯��: B(int b = 1)" << endl;
//	}
//private:
//	int _b;
//	A _aa;
//};



//class A {
//public:
//	A(int a = 0, int b = 10)
//		:_a(a){
//		_b = b;
//	}
//private:
//	int _a;
//	const int _b;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 0, int b = 10)
//		:_a(a){
//		_b = b;
//	}
//private:
//	int _a;
//	int& _b;
//};
//
//int main() {
//
//	A a1;
//	return 0;
//}


//class A {
//public:
//	A(int a) 
//		:_a(a){
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	B(int b = 1) :_b(b) {
//		;
//	}
//private:
//	int _b;
//	A _aa;
//};
//
//int main() {
//
//	B b1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//	}
//private:
//	int _a;
//};
//
//
//int main() {
//
//	A a1;
//	return 0;
//}


//class Stack {
//public:
//	//��ͨ����
//	Stack(int capacity = 4) 
//		:_top(0)
//		,_capacity(capacity){
//
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Stack(int capacity = 4) malloc file");
//			exit(-1);
//		}
//	}
//	~Stack() {
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//int main() {
//	Stack st;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1)
//		:_b(a)
//		,_a(_b) {
//	}
//private:
//	int _a;
//	int _b;
//};
//
//
//int main() {
//
//	A a1;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1, int b = 2, int c = 3)
//		:_a(a)
//		,_b(b)
//		,_c(c){
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//int main() {
//
//	A a1;
//	A a2(10);
//	A a3(10, 20);
//	A a4(10, 20, 30);
//	return 0;
//}

//Aû��Ĭ�Ϲ���
//class A {
//public:
//	A(int a)
//		:_a(a) {}
//private:
//	int _a;
//};
////����B��Ķ���ʱ�����B��Ĭ�Ϲ��죬��B��Ĭ�Ϲ����ʼ���б�����A��Ĭ�Ϲ��죬
////��Aû��Ĭ�Ϲ��죬���Ա�����������û��B��Ĭ�Ϲ��캯����
////������B�Ķ��󲢲��ᱨ����Ϊû�е���B��Ĭ�Ϲ��죻
//class B {
//private:
//	A _aa;
//};
//
//int main() {
//	//B b;
//	return 0;
//}


//class A {
//public:
//	A(int a) 
//		:_a(a){
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	/*B(int b = 1) :_b(b) {
//		;
//	}*/
//private:
//	int _b;
//	A _aa;
//};
//
//int main() {
//
//	B b1;
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

//int main() {
//	//A a1(10);//����
//	//A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+��������
//	////�ȼ���	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	////�ȼ���	const A tmp(100); const A a2(tmp);
//
//
//	A a3(20);//����
//	A a4 = a3;//��������
//	return 0;
//}

//int main() {
//	A a3(20);//����
//	A a4 = a3;//��������
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
//int main() {
//	A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+��������
//	//�ȼ���	const A tmp(10); A a2(tmp);
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
//
//	A tmp(100);//���캯��
//	A a2(tmp);//��������
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
////�±������Թ�����صĲ�����п��ܵ��Ż����ϵı�������֧�֣�
//int main() {
//	//A a2 = 10;//��ʽ����ת�� 10 --> ������ʱA����� --> a2;����+�������� --->(�������Ż�) ֱ�ӹ���
//	////�ȼ���	const A tmp(10); A a2(tmp);
//
//	//const A& a3 = 100;//��ʽ����ת�� ;���õĲ�������100�����õ�����ʱ����A�����
//	////�ȼ���	const A tmp(100); const A& a2 = tmp;
//	A a(10);
//	int aa = (int)a;
//	return 0;
//}


//�Ե��������캯��������ʽ����ת�����ƹ�--
// C++11
//������ҿ���ֻ��һ�������ѵĹ��캯������ʽ����ת��
//
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


////explicit�ؼ������ζ�������캯������ֹ��ʽ����ת���ķ���
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

//int main() {
//	A a2 = { 1,2,3 };//����+�������� --> �Ż�Ϊ ����
//	//�ӽ����˵��������ΪA a1(10,20,30) �ȼ��� A a2 = {1,2,3};
//	return 0;
//}



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
//
//int main() {
//
//	const A& a3 = { 1,2,3 };//����
//	return 0;
//}

//static

//class A {
//public:
//	A(int a = 1):_a(a){}
////private:
//	int _a;
//	static int _b;
//};
//
//int A::_b = 0;
//
//int main() {
//	A aa;
//	cout << A::_b << endl;
//	cout << aa._b << endl;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {}
//	//��̬��Ա����
//	static void Function1() {
//		cout << _b << endl;
//	}
//	//�Ǿ�̬��Ա����
//	void Function2() {
//		cout << _a << " " << _b << endl;
//	}
//private:
//	int _a;
//	static int _b;
//};
//int A::_b = 0;
//int main() {
//
//	A aa;
//	aa.Function1();
//	A::Function1();
//
//	aa.Function2();
//	//A::Function2();//error
//	return 0;
//}


//int Count = 0;
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
//private:
//	int _a;
//};
//
//int main() {
//	A a1(1);//����
//	cout << Count << endl;//Count == 1
//	A a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << Count << endl;//Count == 2
//
//	const A& a3 = 1;//����
//	cout << Count << endl;//Count == 3
//	return 0;
//}


//class a {
//public:
//	a(int a)
//		:_a(a) {
//		count++;
//	}
//	a(a& a) {
//		_a = a._a;
//		count++;
//	}
//	static int count;//����
//private:
//	int _a;
//};
//
//int a::count = 0;//�����ʼ��
//
////��ֵ����
//void func1(a a) {
//	;
//}
////��ֵ����
//a func2() {
//	a a(1);
//	return a;
//}
////�����ô���
//void func3(a& a) {
//	;
//}
////�����÷��� - �����������
//a& func4() {
//	a a(1);
//	return a;
//}
////�����÷���
//a& func5() {
//	static a a(1);
//	return a;
//}
//int main() {
//	a a1(1);//����
//	a a2 = 1;//����+�������� --> ֱ�ӹ���
//	cout << a::count << endl;//count == 2
//
//	const a& a3 = 1;//����
//	cout << a::count << endl;//count == 3
//
//	func1(a1);
//	cout << a::count << endl;//count == 4
//	func2();
//	cout << a::count << endl;//count == 6
//	func3(a1);
//	cout << a::count << endl;//count == 6
//	func4();
//	cout << a::count << endl;//count == 7
//	func5();
//	cout << a::count << endl;//count == 8
//
//��̬��count �������κ�һ������count�ھ�̬��ֻ��һ�ݣ��κ�һ�������ܷ��ʵ�count
//���������������ֻ��˵��count������a���е�count�������õ������ͣ������Ƕ�����
//�����Ա�����ǳ�����
//	cout << a1.count << endl;
//	a* ptr = &a1;
//	cout << ptr->count << endl;
//	ptr = nullptr;
//	cout << ptr->count << endl;
//	return 0;
//}


//class A {
//public:
//	A(int a)
//		:_a(a) {
//	}
//	static int _b;//����
//private:
//	int _a;
//};
//int A::_b = 0;//�����ʼ��
//
//int main() {
//	A a1(1);//����
//	cout << A::_b << endl;
//	cout << a1._b << endl;
//	A* ptr = &a1;
//	cout << ptr->_b << endl;
//	ptr = nullptr;
//	cout << ptr->_b << endl;
//	return 0;
//}



//class A {
//public:
//	A(int a):_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		_a = a._a;
//		Count++;
//	}
//	static int Count;//����
//private:
//	int _a;
//};
//int A::Count = 0;//�����ʼ��
////��ֵ����
//A Func2() {
//	A a(1);//����
//	return a;//��������
//}
//int main() {
//	A a1(1);//����
//	cout << A::Count << endl;//Count == 1
//	Func2();
//	cout << A::Count << endl;//Count == 3
//	return 0;
//}


//class A {
//public:
//	A(int a) :_a(a) {
//		Count++;
//	}
//	A(A& a) {
//		_a = a._a;
//		Count++;
//	}
//	static int Count;//����
//private:
//	int _a;
//};
//int A::Count = 0;//�����ʼ��
////�����ô���
//void Func3(A& a) {
//	;
//}
//int main() {
//	A a1(1);//����
//	cout << A::Count << endl;//Count == 1
//	Func3(a1);
//	cout << A::Count << endl;//Count == 1
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
//int A::Count = 0;//�����ʼ��
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
//	cout << A::Count << endl;//Count == 1
//	A a1(1);//����
//	cout << A::Count << endl;//Count == 2
//	Func4();
//	cout << A::Count << endl;//Count == 3
//	Func5();
//	cout << A::Count << endl;//Count == 3
//	return 0;
//}


//class A {
//public:
//	A(int a):_a(a) {
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
//int A::Count = 0;//�����ʼ��
//
//static A a(1);
////�����÷���
//A& Func5() {
//	return a;
//}
//int main() {
//	cout << A::Count << endl;//Count == 1
//	Func5();
//	cout << A::Count << endl;//Count == 1
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
//	static int GetCount() {
//		return Count;
//	}
//private:
//	int _a;
//	static int Count;//����
//};
//
//int A::Count = 0;//�����ʼ��
//int main() {
//	A a(10);
//	cout << A::GetCount() << endl;
//	return 0;
//}

//class Date {
//public:
//	friend ostream& operator<<(ostream& output, const Date& d);
//	friend istream& operator>>(istream& input, Date& d);
//	Date(int year, int month, int day)
//		:_year(year)
//		,_month(month)
//		,_day(day){}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream & operator<<(ostream & output, const Date & d) {
//	output << d._year << "/" << d._month << "/" << d._day << endl;
//	return output;
//}
//istream& operator>>(istream& input, Date& d) {
//	input >> d._year >> d._month >> d._day;
//	return input;
//}
//int main() {
//	Date d(2022,10,15);
//	cout << d << endl;
//	return 0;
//}


//class A {
//public:
//    friend class B;
//    friend void Function(const A& a, const B& b);
//private:
//    int _a = 1;
//};
//
//class B {
//public:
//    friend void Function(const A& a, const B& b);
//private:
//    int _b = 1;
//};
//
//void Function(const A& a, const B& b) {
//    cout << a._a << endl;
//    cout << b._b << endl;
//}
//
//int main() {
//    A a;
//    B b;
//    Function(a, b);
//    return 0;
//}

////Ҫ�����ֻ����ջ�ϴ���
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
//	A a = A::GetObj(1);
//	return 0;
//}


//class A {
//public:
//    friend class B;
//private:
//    int _a = 1;
//};
//
//class B {
//public:
//    void Function(const A& a) {
//        cout << a._a << endl;
//        cout << _b << endl;
//    }
//private:
//    int _b = 2;
//};
//
//int main() {
//    A a;
//    B b;
//    b.Function(a);
//    return 0;
//}


//class A {
//public:
//
//    class B {
//    public:
//        void Function(A& aa) {
//            cout << aa._a << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//
//int main() {
//    A a;
//    A::B b;
//    b.Function(a);
//    return 0;
//}


//class A {
//public:
//    static int count;
//    class B {
//    public:
//        void Function() {
//            cout << count << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//int A::count = 0;
//int main() {
//
//    A::B b;
//    b.Function();
//    return 0;
//}

//class A {
//public:
//    class B {
//    public:
//        void Function(const A& aa) {
//            cout << aa._a << endl;
//            cout << _b << endl;
//        }
//    private:
//        int _b = 2;
//    };
//
//private:
//    int _a = 1;
//};
//
//int main() {
//
//    A::B b;
//    cout << sizeof(A) << endl;
//    cout << sizeof(A::B) << endl;
//    return 0;
//}


////��������
//class A {
//public:
//	A(int a = 1)
//		:_a(a) {}
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
//	//��������ֻ��һ�У�һ�����ò��󣬵���ʱ�Ƚ����ã�
//	int();
//	int(10);
//	A();
//	A(10);
//	cout << int() << endl;
//	cout << int(10) << endl;
//	A().Print();
//	A(10).Print();
//	return 0;
//}

//int main() {
//	int ret = int();
//	//��������
//	//��������ֻ��һ�У�һ�����ò��󣬵���ʱ�Ƚ����ã�
//	A();
//	A(10);
//
	////����������;,�Ż��������Ա�������ò���
	////ԭ����ֻΪ�˵������ں�����������A����a
	//A a(20);
	//a.Print();
	////�Ż�
	//A().Print();
	//A(10).Print();
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
//	A a1 = 10;//����+�������� --> ����
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



//class A {
//public:
//	A(int a = 1):_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "��������: A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//void Func1(A a) {
//	;
//}
//int main() {
//	//�� ����ʱ ���ܵ��Ż�
//	A a2(10);
//	Func1(a2);//�ȹ����ڿ�������
//	Func1(A(10));//�ȹ����ٿ������� --> ֱ�ӹ���
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	A(const A& a) {
//		cout << "��������: A(const A& a)" << endl;
//		_a = a._a;
//	}
//private:
//	int _a;
//};
//int main() {
//
//	//�� ���������������캯������ʽ����ת�� ���ܵ��Ż�
//	A a1 = 10;//����+�������� --> ����
//}


class A {
public:
	A(int a = 1)
		:_a(a){
		cout << "���캯��: A(int a)" << endl;
	}
	A(const A& a) {
		cout << "��������: A(const A& a)" << endl;
		_a = a._a;
	}
private:
	int _a;
};
A Func2() {
	A a(10);
	return a;
}
int main() {
	//�������޷��Ż�
	A _ret; //����
	_ret = Func2();//����+��������
}


