#include "Sort.h"

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PrintSort(int* a, int n) {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

//ð������
void BubbleSort(int* a, int n) {

	for (int j = 0; j < n; ++j) {
		int flag = 0;
		for (int i = 1; i < n - j; ++i) {
			if (a[i] < a[i - 1]) {
				Swap(&a[i], &a[i - 1]);
				flag = 1;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

//��������
//�ʱ�临�Ӷ�O(N^2) - �����ӽ�����
//���ʱ�临�Ӷ�O(N) - ˳���ӽ�˳��
void InsertSort(int* a, int n) {
	
	//���һ�������Ԫ���������±�Ϊn-1��Ԫ�أ���Ԫ��ǰ������������±�Ϊ[0,n-2]
	for (int i = 0; i < n-1; ++i) {
		//ÿ����������ķ�Χ[0, end];
		int end = i;
		//tmp�ǽ�Ҫ�������������Ԫ��
		int tmp = a[end + 1];
		while (end >= 0) {
			if (a[end] > tmp) {
				a[end + 1] = a[end];
				--end;
			}
			else {
				break;
			}
		}
		a[end + 1] = tmp;
	}
}


//ϣ������
//�ʱ�临�Ӷ�O(N^(1.3)),�Բ���O(N*logN) 
//���ʱ�临�Ӷ�O()
void ShellSort(int* a, int n) {
	//������Ԫ�ط�Ϊ���飬����ÿһ���е�Ԫ����˵�����һ����ȵľ���gap
	//��gap��ÿһ���Ԫ�صľ���
	//gapԽ�󣬴�����ݿ���Խ����������棻С�����ݿ���Խ��ĵ���ǰ��
	//Ԥ�Ž�����Ǻܽӽ�����
	//gapԽС�����������С����������ҲԽС��Խ�ӽ�����
	int gap = n;

	//���ж��Ԥ����ÿ��gap���ڱ仯��ֱ����Ϊ1������ֱ�Ӳ�������
	while (gap > 1) {
		//gap = gap / 2;
		gap = gap / 3 + 1;
		//�ֱ��ÿһ����в�������
		//j��ÿһ�����ʼ�±�
		//j=0,�ǵ�һ��
		//j=1,�ǵڶ���
		//......
		for (int j = 0; j < gap; ++j) {
			//[0,end]����end+1 ����-> [0,end+1]����ÿ��Ԫ�����gap��Ԫ��
			//�ܹ���Ϊgap�飬�ȶ�ÿһ����в�������
			for (int i = j; i < n - gap; i += gap) {
				int end = i;
				int tmp = a[end + gap];
				while (end >= 0) {
					if (a[end] > tmp) {
						a[end + gap] = a[end];
						end -= gap;
					}
					else {
						break;
					}
				}
				a[end + gap] = tmp;
			}
		}
	}
}



//���µ���
void AdjustDown(int* a, int size, int parent) {
	assert(a);
	//�Ӹ��ڵ�(�Ѷ�)��ʼ���µ���
	//���������ǽϴ�Ļ��С��
	int maxChild = parent * 2 + 1;
	while (maxChild < size) {
		if (maxChild + 1 < size && a[maxChild] < a[maxChild + 1]) {
			maxChild = maxChild + 1;
		}
		//С�ѣ�����С�ڸ��׾ͽ�������ѣ����Ӵ��ڸ��׾ͽ���
		if (a[parent] < a[maxChild]) {
			Swap(&a[parent], &a[maxChild]);
			parent = maxChild;
			maxChild = parent * 2 + 1;
		}
		else {
			break;
		}
	}
}

void HeapSort(int* a, int n) {
	//����
	for (int i = (n - 1 - 1) / 2; i >= 0; --i) {
		AdjustDown(a, n, i);
	}

	for (int i = 1; i < n; ++i) {
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n-i, 0);
	}

}