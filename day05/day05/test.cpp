#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//
//int main() {
//	int W = 2, H = 3;
//	//cin >> W >> H;
//	char arr[2][3];
//	//���迪ʼ���ŵ��⣬��0�ַ���ʾ
////     memset(arr, 0, sizeof(arr));
//	for (int i = 0; i < H; ++i) {
//		for (int j = 0; j < W; ++j) {
//			arr[i][j] = '0';
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	//�����ҳ�ÿ��������Ч���鷶Χ������==2�ĵ㣬�����ظ��жϵĵ���б�ǣ���ֹ���ͳ��ͬһλ��
//	int count = W * H;
//	for (int i = 0; i < H; i++) {
//		for (int j = 0; j < W; ++j) {
//			if (arr[i][j] == '0') {
//				if (i - 2 >= 0 && arr[i - 2][j] == '0') {
//					arr[i - 2][j] = '#';
//					count--;
//				}
//				if (i + 2 < H && arr[i + 2][j] == '0') {
//					arr[i + 2][j] = '#';
//					count--;
//				}
//				if (j - 2 >= 0 && arr[i][j - 2] == '0') {
//					arr[i][j - 2] = '#';
//					count--;
//				}
//				if (j + 2 < W && arr[i][j + 2] == '0') {
//					arr[i][j + 2] = '#';
//					count--;
//				}
//			}
//		}
//	}
//	cout << count << endl;
//
//	return 0;
//}

#include <stdio.h>

int main() {
	char ch = 0;
	
	ch = getchar();
	if (ch >= 'a' && ch <= 'z') {
		goto exit;
	}
	ch = ch - 32;

exit: printf("%c\n", ch);

	return 0;
}