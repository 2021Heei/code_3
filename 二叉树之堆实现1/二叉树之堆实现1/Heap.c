#include "Heap.h"

//初始化堆
void HeapInit(Heap* php) {
	//堆的地址不可能为空
	assert(php);
	php->pdata = NULL;
	php->size = php->capacity = 0;
}

//销毁堆
void HeapDestroy(Heap* php) {
	assert(php);
	free(php->pdata);
	php->size = php->capacity = 0;
}

//打印堆数据
void HeapPrint(Heap* php) {
	assert(php);
	for (int i = 0; i < php->size; ++i) {
		printf("%d ", php->pdata[i]);
	}
	printf("\n");
}

//交换两个字符、整数、浮点数
void Swap(HPDataType* a, HPDataType* b){
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//向上调整，child是子节点下标
void AdjustUp(HPDataType* arr, int child) {
	assert(arr);
	
	while (child > 0) {
		int parent = (child - 1) / 2;
		//小堆小于，大堆大于
		if (/*child > 0 && parent >=0 &&*/ arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
		}
		else {
			break;
		}
	}
}

//入数据到堆并保持堆结构
void HeapPush(Heap* php, HPDataType val) {
	assert(php);
	//判断容量，不够扩容
	if (php->size == php->capacity) {
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->pdata, sizeof(HPDataType) * newCapacity);
		if (!tmp) {
			perror("malloc file");
			exit(-1);
		}
		php->capacity = newCapacity;
		php->pdata = tmp;
	}
	php->pdata[php->size] = val;
	++php->size;

	//向上调整
	AdjustUp(php->pdata, php->size - 1);
}

//向下调整
void AdjustDown(HPDataType* a, int size, int parent) {
	assert(a);
	//从父节点(堆顶)开始向下调整
	//假设左孩子是较大的或较小的
	int maxChild = parent * 2 + 1;
	while (maxChild < size) {
		if (maxChild+1 < size && a[maxChild] > a[maxChild +1]) {
			maxChild = maxChild + 1;
		}
		//小堆，孩子小于父亲就交换；大堆，孩子大于父亲就交换
		if (a[parent] > a[maxChild]) {
			Swap(&a[parent], &a[maxChild]);
			parent = maxChild;
			maxChild = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//删除堆顶元素并保持堆结构
void HeapPop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->pdata[0], &php->pdata[php->size - 1]);
	--php->size;
	
	//向下调整
	AdjustDown(php->pdata, php->size, 0);
}

//取到堆顶元素
HPDataType HeapTop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->pdata[0];
}

//判断堆是否为空
bool HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}

//返回堆的大小
int HeapSize(Heap* php) {
	assert(php);
	return php->size;
}