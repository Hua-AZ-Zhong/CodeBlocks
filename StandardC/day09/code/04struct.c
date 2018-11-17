/*
    结构体位域练习
*/
#include <stdio.h>
typedef struct {
    char lei:1;
    char ge_shu:4;
    char zhuang_tai:2;
} wei_zhi;
typedef struct {
    char lei;
    char ge_shu;
    char zhuang_tai;
} wei_zhi_1;
int main() {
    wei_zhi wei;
    //printf("地址是%p\n", &(wei.ge_shu));   不可以获得位域的地址
    printf("sizeof(wei_zhi)是%d\n", sizeof(wei_zhi));
    printf("sizeof(wei_zhi_1)是%d\n", sizeof(wei_zhi_1));
    return 0;
}
