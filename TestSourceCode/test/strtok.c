/*************************************************************************
> File Name: strtok.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年04月02日 星期四 23时20分41秒
*************************************************************************/

#include <string.h> 
#include <stdio.h> 

int main(void) 
{ 
	char input[16] = "abc,d"; 
	char *p; 

	/* strtok places a NULL terminator 
	in front of the token, if found */ 
	p = strtok(input, ","); 
	if (p)
		printf("%s ", p); 

	/* A second call to strtok using a NULL 
	as the first parameter returns a pointer 
	to the character following the token  */ 
	p = strtok(NULL, ","); 
	if (p)
		printf("%s ", p); 

	puts("");
	return 0; 
}
