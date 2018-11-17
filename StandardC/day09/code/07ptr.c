/*
    void*指针练习
*/
#include <stdio.h>

enum type {CHAR, INT, FLOAT};

void xian_shi(int lei_xing, void *p_shu) {
    switch(lei_xing) {
    case CHAR:
        printf("%c\n", *((char *)p_shu));
        break;
    case INT:
        printf("%d\n", *((int *)p_shu));
        break;
    case FLOAT:
        printf("%g\n", *((float *)p_shu));
        break;
    }
}

int main() {
    char zi_fu = 'a';
    int shu_zi = 7;
    float shu = 3.5f;
    printf("%c\n", 'a');
    xian_shi(CHAR, &zi_fu);
    printf("%g\n", 3.5f);
    xian_shi(FLOAT, &shu);
    printf("%d\n", 7);
    xian_shi(INT, &shu_zi);
    return 0;
}
