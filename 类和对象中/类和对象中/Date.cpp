//#include "Date.h"
//
//Date Date::operator+(int day) const {
//	Date cur(*this);
//	cur += day;
//	return cur;
//}
//
//Date& Date::operator+=(int day) {
//	//加负的天数
//	if (day < 0) {
//		return *this -= -day;
//	}
//	_day += day;
//	while (_day > GetMonthDay(_year, _month)) {
//		_day -= GetMonthDay(_year, _month);
//		++_month;
//		if (_month == 13) {
//			_month = 1;
//			++_year;
//		}
//	}
//	return *this;
//}
//
//Date& Date::operator-=(int day) {
//	//减负的天数
//	if (day < 0) {
//		*this += -day;
//	}
//	else {
//		_day -= day;
//		while (_day <= 0) {
//			--_month;
//			if (_month == 0) {
//				_month = 12;
//				--_year;
//			}
//			_day += GetMonthDay(_year, _month);
//			//cout << _year << " " << _month << " " << _day << " " << GetMonthDay(_year, _month) << endl;
//		}
//	}
//	return *this;
//}
//
//Date Date::operator-(int day) const {
//	Date cur(*this);
//	cur -= day;
//	return cur;
//}
////日期之差
////d1.operator-(d2) --> d1 - d2
//int Date::operator-(const Date& d) const {
//	//小日期逐渐趋近大日期，同时计数
//	//1.找大小日期
//	Date max(*this);
//	Date min(d);
//	int flag = 1;
//	if (*this < d) {
//		max = d;
//		min = *this;
//		flag = -1;
//	}
//	//2.循环计数
//	int count = 0;
//	while (min != max) {
//		++min;
//		++count;
//		//cout << count << endl;
//	}
//	return count * flag;
//}
//
////int Date::operator-(const Date& d) {
////	//先分别与一个中间值相减，结果再次相减
////	Date temp(1, 1, 1);
////	int day1 = *this - temp;
////	int day2 = d - temp;
////}
//
//
////前置++
//Date& Date::operator++() {
//	*this += 1;
//	return *this;
//}
////后置++
//Date Date::operator++(int) {
//	Date cur(*this);
//	*this += 1;
//	return cur;
//}
////--是运算符重载，两个--运算符重载函数又构成函数重载
////前置--
//Date& Date::operator--() {
//	*this -= 1;
//	return *this;
//}
////后置--
//Date Date::operator--(int) {
//	Date cur(*this);
//	*this -= 1;
//	return cur;
//}
//
//
//
//bool Date::operator==(const Date& d) const {
//	return _year == d._year
//		&& _month == d._month
//		&& _day == d._day;
//}
//bool Date::operator!=(const Date& d) const {
//	return !(*this == d);
//}
////	>
//bool Date::operator>(const Date& d) const {
//	if (_year > d._year) {
//		return true;
//	}
//	else if (_year == d._year && _month > d._month) {
//		return true;
//	}
//	else if (_year == d._year && _month == d._month && _day > d._day) {
//		return true;
//	}
//	return false;
//}
//bool Date::operator>=(const Date& d) const {
//	return (*this > d) || (*this == d);
//}
//bool Date::operator<(const Date& d) const {
//	return !(*this >= d);
//}
//bool Date::operator<=(const Date& d) const {
//	return !(*this > d);
//}
//////d1.operator>>(cin); -->	d1 << cin ??
////istream& Date::operator>>(istream& input) {
////	input >> _year >> _month >> _day;
////	return input;
////}
//
////d1.operator>>(cin); -->	d1 << cin ??
//istream& operator>>(istream& input, Date& d) {
//	input >> d._year >> d._month >> d._day;
//	return input;
//}
//
//ostream& operator<<(ostream& output, const Date& d) {
//	output << d._year << "/" << d._month << "/" << d._day << endl;
//	return output;
//}