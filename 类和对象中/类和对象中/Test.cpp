#include "Date.h"

void TestDate1() {
	Date d1(2022,10,11);
	//Date d2();//�뺯�����������˻���
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
	//Date d2(d1);	//�������죬һ��������ʼ����һ������Ҫ�����Ķ���
	//Date d3 = d1;	//��������
	//Date d4;
	//d4 = d1;		//��ֵ���ء����ƿ������Ѵ��ڵ���������֮��Ŀ���
	//d1.Print();
	//d2.Print();
	//d3.Print();
	//d4.Print();
	//��ֵ��������أ�
	//Ϊʲô�����÷��أ� - ����һ�ο���
	//Ϊʲô�����ó����ã� - ����һ�ο�������ʹ�÷���
	//Ϊʲô����*this��������d�� 
	//		- this�ǵ�һ���������൱�ڸ�ֵʱ����ֵ��d�ǵڶ����������൱�ڸ�ֵʱ����ֵ��
	//		������ֵʱһ����ʽ�ķ���ֵ����ߵı�����
	//Ϊʲô����ָ�����ڶ��������� - ʹ���鷳

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

	//st1 = st2;//Ĭ�ϸ�ֵ��������غ������ܹ����ջ�ĸ�ֵ������Ҫ�����ֶ�д
	st1 = st2;//����Ϊʲô����realloc()��������free����malloc()???
	//��Ϊ���������������ջ��������
	//st1С��st2
	//st1��st2�����൱
	//st1����st2

	//Stack st3;
	////st3.Push(1);
	//st3.Push(2);

	//st3 = st3;//��ֹ�Լ����Լ���ֵ�������жϼ���

	////myQueue��Date��operator= �������󣬲���Ҫ���ֶ�д��
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

	//	ǰ�úͺ��ú�������������غͺ������أ�
	//	���ö���һ��int������Ŀ������ǰ�����֣��ɱ��������ݣ����ɺ�������
	//	�����������ͣ�ǰ������û���û�в��
	//	�����Զ������ͣ�ǰ�ñȺ����������ο������캯���ĵ��ã����Ծ���ʹ��ǰ��++/--
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
	//d1 >> cin;//�����������>> ���Ҳ���������

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