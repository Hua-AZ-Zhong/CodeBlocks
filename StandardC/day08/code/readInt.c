#include <stdio.h>
#include "readInt.h"
extern int jie_guo;
void readInt() {
    int shu_zi = 0;
    while (!scanf("%d", &shu_zi)) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("请再次输入一个数字：");
    }
    scanf("%*[^\n]");
    scanf("%*c");
    jie_guo = shu_zi;
}
