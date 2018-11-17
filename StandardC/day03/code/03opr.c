/*
     三目运算符练习
*/
#include <stdio.h>
int main() {
    char zi_fu = 0;
    printf("请输入一个字符：");
    scanf("%c", &zi_fu);
    zi_fu = ((zi_fu >= 'A') && (zi_fu <= 'Z')) ? zi_fu : zi_fu - 'a' + 'A';
    printf("转换结果是%c\n", zi_fu);
    return 0;
}
