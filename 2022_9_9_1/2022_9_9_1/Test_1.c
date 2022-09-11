#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define LA 100
#define Lb 100

void  Sort(int* nums1, int nums1Size, int* nums2, int nums2Size);
// ±º‰∏¥‘”∂»O(m+n)
int main() {
	int la[LA] = { 1,3,5,7,9 };
	int lb[Lb] = { 2,4,6,8,10 };

	Sort(la, 5, lb, 5);
	for (int i = 0; i < 10; ++i) {
		printf("%d ", la[i]);
	}
	return 0;
}

void  Sort(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int old1 = nums1Size - 1;
	int old2 = nums2Size - 1;
	int new = nums1Size + nums2Size - 1;
	while (old1 >= 0 && old2 >= 0) {
		if (old1 > old2) {
			nums1[new] = nums1[old1];
			--new;
			--old1;
		}
		else {
			nums1[new] = nums2[old2];
			--new;
			--old2;
		}
	}
	/*if (old1 >= 0) {
		while (old1 >= 0) {
			nums1[new--] = nums1[old1--];
		}
	}*/
	if(old2 >= 0){
		while (old2 >= 0) {
			nums1[new--] = nums2[old2--];
		}
	}
}
