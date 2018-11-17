/*************************************************************************
> File Name: memcmp.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: Mon 24 Mar 2014 09:50:46 AM CST
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	char string[9] = "********";
	memset(string, 0x00, 9);
	if(string[0] == 0x00)
		puts("首字符为空值（空值：不是空格）");
	return 0;
}
