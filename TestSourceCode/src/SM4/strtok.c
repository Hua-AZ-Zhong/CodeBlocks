/*************************************************************************
> File Name: strtok.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月02日 星期一 22时49分15秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
	#if 0
	char *acct_num="6222023202033026898|3568171120675421"; /** In Ubuntu it Will Core, but it can work at AIX **/
	#endif
	char acct_num[]="6222023202033026898|3568171120675421";
	char *p=NULL;
	p=strtok(acct_num,"|");
	p=strtok(NULL,"|");
	printf("%s\n",p);
	return 0;
}
