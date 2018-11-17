/*
    变长参数练习
*/
#include <stdio.h>
#include <stdarg.h>

int max(int cnt, ...) {
    int res = 1 << 31, xun_huan = 0;
    va_list v;
    va_start(v, cnt);
    for (xun_huan = 0; xun_huan < cnt; xun_huan++) {
        int value = va_arg(v, int);
        if (value > res) {
            res = value;
        }
    }
    va_end(v);
    return res;
}

void func(int cnt, ...) {
    int xun_huan = 0;
    va_list v;
    va_start(v, cnt);
    for (xun_huan = 0; xun_huan < cnt; xun_huan++) {
        printf("%d ", va_arg(v, int));
    }
    printf("\n");
    va_end(v);
}

int main() {
    func(3, 9, -6, 17);
    func(5, 1, 8, -15, -27, 2);
    printf("最大数是%d\n", max(3, 9, -6, 17));
    printf("最大数是%d\n", max(5, 1, 8, -15, -27, 2));
    return 0;
}
