#include "Heap.h"

//堆初始化
void HeapInit(Heap* php) {
	assert(php);
	php->pdata = NULL;
	php->size = php->capacity = 0;
}

//打印堆储存数据
void HeapPrint(Heap* php) {
	assert(php);
	for (int i = 0; i < php->size; ++i) {
		printf("%d ", php->pdata[i]);
	}
	printf("\n");
}

//堆的销毁
void HeapDestroy(Heap* php) {
	assert(php);
	php->pdata = NULL;
	php->size = php->capacity = 0;
}

void Swap(HPDataType* pa, HPDataType* pb) {
	HPDataType tmp = *pa;
	*pa = *pb;
	*pb = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child) {
	int parent = (child - 1) / 2;
	while (child > 0) {
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}

//输入数据到堆，并建堆
void HeapPush(Heap* php, HPDataType val) {
	//建堆
	assert(php);
	//判满
	if (php->size == php->capacity) {
		HPDataType newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->pdata, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL) {
			perror("realloc file");
			exit(-1);
		}
		php->pdata = tmp;
		php->capacity = newCapacity;
	}
	php->pdata[php->size] = val;
	++php->size;

	//向上调整
	AdjustUp(php->pdata, php->size - 1);
}

//向下调整
void AdjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		//小堆要找较小的孩子比较,大于孩子交换
		//大堆要找较大的孩子比较，小于孩子交换
		if (child+1 < size && a[child] > a[child+1]) {
			child++;
		}
		if (a[child] < a[parent]) {
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

//删除堆顶元素
void HeapPop(Heap* php) {
	assert(php);
	Swap(&(php->pdata[0]), &(php->pdata[php->size - 1]));
	--php->size;

	//向下调整
	AdjustDown(php->pdata, php->size, 0);
}

//取堆顶元素
HPDataType HeapTop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->pdata[0];
}

//堆的大小
int HeapSize(Heap* php) {
	assert(php);
	return php->size;
}

//判断堆是否为空
bool HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}

//堆排序
void HeapSort(int* a, int n) {
//向下调整建堆
//时间复杂度O(N*logN)

//1.建堆,时间复杂度O(N)
//升序建大堆，每次从堆顶拿最大的元素放在最后，该元素不再考虑
//降序建小堆，每次从堆顶拿最小的元素放在最后，该元素不再考虑
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, n, i);
	}
	//2.在数组未排序元素中 选择 堆顶元素，每次选择之后重新建堆,时间复杂度O(N*logN)
	//n个数排序，n-1个数确定了，剩下那一个也就确定了，所以可以从1开始
	for (int i = 1; i < n; ++i) {
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}


//TopK问题
//在N个最大（最小）的里面找最大的（最小的）前K个
void PrintTopK(int* a, int n, int k) {
	//方法3.向下建小堆一次，
	//然后循环与堆顶元素比较，如果大于堆顶元素，就替换堆顶再向下调整，直到循环结束
	for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, k, i);
	}

	for (int i = k; i < n; ++i) {
		if (a[i] > a[0]) {
			Swap(&a[i], &a[0]);
			AdjustDown(a, k, 0);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", a[i]);
	}
}


