//#include "class.h"
//template class A<int>;
//
//template<typename T>
//A<T>::A(T a)
//	:_a(a) {}
//
//template<typename T>
//A<T>::A(A& a) {
//	_a = a._a;
//}
//
////说模板实参列表要与形参列表匹配
//template<typename T>
//A<T>& A<T>::operator=(const A<T>& a) {
//	_a = a._a;
//	return *this;
//}
//
//template<typename T>
//A<T>::~A() {
//	_a = 0;
//}
//
//template<typename T>
//void A<T>::Print() {
//	cout << _a << endl;
//}
