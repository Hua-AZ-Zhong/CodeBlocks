/*************************************************************************
> File Name: SwtEMU.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月21日 星期五 10时56分33秒
*************************************************************************/

#include <stdio.h>
int main ()
{
    typedef struct {
	    char sfuncname[100];
		char dsp[100];
	} checkfunc;

	checkfunc gaswtcust[10]=
	{
	    { "CreateMchnt",	"获取核心用商户号"},
	    { "GetExprtInfo",	"获取卡有效期" },
	    { "ModifyF060",		"60域值修改" },
	    { "ModifyF122",		"122域值修改" },
	    { "ModCardType",	"手工修改卡类" },
	};
			
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("funcname is %-15s, index = %d, funcdsp = %s\n", gaswtcust[i].sfuncname, i, gaswtcust[i].dsp);
    }
}
