#include "Heap.h"

//��ʼ����
void HeapInit(Heap* php) {
	//�ѵĵ�ַ������Ϊ��
	assert(php);
	php->pdata = NULL;
	php->size = php->capacity = 0;
}

//���ٶ�
void HeapDestroy(Heap* php) {
	assert(php);
	free(php->pdata);
	php->size = php->capacity = 0;
}

//��ӡ������
void HeapPrint(Heap* php) {
	assert(php);
	for (int i = 0; i < php->size; ++i) {
		printf("%d ", php->pdata[i]);
	}
	printf("\n");
}

//���������ַ���������������
void Swap(HPDataType* a, HPDataType* b){
	HPDataType tmp = *a;
	*a = *b;
	*b = tmp;
}

//���ϵ�����child���ӽڵ��±�
void AdjustUp(HPDataType* arr, int child) {
	assert(arr);
	
	while (child > 0) {
		int parent = (child - 1) / 2;
		//С��С�ڣ���Ѵ���
		if (/*child > 0 && parent >=0 &&*/ arr[child] > arr[parent]) {
			Swap(&arr[child], &arr[parent]);
			child = parent;
		}
		else {
			break;
		}
	}
}

//�����ݵ��Ѳ����ֶѽṹ
void HeapPush(Heap* php, HPDataType val) {
	assert(php);
	//�ж���������������
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

	//���ϵ���
	AdjustUp(php->pdata, php->size - 1);
}

//���µ���
void AdjustDown(HPDataType* a, int size, int parent) {
	assert(a);
	//�Ӹ��ڵ�(�Ѷ�)��ʼ���µ���
	//���������ǽϴ�Ļ��С��
	int maxChild = parent * 2 + 1;
	while (maxChild < size) {
		if (maxChild+1 < size && a[maxChild] > a[maxChild +1]) {
			maxChild = maxChild + 1;
		}
		//С�ѣ�����С�ڸ��׾ͽ�������ѣ����Ӵ��ڸ��׾ͽ���
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

//ɾ���Ѷ�Ԫ�ز����ֶѽṹ
void HeapPop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	Swap(&php->pdata[0], &php->pdata[php->size - 1]);
	--php->size;
	
	//���µ���
	AdjustDown(php->pdata, php->size, 0);
}

//ȡ���Ѷ�Ԫ��
HPDataType HeapTop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->pdata[0];
}

//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}

//���ضѵĴ�С
int HeapSize(Heap* php) {
	assert(php);
	return php->size;
}