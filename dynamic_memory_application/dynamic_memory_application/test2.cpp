#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
//namespace weihe{
//	template<typename T>
//	void swap(T& a, T& b) {
//		T tmp = a;
//		a = b;
//		b = tmp;
//	}
//}
////template <class T1,typename T2>
//
//
//
//int main() {
//	 
//	int a = 0, b = 1;
//	weihe::swap(a, b);
//	return 0;
//}


///////////////////////////////////////////////////////////////////////////////////////////////////////
//��������

//int main() {
//	//new��delete�������
//	//�������ͣ����malloc/free�������÷�������û����������
//	int* p1 = new int;
//	delete p1;
//
//	int* p2 = new int(0);
//	delete p2;
//
//	int* p3 = new int[10];
//	delete[] p3;
//	int* p4 = new int[10]{ 1,2,3,4 };
//	delete[] p4;
//	return 0;
//}


//�Զ�������
//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//	}
//private:
//	int _a;
//};
//int main() {
//	//new��delete���˻Ὺ���ڴ���ͷſռ䣬����ֱ�����Զ������͵Ĺ��캯������������
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	delete p1;
//	free(p2);
//	return 0;
//}

//struct ListNode {
//	int _val;
//	ListNode* _next;
//
//	ListNode(int val = 0) 
//		:_val(val), _next(nullptr) {
//		//cout << "���캯��: ListNode(int val = 0)" << endl;
//	}
//	~ListNode() {
//		_val = 0;
//		_next = nullptr;
//		cout << "��������: ~ListNode()" << endl;
//	}
//};
//
//int main() {
//	ListNode* n1 = new ListNode(1);
//	ListNode* n2 = new ListNode(2);
//	ListNode* n3 = new ListNode(3);
//	ListNode* n4 = new ListNode(4);
//	n1->_next = n2;
//	n2->_next = n3;
//	n3->_next = n4;
//	delete n1;
//	delete n2;
//	delete n3;
//	delete n4;
//	return 0;
//}


//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	/*~A() {
//		cout << "��������: ~A()" << endl;
//	}*/
//	~A() { cout << "*"; }
//private:
//	int _a;
//};
//
////new��deleteҪƥ�䣬��ƥ����ܱ���Ҳ���ܲ�������ͬ�ı������ķ�ӦҲ������ͬ
//int main() {
//	//new��һ����delete�˶��
//	//A* p1 = new A;
//
//	//delete[] p1;//����������ʽ���ھ�error
//	//free(p1);//��һ������
//	//delete p1;//true
//
//	//new�˶����delete��һ��
//	A* p2 = new A[10];
//	//delete[] p2;//true
//	//delete p2;//VS��������������ʽʵ�־Ͳ�������ʽʵ�־�error����ͬ������Ҳ����ͬ
//	return 0;
//}

//malloc/free��new/delete������

//int main() {
//	////mallocʧ�ܣ����ؿ�ָ��
//	//while (1) {
//	//	int* p1 = (int*)malloc(sizeof(int) * 1024 * 10);
//	//	if (p1) {
//	//		cout << p1 << endl;
//	//	}
//	//	else {
//	//		cout << "malloc fail" << endl;
//	//		break;
//	//	}
//	//}
//
//	//newʧ�ܣ����쳣
//	try {
//		while (1) {
//			int* p1 = new int[1024 * 10];
//			if (p1) {
//				cout << p1 << endl;
//			}
//			else {
//				cout << "malloc fail" << endl;
//				break;
//			}
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//int main() {
//	//newʧ�ܣ����쳣
//	try {
//		while (1) {
//			char* p1 = new char[1024 * 1024 * 1024];
//			cout << (void*)p1 << endl;
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}

//new�ĵײ� -- operator new
//operator new����new�����أ���������������غ���������һ������ĺ���
//û���Զ��������βΣ��ǿ�����ʵ�ֵ�ȫ�ֺ���

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~a()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	
// ���������operator new����
// 
//	int* p2 = new int;
//	delete p2;
//	A* p1 = new A;
//	delete p1;
//	return 0;
//}

//operator new
//int main() {
//	//newʧ�ܣ����쳣
//	try {
//		while (1) {
//			//char* p1 = new char[1024 * 1024 * 1024];
//			char* p1 = (char*)operator new(1024 * 1024 * 1024);
//			cout << (void*)p1 << endl;
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~a()" << endl;
//	}
//private:
//	int _a;
//};
//
////operator new[]
//int main() {
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = new A[10];
//	delete p2;
//	return 0;
//}


//��λnew
//Ϊ������Ŀռ���ù��캯��

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	
//	A* p1 = new A;
//	delete p1;
//
//	A* p2 = (A*)malloc(sizeof(A));
//	if (p2 == nullptr) {
//		perror("malloc fail");
//		exit(-1);
//	}
//	new(p2)A(2);
//	/*p2->~A();
//	free(p2);*/
//	delete p2;
//
//	return 0;
//}


//��λnew�÷� -- �Դ��ڴ������Ŀռ���г�ʼ��

//������ - ������
//malloc��new������ -- �÷����� -- �ײ�

//ָ������õ�����

