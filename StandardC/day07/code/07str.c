/*
     字符串练习 
*/
#include <stdio.h>
int main() {
    char zi_fu_chuan[] = "abc";
    printf("abcxyz\n");
    printf("%p\n", "xyz");    //字符串用一个地址数据表示
    printf("%p\n", "xyz");   //字面值完全相同的字符串在运行时被合并成同一个 
    printf("%p\n", "xyzab"); //稍有区别的字面值表示的字符串就不会被合并 
    //*"abc" = 'x';   //字面值表示的字符串内容不可以被修改，执行是发生段错误
    zi_fu_chuan[0] = 'x';
    return 0;
}
