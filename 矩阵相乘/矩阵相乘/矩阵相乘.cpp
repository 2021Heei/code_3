//矩阵相乘
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class TwoArray {
	//流插入  和 流提取
	friend ostream& operator<<(ostream& out, const TwoArray& a);
	friend istream& operator>>(istream& in, TwoArray& a);
public:
	//构造
	TwoArray(int row, int col);
	//析构
	~TwoArray();
	//拷贝构造
	TwoArray(TwoArray& a);
	TwoArray(const TwoArray& a);
	//*运算符重载
	TwoArray operator*(TwoArray& a);
	//赋值运算符重载
	TwoArray& operator=(const TwoArray& a);

	//得到某一元素
	int& GetNum(int i, int j);
private:
	int** _p;
	int _row;
	int _col;
};

#define row1 3
#define col1 3
#define row2 3
#define col2 3

int main() {
	
	printf("请输入第一个矩阵的元素%d * %d>", row1, col1);
	TwoArray arr1(row1, col1);
	cin >> arr1;
	cout << arr1;

	printf("请输入第二个矩阵的元素%d * %d>", row2, col2);
	TwoArray arr2(row2, col2);
	cin >> arr2;
	cout << arr2;

	TwoArray ret = arr1 * arr2;//拷贝构造+拷贝构造  优化---> 拷贝构造
	cout << ret;
	return 0;
}

//构造
TwoArray::TwoArray(int row, int col)
	:_row(row)
	, _col(col) {
	//二维数组 - 动态开辟
	//开辟一维一级指针数组
	_p = (int**)malloc(sizeof(int*) * _row);
	//开辟一维整形数组
	for (int i = 0; i < _row; i++) {
		_p[i] = (int*)malloc(sizeof(int) * _col);
	}
}
//拷贝构造
TwoArray::TwoArray(TwoArray& a) {
	_row = a._row;
	_col = a._col;
	_p = (int**)malloc(sizeof(int*) * _row);
	//开辟一维整形数组
	for (int i = 0; i < _row; i++) {
		_p[i] = (int*)malloc(sizeof(int) * _col);
	}
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			_p[i][j] = a._p[i][j];
		}
	}
}
//拷贝构造
TwoArray::TwoArray(const TwoArray& a) {
	_row = a._row;
	_col = a._col;
	_p = (int**)malloc(sizeof(int*) * _row);
	//开辟一维整形数组
	for (int i = 0; i < _row; i++) {
		_p[i] = (int*)malloc(sizeof(int) * _col);
	}
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			_p[i][j] = a._p[i][j];
		}
	}
}

TwoArray& TwoArray::operator=(const TwoArray& a) {
	_row = a._row;
	_col = a._col;
	int** tmp1 = (int**)realloc(_p, sizeof(int*) * _row);
	assert(tmp1);
	_p = tmp1;
	//开辟一维整形数组
	for (int i = 0; i < _row; i++) {
		int* tmp2 = (int*)realloc(_p[i], sizeof(int) * _col);
		assert(tmp2);
		_p[i] = tmp2;
	}
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			_p[i][j] = a._p[i][j];
		}
	}
	return *this;
}

//输入元素
istream& operator>>(istream& in, TwoArray& a) {
	//输入数组元素
	for (int i = 0; i < a._row; ++i) {
		for (int j = 0; j < a._col; ++j) {
			cin >> a._p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const TwoArray& a) {
	cout << a._row << "*" << a._col << " 矩阵如下>" << endl;
	for (int i = 0; i < a._row; ++i) {
		for (int j = 0; j < a._col; j++) {
			printf("%-3d ", a._p[i][j]);
		}
		cout << endl;
	}
	return out;
}

//得到某一元素
int& TwoArray::GetNum(int i, int j) {
	return _p[i][j];
}
//*运算符重载
TwoArray TwoArray::operator*(TwoArray& a) {
	//ret 结果类对象
	TwoArray ret(_row, a._col);
	//相乘
	//ret._row
	for (int i = 0; i < ret._row; ++i) {
		//ret._col
		for (int j = 0; j < ret._col; ++j) {
			int sum = 0;
			//_col或a._row，因为相乘：_col == a._row
			for (int k = 0; k < _col; ++k) {
				sum += GetNum(i, k) * a.GetNum(k, j);
			}
			ret.GetNum(i, j) = sum;
		}
	}
	return ret;
}
//析构
TwoArray::~TwoArray() {
	for (int i = 0; i < _row; i++) {
		free(_p[i]);
		_p[i] = nullptr;
	}
	free(_p);
	_p = nullptr;
}
