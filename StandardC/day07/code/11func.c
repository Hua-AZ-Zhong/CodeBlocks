/*
    字符串函数练习
*/
#include <stdio.h>
#include <string.h>
int main() {
    char zi_fu_chuan[20] = "abc";
    char zi_fu_chuan_1[] = "xyz";
    printf("长度是%d\n", strlen(zi_fu_chuan));  //计算字符串中有效字符的个数
    printf("合并结果是%s\n", strcat(zi_fu_chuan, zi_fu_chuan_1));  //合并两个字符串，有可能溢出，strncat会避免溢出
    printf("拷贝后的结果是%s\n", strcpy(zi_fu_chuan, zi_fu_chuan_1));  //字符串拷贝，有可能溢出，strncpy会避免溢出
    printf("比较结果是%d\n", strcmp(zi_fu_chuan, "xyc"));   //比较两个字符串的大小，前一个大则返回正数，相等返回0，前一个小则返回负数。也可能溢出，所以可以使用strncmp来比较前几个字符。
    return 0;
}
