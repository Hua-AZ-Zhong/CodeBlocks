/*************************************************************************
> File Name: point.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月31日 星期二 21时12分36秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	char *p="abcdefg";
	printf("size of address is %lu\n", sizeof(p));
	printf("p address is %p\n", p);
	printf("p+1 address is %p\n", p+1);
	printf("*p is %c\n", *p);
	printf("p is %s\n", p);
	struct stu
	{
		char *arr[8];
		int num;
	} ppu;
	printf("size of ppu is %lu\n", sizeof(ppu));
	char *abb[8];
	memset(abb,0x00,8);
	memcpy(abb,"hello",5);
	printf("abb address is %p\n", abb);
	printf("abb+1 address is %p\n", abb+1);
	puts((char*)&*abb);

	return 0;
}
