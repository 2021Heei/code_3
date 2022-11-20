//�������
#include <iostream>
#include <cstdlib>
#include <cassert>
using namespace std;

class TwoArray {
	//������  �� ����ȡ
	friend ostream& operator<<(ostream& out, const TwoArray& a);
	friend istream& operator>>(istream& in, TwoArray& a);
public:
	//����
	TwoArray(int row, int col);
	//����
	~TwoArray();
	//��������
	TwoArray(TwoArray& a);
	TwoArray(const TwoArray& a);
	//*���������
	TwoArray operator*(TwoArray& a);
	//��ֵ���������
	TwoArray& operator=(const TwoArray& a);

	//�õ�ĳһԪ��
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
	
	printf("�������һ�������Ԫ��%d * %d>", row1, col1);
	TwoArray arr1(row1, col1);
	cin >> arr1;
	cout << arr1;

	printf("������ڶ��������Ԫ��%d * %d>", row2, col2);
	TwoArray arr2(row2, col2);
	cin >> arr2;
	cout << arr2;

	TwoArray ret = arr1 * arr2;//��������+��������  �Ż�---> ��������
	cout << ret;
	return 0;
}

//����
TwoArray::TwoArray(int row, int col)
	:_row(row)
	, _col(col) {
	//��ά���� - ��̬����
	//����һάһ��ָ������
	_p = (int**)malloc(sizeof(int*) * _row);
	//����һά��������
	for (int i = 0; i < _row; i++) {
		_p[i] = (int*)malloc(sizeof(int) * _col);
	}
}
//��������
TwoArray::TwoArray(TwoArray& a) {
	_row = a._row;
	_col = a._col;
	_p = (int**)malloc(sizeof(int*) * _row);
	//����һά��������
	for (int i = 0; i < _row; i++) {
		_p[i] = (int*)malloc(sizeof(int) * _col);
	}
	for (int i = 0; i < _row; ++i) {
		for (int j = 0; j < _col; ++j) {
			_p[i][j] = a._p[i][j];
		}
	}
}
//��������
TwoArray::TwoArray(const TwoArray& a) {
	_row = a._row;
	_col = a._col;
	_p = (int**)malloc(sizeof(int*) * _row);
	//����һά��������
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
	//����һά��������
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

//����Ԫ��
istream& operator>>(istream& in, TwoArray& a) {
	//��������Ԫ��
	for (int i = 0; i < a._row; ++i) {
		for (int j = 0; j < a._col; ++j) {
			cin >> a._p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const TwoArray& a) {
	cout << a._row << "*" << a._col << " ��������>" << endl;
	for (int i = 0; i < a._row; ++i) {
		for (int j = 0; j < a._col; j++) {
			printf("%-3d ", a._p[i][j]);
		}
		cout << endl;
	}
	return out;
}

//�õ�ĳһԪ��
int& TwoArray::GetNum(int i, int j) {
	return _p[i][j];
}
//*���������
TwoArray TwoArray::operator*(TwoArray& a) {
	//ret ��������
	TwoArray ret(_row, a._col);
	//���
	//ret._row
	for (int i = 0; i < ret._row; ++i) {
		//ret._col
		for (int j = 0; j < ret._col; ++j) {
			int sum = 0;
			//_col��a._row����Ϊ��ˣ�_col == a._row
			for (int k = 0; k < _col; ++k) {
				sum += GetNum(i, k) * a.GetNum(k, j);
			}
			ret.GetNum(i, j) = sum;
		}
	}
	return ret;
}
//����
TwoArray::~TwoArray() {
	for (int i = 0; i < _row; i++) {
		free(_p[i]);
		_p[i] = nullptr;
	}
	free(_p);
	_p = nullptr;
}
