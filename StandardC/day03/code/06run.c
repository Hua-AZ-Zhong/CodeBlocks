/*
    计算闰年的练习
*/
#include <stdio.h>
int main() {
    int nian = 0;
    printf("请输入年份数据：");
    scanf("%d", &nian);
    if ( (!(nian % 4) && (nian % 100)) || 
         !(nian % 400)) {
        printf("年份%d是闰年\n", nian);
    }
    else {
        printf("年份%d不是闰年\n", nian);
    }
    return 0;
}




