//#include <iostream>
//using namespace std;

//����
//typedef struct SeqList {
//	int val;
//	struct SeqList* next;
//}STNode;
//void SLPushBack(STNode** pphead, int val);
////����������Ͳ���
// - ���ٿ��������Ч��
//void SLPushBack(STNode*& pphead, int val);
//
//int main() {
//
//	return 0;
//}


//#include <time.h>
//struct A { int a[10000]; };
//void TestFunc1(A a) {}
//void TestFunc2(A& a) {}
//void TestRefAndValue()
//{
//	A a;
//	// ��ֵ��Ϊ��������
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc1(a);
//	size_t end1 = clock();
//	// ��������Ϊ��������
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 1000000; ++i)
//		TestFunc2(a);
//	size_t end2 = clock();
//	// �ֱ���������������н������ʱ��
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}
//
//int main() {
//	TestRefAndValue();
//	return 0;
//}


//�������������� 

//int Count11() {
//	int n = 0;
//	n++;
//	return n;
//}
//
//int Count12() {
//	static int n = 0;
//	n++;
//	return n;
//}

//int& Count21() {
//	int n = 0;
//	n++;
//	return n;
//}
//
////int& Count22() {
////	static int n = 0;
////	n++;
////	return n;
////}
//
//void Func() {
//	int x = 100;
//}
//
//int main() {
//	int& ret = Count21();
//	cout << ret << endl;//1��ret�ȱ����ʣ�Ȼ��cout����ջ֡������һ��Count����ջ֡
//	cout << ret << endl;//��һ�κ�������cout������ջ֡�ٴδ���������ret��λ�ã��������ֵ
//	Func();
//	cout << ret << endl;//���ֵ
//	return 0;
//}

//���÷��� 
//
//- �޸ķ���ֵ
//#include "SeqList.h"
//int main() {
//	SL s;
//	SLInit(&s);
//	SLPushBack(&s, 1);
//	SLPushBack(&s, 2);
//	SLPushBack(&s, 3);
//	SLPushBack(&s, 4);
//	SLPushBack(&s, 6);
//	for (size_t i = 0; i < SLSize(&s); ++i) {
//		if (SLAt(&s, i) % 2 == 0) {
//			SLAt(&s, i) *= 2;
//		}
//	}
//	SLPrint(&s);
//
//	SLDestroy(&s);
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
//int main()
//{
//	int& ret = Add(1, 2);
//	Add(3, 4);//����ջ֡�����¸��ǵ���
//	cout << "Add(1, 2) is :" << ret << endl;
//	return 0;
//}


//���÷��� �� ��ֵ����Ч��
//#include <time.h>
//struct A { 
//	int a[10000]; 
//};
//A a;
//
//// ֵ����
//A TestFunc1() { 
//	return a; 
//}
//
//// ���÷���
//A& TestFunc2() { 
//	return a; 
//}
//
//void TestReturnByRefOrValue()
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
//	TestReturnByRefOrValue();
//	return 0;
//}


//������
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
//	cout << "&d  " <<  &d << endl;
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

//���õײ�ʵ�� - 
//�����﷨ - 


//�﷨��
//auto - �������ʱ�����Զ�ʶ�����ͣ��Ż����͹�����ɵ�
//��typedef��Щ����

//��Χforѭ��
//int main() {
//	int array[] = { 1,2,3,4,5,6,7,8,9 ,0 };
//	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i) { 
//		cout << array[i] << " ";
//	}
//	cout << endl;
//
//	for (auto e : array) {
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}