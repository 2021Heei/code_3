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
	Date d1;
	Date d2(2022, 10, 11);
	Date d3(d2);	//拷贝构造，一个拷贝初始化另一个马上要创建的对象
	Date d4 = d2;	//拷贝构造
	Date d5;
	d5 = d2;		//赋值重载、复制拷贝，已存在的两个对象之间的拷贝
	d2.Print();
	d3.Print();
	d4.Print();
	d5.Print();
	//赋值运算符重载：
	//为什么用引用返回？ - 减少一次拷贝
	//为什么参数用常引用？ - 减少一次拷贝，且使用方便
	//为什么返回*this，而不是d？ 
	//		- this是第一个参数，相当于赋值时的左值；d是第二个参数，相当于赋值时的右值；
	//		连续赋值时一般表达式的返回值是左边的变量，
	//为什么不用指针做第二个参数？ - 使用麻烦

	Date d6, d7;
	d6 = d7 = d2;
	d6.Print();
	d7.Print();
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

	Stack st3;
	st3.Push(1);
	st3.Push(2);

	st3 = st3;//防止自己给自己赋值，进行判断即可

	//myQueue和Date类operator= 满足需求，不需要再手动写了
	myQueue q1;
	q1.Push(1);
	q1.Push(2);
	myQueue q2;
	q2.Push(2);
	q2.Push(2);

	q1 = q2;

}

int main() {

	//TestDate1();
	//TestDate2();
	TestSatck();
	return 0;
}