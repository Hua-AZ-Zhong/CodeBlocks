#include <stdio.h>

int fun(char *s)
{
    char *t=s;
    while(*t)
    {
        t++;
    }
    return t-s;
}
int main()
{
    int x=1;
    printf("%d %d %d %d\n",x++,x++,x++,--x);

    int y=10;
    while(y--)
        printf("y=%d\n",y);
    printf("final y=%d\n",y);

    char *string="";
    printf("size of hello is %d\n",fun(string));

    return 0;
}
