#define _CRT_SECURE_NO_WARNINGS 1
//�������
#include <iostream>
#define row 3
#define col 3

using namespace std;

class TwoArray {
	//������  �� ����ȡ
	friend ostream& operator<<(ostream& out, const TwoArray& a);
	friend istream& operator>>(istream& in, TwoArray& a);
public:
	//*���������
	TwoArray operator*(TwoArray& a);
	//�õ�ĳһԪ��
	int& GetNum(int i, int j);
private:
	int _p[row][col];
};


int main() {

	printf("�������һ�������Ԫ��%d * %d>", row, col);
	TwoArray arr1;
	cin >> arr1;
	cout << arr1;

	printf("������ڶ��������Ԫ��%d * %d>", row, col);
	TwoArray arr2;
	cin >> arr2;
	cout << arr2;

	TwoArray ret = arr1 * arr2;//��������+��������  �Ż�---> ��������
	cout << ret;
	return 0;
}

//����Ԫ��
istream& operator>>(istream& in, TwoArray& a) {
	//��������Ԫ��
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; ++j) {
			cin >> a._p[i][j];
		}
	}
	return in;
}

ostream& operator<<(ostream& out, const TwoArray& a) {
	cout << row << "*" << col << " ��������>" << endl;
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < col; j++) {
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
	TwoArray ret;
	//���
	//ret._row
	for (int i = 0; i < row; ++i) {
		//ret._col
		for (int j = 0; j < col; ++j) {
			int sum = 0;
			//_col��a._row����Ϊ��ˣ�_col == a._row
			for (int k = 0; k < col; ++k) {
				sum += GetNum(i, k) * a.GetNum(k, j);
			}
			ret.GetNum(i, j) = sum;
		}
	}
	return ret;
}
