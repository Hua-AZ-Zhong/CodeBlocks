/*************************************************************************
> File Name: bbb.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2018年08月01日 星期三 21时53分27秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	int a[2]={0},i,j,k=2;
	for(i=0;i<k;i++)
	{
		for(j=0;j<k;j++)
		{
			a[j]=a[i]+1;
			printf("i=%d,j=%d,a[0]=%d,a[1]=%d\n",i,j,a[0],a[1]);
		}
	}
	printf("i=%d,j=%d,a[0]=%d,a[1]=%d\n",i,j,a[0],a[1]);

	char arr[6];
	memset(arr,0x30,6);
	i=0;
	for(i=0;i<6;i++)
		a[i]=getchar();
	for(i=0;i<6;i++)
		//putchar(a[i]);
		printf("%X\n",a[i]);
}
