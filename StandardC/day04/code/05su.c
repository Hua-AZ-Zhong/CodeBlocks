/*
    列举10到100之间的所有素数
*/
#include <stdio.h>
#include <math.h>
int main() {
    int xun_huan = 0, xun_huan_1 = 0, gen = 0;
    for (xun_huan = 10; xun_huan <= 100; xun_huan++) {
        gen = sqrt(xun_huan);
        for (xun_huan_1 = 2; xun_huan_1 <= gen; xun_huan_1++) {
            if (!(xun_huan % xun_huan_1)) {
                break;
            }
        }
        if (xun_huan_1 > gen) {
            printf("%d ", xun_huan);
        }
    }
    printf("\n");
    return 0;
}




