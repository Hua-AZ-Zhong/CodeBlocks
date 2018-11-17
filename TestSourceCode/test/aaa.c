/*************************************************************************
> File Name: aaa.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年04月25日 星期六 22时44分36秒
*************************************************************************/

#include <stdio.h>

int main()
{
	int a=3;
	a+=a-=a*a;
	printf("a=%d\n",a);
	char x=0xA7;
	printf("The result is %d\n",(2+x));
	printf("The result is %d\n",(~3));
	printf("The result is %d\n",(2+x)^(~3));
	return 0;
}
