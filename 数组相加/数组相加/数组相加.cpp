//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <iostream>
//#include <cassert>
//#include <fstream>
//#include <array>
//#include <new>
//using namespace std;
//
//#define CAPACITY 10
//
//class Array {
//	//输出运算符和输入运算符重载
//	friend ostream& operator<<(ostream& out, const Array& arr);
//	friend istream& operator>>(istream& in, Array& arr);
//public:
//	//构造
//	Array()
//		:_size(0)
//		,_capacity(CAPACITY){
//		_array = new int[_capacity];
//		memset(_array, 0, sizeof(int) * CAPACITY);
//	}
//	//拷贝构造
//	Array(const Array& arr) {
//		_array = new int[arr._capacity];
//		memcpy(_array, arr._array, sizeof(int) * arr._capacity);
//		_size = arr._size;
//		_capacity = arr._capacity;
//	}
//
//	//赋值运算符重载
//	Array& operator=(const Array& arr) {
//		memcpy(_array, arr._array, sizeof(int) * arr._capacity);
//		_size = arr._size;
//		_capacity = arr._capacity;
//		return *this;
//	}
//	//+运算符重载
//	Array operator+(Array& arr) {
//		Array cur(*this);
//		for (int i = 0; i < CAPACITY; ++i) {
//			cur._array[i] += arr._array[i];
//		}
//		cur._size = (cur._size > arr._size) ? cur._size : arr._size;
//		return cur;
//	}
//	//[]运算符重载
//	int& operator[](int i) const{
//		assert(i >= 0 && i < _capacity);
//		return _array[i];
//	}
//
//	//析构
//	~Array() {
//		delete[] _array;
//		_size = _capacity = 0;
//	}
//private:
//	int* _array;//整型指针，指向一块连续空间的起始地址
//	int _size;//数组的有效元素
//	int _capacity;//数组的容量
//};
//
////初始化input.dat文件
//void InitFile(const char* str);
////从文件input.dat中读取数据到两个数组中
//void InitArray(const char* str, Array& arr1, Array& arr2);
////输出到文件output.dat中
//void OutFile(const char* str, const Array& array);
//
//int main() {
//	//初始化文件input.dat中的数据便于读取
//	InitFile("input.dat");
//	Array arr1;
//	Array arr2;
//	//文件初始化数组arr1,arr2
//	InitArray("input.dat", arr1, arr2);
//	//两个数组arr1和arr2相加
//	Array arr3 = arr1 + arr2;
//	cout << "数组arr1与arr2相加后的结果" << endl;
//	OutFile("output.dat", arr3);
//	cout << arr3 << endl;
//	return 0;
//}
//
//
//ostream& operator<<(ostream& out, const Array& arr) {
//	for (int i = 0; i < arr._capacity; ++i) {
//		out << arr[i] << " ";
//	}
//	cout << endl;
//	return out;
//}
//
//istream& operator>>(istream& in, Array& arr) {
//	for (int i = 0; i < arr._capacity; ++i) {
//		in >> arr[i];
//	}
//	return in;
//}
//
////输出到文件output.dat中
//void OutFile(const char* str, const Array& array) {
//	ofstream outfile(str, ios::out);
//	if (!outfile) {
//		cerr << str << " error" << endl;
//		exit(-1);
//	}
//
//	for (int i = 0; i < 10; ++i) {
//		outfile << array[i] << " ";
//	}
//	outfile.close();
//}
//
////初始化input.dat文件
//void InitFile(const char* str) {
//	ofstream outfile(str, ios::out);
//	if (!outfile) {
//		cerr << str << " error" << endl;
//		exit(-1);
//	}
//	srand(time(0));
//	for (int i = 0; i < 20; ++i) {
//		int val = rand() % 1000;
//		outfile << val << " ";
//		if (i == 9) {
//			outfile << '\n';
//		}
//	}
//	outfile.close();
//}
//
////从文件input.dat中读取数据到两个数组中
//void InitArray(const char* str, Array& arr1, Array& arr2) {
//	ifstream infile(str, ios::in);
//	if (!infile) {
//		perror("infile");
//		cerr << str << "error" << endl;
//		exit(-1);
//	}
//	cout << "从文件 " << str << " 中读取第一行数据到数组arr1中" << endl;
//	char ch;
//	for (int i = 0; i < 10; ++i) {
//		ch = 0;
//		int val = 0;
//		while (infile.get(ch) && ch != ' ') {
//			val = val * 10 + ch - '0';
//		}
//
//		arr1[i] = val;
//	}
//	infile.get(ch);
//	cout << arr1 << endl;
//
//	cout << "从文件 " << str << " 中读取第二行数据到数组arr2中" << endl;
//	for (int i = 0; i < 10; ++i) {
//		ch = 0;
//		int val = 0;
//		while (infile.get(ch) && ch != ' ') {
//			val = val * 10 + ch - '0';
//		}
//		arr2[i] = val;
//	}
//	cout << arr2 << endl;
//	infile.close();
//
//}