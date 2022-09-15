#include "Heap.h"

void Test1() {
	Heap h;
	HeapInit(&h);
	//int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		HeapPush(&h, arr[i]);
	}
	HeapPrint(&h);


	HeapPop(&h);
	HeapPrint(&h);
	

	HeapDestroy(&h);
}

void HeapSort(int* arr, int size) {
	//建堆,最下层叶子本身就是堆，不需要再建，直接找最后一个叶子的父节点开始
	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(arr, size, i);
	}

	//升序：建大堆，选择调整
	// 降序：建小堆，选择调整
	//每次向下调整，堆顶就是最大的，将其与最后一个元素交换，再次调整（不包括找出的最大元素）
	//选再向下调整
	for (int i = 0; i < size; ++i ) {
		Swap(&arr[0], &arr[size - 1 - i]);
		AdjustDown(arr, size - 1 - i, 0);
	}
}

void Test2() {
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int size = sizeof(arr) / sizeof(arr[0]); 
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	HeapSort(arr, size);
	for (int i = 0; i < size; ++i) {
		printf("%d ", arr[i]);
	}
}

//找出size中前k个最大元素
void HeapTopk() {
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL) {
		perror("fopen");
		exit(-1);
	}

	int k = 3;
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL) {
		perror("malloc file");
		exit(-1);
	}
	//读前k个数
	for (int i = 0; i < k; ++i) {
		fscanf(fout, "%d", &minHeap[i]);
	}

	//建小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(minHeap, k, i);
	}

	//后n-k个数
	int tmp = 0;
	while (fscanf(fout, "%d", &tmp) != EOF) {
		if (tmp > minHeap[0]) {
			minHeap[0] = tmp;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i) {
		printf("%d ", minHeap[i]);
	}
	fclose(fout);
}
int main() {
	//Test1();
	//Test2();
	HeapTopk();

	return 0;
}