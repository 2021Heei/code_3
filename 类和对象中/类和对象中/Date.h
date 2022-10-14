#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date {
public:
	friend istream& operator>>(istream& input, Date& d);
	friend ostream& operator<<(ostream& output, const Date& d);
	//得到某一月天数
	static int GetMonthDay(int year, int month) {
		//平年
		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//特殊处理闰年2月
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2) {
			return 29;
		}
		return array[month];
	}
	//默认 构造
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
		if (!(_year >= 1
			&& (_month >= 1 && _month <= 12)
			&& (_day >= 1 && _day <= GetMonthDay(_year, _month)))) {
			cout << "非法日期" << endl;
		}
	}
	//拷贝构造
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	//赋值运算符在类中不显式实现时，编译器会生成一份默认的，
	//此时用户在类外再将赋值运算符重载为全局的，就和编译器生
	//成的默认赋值运算符冲突了，故赋值运算符只能重载成成员函数
	Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	//析构
	~Date() {
		_year = 0;
		_month = 0;
		_day = 0;
	}
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	//运算符重载
	//+day
	//AddDay()
	//JiaTian()
	Date operator+(int day) const;
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator-(int day) const;
	//前置++
	Date& operator++();//	d1.operator++()
	//后置++
	Date operator++(int);//	d1.operator++(int)
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);
	//日期之差
	int operator-(const Date& d) const;
	//	==
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
	//	>
	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;

	/*Date* operator&() {
		cout << "Date* operator&()" << endl;
		return this;
	}*/
	//const Date* operator&() const {
	//	cout << "Date* operator&() const " << endl;
	//	return this;
	//}
private:
	int _year;
	int _month;
	int _day;
};



//全局变量和全局函数定义在头文件对于多个源文件会形成重定义,报链接错误
// 全局变量和全局函数都会进符号表，源文件都包含了头文件，在预处理阶段展开
// 每个源文件经编译链接形成各自的.o目标文件，汇编阶段各自形成的符号表中都含有一份全局变量和全局函数，
// 导致每个目标文件都含有都有一份全局变量和全局函数
// 在链接阶段，符号表的合并时不同目标文件各自保存的全局变量和全局函数及其地址产生冲突
//void Func() {
//	;
//}
//
//int a = 10;
//
//解决办法：
//1.static修饰，
//改变修饰对象的声明周期，同时使其的链接属性变为静态，只在本文件中使用，其他文件无法使用
//所以编译时不进符号表，链接时自然不会有冲突的问题
//static void Func() {
//	;
//}
//
//2.声明和定义分离，声明在头文件，定义在某个源文件
//.h  -> void Func();
//.cpp -> void Func(){ ; }
//
//3.定义为内联函数，也不进符号表
//inline void Func() {
//	;
//}

class Stack {
public:
	//普通构造
	Stack(int capacity = 4) {
		cout << "普通构造: Stack(int capacity = 4)" << endl;
		_array = (int*)malloc(sizeof(int) * capacity);
		_top = 0;
		_capacity = capacity;
	}
	//手写拷贝构造
	Stack(const Stack& st) {
		cout << "拷贝构造: Stack(const Stack& st)" << endl;
		_array = (int*)malloc(sizeof(int) * st._capacity);
		assert(_array);
		//memcpy(des, src, sizeByte)
		memcpy(_array, st._array, sizeof(int) * st._top);
		_top = st._top;
		_capacity = st._capacity;
	}
	void Push(int val) {
		if (_top == _capacity) {
			int newcapacity = _capacity * 2;
			int* tmp = (int*)realloc(_array, sizeof(int) * newcapacity);
			assert(tmp);
			_array = tmp;
			_capacity = newcapacity;
		}
		_array[_top++] = val;
	}
	//赋值运算符重载
	Stack& operator=(const Stack& st) {
		cout << "赋值运算符重载: Stack& operator=(const Stack& st)" << endl;
		if (this != &st) {
			free(this->_array);
			_array = (int*)malloc(sizeof(int) * st._capacity);
			assert(_array);
			//memcpy(des, src, sizeByte)
			memcpy(_array, st._array, sizeof(int) * st._top);
			_top = st._top;
			_capacity = st._capacity;
		}
		return *this;
	}
	~Stack() {
		cout << "析构: ~Stack()" << endl;
		free(_array);
		_array = nullptr;
		_top = _capacity = 0;
	}
private:
	int* _array;
	size_t _top;
	size_t _capacity;
};


class myQueue {
public:
	void Push(int val) {
		stPush.Push(val);
		size++;
	}
private:
	Stack stPush;
	Stack stPop;
	int size = 0;
};