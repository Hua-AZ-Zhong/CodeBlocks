/*
    main函数参数的练习
*/
#include <stdio.h>
int main(int argc, char* argv[]) {
    int xun_huan = 0;
    for (xun_huan = 0; xun_huan <= (argc - 1); xun_huan++) {
        printf("%s\n", argv[xun_huan]);
    }
    return 0;
}
