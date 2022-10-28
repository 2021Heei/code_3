#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
//#include <unistd.h>
#include <windows.h>

#define NUM 101     //进度条长度
#define S_NUM 6     //进度条字符数组
#define N 2         //进度条表示选项

extern void ProcessOn();


int main() {
    ProcessOn();
    return 0;
}

//进度条
void ProcessOn() {
    //进度
    int cnt = 0;
    //进度条长度数组
    char bar[NUM];
    memset(bar, '\0', sizeof(bar));
    //进度条字符表示多种
    char style[S_NUM] = { '-', '#', '>', '*', '-', '/' };
    //旋转光标
    const char* lable = "|\\-/";

    while (cnt <= 100) {

        //printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt%4]);
        printf("\033[42;33m [%-100s][%d%%][%c] \033[1m\r", bar, cnt, lable[cnt % 4]);
        fflush(stdout);
        bar[cnt++] = style[N];
        Sleep(50);
        //微秒
        //usleep(50000);
    }

    printf("\033[;m\033[0m\n");
}