#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date {
public:
	friend istream& operator>>(istream& input, Date& d);
	friend ostream& operator<<(ostream& output, const Date& d);
	//�õ�ĳһ������
	static int GetMonthDay(int year, int month) {
		//ƽ��
		int array[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		//���⴦������2��
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && month == 2) {
			return 29;
		}
		return array[month];
	}
	//Ĭ�� ����
	Date(int year = 1, int month = 1, int day = 1) {
		_year = year;
		_month = month;
		_day = day;
		if (!(_year >= 1
			&& (_month >= 1 && _month <= 12)
			&& (_day >= 1 && _day <= GetMonthDay(_year, _month)))) {
			cout << "�Ƿ�����" << endl;
		}
	}
	//��������
	Date(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ���������
	//��ֵ����������в���ʽʵ��ʱ��������������һ��Ĭ�ϵģ�
	//��ʱ�û��������ٽ���ֵ���������Ϊȫ�ֵģ��ͺͱ�������
	//�ɵ�Ĭ�ϸ�ֵ�������ͻ�ˣ��ʸ�ֵ�����ֻ�����سɳ�Ա����
	Date& operator=(const Date& d) {
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}
	//����
	~Date() {
		_year = 0;
		_month = 0;
		_day = 0;
	}
	void Print() {
		cout << _year << "/" << _month << "/" << _day << endl;
	}
	//���������
	//+day
	//AddDay()
	//JiaTian()
	Date operator+(int day) const;
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date operator-(int day) const;
	//ǰ��++
	Date& operator++();//	d1.operator++()
	//����++
	Date operator++(int);//	d1.operator++(int)
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);
	//����֮��
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



//ȫ�ֱ�����ȫ�ֺ���������ͷ�ļ����ڶ��Դ�ļ����γ��ض���,�����Ӵ���
// ȫ�ֱ�����ȫ�ֺ�����������ű�Դ�ļ���������ͷ�ļ�����Ԥ����׶�չ��
// ÿ��Դ�ļ������������γɸ��Ե�.oĿ���ļ������׶θ����γɵķ��ű��ж�����һ��ȫ�ֱ�����ȫ�ֺ�����
// ����ÿ��Ŀ���ļ������ж���һ��ȫ�ֱ�����ȫ�ֺ���
// �����ӽ׶Σ����ű�ĺϲ�ʱ��ͬĿ���ļ����Ա����ȫ�ֱ�����ȫ�ֺ��������ַ������ͻ
//void Func() {
//	;
//}
//
//int a = 10;
//
//����취��
//1.static���Σ�
//�ı����ζ�����������ڣ�ͬʱʹ����������Ա�Ϊ��̬��ֻ�ڱ��ļ���ʹ�ã������ļ��޷�ʹ��
//���Ա���ʱ�������ű�����ʱ��Ȼ�����г�ͻ������
//static void Func() {
//	;
//}
//
//2.�����Ͷ�����룬������ͷ�ļ���������ĳ��Դ�ļ�
//.h  -> void Func();
//.cpp -> void Func(){ ; }
//
//3.����Ϊ����������Ҳ�������ű�
//inline void Func() {
//	;
//}

class Stack {
public:
	//��ͨ����
	Stack(int capacity = 4) {
		cout << "��ͨ����: Stack(int capacity = 4)" << endl;
		_array = (int*)malloc(sizeof(int) * capacity);
		_top = 0;
		_capacity = capacity;
	}
	//��д��������
	Stack(const Stack& st) {
		cout << "��������: Stack(const Stack& st)" << endl;
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
	//��ֵ���������
	Stack& operator=(const Stack& st) {
		cout << "��ֵ���������: Stack& operator=(const Stack& st)" << endl;
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
		cout << "����: ~Stack()" << endl;
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