#include <stdio.h>

int main()
{
    int x,y;
    x=y=10;
    char arr[100]={0};
    printf("%-7.2f\n",(double)(x)/10);
    sprintf(arr,"%-7.2f",(double)x/10);
    printf("[%s]\n",arr);
    char *p=arr;
    printf("%c%c%c\n",*p,*p++,*p);
    printf("%c\n",*p);
    return 0;
}
