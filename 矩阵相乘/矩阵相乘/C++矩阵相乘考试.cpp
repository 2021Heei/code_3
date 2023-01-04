#define _CRT_SECURE_NO_WARNINGS 1
//矩阵相乘
#include <iostream>
#define row 3
#define col 3

using namespace std;

class TwoArray {
	//流插入  和 流提取
	friend ostream& operator<<(ostream& out, const TwoArray& a);
	friend istream& operator>>(istream& in, TwoArray& a);
public:
	//*运算符重载
	TwoArray operator*(TwoArray& a);
	//得到某一元素
	int& GetNum(int i, int j);
private:
	int _p[row][col];
};


int main() {

	printf("请输入第一个矩阵的元素%d * %d>", row, col);
	TwoArray arr1;
	cin >> arr1;
	cout << arr1;

	printf("请输入第二个矩阵的元素%d * %d>", row, col);
	TwoArray arr2;
	cin >> arr2;
	cout << arr2;

	TwoArray ret = arr1 * arr2;//拷贝构造+拷贝构造  优化---> 拷贝构造
	cout << ret;
	return 0;
}

//输入元素
istream& operator>>(istream& in, TwoArray& a) {
	//输入数组元素
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> a._p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const TwoArray& a) {
	cout << row << "*" << col << " 矩阵如下>" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; j++) {
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
	TwoArray ret;
	//相乘
	//ret._row
	for (int i = 0; i < row; ++i) {
		//ret._col
		for (int j = 0; j < col; ++j) {
			int sum = 0;
			//_col或a._row，因为相乘：_col == a._row
			for (int k = 0; k < col; ++k) {
				sum += GetNum(i, k) * a.GetNum(k, j);
			}
			ret.GetNum(i, j) = sum;
		}
	}
	return ret;
}
