//#include "Date.h"
//
//Date Date::operator+(int day) const {
//	Date cur(*this);
//	cur += day;
//	return cur;
//}
//
//Date& Date::operator+=(int day) {
//	//�Ӹ�������
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
//	//����������
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
////����֮��
////d1.operator-(d2) --> d1 - d2
//int Date::operator-(const Date& d) const {
//	//С���������������ڣ�ͬʱ����
//	//1.�Ҵ�С����
//	Date max(*this);
//	Date min(d);
//	int flag = 1;
//	if (*this < d) {
//		max = d;
//		min = *this;
//		flag = -1;
//	}
//	//2.ѭ������
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
////	//�ȷֱ���һ���м�ֵ���������ٴ����
////	Date temp(1, 1, 1);
////	int day1 = *this - temp;
////	int day2 = d - temp;
////}
//
//
////ǰ��++
//Date& Date::operator++() {
//	*this += 1;
//	return *this;
//}
////����++
//Date Date::operator++(int) {
//	Date cur(*this);
//	*this += 1;
//	return cur;
//}
////--����������أ�����--��������غ����ֹ��ɺ�������
////ǰ��--
//Date& Date::operator--() {
//	*this -= 1;
//	return *this;
//}
////����--
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