/*
    数字时钟练习
*/
#include <stdio.h>
#include <time.h>
#include <unistd.h>
int main() {
    int xiao_shi = 0, fen_zhong = 0, miao = 0;
    int shi_jian = 0;
    while (1) {
        shi_jian = time(0);
        miao = shi_jian % 60;
        fen_zhong = shi_jian % 3600 / 60;
        xiao_shi = shi_jian % (24 * 3600) / 3600;
        xiao_shi = (xiao_shi + 8) % 24;
        printf("%2d:%2d:%2d\r", xiao_shi, fen_zhong, miao);
        fflush(stdout);
        //while (shi_jian == time(0));
        sleep(1);
    }
    return 0;
}
