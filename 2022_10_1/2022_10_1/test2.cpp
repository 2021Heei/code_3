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

////����
//typedef struct SeqList {
//	int val;
//	struct SeqList* next;
//}STNode;
//void SLPushBack(STNode** pphead, int val);
////����������Ͳ���
//// - ���ٿ��������Ч��
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
//	cout << "ǰx: " << x;
//	cout << " y: " << y << endl;
//	Swap(x, y);
//	cout << "��x: " << x;
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
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
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
////���÷��� �� ��ֵ����Ч��
//struct A {
//	int a[10000];
//};
//A a;
//
//// ֵ����
//A TestFunc1() {
//	return a;
//}
//// ���÷���
//A& TestFunc2() {
//	return a;
//}
//
//void Test()
//{
//	// ��ֵ��Ϊ�����ķ���ֵ����
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc1();
//	size_t end1 = clock();
//	// ��������Ϊ�����ķ���ֵ����
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 100000; ++i)
//		TestFunc2();
//	size_t end2 = clock();
//	// �������������������֮���ʱ��
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


////������
////Ȩ�޿���ƽ�ƺ���С�����ǲ��ܷŴ�
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
//	//����ָ������ã��ڸ�ֵʱ��Ҫ����Ȩ��
//	//a����Ϊ�ɶ���д����
//	int a = 0;
//	//Ȩ��ƽ�� - ��ȫ���a��Ȩ��
//	int& ra = a;
//	//Ȩ����С - ֻ���a�Ķ�Ȩ��
//	const int& rra = a;
//
//	//b����Ϊֻ������
//	const int b = 10;
//	//Ȩ�޷Ŵ󣬳��� - ��ó���b�����Ȩ��
//	//int& rb = b;
//	//Ȩ��ƽ��
//	const int& rrb = b;
//	//const���γ�����������Ϊ��ֵ�����ǲ�����Ϊ��ֵ
//	a = rrb;//true
//	//rrb = a;//error
//
//	function(a);
//	function(ra);
//	//function(rra);//x��int&���ĸı��Ӱ��rra��const int&�������Բ��ܴ���rra
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
//	//a����Ϊ�ɶ���д����
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
//	//ת�����̣���ʽ���͡�ǿ�����͡���������������ת���ȣ�������������ʱ�������d����С������ֵ3��
//	//����ʱ����������int���Ҿ��г��ԣ�����const�޶������Σ�
//	//rdʵ�����Ǹ���ʱ���������ã���������Ҳ��Ҫ����const����rd
//	cout << rd << endl;
//	//���ߵ�ַ����ͬҲ��˵��
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
////int& a = count();//error,��ʱ�������г��ԣ�const��
//const int& a = count();//true,��ʱ�������г��ԣ�const��

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