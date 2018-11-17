/*
    指针数组练习
*/
#include <stdio.h>
#include <stdlib.h>
int bi_jiao(const void* p_shu_zi, const void* p_shu_zi_1) {
    int shu_zi = **(int**)p_shu_zi, shu_zi_1 = **(int**)p_shu_zi_1;
    if (shu_zi > shu_zi_1) {
        return 1;
    }
    else if (shu_zi < shu_zi_1) {
        return -1;
    }
    else {
        return 0;
    }
}

int main(int argc, char* argv[]) {
    int shu_zi[] = {9, 5, -7, -3, 13}, xun_huan = 0;
    int *p_shu_zi[] = {shu_zi, shu_zi + 1, shu_zi + 2, shu_zi + 3, shu_zi + 4};
    qsort(p_shu_zi, 5, sizeof(int*), bi_jiao);
    for (xun_huan = 0; xun_huan <= 4; xun_huan++) {
        printf("%d ", *(p_shu_zi[xun_huan]));
    }
    printf("\n");
    return 0;
}
