/*************************************************************************
> File Name: 01attribute.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月21日 星期五 15时13分45秒
*************************************************************************/

#include <stdio.h>

void f1()__attribute__((constructor));
void f2()__attribute__((destructor));
int main()
{
	puts("main function()");
}
void f1()
{
	puts("before main");
}

void f2()
{
	puts("after main");
}
