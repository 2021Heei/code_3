#pragma once
#include <iostream>
using namespace std;

inline int Add(int a, int b);
//int Add(int a, int b);
//只要加了inline 修饰 函数名(修饰名) 就不会进入符号表，如果需要链接查找，那么就会找不到而报错
//至于调用时函数展开不展开主要与调用的地方和编译器有关
//对于声明和定义分离的函数，只要加了inline，不管函数体是小还是大，在调用时都会报链接错误
