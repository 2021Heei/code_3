#include "Date.h"

void TestDate1() {
	Date d1(2022,10,11);
	//Date d2();//与函数声明产生了混淆
	/*Date d3(2022, 2, 2202002);
	d3.Print();
	Date d4(2022, 2, 220);
	d4.Print();*/
	/*Date d5(d1);
	d5.Print();
	Date d6 = d5;
	d6.Print();*/
	/*Date d7, d8, d9;
	d7 = d8 = d9 = d1;
	d7.Print();
	d8.Print();
	d9.Print();*/

	Date d2(2022, 10, 11);
	d2 + 40;//d2.operator(40); -> d2.operator(&d2, 40)
	(d2 + 40).Print();
	d2 += 40;
	d2.Print();

	//Date d3;
	//-d3;
}

void TestDate2() {

	Date d1(2022, 10, 12);
	Date d2;

	d2.Print();
	d2 = d1;
	d2.Print();

	//Date d1(2022, 10, 11);
	//Date d2(d1);	//拷贝构造，一个拷贝初始化另一个马上要创建的对象
	//Date d3 = d1;	//拷贝构造
	//Date d4;
	//d4 = d1;		//赋值重载、复制拷贝，已存在的两个对象之间的拷贝
	//d1.Print();
	//d2.Print();
	//d3.Print();
	//d4.Print();
	//赋值运算符重载：
	//为什么用引用返回？ - 减少一次拷贝
	//为什么参数用常引用？ - 减少一次拷贝，且使用方便
	//为什么返回*this，而不是d？ 
	//		- this是第一个参数，相当于赋值时的左值；d是第二个参数，相当于赋值时的右值；
	//		连续赋值时一般表达式的返回值是左边的变量，
	//为什么不用指针做第二个参数？ - 使用麻烦

	/*Date d6, d7;
	d6 = d7 = d2;
	d6.Print();
	d7.Print();*/
}

void TestSatck() {
	Stack st1;
	st1.Push(1);
	st1.Push(2);
	Stack st2;
	st2.Push(10);
	st2.Push(20);
	st2.Push(30);

	//st1 = st2;//默认赋值运算符重载函数不能够完成栈的赋值需求，需要我们手动写
	st1 = st2;//这里为什么不用realloc()，而是先free，再malloc()???
	//分为三种情况：（基于栈的容量）
	//st1小于st2
	//st1与st2基本相当
	//st1大于st2

	//Stack st3;
	////st3.Push(1);
	//st3.Push(2);

	//st3 = st3;//防止自己给自己赋值，进行判断即可

	////myQueue和Date类operator= 满足需求，不需要再手动写了
	//myQueue q1;
	//q1.Push(1);
	//q1.Push(2);
	//myQueue q2;
	//q2.Push(2);
	//q2.Push(2);

	//q1 = q2;

}

void TestDate3() {
	/*Date d1(2022, 10, 11);
	Date d2(2022, 10, 11);
	int ret = d1 > d2;

	(d1 + 1000).Print();
	d2 += 10000;
	d2.Print();
	d1 += -20000;
	d1.Print();*/

	/*Date d1(2022, 10, 11);
	Date d2(2022, 10, 11);
	int ret = d1 > d2;

	(d1 - 1000).Print();
	d2 -= 10000;
	d2.Print();
	d1 -= -10000;
	d1.Print();*/

	//	前置和后置函数，运算符重载和函数重载，
	//	后置多了一个int参数，目的是与前置区分，由编译器传递，构成函数重载
	//	对于内置类型，前置与后置基本没有差别；
	//	对于自定义类型，前置比后置少了两次拷贝构造函数的调用，所以尽量使用前置++/--
	/*Date d1(2022, 10, 11);
	Date d2(2022, 10, 11);
	d1.Print();
	(++d1).Print();
	d1.Print();

	d2.Print();
	(d2++).Print();
	d2.Print();*/

	/*Date d1(2022, 10, 11);
	Date d2(2022, 10, 11);
	d1.Print();
	(--d1).Print();
	d1.Print();

	d2.Print();
	(d2--).Print();
	d2.Print();*/
	
	Date d1(2022, 10, 12);
	Date d2(2020, 12, 28);
	cout << (d1 < d2) << endl;
	cout << d1 - d2 << endl;
}

void TestDate4() {
	Date d1;
	//cin >> d1;
	//d1 >> cin;//流插入运算符>> 左右操作数反了

	Date d2;
	//cin >> d2;
	//cin >> d2;// operator>>(cin, d2);
	d2 << cout;
	//cout << d2;
}

void TestDate5() {
	Date d1;
	cout << &d1 << endl;

	/*const Date d2;
	cout << &d2 << endl;*/
}
//int main() {
//
//	//TestDate1();
//	//TestDate2();
//	//TestSatck();
//	//TestDate3();
//	//TestDate4();
//	TestDate5();
//	return 0;
//}



////////////////////////////////////////////////////////////////////////////////////////////////
//2022 - 10 - 13