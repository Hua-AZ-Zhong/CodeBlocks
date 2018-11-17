/*************************************************************************
> File Name: strtok.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: Fri 14 Mar 2014 05:40:37 PM CST
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char src[]="zhonghua,wukun,wangqiang,liuweiteng,xiaochenchen";
	const char *delim = ",";
	char *p;
    char *end;

	p = strtok(src, delim);
    printf("%s \n", p);
    while(end = strtok(NULL, delim)) 
		printf("%s\n",end);
}
