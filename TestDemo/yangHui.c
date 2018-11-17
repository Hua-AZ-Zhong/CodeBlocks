#include <stdio.h>

int main()
{
    printf("please input a integer:\n");
    int n=0;
    scanf("%d",&n);
    int i=0, j=0, k=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        } 
        for(k=0;k<2*i-1;k++)
        {
            printf("*");
        } 
        puts("");
    }
}
