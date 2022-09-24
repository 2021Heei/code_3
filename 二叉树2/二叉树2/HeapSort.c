#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapSort(int* a, int n) {
	//���ϵ�������
	//ʱ�临�Ӷ�O((N^2)*logN)

	//1.����O(N*logN)
	/*for (int i = 1; i < n; ++i) {
		AdjustUp(a, i);
	}*/
	////2. ѡ��Ԫ���ٽ���
	//for (int i = 1; i < n; ++i) {
	//	Swap(&a[0], &a[n - i]);
	//	for (int j = 0; j < n-i; ++j) {
	//		AdjustUp(a, j);
	//	}
	//}

	//���µ�������
	//ʱ�临�Ӷ�O(N*logN)

	//1.����,ʱ�临�Ӷ�O(N)
	//���򽨴�ѣ�ÿ�δӶѶ�������Ԫ�ط�����󣬸�Ԫ�ز��ٿ���
	//����С�ѣ�ÿ�δӶѶ�����С��Ԫ�ط�����󣬸�Ԫ�ز��ٿ���
	for (int i = (n-1-1)/2; i >= 0; --i) {
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
	//����1.���Ͻ��ѣ�ÿ��Pop�Ѷ����ٴν���
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

	//����2.���Ͻ�K��Ԫ�ص�С�ѣ����������K-1��Ԫ�رȽϣ�
	//�����K-1��Ԫ��������ڶѶ�Ԫ��ʱ�ͽ����Ѷ�Ԫ�غ͸�Ԫ�أ������½���
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

