/*
    条件分支练习
*/
#include <stdio.h>
int main() {
    int jia_ge = 30, ge_shu = 3;
    printf("请输入电影票的单价和张数：");
    scanf("%d %d", &jia_ge, &ge_shu);
    /*if (ge_shu >= 0) {
        printf("总价格是%d\n", jia_ge * ge_shu);
    }
    if (ge_shu < 0) {
        printf("张数不能为负\n");
    }*/
    /*if (ge_shu >= 0) {
        printf("总价格是%d\n", jia_ge * ge_shu);
    }
    else if (ge_shu < 0) {
        printf("张数不能为负\n");
    }*/
    /*if (ge_shu >= 0) {
        printf("总价格是%d\n", jia_ge * ge_shu);
    }
    else {
        printf("张数不能为负\n");
    }*/
    if (0 == ge_shu) {
        printf("张数不能为0\n");
    }
    else if (ge_shu > 0) {
        if (!jia_ge) {
            printf("价格不能为0\n");
        }
        else if (jia_ge > 0) {
            printf("总价格是%d\n", jia_ge * ge_shu);
        }
        else {
            printf("价格不能小于0\n");
        }
    }
    else {
        printf("张数不能为负\n");
    }
    return 0;
}




