#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//#include <unistd.h>
#include <windows.h>

#define NUM 101     //����������
#define S_NUM 6     //�������ַ�����
#define N 2         //��������ʾѡ��

extern void ProcessOn();


int main() {
    ProcessOn();
    return 0;
}

//������
void ProcessOn() {
    //����
    int cnt = 0;
    //��������������
    char bar[NUM];
    memset(bar, '\0', sizeof(bar));
    //�������ַ���ʾ����
    char style[S_NUM] = { '-', '#', '>', '*', '-', '/' };
    //��ת���
    const char* lable = "|\\-/";

    while (cnt <= 100) {

        //printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt%4]);
        printf("\033[42;33m [%-100s][%d%%][%c] \033[1m\r", bar, cnt, lable[cnt % 4]);
        fflush(stdout);
        bar[cnt++] = style[N];
        Sleep(50);
        //΢��
        //usleep(50000);
    }

    printf("\033[;m\033[0m\n");
}