#include "Sort.h"


void TestSpeed() {
	int size = 10000;
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	/*int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);
	int* a1 = (int*)malloc(sizeof(int) * size);
	assert(a1);*/

	for (int k = 0; k < size; ++k) {
		a1[k] = rand();
		//...
	}

	int begin1 = 0, end1 = 0;
	begin1 = clock();
	BubbleSort(a1, sizeof(a1) / sizeof(a1[0]));
	end1 = clock();



 	printf("BubbleSort: %d\n", begin1 - end1);

}


int main() {
	TestSpeed();

	return 0;
}
