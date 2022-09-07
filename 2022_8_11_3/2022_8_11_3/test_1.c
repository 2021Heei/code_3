
#include <stdio.h>

int Add(int x, int y){
	int ret = x + y;
	return ret;
}

int main(){
	int a = 10;
	int b = 20;
	int sum = 0;
	sum = Add(a, b);

	printf("%d\n", sum);
	return 0;
}