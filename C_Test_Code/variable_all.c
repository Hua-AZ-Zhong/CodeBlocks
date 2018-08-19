#include <stdio.h>

/** 典型的同名变量作用范围讲解 **/
int a=4;

int f(int n)
{
    printf("enter func a is %d\n", a);  /** 此时a=4 **/
    int t=0;
    int num=0;
    static int a=5;  /** 覆盖全局变量a，执行后a=5，仅初始化一次，后面延续上一次的值 **/
    printf("after static a is %d\n",a);
    if(n%2)
    {
        int a=6;  /** 覆盖静态局部变量，a=6，作用范围仅在最近的大括号之内 **/
        printf("after int a=6, a is %d\n", a);
        t+=a++;
    }
    else
    {
        int a=7;  /** 覆盖静态局部变量，a=7，作用范围仅在最近的大括号之内 **/
        printf("after int a=7, a is %d\n", a);
        t+=a++;
    }
    num = t+a++;  /** 此a为静态局部变量的作用范围 **/
    printf("num is %d, n is %d, t is %d, a is %d\n",num,n,t, a);
    return num;
}

int main()
{
    int s=a,i=0;  /** 此a为全局变量的作用范围 **/
    printf("%d\n",s);
    for(;i<2;i++)
        s+=f(i);
    printf("%d\n",s);
    return 0;
}
