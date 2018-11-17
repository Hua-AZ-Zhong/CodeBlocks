/*************************************************************************
> File Name: stristr.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月30日 星期一 22时47分25秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

char *stristr(const char *str1, const char *str2)
{
	int i=strlen(str1);
	int j=strlen(str2);
	int k=0;
	for(k=0; k<=(i-j); k++)
	{
		if(memcmp(str1+k, str2, j))
			;
		else
			return (char*)(str1+k);
	}
	return NULL;
}

int main()
{
	char *p="hello word";
    char *q="ello";
    printf("The first character is %1.1s\n",stristr(p,q));
	return 0;
}
