//#include <iostream>
//using namespace std;
//
//int main() {
//
//    int a = 10;
//    int& ra = a;
//    int& rra = ra;
//
//    a++;
//    ra++;
//    rra++;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//
//    int a = 10;
//    int& ra = a;
//    
//    int b = 100;
//    int& ra = b;
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//
//    double d = 3.14;
//    const int& a = d;
//    return 0;
//}

////引用
//typedef struct SeqList {
//	int val;
//	struct SeqList* next;
//}STNode;
//void SLPushBack(STNode** pphead, int val);
////引用做输出型参数
//// - 减少拷贝，提高效率
//void SLPushBack(STNode*& pphead, int val);
//
//int main() {
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Swap(int& a, int& b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main() {
//
//	int x = 10;
//	int y = 20;
//	cout << "前x: " << x;
//	cout << " y: " << y << endl;
//	Swap(x, y);
//	cout << "后x: " << x;
//	cout << " y: " << y << endl;
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int& Count(){
//	int n = 0;
//	n++;
//	
//	return n;
//}
//int main() {
//	int& ret = Count();
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int Count(){
//	static int n = 0;
//	n++;
//
//	return n;
//}
//int main() {
//	int ret = Count();
//	return 0;
//}

//#include <iostream>
//#include <time.h>
//using namespace std;
//
//#include <time.h>
//struct A { 
//	int a[1000];
//};
//
//void TestFunc1(A a) {
//}
//
//void TestFunc2(A& a) {
//}
//
//A a;
//
//void Test(){
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main() {
//	Test();
//	return 0;
//}

//#include <iostream>
//#include <time.h>
//using namespace std;
//
////引用返回 与 传值返回效率
//struct A {
//	int a[10000];
//};
//A a;
//
//// 值返回
//A TestFunc1() {
//	return a;
//}
//// 引用返回
//A& TestFunc2() {
//	return a;
//}
//
//void Test()
//{
//	// 以值作为函数的返回值类型
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// 以引用作为函数的返回值类型
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// 计算两个函数运算完成之后的时间
//	cout << "TestFunc1 time:" << end1 - begin1 << endl;
//	cout << "TestFunc2 time:" << end2 - begin2 << endl;
//}
//
//int main() {
//	Test();
//	return 0;
//}

//#include <iostream>
//
//int main() {
//	int a = 10;
//	int& ra = a;
//	int&& rra = ra;//
//	return 0;
//}

//#include <iostream>
//
//int main() {
//	int a = 10;
//	int& ra = a;
//	int&* p = &ra;
//	return 0;
//}


////常引用
////权限可以平移和缩小，但是不能放大
//void function(int& x) {
//
//}
//
//void func(const int& y) {
//
//}
//
////void func(int& z = 10) {//error
////
////}
//
//void func(const int& z = 10) {
//
//}
//
//int main() {
//	//对于指针和引用：在赋值时需要考虑权限
//	//a定义为可读可写变量
//	int a = 0;
//	//权限平移 - 完全获得a的权限
//	int& ra = a;
//	//权限缩小 - 只获得a的读权限
//	const int& rra = a;
//
//	//b定义为只读变量
//	const int b = 10;
//	//权限放大，出错 - 获得超过b本身的权限
//	//int& rb = b;
//	//权限平移
//	const int& rrb = b;
//	//const修饰常变量可以作为右值，但是不能作为左值
//	a = rrb;//true
//	//rrb = a;//error
//
//	function(a);
//	function(ra);
//	//function(rra);//x（int&）的改变会影响rra（const int&），所以不能传入rra
//	//function(10);
//
//
//	func(a);
//	func(ra);
//	func(rra);
//	func(10);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//void function(const int& x) {
//
//}
//
//int main() {
//	//a定义为可读可写变量
//	int a = 0;
//	int& ra = a;
//	const int& rra = a;
//	function(a);//true
//	function(ra);//true
//	function(rra);//error
//	function(10);//error
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	const int& b = 10;
//	double d = 3.14;
//	cout << (int)d << "\n" << d << endl;
//	//int& rd = d;//error
//	const int& rd = d;//true,
//	//转换过程（隐式类型、强制类型、整形提升、算数转换等）产生了匿名临时变量存放d舍弃小数点后的值3，
//	//该临时变量类型是int，且具有常性（即用const限定符修饰）
//	//rd实际上是该临时变量的引用（别名），也需要加上const修饰rd
//	cout << rd << endl;
//	//二者地址不相同也可说明
//	cout << "&d  " << &d << endl;
//	cout << "&rd " << &rd << endl;
//	return 0;
//}
//
//int count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}
//
////int& a = count();//error,临时变量具有常性（const）
//const int& a = count();//true,临时变量具有常性（const）

//#include <iostream>
//using namespace std;
//
//int main() {
//	double a = 3.14;
//	const int& rra = a;//true
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	
//	int a = 10;
//	int& ra = a;
//	int* pa = &a;
//
//	return 0;
//}