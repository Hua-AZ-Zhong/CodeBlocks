/*************************************************************************
> File Name: test.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月03日 星期二 16时57分41秒
*************************************************************************/

#include <stdio.h>

int main()
{
	char arr[8]={0x12,0x34,0x56,0x78,0x90,0xAB,0xCD,0xEF};
	char *pp=&arr[0];
	int num=0;
	while(*pp !='\0')
	{   
		printf("%02X",(unsigned char)*pp);
		pp++;
		num++;
	}   
	printf("\n");
	printf("num is [%d]\n",num);
}
