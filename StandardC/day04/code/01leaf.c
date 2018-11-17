/*
    叶子练习
*/
#include <stdio.h>
int main() {
    int ge_shu = 0, xun_huan = 0, zhuang_tai = 0;
    printf("请输入叶子的片数：");
    scanf("%d", &ge_shu);
    for (xun_huan = 0; xun_huan < ge_shu; xun_huan++) {
        if (0 == zhuang_tai) {
            printf("她爱我\n");
            zhuang_tai = 1;
        }
        else if (1 == zhuang_tai) {
            printf("她不爱我\n");
            zhuang_tai = 0;
        }
    }
    return 0;
}
