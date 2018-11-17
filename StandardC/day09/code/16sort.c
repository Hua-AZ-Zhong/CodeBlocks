/*
     用函数指针进行排序
*/
#include <stdio.h>
#include <stdlib.h>
int bi_jiao_1(const void * p_shu_zi_1, const void * p_shu_zi_2) {
    return 0 - bi_jiao(p_shu_zi_1, p_shu_zi_2);
}

int bi_jiao(const void* p_shu_zi_1, const void* p_shu_zi_2) {
    if (*(int *)p_shu_zi_1 > *(int *)p_shu_zi_2) {
        return 1;
    }
    else if (*(int *)p_shu_zi_1 < *(int *)p_shu_zi_2) {
        return -1;
    }
    else {
        return 0;
    }
}

void pai_xu(int shu_zi[], int ge_shu, int (*p_func)(const void *, const void*)) {
    if (1 == p_func(&shu_zi[0] ,&shu_zi[1])) {
        int shu = shu_zi[0];
        shu_zi[0] = shu_zi[1];
        shu_zi[1] = shu;
    }
}

int main() {
    int shu_zi[2] = {7, 2};
    //pai_xu(shu_zi, 2, bi_jiao);
    qsort(shu_zi, 2, sizeof(int), bi_jiao);
    printf("排序结果为%d和%d\n", shu_zi[0], shu_zi[1]);
    //pai_xu(shu_zi, 2, bi_jiao_1);
    qsort(shu_zi, 2, sizeof(int), bi_jiao_1);
    printf("排序结果为%d和%d\n", shu_zi[0], shu_zi[1]);
    return 0;
}
