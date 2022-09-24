#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapSort(int* a, int n) {
	//向上调整建堆
	//时间复杂度O((N^2)*logN)

	//1.建堆O(N*logN)
	/*for (int i = 1; i < n; ++i) {
		AdjustUp(a, i);
	}*/
	////2. 选择元素再建堆
	//for (int i = 1; i < n; ++i) {
	//	Swap(&a[0], &a[n - i]);
	//	for (int j = 0; j < n-i; ++j) {
	//		AdjustUp(a, j);
	//	}
	//}

	//向下调整建堆
	//时间复杂度O(N*logN)

	//1.建堆,时间复杂度O(N)
	//升序建大堆，每次从堆顶拿最大的元素放在最后，该元素不再考虑
	//降序建小堆，每次从堆顶拿最小的元素放在最后，该元素不再考虑
	for (int i = (n-1-1)/2; i >= 0; --i) {
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
	//方法1.向上建堆，每次Pop堆顶，再次建堆
	/*int* b = (int*)calloc(k, sizeof(int));
	if (b == NULL) {
		perror("malloc file");
		exit(-1);
	}
	for (int i = 0; i < n; ++i) {
		AdjustUp(a, i);
	}

	for (int i = 0; i < k; ++i) {
		b[i] = a[0];
		Swap(&a[0], &a[n - i - 1]);
		for (int j = 0; j < n-i-1; ++j) {
			AdjustUp(a, j);
		}
	}*/

	//方法2.向上建K个元素的小堆，再依次与后K-1个元素比较，
	//如果后K-1个元素满足大于堆顶元素时就交换堆顶元素和该元素，并重新建堆
	for (int i = 0; i < k; ++i) {
		AdjustUp(a, i);
	}
	for (int i = k; i < n; ++i) {
		if (a[0] < a[i]) {
			Swap(&a[0], &a[i]);
			for (int j = 0; j < k; ++j) {
				AdjustUp(a, j);
			}
		}
	}


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

//int main() {
//	int a[] = { 65,37,49,28,34,25,18,27,19,15 };
//	HeapSort(a, sizeof(a) / sizeof(a[0]));
//
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i) {
//		printf("%d ", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

