/*
    字符数组表示字符串的练习
*/
#include <stdio.h>
int main() {
    //char zi_fu_chuan[] = "abc", xun_huan = 0;
    char zi_fu_chuan[] = {'a', 'b', 'c', '\0'}, xun_huan = 0;
    printf("sizeof(zi_fu_chuan)是%d\n", sizeof(zi_fu_chuan));
    for (xun_huan = 0; xun_huan <= 3; xun_huan++) {
        printf("%d ", zi_fu_chuan[xun_huan]);
    }    
    printf("\n");
    return 0;
}
