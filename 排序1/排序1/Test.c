#include "Sort.h"


void TestSort() {
	int a[] = { 9,1,2,5,7,4,8,6,3,5 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	PrintSort(a, sizeof(a) / sizeof(a[0]));

}

void TestSpeed() {
	srand(time(0));
	int size = 100000;
	int a[] = { 9,8,7,6,5,4,3,2,1,10 };
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a2 = (int*)malloc(sizeof(int) * size);
	assert(a2);
	int* a3 = (int*)malloc(sizeof(int) * size);
	assert(a3);
	int* a4 = (int*)malloc(sizeof(int) * size);
	assert(a4);
	/*int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);*/
	/*int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);*/

	for (int k = 0; k < size; ++k) {
		a1[k] = rand();
		a2[k] = a1[k];
		a3[k] = a1[k];
		a4[k] = a1[k];
		//...
	}

	
	int begin1 = clock();
	//BubbleSort(a1, size);
	//BubbleSort(a, sizeof(a) / sizeof(a[0]));
	int end1 = clock();

	int begin2 = clock();
	//InsertSort(a2, size);
	//InsertSort(a, sizeof(a) / sizeof(a[0]));
	int end2 = clock();

	int begin3 = clock();
	HeapSort(a3, size);
	//HeapSort(a, sizeof(a) / sizeof(a[0]));
	int end3 = clock();
	
	int begin4 = clock();
	ShellSort(a4, size);
	//ShellSort(a, sizeof(a) / sizeof(a[0]));
	int end4 = clock();

	printf("BubbleSort: %d\n", end1 - begin1);
	printf("InsertSort: %d\n", end2 - begin2);
	printf("HeapSort:   %d\n", end3 - begin3);
	printf("shellSort:  %d\n", end4 - begin4);

	free(a1);
	free(a2);
	free(a3);
	free(a4);
}



int main() {
	//TestSpeed();
	TestSort();

	return 0;
}
