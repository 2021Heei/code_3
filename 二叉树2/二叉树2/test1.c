#include "Heap.h"
#include <time.h>

void test1() {
	Heap h;
	HeapInit(&h);
	HPDataType b[] = { 18,19,25,28,34,65,49,27,37,15 };
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
		HeapPush(&h, b[i]);
	}
	HeapPrint(&h);

	HeapPop(&h);

	HeapDestroy(&h);
}

void CreatNum(const char* file, int n) {
	FILE* fout = fopen(file, "w");
	if (fout == NULL) {
		perror("fopen false");
		exit(-1);
	}
	srand(time(NULL));
	for (int i = 0; i < n; ++i) {
		fprintf(fout, "%d\n", rand() % 1000000);
	}

	fclose(fout);
	fout = NULL;
}
void TopKTest(const char* file, int k) {
	FILE* fin = fopen(file, "r");
	if (fin == NULL) {
		perror("fopen false");
		exit(-1);
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL) {
		perror("malloc false");
		exit(-1);
	}
	//从文件读取k个数
	for (int i = 0; i < k; ++i) {
		fscanf(fin, "%d", &minHeap[i]);
	}
	//建立k个数的小堆
	for (int i = (k - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(minHeap, k, i);
	}
	//与剩下的数比较
	int tmp;
	for (int i = 0; fscanf(fin, "%d", &tmp) != EOF; ++i) {
		if (tmp > minHeap[0]) {
			Swap(&minHeap[0], &tmp);
			AdjustDown(minHeap, k, 0);
		}
	}
	for (int i = 0; i < k; ++i) {
		printf("%d ", minHeap[i]);
	}
	printf("\n");

	free(minHeap);
	minHeap = NULL;
	fclose(fin);
}

int main() {
	//test1();
	//test2();
	const char* file = "text.txt";
	//CreatNum(file, 10000);
	TopKTest(file, 4);
	return 0;
}
