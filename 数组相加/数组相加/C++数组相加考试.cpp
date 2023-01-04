#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <fstream>
#define CAPACITY 10
using namespace std;

class Array {
	friend ostream& operator<<(ostream& out, Array& arr);
	friend istream& operator>>(istream& in, Array& arr);
public:
	Array operator+(Array& arr) {
		Array cur(*this);
		for (int i = 0; i < CAPACITY; ++i) {
			cur._array[i] += arr._array[i];
		}
		return cur;
	}
	int& operator[](int i) {
		assert(i >= 0 && i < CAPACITY);
		return _array[i];
	}
private:
	int _array[CAPACITY];
};

//初始化input.dat文件
void InitFile(const char* str);
//从文件input.dat中读取数据到两个数组中
void InitArray(const char* str, Array& arr1, Array& arr2);
//输出到文件output.dat中
void OutFile(const char* str, Array& array);

int main() {
	//初始化文件input.dat中的数据便于读取
	InitFile("input.dat");
	Array arr1;
	Array arr2;
	//文件初始化数组arr1,arr2
	InitArray("input.dat", arr1, arr2);
	//两个数组arr1和arr2相加
	Array arr3 = arr1 + arr2;
	cout << "数组arr1与arr2相加后的结果" << endl;
	OutFile("output.dat", arr3);
	cout << arr3 << endl;
	return 0;
}

ostream& operator<<(ostream& out, Array& arr) {
	for (int i = 0; i < CAPACITY; ++i) {
		out << arr[i] << " ";
	}
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Array& arr) {
	for (int i = 0; i < CAPACITY; ++i) {
		in >> arr[i];
	}
	return in;
}

void InitFile(const char* str) {
	ofstream outfile(str, ios::out);
	if (!outfile) { exit(-1); }
	srand(time(0));
	for (int i = 0; i < 20; ++i) {
		outfile << rand() % 1000 << " ";
		if (i == 9) {
			outfile << '\n';
		}
	}
	outfile.close();
}

void OutFile(const char* str, Array& array) {
	ofstream outfile(str, ios::out);
	if (!outfile) { exit(-1); }
	for (int i = 0; i < 10; ++i) {
		outfile << array[i] << " ";
	}
	outfile.close();
}

void InitArray(const char* str, Array& arr1, Array& arr2) {
	ifstream infile(str, ios::in);
	if (!infile) { exit(-1); }
	cout << "从文件 " << str << " 中读取第一行数据到数组arr1中" << endl;
	char ch;
	for (int i = 0; i <= 20; ++i) {
		ch = 0;
		int val = 0;
		while (infile.get(ch) && ch != ' '&& ch!='\n') {
			val = val * 10 + ch - '0';
		}
		if (i >= 0 && i <= 9) {
			arr1[i] = val;
		}
		else if(i==10){
			cout << arr1 << endl;
			cout << "从文件 " << str << " 中读取第二行数据到数组arr2中" << endl;
		}
		else {
			arr2[i-11] = val;
		}
	}
	cout << arr2 << endl;
	infile.close();
}