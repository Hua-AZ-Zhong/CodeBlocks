/*
    读取字符串的练习
*/
#include <stdio.h>
int main() {
    char zi_fu_chuan[10];
    printf("请输入字符串：");
    //scanf("%s", zi_fu_chuan);   不安全，有可能溢出造成严重错误
    //gets(zi_fu_chuan);   也可能造成溢出
    fgets(zi_fu_chuan, 10, stdin);  //安全的从键盘读取字符串的方法
    printf("%s\n", zi_fu_chuan);
    return 0;
}


