/*
    数字交换练习
*/
#include <stdio.h>

/*void jiao_huan(int shu_zi_1, int shu_zi_2) {
    int shu = shu_zi_1;
    shu_zi_1 = shu_zi_2; 
    shu_zi_2 = shu;
}*/

void jiao_huan(int *p_shu_zi) {
    int shu = p_shu_zi[0];
    p_shu_zi[0] = p_shu_zi[1];
    p_shu_zi[1] = shu;
}

void jiao_huan_1(int *p_shu_zi, int *p_shu_zi_1) {
    int shu = *p_shu_zi;
    *p_shu_zi = *p_shu_zi_1;
    *p_shu_zi_1 = shu;
}

int main() {
    /*int shu_zi_1 = 3, shu_zi_2 = 7;
    jiao_huan(shu_zi_1, shu_zi_2);
    printf("shu_zi_1是%d, shu_zi_2是%d\n", shu_zi_1, shu_zi_2);*/
    /*int shu_zi[2] = {3, 7};
    jiao_huan(shu_zi);
    printf("shu_zi[0]是%d,shu_zi[1]是%d\n", shu_zi[0], shu_zi[1]);*/
    int shu_zi_1 = 3, shu_zi_2 = 7;
    jiao_huan_1(&shu_zi_1, &shu_zi_2);
    printf("shu_zi_1是%d, shu_zi_2是%d\n", shu_zi_1, shu_zi_2);
    return 0;
}



