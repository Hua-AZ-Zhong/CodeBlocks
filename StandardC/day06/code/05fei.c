/* 
     数列练习
*/
#include <stdio.h>

/*int f(int shu_zi) {
    if (1 >= shu_zi) {
        return 1;
    }
    else {
        return f(shu_zi - 2) + f(shu_zi - 1);
    }
}*/
int shu[100] = {1, 1};
int f(int shu_zi) {
    //int shu[100] = {1, 1};
    if (!shu[shu_zi]) {
        shu[shu_zi] = f(shu_zi - 2) + f(shu_zi - 1);
        return shu[shu_zi];
    }
    else {
        return shu[shu_zi];
    }
}

int main() {
    int shu_zi = 0, shu_zi_1 = 1, shu_zi_2 = 1, xun_huan = 0;
    printf("请输入数字编号：");
    scanf("%d", &shu_zi);
    /*if (shu_zi <= 1) {
        printf("结果是1\n");
    }
    else {
        for (xun_huan = 2; xun_huan <= shu_zi; xun_huan++) {
            int shu = shu_zi_1 + shu_zi_2;
            shu_zi_1 = shu_zi_2;
            shu_zi_2 = shu;
        }
        printf("结果是%d\n", shu_zi_2);
    }*/
    printf("结果是%d\n", f(shu_zi));
    return 0;
}
