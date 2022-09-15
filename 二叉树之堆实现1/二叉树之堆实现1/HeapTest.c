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
	//����,���²�Ҷ�ӱ�����Ƕѣ�����Ҫ�ٽ���ֱ�������һ��Ҷ�ӵĸ��ڵ㿪ʼ
	for (int i = (size - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(arr, size, i);
	}

	//���򣺽���ѣ�ѡ�����
	// ���򣺽�С�ѣ�ѡ�����
	//ÿ�����µ������Ѷ��������ģ����������һ��Ԫ�ؽ������ٴε������������ҳ������Ԫ�أ�
	//ѡ�����µ���
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

//�ҳ�size��ǰk�����Ԫ��
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
	//��ǰk����
	for (int i = 0; i < k; ++i) {
		fscanf(fout, "%d", &minHeap[i]);
	}

	//��С��
	for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(minHeap, k, i);
	}

	//��n-k����
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