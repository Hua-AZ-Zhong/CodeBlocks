/*
    字符串排序练习
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bi_jiao(const void * p_str, const void * p_str_1) {
    return strcmp(*(char**)p_str,*(char**)p_str_1);
}

int main() {
    char * str[] = {"China",
                    "Russia",
                    "America",
                    "France",
                    "England"};
    int xun_huan = 0;
    qsort(str, 5, sizeof(char*), bi_jiao);
    for (xun_huan = 0; xun_huan <= 4; xun_huan++) {
        printf("%s\n", str[xun_huan]);
    }
    return 0;
}


