#include <stdio.h>

#define VAL_1 1
#define VAL_2 2

int main()
{
    int val = 1;
    switch(val)
    {
        // ————————————————
        // 声明了变量的case分支如果不加大括号，会提示 error: a label can only be part of a statement and a declaration is not a statement
        // 原文链接：https://blog.csdn.net/qq_37600027/article/details/89503824
        // 由于switch的几个case语句在同一个作用域（因为case 语句只是标签，它们共属于一个swtich语句块）
        // 所以如果在某个case下面声明变量的话，对象的作用域是在俩个花括号之间 也就是整个switch语句，其他的case语句也能看到，这样的话就可能导致错误。
        // 我们可以通过在case后面的语句加上大括号处理，之所以加大括号就是为了明确我们声明的变量的作用域，就是仅仅在本case之中，其实为了更规范的写switch-case语句，我们应该在case语句后边加大括号。
        // ————————————————
        case VAL_1:
        { // 本行不可缺少
            // This won't work
            int newVal = 42;
            printf("newVal is [%d] in case VAL_1\n", newVal);
            break;
        } // 本行不可缺少
        case VAL_2:
            break;
        default:
            break;
    }
}
