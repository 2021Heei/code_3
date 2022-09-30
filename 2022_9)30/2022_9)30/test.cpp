//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//#include <ctype.h>
//#include <stdbool.h>
////int firstUniqChar(char* s) {
////    int len = strlen(s);
////    char* cur = (char*)malloc(sizeof(char) * len);
////    strcpy(cur, s);
////    for (int i = 0; i < len; ++i) {
////        int flag = 0;
////        if (isupper(cur[i])) {
////            continue;
////        }
////        for (int j = i + 1; j < len; ++j) {
////            if (islower(cur[j]) && cur[i] == cur[j]) {
////                cur[j] = cur[j] -'a'+'A';
////                flag = 1;
////            }
////        }
////        if (flag == 0) {
////            return i;
////        }
////    }
////    return -1;
////}
//
//char* Find(char* s, char ch) {
//    while (*s) {
//        if (*s == ch) {
//            return s;
//        }
//        s++;
//    }
//    return NULL;
//}
//
//bool isAnagram(char* s, char* t) {
//    //在magaine中寻找与ransomNote相等的字符，找到就继续找，找不到就返回false
//    char* cur1 = s;
//    char* cur2 = t;
//    // int len1 = strlen(cur1);
//    // int len2 = strlen(cur2);
//    // if(len1 != len2){
//    //     return false;
//    // }
//    while (*cur1) {
//        char* ret = Find(t, *cur1);
//        if (ret) {
//            *ret = *ret - 'a' + 'A';
//        }
//        else {
//            return false;
//        }
//        cur1++;
//        cur2++;
//    }
//    int len1 = strlen(cur1);
//    int len2 = strlen(cur2);
//    //if (cur1 == '\0' && cur2 == '\0')
//    if (len1 == 0 && len2 == 0)
//        return true;
//    else
//        return false;
//}
//
//int main() {
//    char str1[] = "anagram";
//    char str2[] = "nagaram";
//    int ret = isAnagram(str1, str2);
//    printf("%d\n", ret);
//    return 0;
//}



//#include <stdio.h>
//#include <stdlib.h>
//int rand = 0;
//int main() {
//
//	printf("%d\n", rand);
//	return 0;
//}
//
//#include <iostream>
//
//int main() {
//	int rand = 0;//局部优先原则
//	std::cout << rand << std::endl;
//	std::cout << std::rand << std::endl;
//	return 0;
//}
//
// 命名空间意义：预防了名义冲突
//默认查找规则 - 先在本作用域查找，再去全局查找，仅向上查找，找不到报错
//命名空间影响查找规则，是全局变量
//指定查找规则 - 需要域作用限定符，找不到直接报错
//#include <iostream>
//namespace weihe {
//	int rand = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//}
//
//namespace wei {
//	int rand = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//}
//
//int main() {
//	int rand = 1;
//	std::cout << &weihe::rand << std::endl;
//	std::cout << &wei::rand << std::endl;
//	std::cout << weihe::Add << std::endl;
//	std::cout << wei::Add << std::endl;
//	return 0;
//}

////命名空间的嵌套
//#include <iostream>
//
//namespace N1 {
//	int rand = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//
//	namespace N2 {
//		int rand = 0;
//		int Add(int a, int b) {
//			return a + b;
//		}
//	}
//}
//
//int main() {
//	int rand = 1;
//	std::cout << &N1::rand << std::endl;
//	std::cout << &N1::N2::rand << std::endl;
//	std::cout << N1::Add << std::endl;
//	std::cout << N1::N2::Add << std::endl;
//	return 0;
//}

//std C++官方库内容定义的命名空间
//不同位置的同名的命名空间的自动合并

//#include <iostream>
//
//namespace N1 {
//	int rand = 0;
//	int Add(int a, int b) {
//		return a + b;
//	}
//
//	namespace N1 {
//		int rand = 0;
//		int Add(int a, int b) {
//			return a + b;
//		}
//	}
//}
//
//int main() {
//	int rand = 1;
//	std::cout << &N1::rand << std::endl;
//	std::cout << &N1::N1::rand << std::endl;
//	std::cout << N1::Add << std::endl;
//	std::cout << N1::N1::Add << std::endl;
//	return 0;
//}

////命名空间 - 全部展开
//#include <iostream>
//using namespace std;
//
//int main() {
//	cout << "ad" << endl;
//	std::cout << "ad" << std::endl;
//
//	return 0;
//}

////命名空间 - 部分展开
//#include <iostream>
//using std::cout;
//using std::endl;
//
//int main() {
//	cout << "ad" << endl;
//	std::cout << "ad" << std::endl;
//
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//int main() {
//	int a;
//	double d;
//	char c;
//	cin >> a >> d >> c;
//	cout <<"int: " << a << " " << "double: " << d << " " << " char: " << c << " " << endl;
//	printf("int:%d double:%.2lf char:%c\n", a, d, c);
//	cout << &a << " " << &d << " " << (int)c << endl;
//	return 0;
//}

//缺省形参参数 - 全缺省 - 部分缺省
//#include <iostream>
//using namespace std;
//
//void Func(int a = 10) {
//	cout << a << endl;
//}
//
//int main() {
//	Func();
//	Func(100);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Func(int a = 0, int b = 0, int c = 0) {
//	cout << "a " << a << endl;
//	cout << "b " << b << endl;
//	cout << "c " << c << endl;
//}
//
//int main() {
//	Func();
//	Func(100);
//	Func(100, 200);
//	Func(100, 200);
//	//Func(100,,300);//语法上来说实参依次从左向右传（与形参匹配），不能跳跃
//	return 0;		//缺省参数需要从右往左连续缺省
//}

//#include <iostream>
//using namespace std;
//
//void Func(int a, int b = 0, int c = 0) {
//	cout << "a " << a << endl;
//	cout << "b " << b << endl;
//	cout << "c " << c << endl;
//}
//
//int main() {
//	//Func();
//	Func(100);
//	Func(100, 200);
//	Func(100, 200, 300);
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//void Func(int a, int b = 0, int c) {
//	cout << "a " << a << endl;
//	cout << "b " << b << endl;
//	cout << "c " << c << endl;
//}
//
//int main() {
//	//Func();
//	//Func(100);
//	Func(100, 200);
//	Func(100, 200, 300);
//	return 0;
//}


//#include <iostream>
//#include "Stack.h"
//using namespace std;
//
//
//int main() {
//	Stack::ST st1;
//	//使用默认初始化
//	Stack::Init(&st1);
//	//不使用默认初始化
//	Stack::ST st2;
//	Stack::Init(&st2, 1000);
//	return 0;
//}

//函数重载 - 一词多义
//#include <iostream>
//using namespace std;
//
//int Add(int a, int b) {
//	return a + b;
//}
//
//double Add(double x, double y) {
//	return x + y;
//}
//
//void Swap(int* pa, int* pb) {
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//void Swap(double* pa, double* pb) {
//	double tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//int main() {
//	cout << Add(10, 20) << endl;
//	cout << Add(10.2, 20.3) << endl;
//
//	int a = 10, b = 20;
//	Swap(&a, &b);
//	double x = 30.3, y = 40.4;
//	Swap(&x, &y);
//	cout << a << " " << b << endl;
//	cout << x << " " << y << endl;
//	return 0;
//}


//#include <iostream>
//using namespace std;
//
//void func() {
//	cout << "func()" << endl;
//}
//
//void func(int a) {
//	cout << "func(int a)" << endl;
//}
//
//void func(int a, char b) {
//	cout << "func(int a, char b)" << endl;
//}
//
//void func(char a, int b) {
//	cout << "func(char a, int b)" << endl;
//}
//
//
//int main() {
//	func();
//	func(1);
//	func(1, 'a');
//	func('a', 10);
//
//	return 0;
//}

////函数重载与缺省参数 - 
//#include <iostream>
//using namespace std;
//void f() {
//	cout << "f()" << endl;
//}
//
//void f(int a = 0, char b = 'a') {
//	cout << "f(int a, char b)" << endl;
//}
//int main() {
//	f(10);
//	f(10, 'd');
//	//f();//存在歧义，报错
//	return 0;
//}

//#include <iostream>
//using namespace std;
//
//typedef struct ListNode {
//	int data;
//	struct ListNode* next;
//}SLNode,*PSTNode;
//
////void SeqListPush(SLNode** pphead, int val) {
////
////}
////void SeqListPush(SLNode*& phead, int val) {
////
////}
//
//void SeqListPush(PSTNode& phead, int val) {
//
//}
//int main() {
//	SLNode* plist = NULL;
//	//SeqListPush(&plist, 10);
//	//SeqListPush(plist, 10);
//	//SeqListPush(plist, 10);
//
//
//	int a = 10;
//	int& b = a;
//	int& c = b;
//	int& d = a;
//	a++;
//	b++;
//	c++;
//	d++;
//
//
//	return 0;
//}


