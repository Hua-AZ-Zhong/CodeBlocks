/*************************************************************************
> File Name: stringnode.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年04月01日 星期三 23时22分59秒
*************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char arr[]="abc def ghi jkl mno pqr stu vwx yz";
	puts(arr);
	char *p3;
	p3=strtok(arr," ");
	while(p3)
	{
		printf("%s ",p3);
		p3=strtok(NULL," ");
	}
	puts("");
	int n=0;
	int m=sizeof(arr);
	printf("string length is [%d]\n", m-1);
	char *psrc=arr;
	while(m)
	{
		if(*psrc++ == ' ' && *psrc != '\0')
			n++;
		printf("This condition have been activated!\n");
		m--;
	}
	printf("The number of spaces is [%d]\n", n);

	struct NODE
	{
		char *data;
		struct NODE *next;
	};

	struct NODE *head, *p1, *p2;
	int LEN=sizeof(struct NODE);
	printf("LEN is [%d]\n", LEN);
		#if 0
		p2=(struct NODE*) malloc(LEN);
		head = p1 = p2;
		#endif
	return 0;
}
