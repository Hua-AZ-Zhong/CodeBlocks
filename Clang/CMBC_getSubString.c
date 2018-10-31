#include <stdio.h>
#include <string.h>

/**
 * 民生银行笔试题唯一的一道编程题
 * 要求输出指定的第N(从0开始)个子字符串，字符串以;分隔
 * 函数返回值0-代表成功，-1 - 代表失败
 */
int getSubString(char *src, long num, char *dest)
{
	for(long n=0; n<num; n++)
	{
		while(*src!=';')
			src++;
		src++;
	}

	if(*src=='\0')
		return -1;

	while((*dest=*src)!='\0' && (*dest=*src)!=';')
	{
		dest++;
		src++;
	}
	*dest='\0';
	return 0;
}

int main()
{
	char *src="hello;world;everyone;goodnight";
	char dest[256]={0};
	getSubString(src,2,dest);
	puts(dest);
	return 0;
}
