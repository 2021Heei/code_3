#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>

//int main() {
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	if (!p1) {
//		perror("malloc fail");
//		return -1;
//	}
//	free(p1);
//	p1 = NULL;
//	int* p2 = (int*)calloc(10, sizeof(int));
//	if (!p2) {
//		perror("calloc fail");
//		return -1;
//	}
//	free(p2);
//	p2 = NULL;
//	/*int* tmp = (int*)realloc(p1, sizeof(int) * 100);
//	if (!tmp) {
//		perror("realloc fail");
//		return -1;
//	}
//	p1 = tmp;
//	free(p1);*/
//	return 0;
//}

//int main() {
//	//�������4�����͵Ŀռ�
//	int* p1 = (int*)malloc(sizeof(int) * 4);
//	//���ռ��Ƿ�����ɹ�������ʧ�ܷ��ؿ�ָ��
//	if (!p1) {
//		perror("malloc fail");
//		return -1;
//	}
//	//�ͷ�ָ��p1ָ��Ŀռ�
//	free(p1);
//	//p1��NULL����ֹ��Ұָ���ʹ��
//	p1 = NULL;
//	return 0;
//}


//int main() {
//	//�������4�����͵Ŀռ�
//	char* p2 = (char*)calloc(400, sizeof(char));
//	//���ռ��Ƿ�����ɹ�������ʧ�ܷ��ؿ�ָ��
//	if (!p2) {
//		perror("malloc fail");
//		return -1;
//	}
//	//�ͷ�ָ��p1ָ��Ŀռ�
//	free(p2);
//	//p1��NULL����ֹ��Ұָ���ʹ��
//	p2 = NULL;
//	return 0;
//}

//int main() {
//	//�������4�����͵Ŀռ�
//	int* p1 = (int*)malloc(sizeof(int) * 4);
//	//���ռ��Ƿ�����ɹ�������ʧ�ܷ��ؿ�ָ��
//	if (!p1) {
//		perror("malloc fail");
//		return -1;
//	}
//	//���Ѿ����ٵ��ڴ�ռ�������ݣ���Ϊ�������
//	//ԭ�����������
//	//���ﲻֱ��ʹ��p1ָ�����realloc����ֵ��
//	//��Ϊp1�о����ָ���������ʧ��realloc���ؿ�ָ�룬
//	//����p1����Ϊ��ָ��,����ԭ��ָ���ڴ�ռ��Ҳ�����
//	int* tmp = (int*)realloc(p1, sizeof(int) * 8);
//	//���ռ��Ƿ�����ɹ�������ʧ�ܷ��ؿ�ָ��
//	if (!tmp) {
//		perror("realloc fail");
//		return -1;
//	}
//	p1 = tmp;
//
//	//�ͷ�ָ��p1ָ��Ŀռ�
//	free(p1);
//	//p1��NULL����ֹ��Ұָ���ʹ��
//	p1 = NULL;
//	return 0;
//}

#include <iostream>
#include <cstdlib>
using namespace std;

//int main() {
//
//	int* p1 = new int;
//	cout << "*p1= " << * p1 << endl;
//	*p1 = 10;
//	cout << "*p1= " << *p1 << endl;
//	return 0;
//}

//int main() {
//
//	int* p1 = new int[5];
//	return 0;
//}


//int main() {
//
//	int* p1 = new int(20);
//	cout << "*p1= " << *p1 << endl;
//	return 0;
//}

//int main() {
//
//	int* p1 = new int[5]{ 1,2 };
//	int* p2 = new int[5]{ 1,2,3,4,5 };
//	return 0;
//}

//int main() {
//
//	int* p1 = new int(20);
//	cout << "*p1= " << *p1 << endl;
//	delete p1;
//	return 0;
//}
//
//int main() {
//
//	int* p1 = new int[5]{ 1,2 };
//	delete[] p1;
//	p1 = nullptr;
//	return 0;
//}

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
//
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//	delete p1;
//	free(p2);
//	return 0;
//}

//int main() {
//
//	A* p1 = new A;
//	A* p2 = (A*)malloc(sizeof(A));
//
//	return 0;
//}


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

////new��deleteҪƥ�䣬��ƥ����ܱ���Ҳ���ܲ�������ͬ�ı������ķ�ӦҲ������ͬ
//int main() {
//	//new��һ����delete�˶��
//	//A* p1 = new A;
//
//	//delete[] p1;//����������ʽ���ھ�error
//	//free(p1);//��һ������
//	////delete p1;//true
//
//	//new�˶����delete��һ��
//	A* p2 = new A[10];
//	delete[] p2;//true
//	delete p2;//VS��������������ʽʵ�־Ͳ�������ʽʵ�־�error����ͬ������Ҳ����ͬ
//	return 0;
//}

//int main() {
//	/*int* p1 = new int;
//	delete[] p1;*/
//	A* p1 = new A[10];
//	free(p1);
//	return 0;
//}


////operator new
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

////operator new
//int main() {
//
//	int* p1 = new int;
//	int* p2 = (int*)operator new(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int));
//	return 0;
//}

////operator delete
//int main() {
//
//	int* p1 = (int*)operator new(sizeof(int));
//
//	delete p1;
//	p1 = nullptr;
//	return 0;
//}




//int main() {
//
//	A* p1 = new A;
//	A* p2 = (A*)operator new(sizeof(A));
//	A* p3 = (A*)malloc(sizeof(A));
//	return 0;
//
//}



//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//int main() {
//
//	A* p1 = (A*)operator new(sizeof(A));
//	/*p1->~A();
//	operator delete(p1);*/
//	delete p1;
//	p1 = nullptr;
//	return 0;
//}


//int main() {
//
//	int* p1 = (int*)operator new[](sizeof(int)*4);
//	operator delete[](p1);
//	p1 = nullptr;
//	return 0;
//}

//int main() {
//
//	A* p1 = new A[4];
//	A* p2 = (A*)operator new[](sizeof(A) * 4);
//	A* p3 = (A*)malloc(sizeof(A) * 4);
//	return 0;
//}

//class A {
//public:
//	A() {
//		cout << "���캯��: A(int a)" << endl;
//		_a = (int*)malloc(1024*1024*100);
//		if (!_a) {
//			perror("malloc fail");
//			exit(-1);
//		}
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//	}
//private:
//	int *_a;
//};
//
//int main() {
//
//	A* p1 = new A[4];
//	int a = 1;
//	free(p1-1);
//	//delete[](p1);
//	int b = 1;
//
//	return 0;
//}

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
//	A* p1 = (A*)operator new[](sizeof(A) * 4);
//	operator delete[](p1);
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
//		_a = 0;
//	}
//private:
//	int _a;
//};
//int main() {
//	A* p1 = (A*)operator new(sizeof(A));
//	new(p1)A(2);
//	p1->~A();
//	operator delete(p1);
//	p1 = nullptr;
//	return 0;
//}

//int main() {
//
//	A* p1 = (A*)malloc(sizeof(A));
//	new(p1)A(2);
//	p1->~A();
//	free(p1);
//	p1 = nullptr;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1,int b = 1, int c = 1) :_a(a),_b(b),_c(c) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = _b = _c = 0;
//	}
//private:
//	int _a;
//	int _b;
//	int _c;
//};
//int main() {
//	A* p1 = (A*)operator new(sizeof(A));
//	new(p1)A{ 2,2,2 };
//	//new(p1)A(2, 2, 2);
//	p1->~A();
//	operator delete(p1);
//	p1 = nullptr;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//int main() {
//	A* p1 = (A*)operator new[](sizeof(A) * 4);
//	//new(p1)A{ 2,2,2,2 };
//	for (int i = 0; i < 4; ++i) {
//		new(p1+i)A(2);
//	}
//	for (int i = 0; i < 4; ++i) {
//		(p1+i)->~A();
//	}
//	operator delete(p1);
//	p1 = nullptr;
//	return 0;
//}



//int main() {
//	//newʧ�ܣ����쳣
//	try {
//		while (1) {
//			//һ������1G�ڴ�
//			char* p1 = new char[1024 * 1024 * 1024];
//			cout << (void*)p1 << endl;
//		}
//	}
//	catch (exception& e) {
//		cout << e.what() << endl;
//	}
//	return 0;
//}


//int main() {
//
//	int* p1 = new int;
//	int* p2 = (int*)operator new(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int));
//	return 0;
//}

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
//	A* p2 = (A*)operator new(sizeof(A));
//	A* p3 = (A*)malloc(sizeof(A));
//	return 0;
//}


////operator new[]
//int main() {
//
//	int* p1 = new int[4];
//	int* p2 = (int*)operator new[](sizeof(int) * 4);
//	int* p3 = (int*)malloc(sizeof(int) * 4);
//	return 0;
//}

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
//	A* p1 = new A[4];
//	A* p2 = (A*)operator new[](sizeof(A) * 4);
//	A* p3 = (A*)malloc(sizeof(A) * 4);
//	return 0;
//}

////operator delete
//int main() {
//
//	int* p1 = (int*)operator new(sizeof(int));
//
//	operator delete(p1);
//	p1 = nullptr;
//	return 0;
//}

////operator delete
//int main() {
//
//	int* p1 = (int*)operator new(sizeof(int));
//
//	delete p1;
//	p1 = nullptr;
//	return 0;
//}


//class A {
//public:
//	A(int a = 1) : _a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
//	~A() {
//		cout << "��������: ~A()" << endl;
//		_a = 0;
//	}
//private:
//	int _a;
//};
//
//int main() {
//
//	A* p1 = (A*)operator new(sizeof(A));
//	int a = 0;
//	delete p1;
//	p1 = nullptr;
//	return 0;
//}


//int main() {
//
//	int* p1 = (int*)operator new[](sizeof(int) * 4);
//
//	operator delete[](p1);
//	p1 = nullptr;
//	return 0;
//}

//class A {
//public:
//	A(int a = 1) :_a(a) {
//		cout << "���캯��: A(int a)" << endl;
//	}
	//~A() {
	//	cout << "��������: ~A()" << endl;
	//}
//private:
//	int _a;
//};
//
//int main() {
//
//	A* p1 = (A*)operator new[](sizeof(A) * 4);
//	delete p1;
//	return 0;
//}

//int main() {
//
//	A* p1 = new A[4];
//	delete[] p1;
//	return 0;
//}

//operator delete[](p1);

//int main() {
//
//	A* p1 = (A*)operator new(sizeof(A));
//	operator delete(p1);
//	p1 = nullptr;
//	return 0;
//}

//int main() {
//	int* p1 = new int[4];
//
//	_CrtDumpMemoryLeaks();
//	return 0;
//}


class A {
public:
	A(int a = 1) :_a(a) {
		cout << "���캯��: A(int a)" << endl;
	}
private:
	int _a;
};

int main() {
	A* p = new A[4];

	delete p;
	_CrtDumpMemoryLeaks();
	return 0;
}


//int main() {
//	A* p = new A[7];
//
//	delete[] p;
//
//	return 0;
//}


