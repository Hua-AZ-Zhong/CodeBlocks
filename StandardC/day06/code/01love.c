/*
    递归练习
*/
#include <stdio.h>

void ai(void) {
    printf("我爱你\n");
}

void ai_1(int ci_shu) {
    printf("我爱你\n");
    if (ci_shu > 1) {
        ai_1(ci_shu - 1);
    }
}

int main() {
    int xun_huan = 0;
    /*for (xun_huan = 0; xun_huan < 5; xun_huan++) {
        ai();
    }*/
    ai_1(5);
    return 0;
}
