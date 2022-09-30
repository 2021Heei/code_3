#pragma once
#include <stdlib.h>
namespace Stack {
	typedef int STDataType;
	typedef struct Stack {
		STDataType* val;
		int top;
		int capacity;
	}ST;
	//缺省参数不能在函数声明和定义中同时出现
	void Init(ST* ps, int defaultCapacity = 4);
	void Push(ST* ps, STDataType  val);
}
