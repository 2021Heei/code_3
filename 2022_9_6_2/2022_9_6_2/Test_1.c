#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
//	*returnSize = 2;
//	static ret_arr[2] = { 0 };
//	memset(ret_arr, 0x00, sizeof(ret_arr));//��̬�ռ䲻����γ�ʼ��������ֶ���ʼ��
//	for (int i = 0; i < numbersLen; i++) {//�ӵ�0��λ�ÿ�ʼһ��һ��������
//		for (int j = i + 1; j < numbersLen; j++) {//�ӵ�һ������������������ҳ���һ������
//		//��numbers[i]��ӵ���target�������ҵ�����i��j���Ƕ�Ӧ���������±�
//			if (numbers[i] + numbers[j] == target) {
//				ret_arr[0] = i + 1;//��ĿҪ���±��1��ʼ
//				ret_arr[1] = j + 1;
//				return ret_arr;
//			}
//		}
//	}
//}
//
//int main()
//{
//	/*int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 }, * p = a + 5, * q = NULL;
//	*q = *(p + 5);
//	printf("%d %d\n", *p, *q);*/
//
//	char* p[] = { "Shanghai","Beijing","Honkong" };
//	*p[1] + 3; *(p[1] + 3); *(p[3] + 1); p[3][1];
//
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));

    int flag = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] == 0) {
            continue;
        }
        for (int j = 0; j < n; ++j) {
            if (arr[i] == arr[j]) {
                arr[j] = 0;
                flag = 1;
            }
        }
        if (flag) {
            arr[i] = 0;
            flag = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("%d\n", sum);
    return 0;
}