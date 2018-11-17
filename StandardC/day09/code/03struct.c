/*
     结构体的对齐和补齐
*/
#include <stdio.h>
typedef struct {  //大小是8个字节
    char zi_fu;
    char zi_fu_1;
    int shu_zi;
} jie_gou;
typedef struct {   //大小是8个字节
    int shu_zi;
    char zi_fu;
    char zi_fu_1;
} jie_gou;
typedef struct {    //大小是12个字节
    char zi_fu;
    int shu_zi;
    char zi_fu_1;
} jie_gou;
int main() {
    printf("sizeof(jie_gou)是%d\n", sizeof(jie_gou));
    return 0;
}

