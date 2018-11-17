/*************************************************************************
> File Name: hex.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月01日 星期日 21时39分32秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

int hexToStr(char *hex, char *ch)
{
	int high,low;
	int tmp = 0;
	if(hex == NULL || ch == NULL)
	{
		return -1;
	}

	if(strlen(hex) %2 == 1)
	{
		return -2;
	}

	while(*hex)
	{
		high = hexCharToValue(*hex);
		if(high < 0)
		{
			*ch = '\0';
			return -3;
		}
		hex++; //指针移动到下一个字符上
		low = hexCharToValue(*hex);
		if(low < 0)
		{
			*ch = '\0';
			return -3;
		}
		tmp = (high << 4) + low;
		*ch++ = (char)tmp;
		hex++;
	}
	*ch = '\0';
	return 0;
}

int hexCharToValue(const char ch)
{
	int result = 0;
	//获取16进制的高字节位数据
	if(ch >= '0' && ch <= '9')
	{
		result = (int)(ch - '0');
	}
	else if(ch >= 'a' && ch <= 'z')
	{
		result = (int)(ch - 'a') + 10;
	}
	else if(ch >= 'A' && ch <= 'Z')
	{
		result = (int)(ch - 'A') + 10;
	}
	else
	{
		result = -1;
	}
	return result;
}

int main()
{
	char arr[16];
	memset(arr,0x00,16);
	printf("Please Input The HEX Strings:");
	scanf("%s",arr);
	//gets(arr);
	printf("The HEX Strings is [%s]\n",arr);
	char buffer[50];
	char *result=buffer;
	hexToStr(arr,result);
	printf("result is %s\n",result);
	return 0;
}
