/*************************************************************************
> File Name: h3c02.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年03月03日 星期一 11时21分32秒
*************************************************************************/

#include <stdio.h>

int	main()
{
	const char *pc = "abcdefg";
	printf("\r\n %d",	sizeof(pc));
	printf("\r\n %d",	sizeof(*pc));
	printf("\r\n %d",	sizeof("abcd"));
	printf("\r\n %d",	sizeof(pc+3));

	puts("");
	printf("%d\n", sizeof(pc));
	printf("%d\n", *(pc+2));
	printf("%d\n", sizeof("abcd"));
	printf("%c\n", *pc);
	printf("%d\n", sizeof(pc+3));
	puts(pc);

	char *arr[9];
	printf("%d\n", sizeof(arr));
	char arr2[9] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	printf("%d\n", sizeof(arr2));
	puts(arr2);
}
