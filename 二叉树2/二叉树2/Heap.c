#include "Heap.h"

//�ѳ�ʼ��
void HeapInit(Heap* php) {
	assert(php);
	php->pdata = NULL;
	php->size = php->capacity = 0;
}

//��ӡ�Ѵ�������
void HeapPrint(Heap* php) {
	assert(php);
	for (int i = 0; i < php->size; ++i) {
		printf("%d ", php->pdata[i]);
	}
	printf("\n");
}

//�ѵ�����
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

//���ϵ���
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

//�������ݵ��ѣ�������
void HeapPush(Heap* php, HPDataType val) {
	//����
	assert(php);
	//����
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

	//���ϵ���
	AdjustUp(php->pdata, php->size - 1);
}

//���µ���
void AdjustDown(HPDataType* a, int size, int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		//С��Ҫ�ҽ�С�ĺ��ӱȽ�,���ں��ӽ���
		//���Ҫ�ҽϴ�ĺ��ӱȽϣ�С�ں��ӽ���
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

//ɾ���Ѷ�Ԫ��
void HeapPop(Heap* php) {
	assert(php);
	Swap(&(php->pdata[0]), &(php->pdata[php->size - 1]));
	--php->size;

	//���µ���
	AdjustDown(php->pdata, php->size, 0);
}

//ȡ�Ѷ�Ԫ��
HPDataType HeapTop(Heap* php) {
	assert(php);
	assert(!HeapEmpty(php));
	return php->pdata[0];
}

//�ѵĴ�С
int HeapSize(Heap* php) {
	assert(php);
	return php->size;
}

//�ж϶��Ƿ�Ϊ��
bool HeapEmpty(Heap* php) {
	assert(php);
	return php->size == 0;
}

//������
void HeapSort(int* a, int n) {
//���µ�������
//ʱ�临�Ӷ�O(N*logN)

//1.����,ʱ�临�Ӷ�O(N)
//���򽨴�ѣ�ÿ�δӶѶ�������Ԫ�ط�����󣬸�Ԫ�ز��ٿ���
//����С�ѣ�ÿ�δӶѶ�����С��Ԫ�ط�����󣬸�Ԫ�ز��ٿ���
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, n, i);
	}
	//2.������δ����Ԫ���� ѡ�� �Ѷ�Ԫ�أ�ÿ��ѡ��֮�����½���,ʱ�临�Ӷ�O(N*logN)
	//n��������n-1����ȷ���ˣ�ʣ����һ��Ҳ��ȷ���ˣ����Կ��Դ�1��ʼ
	for (int i = 1; i < n; ++i) {
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}


//TopK����
//��N�������С�������������ģ���С�ģ�ǰK��
void PrintTopK(int* a, int n, int k) {
	//����3.���½�С��һ�Σ�
	//Ȼ��ѭ����Ѷ�Ԫ�رȽϣ�������ڶѶ�Ԫ�أ����滻�Ѷ������µ�����ֱ��ѭ������
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


