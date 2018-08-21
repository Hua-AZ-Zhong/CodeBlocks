#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/** 产生随机数的小程序 **/
int main()
{
    srand((unsigned)time(NULL));  /** 调用srand()函数设置随机数种子，种子加入时间 **/
    int STAN=rand()%1000000;      /** 调用rand()函数产生一个随机数，除以100万取模，得到六位随机流水号 **/
    printf("STAN is [%06d]\n", STAN);

    int loop_num=0;
    while(STAN!=999999)
    {
        STAN=rand()%1000000;
        loop_num++;
        printf("STAN is <%06d>\n", STAN);
    }
    printf("final loop_num is %d\n", loop_num);
    return 0;
}
