/*************************************************************************
> File Name: test1.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月10日 星期二 22时04分52秒
*************************************************************************/

#include <stdio.h>
#include <stdarg.h>
void fun1(int a,int b,...)
{
    va_list lst;

    printf( "fun1\n" );
    va_start(lst,b);

    printf(" the varg is [%d]\n",va_arg(lst,int));
    return;
}
void fun2(int a,int b,...)
{
    va_list lst;

    printf( "fun2\n" );
    va_start(lst,a);

    printf(" the varg is [%d]\n",va_arg(lst,int));
    return;
}

void fun3(int a,int b,...)
{
    va_list lst;

    int xx = 0;
    printf( "fun3\n" );
    va_start(lst,xx);

    printf(" the varg is [%d]\n",va_arg(lst,int));
    return;
}


int main(int argc, char* argv[])
{
    fun1(1,2,3);
    fun2(1,2,3);
    fun3(1,2,3);

    return 0;
}

