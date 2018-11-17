/*
    字符类型练习
*/
#include <stdio.h>
int main() {
    char zi_fu = -1;
    unsigned char u_zi_fu = zi_fu;
    printf("%d %c\n", 'a', 'a');
    printf("%d %d\n", zi_fu, u_zi_fu);  //结果不同
    printf("sizeof(char)是%d,sizeof(zi_fu)是%d\n", sizeof(char), sizeof(zi_fu));
    printf("sizeof(zi_fu = 5)是%d\n", sizeof(zi_fu = 5));
    printf("zi_fu是%d\n", zi_fu);
    return 0;
}
