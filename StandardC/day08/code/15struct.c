/*
    结构的练习
*/
#include <stdio.h>
int main() {
    struct ren {
        float shen_gao;    //没有声明变量，只是描述了变量shen_gao和结构体之间的关系
        int nian_ling;
        char xing_bie;
    } ren1;  //结构体变量声明
    struct ren ren2 = {1.78, 20, 'F'};  //结构体变量声明及初始化
    printf("身高是%g\n", ren2.shen_gao);
    printf("年龄是%d\n", ren2.nian_ling);
    printf("性别是%c\n", ren2.xing_bie);
    return 0;
}



