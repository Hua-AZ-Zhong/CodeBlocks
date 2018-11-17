/*
   结构体练习
*/
#include <stdio.h>
struct sren {   //结构体声明，可用于声明变量
    float shen_gao;
    int nian_ling;
    char xing_bie;
} ren5;
typedef struct sren sren;   //给数据类型起别名
typedef struct /*ssren*/{   //结构体的声明和起别名
    float shen_gao;         //合并成一条语句
    int nian_ling;
    char xing_bie;
} ssren;
//#define sren struct sren  //对其他数据类型会有问题
#define PINT   int*
int main() {
    struct ren {    //结构体声明
        float shen_gao;
        int nian_ling;
        char xing_bie;
    } ren1;   //使用结构体作为数据类型声明变量
    struct ren ren2 = {1.78, 20, 'F'};  //使用结构体作为数据类型声明变量并初始化
    sren ren3 = {1.60, 40, 'M'};
    ssren ren4 = {1.00, 13, 'F'};
    //PINT p_shu_zi = NULL, p_shu_zi_1 = NULL;  //后一个变量是整数变量不是指针变量，原因就是PINT是采用红定义的方式起的别名
    printf("身高是%g\n", ren2.shen_gao);  //通过结构体变量名称获得其中的各个简单变量
    printf("年龄是%d\n", ren2.nian_ling);
    printf("性别是%c\n", ren2.xing_bie);
    return 0;
}



