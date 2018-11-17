/*************************************************************************
> File Name: sprintf.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2016年01月04日 星期一 21时17分53秒
*************************************************************************/

#include <stdio.h>

int main()
{
	int num=1234567;
	char pbuf[100]={0};
	#if 0
	num=num%1000000;
	#endif
	snprintf(pbuf,7,"%06d",num);
	printf("pbuf is [%s]\n",pbuf);
	return 0;
}
