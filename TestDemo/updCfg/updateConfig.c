/*************************************************************************
> File Name: file.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2016年01月28日 星期四 20时43分08秒
*************************************************************************/

#include <stdio.h>
#include <stdio.h>
#include <string.h>

int updatekey(int keyflag,char *clearkey)
{
	FILE *fp = fopen("cardtype.cfg","r+");
	int found=0;
	int counter=0;
	char cTempString[1024];
	while(found != 1 && counter>=0 && counter<12)
	{
		memset(cTempString,0x00,1024);
		fgets(cTempString,1024,fp);
		#if 0
		printf("%s",cTempString);
		#endif
		if(keyflag==1)
		{
			if(memcmp(cTempString,"PINKEY:[",8)==0)
			{
				printf("PIN KEY FOUNDED\n");
				found=1;
				fseek(fp,-(strlen(cTempString)),SEEK_CUR);
				fprintf(fp,"PINKEY:[%32.32s]",clearkey);
				break;
			}
		}
		else if(keyflag==3)
		{
			if(memcmp(cTempString,"MACKEY:[",8)==0)
			{
				printf("MAC KEY FOUNDED\n");
				found=1;
				fseek(fp,-(strlen(cTempString)),SEEK_CUR);
				fprintf(fp,"MACKEY:[%32.32s]",clearkey);
				break;
			}
		}
		counter++;
	}
	fclose(fp);
}
int main()
{
	#if 0
	FILE *fp = fopen("cardtype.cfg", "a+");
	if (fp==0)
	{
		printf("can't open file\n");
		return 0;
	}
	fseek(fp, 0, SEEK_END);
	char sz_add[] = "hello world\n";
	fwrite(sz_add, strlen(sz_add), 1, fp);
	fclose(fp);
	#endif
	updatekey(1,"PINPINPINPINPINPINPINPINPINPINPI");
	updatekey(3,"MACMACMACMACMACMACMACMACMACMACMA");
	return 0;
}
