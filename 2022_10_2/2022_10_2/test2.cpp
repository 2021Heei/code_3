//类的引入
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

//复习C语言结构体 C++向前兼容C语言

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//};
//
//void StackInit(struct Stack* pst) {
//	assert(pst);
//	pst->val = NULL;
//	pst->top = 0;
//	pst->capacity = 0;
//}
//
//void StackPush(struct Stack* pst, int val) {
//	assert(pst);
//	if (pst->top == pst->capacity) {
//		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//		STDataType* tmp = (STDataType*)realloc(pst->val, sizeof(STDataType) * newcapacity);
//		if (tmp == nullptr) {
//			perror("realloc file");
//			exit(-1);
//		}
//		pst->val = tmp;
//		pst->capacity = newcapacity;
//	}
//	pst->val[pst->top] = val;
//	++(pst->top);
//}
//
//void StackDestroy(struct Stack* pst) {
//	assert(pst);
//	free(pst->val);
//	pst->top = pst->capacity = 0;
//}
//
//void test1() {
//	struct Stack st;
//	StackInit(&st);
//	StackPush(&st, 1);
//	StackPush(&st, 2);
//	
//	StackDestroy(&st);
//}
//
//class A {
//public:
//	int a;
//private :
//	int b;
//};
//
//int main() {
//	test1();
//
//	return 0;
//}

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//	void StackInit(struct Stack* pst);
//	void StackPush(struct Stack* pst, int val);
//	void StackPop(struct Stack* pst);
//	int StackTop(struct Stack* pst);
//	bool StackEmpty(struct Stack* pst);
//	void StackDestroy(struct Stack* pst);
//};

//typedef int STDataType;
//struct Stack {
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//	void StackInit();
//	void StackPush(int val);
//	void StackPop();
//	int StackTop();
//	bool StackEmpty();
//	void StackDestroy();
//};


//struct Stack {
//private:
//	STDataType* val;//指针
//	int top;//栈顶的下一个位置
//	int capacity;//栈的容量
//
//public:
//	void StackInit();
//	void StackPush(int val);
//	void StackPop();
//	int StackTop();
//	bool StackEmpty();
//	void StackDestroy();
//};

//升级的struct，与 类 class的功能相同
//C语言用法 - 结构体
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	struct ListNode* next;
//};
//
//typedef int LTDataType;
//struct ListNode {
//	LTDataType val;
//	//C++用法 - 类；C语言不能这么用（C的语法不支持）
//	ListNode* next;
//};
//
//int main() {
//
//	return 0;
//}


//class 类的引入
//class Stack {
//public:
//	void Init(size_t capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Destroy() {
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//
//	void Push(int val) {
//		if (_top == _capacity) {
//			size_t newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			if (tmp == nullptr) {
//				perror("Push flie");
//				exit(-1);
//			}
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top] = val;
//		++_top;
//	}
//	void Pop() {
//		--_top;
//	}
//	int Top() {
//		return _array[_top - 1];
//	}
//	bool Empty() {
//		return _top == 0;
//	}
//
//private:
//	int* _array;//指向数组
//	size_t _top;//栈顶的下一个位置
//	size_t _capacity;//栈容量
//};
//
//void test1() {
//	Stack st;
//	st.Init();
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	st.Push(4);
//	while (!st.Empty()) {
//		cout << st.Top() << " ";
//		st.Pop();
//	}
//	st.Destroy();
//}

//int main() {
//	test1();
//
//	return 0;
//}

//class A {
//public:
//	void Print1() {
//		_a = _b = 1;
//		cout << _a << " " << _b << endl;
//	}
//private:
//	int _a;
//	int _b;
//public:
//	void Print2() {
//		_a = _b = 2;
//		cout << _a << " " << _b << endl;
//	}
//};
//int main() {
//	A A1;
//	A1.Print1();
//	A1.Print2();
//	return 0;
//}

//class Date {
//public:
//	void Init(int year, int month, int day) {
//		//这样不太好区分类私有成员和函数形参
//		//解决办法是：
//		//1.默认左边就是类私有成员，函数形参是右边
//		//2.左边类私有成员加上类域修饰，如：year --> Date::year
//		//3.定义私有成员时手动修饰一下，如：year --> _year/year_/m_year/mYear等
//		year = year;
//		month = month;
//		day = day;
//	}
//
//private:
//	int year;
//	int month;
//	int day;
//};

//class Date {
//public:
//	void Init(int year, int month, int day) {
//		Date::year = year;
//		Date::month = month;
//		Date::day = day;
//	}
//	void Print() {
//		cout << year << "/" << month << "/" << day << endl;
//	}
//private:
//	int year;
//	int month;
//	int day;
//};
//int main() {
//	Date d;
//	d.Init(2122, 10, 10);
//	d.Print();
//}

//class Date {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//	//_day 或 day_ 或 m_day 或 mDay等
//};
//int main() {
//	Date d;
//	d.Init(2122, 10, 10);
//	d.Print();
//}

//namespace B {
//	void function() {
//		cout << "namespace B\n" << endl;
//	}
//	int c = 20;
//}
//int c = 10;
//int main() {
//	cout << B::c << endl;
//	B::function();
//	return 0;
//}
//class A {
//public:
//	void func() {
//		cout << "hello world!\n" << endl;
//	}
//	int _a;
//private:
//	int _b;
//};
//
//int main() {
//	A::_a = 10;
//	A::func();
//	
//	return 0;
//}

//class A {
//public:
//	//在公共代码区，不占类的储存空间，
//	//调用时编译器会直接到公共代码区找相应的函数
//	void func() {
//		cout << "hello world!\n" << endl;
//	}
//private:
//	char _a;//0
//			//1 -> 3
//	int _b;//4 -> 7  共8byte
//};
//
//int main() {
//	sizeof(A);
//	A A1;
//	sizeof(A1);
//	return 0;
//}


//int main() {
//	//A::a = 10;//类还没有实体（实例），还只是一个类型
//	//A::func();//this指针
//
//	A A1;
//	A1.a = 10;
//	A1.func();
//	A* pA1 = &A1;
//	pA1->a = 20;
//	A1.func();
//
//	return 0;
//}


//class A {
//	void func2() {
//		;
//	}
//};
////空类
//class B{
//};
////类储存方式的选择：
////类大小的计算：与C语言结构体相同
//int main() {
//
//	A A1;
//	//不储存有效数据，占位，标识对象存在
//	cout << sizeof(A1) << endl;
//	B B1;
//	//不储存有效数据，占位，标识对象存在
//	cout << sizeof(B1) << endl;
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print(A* const this)//修饰指针this        常量指针
//	  void Print(const A* this)//修饰指针指向内容    指针常量
//	void Print() {
//		cout << "this: " << this << endl;
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << this->_year << "/" << this->_month << "/" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	A a, b;
//	a.Init(2122, 10, 3);
//	a.Print();
//	cout << "&a: " << & a << endl;
//	b.Init(3122, 10, 3);
//	b.Print();
//	cout << "&b: " << &b << endl;
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	A a;
//	a.Init(2122, 10, 3);
//	a.Print();
//
//	A b;
//	b.Init(3122, 10, 3);
//	b.Print();
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		this->_year = year;
//		this->_month = month;
//		this->_day = day;
//	}
//	void Print() {
//		cout << "this: " << this << endl;
//		//cout << _year << "/" << _month << "/" << _day << endl;
//		cout << this->_year << "/" 
//			<< this->_month << "/" << this->_day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	A a;
//	a.Init(2122, 10, 3);
//	a.Print();
//	cout << "&a: " << &a << endl;
//
//	A b;
//	b.Init(3122, 10, 3);
//	b.Print();
//	cout << "&b: " << &b << endl;
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////////////

//class Date {
//public:
//	/*void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	//构造函数
//	//对象创建时，自动调用构造函数对对象进行初始化  
//	//函数名和类名相同
//	//没有返回值且不写返回类型位置啥也不写
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main() {
//
//	Date a(2020, 1, 2);
//	a.Print();
//
//	Date b(2010, 10, 10);
//	b.Print();
//	return 0;
//}

//class Date {
//public:
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	Date a(2022, 10, 10);
//	a.Print();
//	return 0;
//}


//class Date {
//public:
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(int year, int month) {
//		_year = year;
//		_month = month;
//		_day = 1;
//	}
//	Date(int year) {
//		_year = year;
//		_month = 0;
//		_day = 0;
//	}
//	Date() {
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	Date a1(2021, 1, 1);
//	Date a2(2022, 2);
//	Date a3(2023);
//	//Date a4;
//	a1.Print();
//	a2.Print();
//	a3.Print();
//	//a4.Print();
//
//	Date a4();//error
//	a4.Print();
//
//
//
//
//	//a4.Print();
//	////Date a3();//使用无参构造函数初始化时，不加括号，否则会与 函数声明混淆
//	////Date func();// warning C4930: “Date a3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	//a1.Print();
//	//a2.Print();
//	////a3.Print();
//	return 0;
//}


//class Date {
//public:
//	/*Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date() {
//		_year = 0;
//		_month = 0;
//		_day = 0;
//	}*/
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	Date a1;
//	a1.Print();
//	return 0;
//}
//
//
//class Date {
//public:
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//
//	Date a1;
//	a1.Print();
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1970, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//全缺省和无参构造函数可以同时存在，但函数调用时会产生二义性，
//	//全缺省构造函数可以完美代替无参构造函数
//	Date() {
//		_year = 1970;
//		_month = 1;
//		_day = 1;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//
//	Date a1(2020, 1, 2);
//	Date a2;
//
//	a1.Print();
//	a2.Print();
//	return 0;
//}

//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//class Stack {
//public:
//	//构造函数
//	Stack(int capacity = 4) {
//		cout << "构造函数: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//
//class Queue {
//public:
//	void Push(int val) {
//		_stPush.Push(val);
//	}
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size;
//};
//
//int main() {
//
//	Queue q;
//	return 0;
//}
//
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

//class Stack {
//public:
//	//构造函数
//	Stack(int capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//class Queue {
//public:	//...
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 0;//内置类型变量size声明时给一缺省值
//};
//int main() {
//	Queue q;
//	return 0;
//}

//class Date {
//public:
//	//Date(int year = 1, int month = 1, int day = 1) {
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//private:
//	int _year  = 1;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 1;
//	int _day   = 1;
//};
//
//int main() {
//	Date d;
//	d.Print();
//	return 0;
//}

//class Stack {
//public:
//	//缺省值能声明或定义一处给出
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
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
//class Queue {
//public:
//	//初始化形参列表
//	Queue(int capacity = 8) : _stPush(8), _stPop(8), _size(0) {
//		//_size = 10;
//	}
//
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int _size;
//};
//
//int main() {
//
//	Queue q;
//	return 0;
//}

//class Stack {
//public:
//	//缺省值能声明或定义一处给出
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//class Queue {
//public:
//	//初始化形参列表
//	Queue(int capacity = 100) :
//		_stPush(capacity), 						
//		_stPop(capacity),					
//		_size(0) {
//		//_size = 10;
//	}
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int _size;
//};
//int main() {
//
//	Queue q;
//	return 0;
//}


//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//class Stack {
//public:
//	//构造函数
//	Stack(int capacity = 4) {
//		cout << " 构造函数 " << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//
//	}
//	//析构函数 - 类似于Destroy()功能，完成资源的清理，不清理类对象本身
//	//局部域、全局域、动态申请的，影响生命周期
//	~Stack() {
//		cout << " 析构函数 " << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//int main() {
//	Stack st;
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	return 0;
//}

//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;



//class Stack {
//public:
//	//构造函数
//	Stack(int capacity = 4) {
//		cout << "构造函数: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "析构函数: ~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	int _top;
//	int _capacity;
//};
//void Function() {
//	Stack st;
//}
//int main() {
//	Function();
//	Stack st;
//	return 0;
//}


//class Stack {
//public:
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		if (_array == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
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
//class myQueue {
//public:
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 10;
//};
//int main() {
//
//	myQueue q;
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "构造函数: Date(int year = 1, int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//显式写这个析构 只为了说明调用先后的关系
//	~Date() {
//		cout << "析构函数: ~Date()" << endl;
//		_year = 0; _month = 0; _day = 0;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//
//	Date d1;
//	Date d2;
//	Date d3;
//	cout << endl;
//	return 0;
//}


#include <iostream>
#include <cassert>
#include <cstdlib>
using namespace std;

//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//我们不写，编译器默认会生成拷贝构造函数
//	//内置类型编译器自动拷贝构造
//	//自定义类型看具体情况，可能需要我们字节写，也可能不需要我们自己写
//	Date(Date& d) {
//		cout << "拷贝构造 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//用指针就不是拷贝构造了，是普通构造函数
//	/*Date(Date* d) {
//		cout << "普通构造 Date(Date &d)" << endl;
//		_year = d->_year;
//		_month = d->_month;
//		_day = d->_day;
//	}*/
//private:
//	int _year = 0;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 0;
//	int _day = 0;
//};
//
////传值传参，先调用了拷贝构造，形参是实参的别名
//void Func1(Date d) {
//	cout << "Func1()" << endl;
//}
////传引用传参，形参是实参的别名
//void Func2(Date& d) {
//	cout << "Func2()" << endl;
//}
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//拷贝构造 - 拷贝初始化
//	/*Func1(d1);
//	Func2(d1);*/
//	return 0;
//}

//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "构造函数 Date(int year = 1," 
//				"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//显式写出的拷贝构造函数
//	Date(Date& d) {
//		cout << "拷贝构造函数 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//构造初始化
//	Date d2(d1);//拷贝构造 - 赋值初始化
//	return 0;
//}

//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "构造函数 Date(int year = 1,"
//			"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//	//显式写出的拷贝构造函数
//	Date(const Date d) {
//		cout << "拷贝构造函数 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//构造初始化
//	Date d2(d1);//拷贝构造 - 赋值初始化
//	return 0;
//}
//
//Date(const Date d) {
//	_year = d._year;
//	_month = d._month;
//	_day = d._day;
//}


//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		cout << "构造函数 Date(int year = 1,"
//			"int month = 1, int day = 1)" << endl;
//		_year = year; _month = month; _day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//int main() {
//	Date d1(2022, 11, 11);//构造初始化
//	Date d2(d1);//拷贝构造 - 赋值初始化
//	return 0;
//}

////对于内置类型
////浅拷贝（值拷贝）时，编译器默认生成的拷贝构造就是够用的
////深拷贝时，内置类型也许要自己写拷贝构造函数，即编译器默认生成的不完全适合
//class Stack {
//public:
//	//普通构造
//	Stack(int capacity = 4) {
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//手写拷贝构造
//	Stack(const Stack& st) {
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
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
////需要写析构函数的类，都需要写深拷贝的拷贝构造，因为有资源需要额外创建空间并拷贝到该空间
////比如说动态申请的空间资源......
////不需要写析构函数的类，默认生成的浅拷贝的拷贝构造就足够使用了
//int main() {
//	Stack st1;
//	st1.Push(1);
//	st1.Push(2);
//	Stack st2(st1);
//	st2.Push(3);
//	//析构的时候出问题了，同一块空间free了两次
//	return 0;
//}


//对于内置类型
//浅拷贝（值拷贝）时，编译器默认生成的拷贝构造就是够用的
//深拷贝时，内置类型也许要自己写拷贝构造函数，即编译器默认生成的不完全适合

//class Stack {
//public:
//	Stack(int capacity = 4) {
//		cout << "Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	~Stack() {
//		cout << "~Stack()" << endl;
//		free(_array);
//		_array = nullptr;
//		_top = _capacity = 0;
//	}
//private:
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//int main() {
//	Stack st1;
//	Stack st2(st1);
//	//析构的时候出问题了，同一块空间free了两次
//	return 0;
//}
//



//class Stack {
//public:
//	//普通构造
//	Stack(int capacity = 4) {
//		cout << "普通构造: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//手写拷贝构造
//	Stack(const Stack& st) {
//		cout << "拷贝构造: Stack(const Stack& st)" << endl;
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity * 2;
//			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
//			assert(tmp);
//			_array = tmp;
//			_capacity = newcapacity;
//		}
//		_array[_top++] = val;
//	}
//	~Stack() {
//		cout << "析构: ~Stack()" << endl;
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
//class myQueue {
//	//我们没写，这里生成了 默认构造函数，但编译器对内置类型一般不做处理，是随机值(如果编译器处理那就是0)
//	//对自定义类型就调用自定义类型变量的构造函数
//private:
//	Stack stPush;
//	Stack stPop;
//	int size;
//};
//
////myQueue的成员变量包含自定义类型，但是myQueue就不需要写拷贝构造
////因为对于内置类型size，编译器会默认生成拷贝构造
////对于自定义类型stPush和stPop，编译器会直接调用它们自己的拷贝构造函数
////总的来说，是看具体的需求和情况
//int main() {
//
//	myQueue q1;
//	myQueue q2(q1);
//	return 0;
//}


//class Stack {
//public:
//	//普通构造
//	Stack(int capacity = 4) {
//		cout << "普通构造: Stack(int capacity = 4)" << endl;
//		_array = (int*)malloc(sizeof(int) * capacity);
//		_top = 0;
//		_capacity = capacity;
//	}
//	//手写拷贝构造
//	Stack(const Stack& st) {
//		cout << "拷贝构造: Stack(const Stack& st)" << endl;
//		_array = (int*)malloc(sizeof(int) * st._capacity);
//		assert(_array);
//		//memcpy(des, src, sizeByte)
//		memcpy(_array, st._array, sizeof(int) * st._top);
//		_top = st._top;
//		_capacity = st._capacity;
//	}
//	~Stack() {
//		cout << "析构: ~Stack()" << endl;
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
//class myQueue {
//private:
//	Stack stPush;
//	Stack stPop;
//	int size;
//};
//int main() {
//
//	myQueue q1;
//	myQueue q2(q1);
//	return 0;
//}

//class A {
//public:
//	A(int a, int b) {
//		cout << "构造函数: A(int a, int b) " << this <<  endl;
//		_a = a;
//		_b = b;
//	}
//	A(const A& A1) {
//		cout << "拷贝构造函数: A(const A& A1) " << this << endl;
//		_a = A1._a;
//		_b = A1._b;
//	}
//	~A() {
//		cout << "析构函数: ~A() " << this << endl;
//		_a = _b = 0;
//	}
//private:
//	int _a;
//	int _b;
//};
//
//A Copy(const A A2) {
//	A A3(A2);
//	return A3;
//}
//int main() {
//
//	A A1(1, 1);
//	Copy(A1);
//	return 0;
//}




//class Date
//{
//public:
//	Date(int year, int minute, int day)
//	{
//		cout << "Date(int,int,int):" << this << endl;
//	}
//	Date(const Date& d)
//	{
//		cout << "Date(const Date& d):" << this << endl;
//	}
//	~Date()
//	{
//		cout << "~Date():" << this << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//Date Test(Date d)
//{
//	Date temp(d);
//	return temp;
//}
//int main()
//{
//	Date d1(2022, 1, 13);
//	Date d2(Test(d1));
//	return 0;
//}



class Date {
public:
	//构造
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
	}

	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
//private:
	int _year;
	int _month;
	int _day;
};
//函数完成功能
bool isEqual(const Date& d1, const Date& d2) {
	return d1._year == d2._year &&
		d1._month == d2._month &&
		d1._day == d2._day;
}
//c++引入，但是在类外不能访问到私有成员变量了，除了友元函数
bool operator==(const Date& d1, const Date& d2) {
	return d1._year == d2._year &&
		d1._month == d2._month &&
		d1._day == d2._day;
}

int main() {
	Date d1(2022, 11, 11);
	Date d2(2022, 11, 11);
	int ret1 = d1 == d2;
	cout << "(d1 == d2): " << (d1 == d2) << endl;
	cout << "ret1: " << ret1 << endl;
	int ret2 = operator==(d1, d2);
	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
	cout << "ret2: " << ret2 << endl;
	return 0;
}