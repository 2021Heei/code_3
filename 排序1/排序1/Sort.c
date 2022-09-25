#include "Sort.h"

void Swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void BubbleSort(int* a, int n) {

	for (int j = 0; j < n; ++j) {
		for (int i = 1; i < n - i; ++i) {
			if (a[i] > a[i - 1]) {
				Swap(&a[i], &a[i - 1]);
			}
		}
	}
}