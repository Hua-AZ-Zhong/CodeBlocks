/*************************************************************************
> File Name: test.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月28日 星期六 11时58分45秒
*************************************************************************/

#include<stdio.h>
main()
{
	int a,b,c,d;
	a=10;
	b=a++;
	c=++a;
	d=10*a++;
	printf("b, c, d: %d %d %d", b, c, d);
	return 0;
}
