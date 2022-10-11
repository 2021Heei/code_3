#pragma once
#include <iostream>
#include <assert.h>
using namespace std;


class Date {
public:
	//得到某一月天数
	static int GetMonthDay(int year, int month) {
		//平年
		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//特殊处理闰年2月
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) && month == 2) {
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
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	////拷贝构造
	//Date(const Date& d) {
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//}
	////赋值运算符重载
	//Date& operator=(const Date& d) {
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;
	//	return *this;
	//}
	//析构
	~Date() {
		_year = 0;
		_month = 0;
		_day = 0;
	}
	//运算符重载
	//+day
	//AddDay()
	//JiaTian()
	Date operator+(int day) {
		Date cur(*this);
		cur._day += day;
		while (cur._day > GetMonthDay(cur._year, cur._month)) {
			cur._day -= GetMonthDay(cur._year, cur._month);
			++cur._month;
			if (cur._month == 13) {
				cur._month = 1;
				++cur._year;
			}
		}
		return cur;
	}
	Date& operator+=(int day) {
		_day += day;
		while (_day > GetMonthDay(_year, _month)) {
			_day -= GetMonthDay(_year, _month);
			++_month;
			if (_month == 13) {
				_month = 1;
				++_year;
			}
		}
		return *this;
	}
	/*Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}*/
	bool operator==(const Date& d) {
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};


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