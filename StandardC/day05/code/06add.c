/*
    函数的练习
*/
#include <stdio.h>

int jia(int, int);
double jia1(double, double);
/*
int jia();    //不会有问题
double jia1();  //参数描述和实参不匹配，调用会出错
*/

int main() {
    int shu_zi = 0;
    /*shu_zi = jia(2, 3);
    shu_zi = jia(shu_zi, 4);
    printf("%d\n", shu_zi);*/
    //printf("jia1(2.6, 3.1)是%lf\n", jia1(2.6, 3.1));
    printf("jia1(4, 7)是%lf\n", jia1(4, 7));
    return 0;
}

double jia1(double shu_zi, double shu_zi_1) {
    return shu_zi + shu_zi_1;
}

int jia(int shu_zi, int shu_zi_1) {
    return shu_zi + shu_zi_1;
}
