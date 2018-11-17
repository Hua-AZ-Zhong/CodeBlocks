/*
    输出20到100之间的所有奇数
*/
#include <stdio.h>
int main() {
    int xun_huan = 0;
    for (xun_huan = 20; xun_huan <= 100; xun_huan++) {
        if (xun_huan % 2) {
            printf("%d ", xun_huan);
        }
    }
    printf("\n");
    return 0;
}
