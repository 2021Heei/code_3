//#include "statement.h"
//类的引入
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;

//复习C语言结构体 C++向前兼容C语言
//typedef int STDataType;
//struct Stack {
//	STDataType* val;
//	int top;
//	int capacity;
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
//void StackPop(struct Stack* pst) {
//	assert(pst);
//	--(pst->top);
//}
//
//int StackTop(struct Stack* pst) {
//	assert(pst);
//	return pst->val[pst->top - 1];
//}
//bool StackEmpty(struct Stack* pst) {
//	assert(pst);
//	return pst->top == 0;
//}
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
//	StackPush(&st, 3);
//	while (!StackEmpty(&st)) {
//		printf("%d ", StackTop(&st));
//		StackPop(&st);
//	}
//	StackDestroy(&st);
//}
//int main() {
//	test1();
//	return 0;
//}


////升级的struct，与 类 class的功能相同
//typedef int STDataType;
//struct Stack {
//	STDataType* _val;
//	int _top;
//	int _capacity;
//
//	void Init(int capacity) {
//		_val = (STDataType*)malloc(sizeof(STDataType) * capacity);
//		if (_val == nullptr) {
//			perror("Init file");
//			exit(-1);
//		}
//		_top = 0;
//		_capacity = capacity;
//	}
//
//	void Push(int val) {
//		if (_top == _capacity) {
//			int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//			STDataType* tmp = (STDataType*)realloc(_val, sizeof(STDataType) * newcapacity);
//			if (tmp == nullptr) {
//				perror("realloc file");
//				exit(-1);
//			}
//			_val = tmp;
//			_capacity = newcapacity;
//		}
//		_val[_top] = val;
//		++(_top);
//	}
//	void Pop() {
//		--(_top);
//	}
//
//	int Top() {
//		return _val[_top - 1];
//	}
//	bool Empty() {
//		return _top == 0;
//	}
//	void Destroy() {
//		free(_val);
//		_val = nullptr;
//		_top = _capacity = 0;
//	}
//};
//
//
//void test1() {
//	//C++类的用法
//	Stack st;
//	st.Init(10);
//	st.Push(1);
//	st.Push(2);
//	st.Push(3);
//	while (!st.Empty()) {
//		cout << st.Top() << " ";
//		st.Pop();
//	}
//	st.Destroy();
//}
//int main() {
//	test1();
//	return 0;
//}

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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
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
//
//
//
//int main() {
//	//test1();
//
//	return 0;
//}

//class 默认为私有,类外不能访问私有成员
//访问限定符：
//public
//private
//protect
//数据成员可以在（使用时的）上也可以在下，因为类是一个整体，不分上下。不需要像C语言那样先声明再使用
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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
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
//
//int main() {
//	test1();
//
//	return 0;
//}


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
//	int* _array;
//	size_t _top;
//	size_t _capacity;
//};
//
//struct ListNode {
//	int val;
//	struct ListNode* next;
//};
//
//void test1() {
//	//ListNode::val;//error
//	//Stack::Init();//error
//	ListNode node;
//	node.val;//true
//	Stack st;
//	st.//
//
//}
//	
//int main() {
//	test1();
//	
//	return 0;
//}


//为什么要声明和定义分离？
//方便他人阅读你的代码
//避免源码泄露
//

//类作用域的提出 - 定义时类成员函数需要加上类域，
//成员函数先在其内部局部访问->再到类中访问->再到全局访问。


//类私有成员命名习惯
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
//
//int main() {
//	Date d;
//	d.Init(2022, 10, 3);
//
//	return 0;
//}



////类成员函数直接定义在类里面，编译器把它默认当做内联函数处理，不进符号表
//// 声明和定义分离之后，就是普通函数，进符号表
//int main() {
//	Stack st;
//	st.Init();
//	st.Destroy();//声明定义分离，且内联函数，error，链接错误
//	Queue q;
//	q.Init();
//	q.Destroy();
//
//	return 0;
//}

//class A {
//public:
//	void func() {
//		;
//	}
//	int a;
//	int b;
//};
//
//int main() {
//	//A::a = 10;//类还没有实体（实例），还只是一个类型
//	//A::func();//this指针
//
//	A A1;
//	A1.a = 10;
//	cout << A1.a << endl;
//	A* pA1 = &A1;
//	pA1->a = 20;
//	cout << A1.a << endl;
//
//	return 0;
//}


//class A {
//public:
//	void func() {
//		cout << a<< endl;
//	}
//	int a;
//};
////类储存方式的选择：
////类大小的计算：与C语言结构体相同
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
//public:
//	void func() {
//		cout << a << endl;
//	}
//	char ch;
//	int a;
//};
//
//class A2 {
//	void func2() {
//		;
//	}
//};
////空类
//class A3{
//};
////类储存方式的选择：
////类大小的计算：与C语言结构体相同
//int main() {
//
//	A a1;
//	cout << sizeof(a1) << endl;
//	A2 a2;
//	//不储存有效数据，占位，标识对象存在
//	cout << sizeof(a2) << endl;
//	A3 a3;
//	//不储存有效数据，占位，标识对象存在
//	cout << sizeof(a3) << endl;
//
//
//	return 0;
//}

//class A {
//public:
//	void Init(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//void Print(A* const this)//修饰指针this
//	//void Print(const A* this)//修饰指针指向内容
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

//为什么要设计出this指针？
//这还是要从C语言说起：
//C语言实现数据结构时，比如实现一个栈，首先需要创建一个栈的结构体类型
//typedef struct Stack{ ...}Stack;
//在定义栈的功能函数时往往需要传入栈实例的地址
//void StackInit(Stack* pst) { };
//void StackPush(Stack* pst) { };
//既然每个栈的函数都需要传如栈实例的地址，C++中在实现类成员函数时就把传入数据结构实例的地址
//默认传入了，就被隐藏起来了，对该地址的使用也隐藏起来了。也就是说变成了编译器帮助使用者完成，即编译器做的事增多了，使用者要做的事变少了。

////////////////////////////////////////////////////////////////////////////////////////



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
//
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
//	//构造函数
//	//对象创建时，自动调用构造函数对对象进行初始化  
//	//函数名和类名相同
//	//没有返回值且不写返回类型位置啥也不写
//	Date(int year, int month, int day) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
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
//	Date a3();//使用无参构造函数初始化时，不加括号，否则会与 函数声明混淆
//	//Date func();// warning C4930: “Date a3(void)”: 未调用原型函数(是否是有意用变量定义的?)
//	a1.Print();
//	a2.Print();
//	//a3.Print();
//	return 0;
//}

//class Date {
//public:
//	//构造函数
//	//对象创建时，自动调用构造函数对对象进行初始化  
//	//函数名和类名相同
//	//没有返回值且不写返回类型位置啥也不写
//	Date(int year = 1970, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//全缺省和无参构造函数可以同时存在，但函数调用时会产生二义性，
//	//全缺省构造函数可以完美代替无参构造函数
//	/*Date() {
//		_year = 1970;
//		_month = 1;
//		_day = 1;
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

//class A {
//public:
//	A() {
//		cout << "构造函数 A()" << endl;
//		_a = 10;
//	}
//	~A() {
//		cout << "析构函数 ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//class B {
//public:
//	~B() {
//		cout << "析构函数 ~B()" << endl;
//	}
//private:
//	//内置类型，
//	// C++标准没有规定默认构造函数需要是否对内置类型进行初始化
//	//大多数编译器实现的默认构造函数不初始化内置类型
//	int _b1;
//	int _b2;
//	//自定义类型，
//	//默认构造函数将调用该类的默认构造函数初始化
//	//默认构造函数->自定义构造函数->自定义析构函数->默认析构函数
//	//先构造的后析构
//	A A1;
//};
//
//int main() {
//	B B1;
//	return 0;
//}

//类A我们知道定义了构造函数和析构函数
//class A {
//public:
//	A() {
//		cout << "构造函数 A()" << endl;
//		_a = 10;
//	}
//	~A() {
//		cout << "析构函数 ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
////类B我们没有定义构造函数
//class B {
//public:
//	~B() {
//		cout << "析构函数 ~B()" << endl;
//	}
//private:
//	//内置类型，
//	int _b1;
//	int _b2;
//	//自定义类型，
//	A A1;
//};
//
//int main() {
//	B B1;
//	return 0;
//}

//1.语法特性
//........

//2.注意什么时候写，什么时候不写
//以Stack和MyQueue为例：
//什么时候需要自己写构造函数？
//什么时候不需要自己写？
//要看实际的需求，编译器默认生成的够用就不需要自己写，不够用就自己写。
//往往内置类型需要写，默认构造函数不对内置类型做处理，需要手动处理
//自定义类型不需要写，自定义类型内部往往有自己构造函数的实现，只需要调用已有的构造函数即可

//什么时候需要写析构函数？
//什么时候不需要写析构函数？
//要看实际需求，编译器默认生成的够用就不需要自己写，不够用就自己写。

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
//class myQueue {
//public:
//	//初始化形参列表
//	/*myQueue(int capacity = 8) : _stPush(8),_stPop(8){
//		size = 10;
//	}*/
//	/*void Push(int val) {
//		_stPush.Push(val);
//	}*/
//
//private:
//	/*Stack _stPush;
//	Stack _stPop;*/
//	int size;
//};
//
//int main() {
//	myQueue q;
//
//	return 0;
//}


//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//private:
//	int _year = 0;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d;
//	return 0;
//}

//class Date {
//public:
//	//默认构造函数：不需要传参就能调用的构造函数
//	//包括无参构造函数和全缺省构造函数和编译器自动生成的
//	/*Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//	Date() {
//		_year = 10;
//		_month = 10;
//		_day = 10;
//	}
//private:
//	int _year = 0;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d;
//	return 0;
//}


//class Stack {
//public:
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
//	//int* _array = nullptr;
//	int* _array = (int*)malloc(sizeof(int) * 4);
//	//这也是缺省值，无构造函数时才会调用,但是没有对返回的结果进行检查
//	size_t _top = 0;
//	size_t _capacity = 4;
//};
//
//class myQueue {
//public:
//
//
//private:
//	Stack _stPush;
//	Stack _stPop;
//	int size = 10;
//};
//
//int main() {
//	Stack st;
//	myQueue q;
//
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////
//拷贝构造


//#include <iostream>
//using namespace std;
//int main() {
//	float x, y, a;
//	for (y = 1.5; y > -1.5; y -= 0.1)
//	{
//		for (x = -1.5; x < 1.5; x += 0.05) {
//			a = x * x + y * y - 1;
//			putchar(a * a * a - x * x * y * y * y <= 0.0 ? '*' : ' ');
//		}
//		system("color 0c");
//		putchar('\n');
//	}
//	return 0;
//}
//
//#include <iostream>
//#include <cassert>
//#include <cstdlib>
//using namespace std;
//
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
//	Date(Date &d) {
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
//	Date d1(2022,11,11);
//	Date d2(d1);//拷贝构造 - 拷贝初始化
//	/*Func1(d1);
//	Func2(d1);*/
//	return 0;
//}


//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
	////形参多加一个const限制，使引用d权限序缩小，写反时便于编译器检查，
	//Date(const Date& d) {
	//	cout << "拷贝构造 Date(Date &d)" << endl;
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
//
//private:
//	int _year = 0;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//拷贝构造 - 拷贝初始化
//	return 0;
//}

//后构造的先析构，符合栈的性质
//class Date {
//public:
//	//构造即是初始化
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year = 0;//缺省值，不是初始化，因为类类型并不占空间
//	int _month = 0;
//	int _day = 0;
//};
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(d1);//拷贝构造 - 拷贝初始化
//	return 0;
//}


//对于内置类型
//浅拷贝（值拷贝）时，编译器默认生成的拷贝构造就是够用的
//深拷贝时，内置类型也许要自己写拷贝构造函数，即编译器默认生成的不完全适合
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


///////////////////////////////////////////////////////////////////////////
//运算符重载
//有什么意义？
//以日期类为例解答
//支持类的运算，并简化类运算时的表示
//与函数重载不同哦

//class Date {
//public:
//	//构造
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//形参多加一个const限制，使引用d权限序缩小，写反时便于编译器检查，
//	Date(const Date& d) {
//		//cout << "拷贝构造 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
////private:
//	int _year;
//	int _month;
//	int _day;
//};
////函数完成功能
//bool isEqual(const Date& d1, const Date& d2) {
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
////c++引入，但是在类外不能访问到私有成员变量了，除了友元函数
//bool operator==(const Date& d1, const Date& d2) {
//	return d1._year == d2._year &&
//		d1._month == d2._month &&
//		d1._day == d2._day;
//}
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = operator==(d1, d2);
//	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}


//class Date {
//public:
//	//构造
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//形参多加一个const限制，使引用d权限序缩小，写反时便于编译器检查，
//	Date(const Date& d) {
//		//cout << "拷贝构造 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	int GetYear() {
//		int year = _year;
//		return year;
//	}
//	int GetMonth() {
//		int month = _month;
//		return month;
//	}
//	int GetDay() {
//		int day = _day;
//		return day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
////c++引入，但是在类外不能访问到私有成员变量了，除了友元函数
////发生错误，
//bool operator==(Date& d1, Date& d2) {
//	return d1.GetYear() == d2.GetYear() &&
//		d1.GetMonth() == d2.GetMonth() &&
//		d1.GetDay() == d2.GetDay();
//}
//bool operator==(Date& d1, Date& d2) {
//	return d1.GetYear() == d2.GetYear() &&
//		d1.GetMonth() == d2.GetMonth() &&
//		d1.GetDay() == d2.GetDay();
//}

//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = operator==(d1, d2);
//	cout << "operator==(d1, d2): " << operator==(d1, d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}


//class Date {
//public:
//	//构造
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//形参多加一个const限制，使引用d权限序缩小，写反时便于编译器检查，
//	Date(const Date& d) {
//		//cout << "拷贝构造 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//错误，参数过多，==应该只有两个操作数，
//	//而在类内的函数都会有一个隐含的形参this指针
//	/*bool operator==(const Date& d1, const Date& d2) {
//		return d1._year == d2._year &&
//			d1._month == d2._month &&
//			d1._day == d2._day;
//	}*/
//
//	bool operator==(const Date& d) {
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 11, 11);
//	int ret1 = d1 == d2;
//	cout << "(d1 == d2): " << (d1 == d2) << endl;
//	cout << "ret1: " << ret1 << endl;
//	int ret2 = d1.operator==(d2);
//	cout << "d1.operator==(d2): " << d1.operator==(d2) << endl;
//	cout << "ret2: " << ret2 << endl;
//	return 0;
//}

//class Date {
//public:
//	//构造
//	Date(int year = 1, int month = 1, int day = 1) {
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//形参多加一个const限制，使引用d权限序缩小，写反时便于编译器检查，
//	Date(const Date& d) {
//		//cout << "拷贝构造 Date(Date &d)" << endl;
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print() {
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//	int DateTransDay() {
//		 Date cur(*this);
//		 
//		 while (cur._year > 0 || cur._month > 0) {
//			 cur._month--;
//			 if (cur._month == 0 && cur._year > 0) {
//				 cur._month = 12;
//				 cur._year--;
//			 }
//			 cur._day += GetDay(cur._year, cur._month);
//			 //cout << cur._year << "    " << cur._month << "    " << cur._day << endl;
//		}
//		 return cur._day;
//	}
//	//等于
//	bool operator==(const Date& d) {
//		return _year == d._year &&
//			_month == d._month &&
//			_day == d._day;
//	}
//	//大于
//	bool operator>(const Date& d) {
//		if (_year > d._year) {
//			return true;
//		}
//		else if (_year == d._year && _month > d._month) {
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day > d._day) {
//			return true;
//		}
//		return false;
//	}
//	//小于
//	bool operator<(const Date& d) {
//		//return !((this->operator==(d)) || (this->operator>(d)));
//		if (_year < d._year) {
//			return true;
//		}
//		else if (_year == d._year && _month < d._month) {
//			return true;
//		}
//		else if (_year == d._year && _month == d._month && _day < d._day) {
//			return true;
//		}
//		return false;
//	}
//	//小于等于
//	bool operator<=(const Date& d) {
//		return this->operator<(d) || this->operator==(d);
//	}
//	//大于等于
//	bool operator>=(const Date& d) {
//		return this->operator>(d) || this->operator==(d);
//	}
//	//得到某一月天数
//	static int GetDay(int year, int month) {
//		//平年
//		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		//特殊处理闰年2月
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && month == 2) {
//			return 29;
//		}
//		return array[month];
//	}
//	//d1+d2
//	Date operator+(int day) {
//		Date cur(*this);
//		cur._day = cur._day + day;
//		while (cur._day > GetDay(cur._year, cur._month)) {
//			cur._day -= GetDay(cur._year, cur._month);
//			cur._month++;
//			if (cur._month > 12) {
//				cur._year++;
//				cur._month = 1;
//			}
//		}
//		return cur;
//	}
//	//+=
//	Date& operator+=(int day) {
//		_day = _day + day;
//		while (_day > GetDay(_year, _month)) {
//			_day -= GetDay(_year, _month);
//			_month++;
//			if (_month > 12) {
//				_year++;
//				_month = 1;
//			}
//		}
//		return *this;
//	}
//	//-
//	int operator-(Date& d) {
//		Date cur(*this);
//		return this->DateTransDay() - d.DateTransDay();
//
//		/*cur._day -= d._day;
//		if (cur._day < 0) {
//			cur._day += GetDay(cur._year, cur._month);
//			cur._month--;
//		}
//		cur._month -= d._month;
//		if (cur._month < 0) {
//			cur._month += 12;
//			cur._year--;
//		}
//		cur._year -= d._year;
//		return cur;*/
//	}
//
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//
//int main() {
//	Date d1(2022, 11, 11);
//	Date d2(2022, 12, 12);
//	//cout << (d1 > d2) << endl;
//
//	/*cout << (d1 < d2) << endl;
//	cout << (d2 < d1) << endl;*/
//
//	/*cout << (d1 <= d2) << endl;
//	cout << (d2 <= d1) << endl;*/
//
//	//cout << (d1 >= d2) << endl;
//	//cout << (d2 >= d1) << endl;
//
//	/*d1.Print();
//	(d1 + 50).Print();
//	d2.Print();
//	(d2 + 60).Print();*/
//
//	d1.Print();
//	d1 += 50;
//	d1.Print();
//
//	d2.Print();
//	d2 += 60;
//	d2.Print();
//
//	//cout << d1.DateTransDay() << endl;
//	/*cout << (d1 - d2) << endl;
//	cout << (d2 - d1) << endl;*/
//
//	return 0;
//}




























