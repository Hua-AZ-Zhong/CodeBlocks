/*
   计算电影票价格练习
*/
#include <stdio.h>
int main() {
    int jia_ge = 30, ge_shu = 3;
    printf("请输入电影票的单价和张数：");
    //scanf("jia_ge = %d, ge_shu = %d", jia_ge, ge_shu);    //严重错误，必须使用变量地址而不能是变量名称
    scanf("jia_ge = %d, ge_shu = %d", &jia_ge, &ge_shu);
    printf("总价格是%d\n", jia_ge * ge_shu);
    return 0;
}



