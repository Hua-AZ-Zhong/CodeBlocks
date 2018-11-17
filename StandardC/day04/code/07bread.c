/*
    面包房的练习
*/
#include <stdio.h>
int main() {
    int xun_huan = 0, xun_huan_1 = 0, shang_xian = 0;
    for (xun_huan = 0; xun_huan <= 10; xun_huan++) {
        shang_xian = (200 - 20 * xun_huan) / 25;
        for (xun_huan_1 = 0; xun_huan_1 <= shang_xian; xun_huan_1++) {
            if (!((200 - 20 * xun_huan - 25 * xun_huan_1) % 30)) {
                printf("20g的面包买%d个，25g的面包买%d个，30g的面包买%d个\n", xun_huan, xun_huan_1, (200 - 20 * xun_huan - 25 * xun_huan_1) / 30);
            }
        }
    }
    return 0;
}
