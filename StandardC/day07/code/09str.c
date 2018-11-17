/*
     字符指针表示字符串
*/
#include <stdio.h>
int main() {
    char *p_zi_fu_chuan = "abc";
    //char zi_fu_chuan[3] = "abc";    没有'\0'字符的数组不能当字符串使用
    char zi_fu_chuan[] = "xyz";
    printf("%s\n", "abc");
    printf("%s\n", p_zi_fu_chuan);
    p_zi_fu_chuan = zi_fu_chuan;
    printf("%s\n", p_zi_fu_chuan);
    return 0;
}


