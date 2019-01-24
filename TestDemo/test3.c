/*************************************************************************
> File Name: test.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月10日 星期二 14时34分26秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

void TermBanks(char *buf, int length)
{
    int  i, j;
    char mybuf[1024];
    
    memset(mybuf, 0x00, 1024);
    for(i = 0, j = 0; i < length && (buf[i] == ' ' || buf[i] == '	'); i++)
	{
		;
	}
    
    memset(mybuf, 0, 1024);
    strcpy(mybuf, &buf[i]);
    memset(buf, 0x00, length);
    strncpy(buf, mybuf, length);
}

int main()
{
	char buffer[100]="	165001 make-call<22.7.14.62> 7007  auto";
	//char *buffer="          165001 make-call<22.7.14.62> 7007  auto";
	puts(buffer);
	TermBanks(buffer,strlen(buffer));
	puts(buffer);
	return 0;
}
