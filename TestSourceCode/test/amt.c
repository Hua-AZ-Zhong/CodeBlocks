/*************************************************************************
> File Name: amt.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2016年04月10日 星期日 15时31分46秒
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *amt="999999999999";
	char *amt_int="2147483648";
	printf("amt in ascii[%s] convert to integer is [%d]\n",amt,atoi(amt));
	printf("amt_int in ascii[%s] convert to integer is [%d]\n",amt_int,atoi(amt_int));
	int i=2147483647;
	printf("i=%d\n",i);
	printf("%s\n",itoa(i,amt,10));
	return 0;
}
