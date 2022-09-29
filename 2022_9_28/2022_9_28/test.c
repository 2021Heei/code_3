#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** ans = (int**)malloc(sizeof(int*) * numRows);
    for (int i = 0; i < numRows; ++i) {
        ans[i] = (int*)malloc(sizeof(int) * (i + 1));
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    for (int i = 0; i < numRows; ++i) {
        (*returnColumnSizes)[i] = i + 1;
        for (int j = 0; j <= i; ++j) {
            if (i == 0 || j == 0 || i == j) {
                ans[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (i != 0 && j != 0 && i != j) {
                ans[i][j] = ans[i - 1][j] + ans[i - 1][j - 1];
            }
        }
    }
    return ans;
}

int main() {
    int n = 0;
    int* p;
    int** arr = generate(5, &n, &p);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}