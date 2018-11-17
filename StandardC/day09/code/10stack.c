/*
    堆的练习
*/
#include <stdio.h>
#include <stdlib.h>
int main() {
    //int shu_zi[3] = {0}, xun_huan = 0;
    int *shu_zi = NULL, xun_huan = 0;
    shu_zi = (int *)malloc(3 * sizeof(int));  //从堆中分配3个整数变量
    if (!shu_zi) {  //如果分配失败则返回NULL
        printf("内存分配失败\n");
        return 0;
    }
    for (xun_huan = 0; xun_huan < 3; xun_huan++) {
        printf("请输入一个数字：");
        scanf("%d", shu_zi + xun_huan);
    }
    for (xun_huan = 2; xun_huan >= 0; xun_huan--) {
        printf("%d\n", shu_zi[xun_huan]);
    }
    free(shu_zi);    //释放从堆中分配的所有变量
    shu_zi = NULL;   //释放完空间以后要把指针变量
                     //设置成NULL
    return 0;
}
