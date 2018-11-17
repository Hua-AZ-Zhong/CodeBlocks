/*
    在屏幕上打印如下内容
    123456789
    123456879
    123458679
    ....
    182345679
*/
#include <stdio.h>
int main() {
    int shu_zi_1 = 1234567, shu_zi_2 = 9, ji_shu = 10;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    shu_zi_2 = shu_zi_1 % 10 * ji_shu + shu_zi_2;
    shu_zi_1 = shu_zi_1 / 10;
    ji_shu = 10 * ji_shu;
    printf("%d8%d\n", shu_zi_1, shu_zi_2);

    return 0;
}




