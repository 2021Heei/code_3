#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int f(int n)
{
	int i, sum = 0;
	for (i = 1; i < n + 1; i++)
	{
		for (int j = n; j > i - 1; j--)
			for (int k = 1; k < j + 1; k++)
				sum++;
		printf("sum=%d\n", sum);
	}
	return (sum);
}

int main() {

	f(5);
	return 0;
}