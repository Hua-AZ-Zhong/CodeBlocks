/*************************************************************************
> File Name: ASC_convert.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月03日 星期二 00时00分33秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

void ChangeASCIItoBIN(char *Out, char *In, int iLength) /** by ctf **/
{
    int i;

    for (i=0;i<iLength;i++)
    {
        if (In[i]>='0' && In[i]<='9') Out[i] =In[i]-'0';
        if (In[i]>='a' && In[i]<='f') Out[i] =In[i]-'a'+10;
        if (In[i]>='A' && In[i]<='F') Out[i] =In[i]-'A'+10;
    }

}

#if 1
void str2hex(char* hex_str,int len,unsigned char* hex) /** by lbw **/
{
    char* tmp=(char *)hex_str;
    int sum=0;
    int i,o,p;
    int l=len/2;
    for (i=0;i<l;i++)
    {
        o=*(tmp+2*i);
        p=*(tmp+2*i+1);
        o=(o<=57?o-48:o-55);
        p=(p<=57?p-48:p-55);
        sum=o*16+p;
        *(hex+i)=sum;
    }
}
#endif

int main()
{
	#if 0
    char *In="31323334";
	#endif
    char In[]="    ";
	unsigned char buffer[50];
    unsigned char *Out=buffer;
    #if 1
    printf("call str2hex\n");
    str2hex(In,strlen(In),buffer);
    #endif
#if 0
	printf("Call ChangeASCIItoBIN\n");
    ChangeASCIItoBIN(Out,In,8);
#endif
    int i=0;
    for(i=0;i<strlen(In)/2;i++)
        printf("%02X",Out[i]);
	#if 0
	#endif
    printf("\n");
    return 0;
}
