#include "process.h"

////进度条
//void ProcessOn(){
//    //进度
//    int cnt = 0;
//    //进度条长度数组
//    char bar[NUM];
//    memset(bar, '\0', sizeof(bar));
//    //进度条字符表示多种
//    char style[S_NUM] = {'-', '#', '>', '*', '-', '/'};
//    //旋转光标
//    const char *lable = "|\\-/";
//
//    while(cnt<=100){
//
//        //printf("[%-100s][%d%%][%c]\r", bar, cnt, lable[cnt%4]);
//        printf("\033[42;33m [%-100s][%d%%][%c] \033[1m\r", bar, cnt, lable[cnt%4]);
//        fflush(stdout);
//        bar[cnt++] = style[N];
//        //sleep(1);
//        //微秒
//        usleep(50000);
//    }
//
//    printf("\033[;m\033[0m\n");
//}
