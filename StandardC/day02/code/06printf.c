/*
    转义字符练习
*/
#include <stdio.h>
int main() {
    printf("abc\nxy\n");
    printf("abc\"xy\"\n");
    printf("abc\rxy\n");
    printf("abc\\xy\n");
    printf("15 %% 4是%d\n", 15 % 4);
    return 0;
}
