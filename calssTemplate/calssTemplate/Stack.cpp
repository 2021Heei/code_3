#include "Stack.h"

//对于分离定义来说，类模板的函数定义部分与普通类的函数定义有所差别
//对于类模板，
//在每个函数定义前需要指定类模板
//指定函数类域时需要是实例化后的类的类型，需要额外加上模板参数，即 类名<模板参数列表>

//template<typename T>
//Stack<T>::Stack(int capacity)
//	:_size(0)
//	, _capacity(capacity) {
//	_a = (T*)malloc(sizeof(T) * _capacity);
//	assert(_a);
//}
//template<typename T>
//Stack<T>::~Stack() {
//	delete[] _a;
//	_size = _capacity = 0;
//}
//template<typename T>
//void Stack<T>::Push(const T& val) {
//	if (_size == _capacity) {
//		_capacity = _capacity * 2;
//		T* tmp = (T*)realloc(_a, sizeof(T) * _capacity);
//		assert(tmp);
//		_a = tmp;
//	}
//	_a[_size++] = val;
//}

//类模板显式实例化，不过缺陷是实例化成的是具体的类型了，不适用与其他类型了
//不具有普遍性，这是较大的缺陷
//所以一般类模板不会声明和定义分离在两个文件中，而是共同放在一个文件中
template
class Stack<int>;

//不显式实例化程序将会报链接错误Link error
//原因：分析编译链接过程
//链接错误，说明不是语法问题，而是链接时，Test.o在Stack.o中寻找不到要调用的类模板实例化出来的函数，即类模板没有实例化处具体的函数，Stack.o符号表中也就没有相应函数的地址；
//为什么在类模板没有实例化出具体的函数呢？
//因为类模板函数定义与类模板分离，Test.c和Stack.c的预处理/编译/汇编都是独立进行的，
//Test.c中有类模板的实例化Stack<int>，Stack.c中没有类模板的实例化Stack<int>，类具体函数无法实例化，Stack.o符号表中也就没有类具体函数的地址；而Test.o中虽有实例化Stack<int>,但是头文件展开后，Test.c只有类模板函数的声明，只实例化了类的函数的声明，而函数的声明没有实际有效地址，故Test.o会在链接期间到Stack.o中寻找函数有效地址（类函数实例化后才有），结果是找不到待调用函数有效地址，导致链接错误；
