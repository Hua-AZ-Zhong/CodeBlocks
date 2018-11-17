/*
     大小写转换的宏
*/
#include <stdio.h>
#define ZHUAN_HUAN(c) c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c
#define ZHUAN_HUAN1(c) c = (c>= 'a' && c <= 'z' ? c - 'a' + 'A' : c )
int main() {
    char zi_fu = 0;
    printf("请输入一个字符：");
    scanf("%c", &zi_fu);
    printf("转换结果是%c\n", ZHUAN_HUAN(zi_fu));
    ZHUAN_HUAN1(zi_fu);
    printf("转换结果是%c\n", zi_fu);
    return 0;
}
