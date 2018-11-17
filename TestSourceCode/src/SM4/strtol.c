/*************************************************************************
> File Name: strtol.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月01日 星期日 21时57分33秒
*************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char a[] = "123342abcdAFCB";
    char str[3] = {0}, *p = &str[2];
    int i;
	char arr[8];
	#if 0
	int arr[8]; /** will warning **/
	#endif
	int j=0;
 
    for(i=0; i<sizeof(a); i=i+2) {
        memcpy(str, &a[i], 2);
        arr[j]= strtol(str, &p, 16);
		#if 0
        if(!(*p)) {
            printf("0x%x, ", c );
        } else {
            break;
        }
		#endif
		j++;
    }
	for(j=0;j<7;j++)
		printf("%X",arr[j]);
	printf("\n");
	char *pointer=&arr[0];
	int num=1;
	
	#if 1 /** Work Well **/
	while(*pointer !='\0')
	{
		printf("%02X",(unsigned char)*pointer);
		pointer++;
		num++;
	}
	printf("\n");
	printf("num is %d \n",num);
	#endif
	#if 0 /** Error **/
	while(*(arr++)!='\0') /** array name can not ++ **/
	{
		printf("arr = %X\n",(unsigned char)*(arr++));
		num++;
	}
	#endif
	#if 0 /** Work Well **/
	while(*(pointer++)!='\0')
	{
		printf("%02X",(unsigned char)*(pointer++));
		num++;
	}
	#endif
    printf("\n count=%d\n", i/2);
    return 0;
}

#if 0
/** Orignal **/
int main()
{
    char a[] = "123342abcdAFB1H";
    char str[3] = {0}, *p = &str[2];
    int i,  c;
 
    for(i=0; i<sizeof(a); i=i+2) {
        memcpy(str, &a[i], 2);
        c = strtol(str, &p, 16);
        if(!(*p)) {
            printf("0x%x, ", c );
        } else {
            break;
        }
    }
    printf("\n count=%d\n", i/2);
    return 0;
}
#endif
