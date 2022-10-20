#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//using namespace std;
//
//class Date {
//public:
//	Date(int year = 1, int month = 1, int day = 1)
//		:_year(year),_month(month),_day(day){}
//
//	int GetMonthDay(int year, int month) {
//		int ArrayDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
//			return 29;
//		}
//		return ArrayDay[month];
//	}
//	Date& operator-(Date& d) {
//		_year -= d._year;
//		_month -= d._month;
//		_day -= d._day;
//		return *this;
//	}
//	int Day() {
//		Date d(_year, 1, 1);
//		if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month)) {
//			perror("Date error");
//			return -1;
//		}
//		Date tmp = *this - d;
//		
//		while (tmp._month) {
//			tmp._day += GetMonthDay(_year, tmp._month);
//			tmp._month--;
//		}
//		return tmp._day;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main() {
//	int year, month, day;
//	cin >> year >> month >> day;
//	Date d1(year,month,day);
//	cout << d1.Day() << endl;
//	return 0;
//}

//#include<iostream>
//
//
//using namespace std;
//
//int getDays(int year, int month, int day) {
//    int days_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };//一月份加的天数为0
//    //判断平年闰年，平年二月28天，闰年多一天
//    if ((year % 4 == 0) && (year & 100 != 0) || (year % 400 == 0)) {
//        days_of_month[2] = 29;
//    }
//    else {
//        days_of_month[2] = 28;
//    }
//
//    //参数有效性检查
//    if (month < 1 || month>12 || day<0 || day>days_of_month[month]) {
//        return -1;
//    }
//
//    int Days = 0;
//    for (int i = 0; i < month; i++) {//不能int i=1,这样在一月时也会进行一次循环
//        Days += days_of_month[i];
//    }
//    Days += day;    //加上当月的天数
//    return Days;
//}
//int main(int argc, char* argv[]) {
//    cout << getDays(2022, 10, 15);
//    getchar();
//    return 0;
//}


//#include <iostream>
//using namespace std;
//
//int GetMonthDay(int year, int month) {
//	//时间换空间
//	//前n个月的天数
//	int ArrayDay[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
//	//int ArrayDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	int day = ArrayDay[month];
//	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))) {
//		return day++;
//	}
//	return day;
//}
//int Day(int _year, int _month, int _day) {
//	if (_month < 1 || _month > 12 || _day < 1 || _day > GetMonthDay(_year, _month)) {
//		perror("Date error");
//		return -1;
//	}
//	int day = _day + GetMonthDay(_year, _month - 1);
//
//	return day;
//}
//
//int main() {
//	int year, month, day;
//	cin >> year >> month >> day;
//
//	cout << Day(year,month,day) << endl;
//	return 0;
//}



///////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 

//内置类型，new和delete相比malloc和free操作几乎没有区别
//#include <iostream>
//using namespace std;
//
//int main() {
//	int* p1 = new int;//默认不对申请的空间初始化
//	delete p1;//delete之后，指针指向的发生改变（随机变化），这一点与malloc申请的空间被free不同（指针指向不变）
//	p1 = nullptr;
//
//	int* p2 = new int(0);//申请空间同时初始化
//	delete p2;
//	p2 = nullptr;
//
//	int* p3 = (int*)malloc(sizeof(int));
//	if (p3 == nullptr)
//		return -1;
//	free(p3);
//	int a;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int* p1 = new int[10];
//	delete[] p1;
//	
//	int* p2 = new int[10]{ 1,2,3,4,5 };
//	delete[] p2;
//
//	//int* p3 = new int[10](0);//error
//	//delete[] p3;
//	return 0;
//}


//自定义类型
//new/delete 相比 malloc/free,除了申请和释放内存空间，还会分别调用自定义类型的构造函数和析构函数

//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	A(int a = 1):_a(a){
//		cout << "构造函数: A(int a = 1)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//int main() {
//
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr)
//		return -1;
//
//	delete p1;
//	free(p2);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//struct ListNode {
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val = 0)
//		:_val(val),_next(nullptr){
//		cout << "构造函数: ListNode(int val)" << endl;
//	}
//
//	~ListNode() {
//		cout << "~ListNode()" << endl;
//	}
//};
//
//int main() {
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	n1->_next = n2;
//	n2->_next = n3;
//
//	delete n1;
//	delete n2;
//	delete n3;
//	return 0;
//}


//new和delete要匹配，否则可能会出现隐患
//#include <iostream>
//using namespace std;
//
//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//		cout << "构造函数: A(int a = 1)" << endl;
//	}
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	//A* p1 = new A(1);
//	////free(p1);
//	//delete p1;
//
//	A* p2 = new A[10];
//	//free(p2);
//	//delete p2;
//	delete[] p2;
//	return 0;
//}

//#include <iostream>
//#include <cstdlib>
//using namespace std;

//int main() {
//	while (1) {
//		int* p = (int*)malloc(sizeof(int) * 1024 * 10);
//		if (p) {
//			cout << p << endl;
//		}
//		else {
//			cout << "malloc fail" << endl;
//			break;
//		}
//	}
//	return 0;
//}

//int main() {
//	try {
//	//new失败不会返回nullptr，而是抛出一个异常，故不需要new的指针进行检查了，异常可以代替，这与malloc不同
//		while (1) {
//			int* p = new int[1024 * 10];
//			if (p) {
//				cout << p << endl;
//			}
//			else {
//				cout << "new fail" << endl;
//				break;
//			}
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main() {
//	try {
//		//new失败不会返回nullptr，而是抛出一个异常，故不需要new的指针进行检查了，异常可以代替，这与malloc不同
//		while (1) {
//			//char* p = new char[1024 * 1024* 1024];
//			char* p = (char*)operator new(1024 * 1024 * 1024);
//			if (p) {
//				cout << (void*)p << endl;
//			}
//			else {
//				cout << "new fail" << endl;
//				break;
//			}
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//class A {
//public:
//	A(int a = 1)
//		:_a(a) {
//		cout << "构造函数: A(int a = 1)" << endl;
//	}/*
//	~A() {
//		cout << "析构函数: ~A()" << endl;
//	}*/
//private:
//	int _a;
//};
//
//int main() {
//	A* p = new A[10];
//	//delete[] p;
//	//delete p;
//	free(p);
//	return 0;
//}


////矩阵相乘
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//
//int** GetArray(int row, int col);
//void CinArray(int**& p, int row, int col);
//void Print(int**& p, int row, int col);
//
//int main() {
//	int row1, row2, col1, col2;
//	//分别输入二维数组行和列
//	cout << "请输入第一个矩阵行row1和列col1(以空格分隔)>";
//	cin >> row1 >> col1;
//	cout << "请输入第二个矩阵行row2和列col2(以空格分隔)>";
//	cin >> row2 >> col2;
//
//	if (col1 == row2) {
//		int row3 = row1;
//		int col3 = col2;
//
//		printf("请输入第一个矩阵的元素%d * %d>", row1, col1);
//		int** p1 = GetArray(row1, col1);
//		CinArray(p1, row1, col1);
//		Print(p1, row1, col1);
//
//		printf("请输入第一个矩阵的元素%d * %d>", row2, col2);
//		int** p2 = GetArray(row2, col2);
//		CinArray(p2, row2, col2);
//		Print(p2, row2, col2);
//
//		int** p3 = GetArray(row3, col3);
//
//		//相乘
//		for (int i = 0; i < row3; ++i) {
//			for (int j = 0; j < col3; ++j) {
//				int sum = 0;
//				//col1或row2，因为相乘：col1 == row2
//				for (int k = 0; k < col1; ++k) {
//					sum += p1[i][k] * p2[k][j];
//				}
//				p3[i][j] = sum;
//			}
//		}
//
//		Print(p3, row3, col3);
//		
//	}
//	else {
//		cout << "输入的矩阵不能相乘" << endl;
//	}
//	return 0;
//}
//
//
//int** GetArray(int row, int col) {
//	//二维数组 - 动态开辟
//	//开辟一维一级指针数组
//	int** p = (int**)malloc(sizeof(int*) * row);
//	//开辟一维整形数组
//	for (int i = 0; i < row; i++) {
//		p[i] = (int*)malloc(sizeof(int) * col);
//	}
//	return p;
//}
//
//void CinArray(int**& p, int row, int col) {
//	//输入数组元素
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; ++j) {
//			cin >> p[i][j];
//		}
//	}
//}
//void Print(int**& p, int row, int col) {
//	cout << row << "*" << col << " 矩阵如下>" << endl;
//	for (int i = 0; i < row; ++i) {
//		for (int j = 0; j < col; j++) {
//			cout << p[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void Free(int**& p, int row, int col) {
//	for (int i = 0; i < row; i++) {
//		free(p[i]);
//		p[i] = nullptr;
//	}
//	free(p);
//	p = nullptr;
//}


////矩阵相乘
//#include <iostream>
//#include <cstdlib>
//using namespace std;
//
//class TwoArray {
//public:
//	//构造
//	TwoArray(int row, int col)
//		:_row(row)
//		,_col(col){
//		cout << "构造: TwoArray(int row, int col)" << endl;
//		//二维数组 - 动态开辟
//		//开辟一维一级指针数组
//		_p = (int**)malloc(sizeof(int*) * _row);
//		//开辟一维整形数组
//		for (int i = 0; i < _row; i++) {
//			_p[i] = (int*)malloc(sizeof(int) * _col);
//		}
//	}
//	//拷贝构造
//	TwoArray(TwoArray& a) {
//		cout << "拷贝构造: TwoArray(TwoArray& a)" << endl;
//		_row = a._row;
//		_col = a._col;
//		_p = (int**)malloc(sizeof(int*) * _row);
//		//开辟一维整形数组
//		for (int i = 0; i < _row; i++) {
//			_p[i] = (int*)malloc(sizeof(int) * _col);
//		}
//		for (int i = 0; i < _row; ++i) {
//			for (int j = 0; j < _col; ++j) {
//				_p[i][j] = a._p[i][j];
//			}
//		}
//	}
//	//拷贝构造
//	TwoArray(const TwoArray& a) {
//		cout << "拷贝构造: TwoArray(const TwoArray& a)" << endl;
//		_row = a._row;
//		_col = a._col;
//		_p = (int**)malloc(sizeof(int*) * _row);
//		//开辟一维整形数组
//		for (int i = 0; i < _row; i++) {
//			_p[i] = (int*)malloc(sizeof(int) * _col);
//		}
//		for (int i = 0; i < _row; ++i) {
//			for (int j = 0; j < _col; ++j) {
//				_p[i][j] = a._p[i][j];
//			}
//		}
//	}
//
//	TwoArray& operator=(const TwoArray& a) {
//		_row = a._row;
//		_col = a._col;
//		_p = (int**)malloc(sizeof(int*) * _row);
//		//开辟一维整形数组
//		for (int i = 0; i < _row; i++) {
//			_p[i] = (int*)malloc(sizeof(int) * _col);
//		}
//		for (int i = 0; i < _row; ++i) {
//			for (int j = 0; j < _col; ++j) {
//				_p[i][j] = a._p[i][j];
//			}
//		}
//		return *this;
//	}
//
//	//输入元素
//	void CinArray() {
//		//输入数组元素
//		for (int i = 0; i < _row; ++i) {
//			for (int j = 0; j < _col; ++j) {
//				cin >> _p[i][j];
//			}
//		}
//	}
//
//	void Print() {
//		cout << _row << "*" << _col << " 矩阵如下>" << endl;
//		for (int i = 0; i < _row; ++i) {
//			for (int j = 0; j < _col; j++) {
//				printf("%-3d ", _p[i][j]);
//			}
//			cout << endl;
//		}
//	}
//	//得到某一元素
//	int& GetNum(int i, int j) {
//		return _p[i][j];
//	}
//	//*运算符重载
//	TwoArray operator*(TwoArray& a) {
//		//ret 结果类对象
//		TwoArray ret(_row, a._col);
//		//相乘
//		//ret._row
//		for (int i = 0; i < ret._row; ++i) {
//			//ret._col
//			for (int j = 0; j < ret._col; ++j) {
//				int sum = 0;
//				//_col或a._row，因为相乘：_col == a._row
//				for (int k = 0; k < _col; ++k) {
//					sum += GetNum(i, k) * a.GetNum(k, j);
//				}
//				ret.GetNum(i, j) = sum;
//			}
//		}
//		return ret;
//	}
//	//析构
//	~TwoArray() {
//		cout << "析构: ~TwoArray()" << endl;
//		for (int i = 0; i < _row; i++) {
//			free(_p[i]);
//			_p[i] = nullptr;
//		}
//		free(_p);
//		_p = nullptr;
//	}
//private:
//	int** _p;
//	int _row;
//	int _col;
//};
//
//
//int main() {
//	int row1, row2, col1, col2;
//	//分别输入二维数组行和列
//	cout << "请输入第一个矩阵行row1和列col1(以空格分隔)>";
//	cin >> row1 >> col1;
//	cout << "请输入第二个矩阵行row2和列col2(以空格分隔)>";
//	cin >> row2 >> col2;
//
//	if (col1 == row2) {
//
//		printf("请输入第一个矩阵的元素%d * %d>", row1, col1);
//		TwoArray p1(row1, col1);
//		p1.CinArray();
//		p1.Print();
//		
//
//		printf("请输入第一个矩阵的元素%d * %d>", row2, col2);
//		TwoArray p2(row2, col2);
//		p2.CinArray();
//		p2.Print();
//
//		
//		TwoArray ret = p1 * p1;
//		ret.Print();
//	}
//	else {
//		cout << "输入的矩阵不能相乘" << endl;
//	}
//	return 0;
//}



////矩阵相乘
//#include <iostream>
//#include <cstdlib>
//#include <cassert>
//using namespace std;
//
//class TwoArray {
//	//流插入  和 流提取
//	friend ostream& operator<<(ostream& out, const TwoArray& a);
//	friend istream& operator>>(istream& in, TwoArray& a);
//public:
//	//构造
//	TwoArray(int row, int col);
//	//析构
//	~TwoArray();
//	//拷贝构造
//	TwoArray(TwoArray& a);
//	TwoArray(const TwoArray& a);
//	//*运算符重载
//	TwoArray operator*(TwoArray& a);
//	TwoArray& operator=(const TwoArray& a);
//
//	//得到某一元素
//	int& GetNum(int i, int j);
//private:
//	int** _p;
//	int _row;
//	int _col;
//};
//
//
//int main() {
//	int row1, row2, col1, col2;
//	//分别输入二维数组行和列
//	cout << "请输入第一个矩阵行row1和列col1(以空格分隔)>";
//	cin >> row1 >> col1;
//	cout << "请输入第二个矩阵行row2和列col2(以空格分隔)>";
//	cin >> row2 >> col2;
//
//	if (col1 == row2) {
//
//		printf("请输入第一个矩阵的元素%d * %d>", row1, col1);
//		TwoArray arr1(row1, col1);
//		cin >> arr1;
//		cout << arr1;
//
//		printf("请输入第一个矩阵的元素%d * %d>", row2, col2);
//		TwoArray arr2(row2, col2);
//		cin >> arr2;
//		cout << arr2;
//
//		TwoArray ret = arr1 * arr2;//拷贝构造+拷贝构造  优化---> 拷贝构造
//		cout << ret;
//	}
//	else {
//		cout << "输入的矩阵不能相乘" << endl;
//	}
//	return 0;
//}
//
////构造
//TwoArray::TwoArray(int row, int col)
//	:_row(row)
//	, _col(col) {
//	//二维数组 - 动态开辟
//	//开辟一维一级指针数组
//	_p = (int**)malloc(sizeof(int*) * _row);
//	//开辟一维整形数组
//	for (int i = 0; i < _row; i++) {
//		_p[i] = (int*)malloc(sizeof(int) * _col);
//	}
//}
////拷贝构造
//TwoArray::TwoArray(TwoArray& a) {
//	_row = a._row;
//	_col = a._col;
//	_p = (int**)malloc(sizeof(int*) * _row);
//	//开辟一维整形数组
//	for (int i = 0; i < _row; i++) {
//		_p[i] = (int*)malloc(sizeof(int) * _col);
//	}
//	for (int i = 0; i < _row; ++i) {
//		for (int j = 0; j < _col; ++j) {
//			_p[i][j] = a._p[i][j];
//		}
//	}
//}
////拷贝构造
//TwoArray::TwoArray(const TwoArray& a) {
//	_row = a._row;
//	_col = a._col;
//	_p = (int**)malloc(sizeof(int*) * _row);
//	//开辟一维整形数组
//	for (int i = 0; i < _row; i++) {
//		_p[i] = (int*)malloc(sizeof(int) * _col);
//	}
//	for (int i = 0; i < _row; ++i) {
//		for (int j = 0; j < _col; ++j) {
//			_p[i][j] = a._p[i][j];
//		}
//	}
//}
//
//TwoArray& TwoArray::operator=(const TwoArray& a) {
//	_row = a._row;
//	_col = a._col;
//	int** tmp1 = (int**)realloc(_p, sizeof(int*) * _row);
//	assert(tmp1);
//	_p = tmp1;
//	//开辟一维整形数组
//	for (int i = 0; i < _row; i++) {
//		int* tmp2 = (int*)realloc(_p[i], sizeof(int) * _col);
//		assert(tmp2);
//		_p[i] = tmp2;
//	}
//	for (int i = 0; i < _row; ++i) {
//		for (int j = 0; j < _col; ++j) {
//			_p[i][j] = a._p[i][j];
//		}
//	}
//	return *this;
//}
//
////输入元素
//istream& operator>>(istream& in, TwoArray& a) {
//	//输入数组元素
//	for (int i = 0; i < a._row; ++i) {
//		for (int j = 0; j < a._col; ++j) {
//			cin >> a._p[i][j];
//		}
//	}
//	return in;
//}
//
//ostream& operator<<(ostream& out, const TwoArray& a) {
//	cout << a._row << "*" << a._col << " 矩阵如下>" << endl;
//	for (int i = 0; i < a._row; ++i) {
//		for (int j = 0; j < a._col; j++) {
//			printf("%-3d ", a._p[i][j]);
//		}
//		cout << endl;
//	}
//	return out;
//}
//
////得到某一元素
//int& TwoArray::GetNum(int i, int j) {
//	return _p[i][j];
//}
////*运算符重载
//TwoArray TwoArray::operator*(TwoArray& a) {
//	//ret 结果类对象
//	TwoArray ret(_row, a._col);
//	//相乘
//	//ret._row
//	for (int i = 0; i < ret._row; ++i) {
//		//ret._col
//		for (int j = 0; j < ret._col; ++j) {
//			int sum = 0;
//			//_col或a._row，因为相乘：_col == a._row
//			for (int k = 0; k < _col; ++k) {
//				sum += GetNum(i, k) * a.GetNum(k, j);
//			}
//			ret.GetNum(i, j) = sum;
//		}
//	}
//	return ret;
//}
////析构
//TwoArray::~TwoArray() {
//	for (int i = 0; i < _row; i++) {
//		free(_p[i]);
//		_p[i] = nullptr;
//	}
//	free(_p);
//	_p = nullptr;
//}


//int main() {
//	int a1[3][3] = { 1,2,3,4,5,6,7,8,9 };
//	int a2[3][4] = { 1,1,1,1,1,1,1,1,1,1,1,1 };
//	int a3[3][4] = { 0 };
//	for (int i = 0; i < 3; ++i) {
//		for (int j = 0; j < 4; ++j) {
//			int sum = 0;
//			//行
//			for (int k = 0; k < 3; ++k) {
//				sum += a1[i][k] * a2[k][j];
//			}
//			a3[i][j] = sum;
//		}
//	}
//	for (int i = 0; i < 3; ++i) {
//		for (int j = 0; j < 4; j++) {
//			cout << a3[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//	return 0;
//}