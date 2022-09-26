#include "Sort.h"

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintSort(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//冒泡排序
void BubbleSort(int* a, int n) {

	for (int j = 0; j < n; ++j) {
		int flag = 0;
		for (int i = 1; i < n - j; ++i) {
			if (a[i] < a[i - 1]) {
				Swap(&a[i], &a[i - 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

//插入排序
//最坏时间复杂度O(N^2) - 逆序或接近逆序
//最好时间复杂度O(N) - 顺序或接近顺序
void InsertSort(int* a, int n) {
	
	//最后一个插入的元素是数组下标为n-1的元素，该元素前面的有序数组下标为[0,n-2]
	for (int i = 0; i < n-1; ++i) {
		//每次有序数组的范围[0, end];
		int end = i;
		//tmp是将要插入有序数组的元素
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}


//希尔排序
//最坏时间复杂度O(N^(1.3)),略差于O(N*logN) 
//最好时间复杂度O()
void ShellSort(int* a, int n) {
	//把数组元素分为多组，对于每一组中的元素来说都相差一个相等的距离gap
	//即gap是每一组的元素的距离
	//gap越大，大的数据可以越快的跳到后面；小的数据可以越快的调到前面
	//预排结果不是很接近有序
	//gap越小，大的数据与小的数据跳的也越小，越接近有序
	int gap = n;

	//进行多次预排序，每次gap都在变化，直到变为1，就是直接插入排序
	while (gap > 1) {
		//gap = gap / 2;
		gap = gap / 3 + 1;
		//分别对每一组进行插入排序
		//j是每一组的起始下标
		//j=0,是第一组
		//j=1,是第二组
		//......
		for (int j = 0; j < gap; ++j) {
			//[0,end]有序，end+1 排序到-> [0,end+1]有序，每个元素像个gap个元素
			//总共分为gap组，先对每一组进行插入排序
			for (int i = j; i < n - gap; i += gap) {
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0) {
					if (a[end] > tmp) {
						a[end + gap] = a[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}



//向下调整
void AdjustDown(int* a, int size, int parent) {
	assert(a);
	//从父节点(堆顶)开始向下调整
	//假设左孩子是较大的或较小的
	int maxChild = parent * 2 + 1;
	while (maxChild < size) {
		if (maxChild + 1 < size && a[maxChild] < a[maxChild + 1]) {
			maxChild = maxChild + 1;
		}
		//小堆，孩子小于父亲就交换；大堆，孩子大于父亲就交换
		if (a[parent] < a[maxChild]) {
			Swap(&a[parent], &a[maxChild]);
			parent = maxChild;
			maxChild = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int* a, int n) {
	//建堆
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, n, i);
	}

	for (int i = 1; i < n; ++i) {
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n-i, 0);
	}

}