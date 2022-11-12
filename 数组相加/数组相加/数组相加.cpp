#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cassert>
#include <fstream>
#include <array>
#include <new>
using namespace std;

#define CAPACITY 10

class Array {
	friend ostream& operator<<(ostream& out, const Array& arr);
	friend istream& operator>>(istream& in, Array& arr);
public:
	//构造
	Array()
		:_size(0)
		,_capacity(CAPACITY){
		_array = new int[_capacity];
		memset(_array, 0, sizeof(int) * CAPACITY);
	}
	//拷贝构造
	Array(const Array& arr) {
		_array = new int[arr._capacity];
		memcpy(_array, arr._array, sizeof(int) * arr._capacity);
		_size = arr._size;
		_capacity = arr._capacity;
	}

	//赋值运算符重载
	Array& operator=(const Array& arr) {
		memcpy(_array, arr._array, sizeof(int) * arr._capacity);
		_size = arr._size;
		_capacity = arr._capacity;
		return *this;
	}

	Array operator+(Array& arr) {
		Array cur(*this);
		for (int i = 0; i < CAPACITY; ++i) {
			cur._array[i] += arr._array[i];
		}
		cur._size = (cur._size > arr._size) ? cur._size : arr._size;
		return cur;
	}

	int& operator[](int i) const{
		assert(i >= 0 && i < _capacity);
		return _array[i];
	}

	//析构
	~Array() {
		delete[] _array;
		_size = _capacity = 0;
	}
private:
	int* _array;
	int _size;
	int _capacity;
};

ostream& operator<<(ostream& out, const Array& arr) {
	for (int i = 0; i < arr._capacity; ++i) {
		out << arr[i] << " ";
	}
	cout << endl;
	return out;
}

istream& operator>>(istream& in, Array& arr) {
	for (int i = 0; i < arr._capacity; ++i) {
		in >> arr[i];
	}
	return in;
}

void InitArray(Array& arr1, Array& arr2) {
	ofstream outfile("input.dat", ios::out);
	if (!outfile) {
		cerr << "outfile error" << endl;
		exit(-1);
	}
	srand(time(0));
	for (int i = 0; i < 20; ++i) {
		int v = rand() % 1000;
		outfile << v << " ";
		if (i == 9) {
			outfile << '\n';
		}
	}
	outfile.close();

	ifstream infile("input.dat", ios::in);
	if (!infile) {
		perror("infile");
		cerr << "infile error" << endl;
		exit(-1);
	}
	char ch;
	for (int i = 0; i < 10; ++i) {
		ch = 0;
		int val = 0;
		while (infile.get(ch) && ch != ' ') {
			val = val * 10 + ch - '0';
		}
		
		arr1[i] = val;
	}
	infile.get(ch);
	for (int i = 0; i < 10; ++i) {
		ch = 0;
		int val = 0;
		while (infile.get(ch) && ch != ' ') {
			val = val * 10 + ch - '0';
		}
		arr2[i] = val;
	}
	infile.close();

}

int main() {

	Array a1;
	Array a2;
	//文件初始化数组a1,a2
	InitArray(a1, a2);
	cout << a1 << endl;
	cout << a2 << endl;
	//两个数组a1和a2相加
	Array a3 = a1 + a2;
	cout << a3 << endl;
	return 0;
}