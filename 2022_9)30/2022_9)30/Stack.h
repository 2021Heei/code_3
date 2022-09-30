#pragma once
#include <stdlib.h>
namespace Stack {
	typedef int STDataType;
	typedef struct Stack {
		STDataType* val;
		int top;
		int capacity;
	}ST;
	//ȱʡ���������ں��������Ͷ�����ͬʱ����
	void Init(ST* ps, int defaultCapacity = 4);
	void Push(ST* ps, STDataType  val);
}
