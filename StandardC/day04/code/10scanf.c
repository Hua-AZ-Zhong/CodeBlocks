/*
    缓冲区练习
*/
#include <stdio.h>
int main() {
    int shu_zi = 0, shu_zi_1 = 0;
    printf("请输入一个数字：");
    while (!scanf("%d", &shu_zi)) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("请再次输入一个数据：");
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("请输入一个数字：");
    while (!scanf("%d", &shu_zi_1)) {
        scanf("%*[^\n]");
        scanf("%*c");
        printf("请再次输入一个数据：");
    }
    scanf("%*[^\n]");
    scanf("%*c");
    printf("shu_zi是%d,shu_zi_1是%d\n", shu_zi, shu_zi_1);
    return 0;
}
