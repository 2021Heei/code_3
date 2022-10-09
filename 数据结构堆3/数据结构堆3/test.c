#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int HPDataType;
typedef struct Heap {
	HPDataType* a;
	int size;
	int capacity;
}Heap;

void HeapInit(Heap* php);
void HeapDestroy(Heap* php);
void HeapPrint(Heap* php);
void HeapPush(Heap* php, HPDataType val);
void HeapPop(Heap* php);
HPDataType HeapTop(Heap* php);
int HeapEmpty(Heap* php);
int HeapSize(Heap* php);


 void HeapInit(Heap * php) {
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

 void HeapDestroy(Heap * php) {
	assert(php);
	php->a = NULL;
	php->size = php->capacity = 0;
}

 void HeapPrint(Heap * php) {
		assert(php);
		int i;
		for(i=0; i<php->size; ++i){
			printf("%d ", php->a[i]);
		}
		printf("\n");
	}

 void Swap(HPDataType * pdata1, HPDataType * pdata2) {
	HPDataType tmp = *pdata1;
	*pdata1 = *pdata2;
	*pdata2 = tmp;
}

 void AdjustUp(HPDataType * a, int child) {
	int parent = (child-1)/2;
	while(child>0){
		if(a[child] < a[parent]){
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child-1)/2;
		}
		else{
			break;
		}
	}
}

void HeapPush(Heap * php, HPDataType val) {
	assert(php);
	//ÅÐÈÝÁ¿
	if (php->size == php->capacity)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL) {
			perror("malloc file");
			exit(-1);
		}
		php->capacity = newCapacity;
		php->a = tmp;
	}
	php->a[php->size] = val;
	++php->size;
	
	AdjustUp(php->a, php->size-1);
	
}

void AdjustDown(HPDataType * a, int size, int parent) {
	int child = parent*2 + 1;
	while(child < size){
		if(child+1 < size && a[child+1] < a[child]){
			++child;
		}
		if(a[child] < a[parent]){
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1 ;
		}
		else{
			break;
		}
	}
}
							
 void HeapPop(Heap * php) {
	assert(php);
	Swap(&php->a[0], &php->a[php->size-1]);
	--php->size;

	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(Heap* php){
	assert(php);
	assert(!HeapEmpty(php));
	return php->a[0];
}

int HeapEmpty(Heap* php){
	//assert(php);
	return php->size == 0;
}

int HeapSize(Heap* php){
	assert(php);
	return php->size;
}


void test() {
	Heap hp;
	HeapInit(&hp);
	HPDataType b[] = { 10,1,2,3,4,5,6,7,8,9 };
	for (int i = 0; i < sizeof(b) / sizeof(b[0]); ++i) {
		HeapPush(&hp, b[i]);
	}
	HeapPrint(&hp);

	HeapPop(&hp);
	HeapPrint(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	HPDataType ret = HeapTop(&hp);
	printf("%d\n", ret);
	HeapDestroy(&hp);

}

int main() {

	test();
	return 0;
}