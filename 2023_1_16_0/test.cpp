#define _CRT_SECURE_NO_WARNINGS 1

//快速排序模板
#include <iostream>
using namespace std;

const int N = 1000000;
int a[N];
/*
选基准值
基于基准值排序
递归
*/
void QuickSort(int a[], int l, int r) {
	if (l >= r) return; 
	int x = a[l], i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (a[i] < x);
		do j--; while (a[j] > x);
		if (i < j) {
			swap(a[i++], a[j--]);
		}
	}
	QuickSort(a, l, j);
	QuickSort(a, j + 1, r);
}
int main() {
	int n;
	scanf("%d", &n);
	//for(int i=0; i<N; i++) scanf("%d", &a[i]);
	srand(time(nullptr));
	for (int i = 0; i < n; i++) a[i] = rand()%100+1;
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	printf("\n");
	QuickSort(a, 0, n - 1);
	for (int i = 0; i < n; i++) printf("%d ", a[i]);
	return 0;
}