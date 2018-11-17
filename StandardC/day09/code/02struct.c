/*
    结构体练习
*/
#include <stdio.h>

typedef struct {
    float shen_gao;
    int nian_ling;
    char xing_bie;
} ren;

//结构体变量地址作为函数的参数和返回值
//可以提高程序运行效率
ren* du(ren * p_ren) {
    printf("请输入身高，年龄和性别：");
    scanf("%f %d %c", &(p_ren->shen_gao), &(p_ren->nian_ling), &(p_ren->xing_bie));  //通过结构体变量地址表示其中简单变量的语法要使用->
    return p_ren;
}

int main() {
    ren ren1 = {0.0f, 0, 0};
    ren* p_ren = NULL;
    /*printf("请输入身高，年龄和性别：");
    scanf("%f %d %c", &ren1.shen_gao, &ren1.nian_ling, &ren1.xing_bie);*/
    //ren1 = du();
    p_ren = du(&ren1);
    printf("身高是%g, 年龄是%d,性别是%c\n", p_ren->shen_gao, p_ren->nian_ling, p_ren->xing_bie);
    return 0;
}



