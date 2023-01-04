//#include <iostream>
//using namespace std;
//
//class Array {
//public:
//	Array(int n) {
//		_n = n;
//	}
//private:
//	int* _arr;
//	int _n;
//};
//int main() {
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//class Complex {
//	friend ostream& operator<<(ostream& out, Complex& c);
//public:
//	Complex(double _real, double _imag) {
//		real = _real;
//		imag = _imag;
//	}
//	Complex(double r){ 
//		real = r, imag = 0;
//	}
//	Complex(Complex& c) {
//		real = c.real;
//		imag = c.imag;
//	}
//	Complex& operator+(double r) {
//		real += r;
//		return *this;
//	}
//private:
//	double real;
//	double imag;
//};
//
//ostream& operator<<(ostream& out, Complex& c) {
//	out << c.real << " + " << c.imag << "i" << endl;
//	return out;
//}
//
//int main() {
//	Complex c(1.5, 2.1);
//	double r = 3.14;
//	cout << c + r;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//class Furniture {
//public:
//	Furniture(double _length, double _wide) {
//		length = _length;
//		wide = _wide;
//	}
//	void display() {
//		cout << "length: " << length << endl;
//		cout << "wide: " << wide << endl;
//	}
//protected:
//	double length;
//	double wide;
//};
//
//class Bed :public virtual Furniture {
//public:
//	Bed(double _length, double _wide,double _high)
//		:Furniture(_length, _wide),high(_high){}
//protected:
//	double high;
//};
//
//class Sofa :public virtual Furniture {
//public:
//	Sofa(double _length, double _wide, string _material)
//		:Furniture(_length, _wide), material(_material) {}
//protected:
//	string material;
//};
//
//class SofaBed :public Bed, public Sofa {
//public:
//	SofaBed(double _length, double _wide, double _high, string _material, double _price)
//		:Furniture(_length, _wide), Bed(_length,_wide,_high), Sofa(_length,_wide,_material) {
//		price = _price;
//	}
//	void show() {
//		display();
//		cout << "high: " << high << endl;
//		cout << "material: " << material << endl;
//		cout << "price: " << price << endl;
//	}
//private:
//	double price;
//};
//
//int main() {
//	SofaBed s(10.5, 20.5, 10.5, "ľͷ", 50.5);
//	s.show();
//	return 0;
//}


#include<iostream>
using namespace std;
class Array{
public:
	void set();
	void find_max();
	void show();
	Array() { N = 0; array = nullptr; max = 0; };
private:
	int N;
	int* array;
	int max;
};

void Array::set() {
	cout << "Please enter the length of the array:" << endl;
	cin >> N;
	array = new int[N];
	cout << "Please enter the data in the array:" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> array[i];
	}
}
void Array::find_max() {
	max = array[0];
	for (int i = 1; i < N; i++)
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
}
void Array::show() {
	cout << "max=" << Array::max << endl;
}
int main(){
	Array arr;
	arr.set();
	arr.find_max();
	arr.show();
	return 0;
}