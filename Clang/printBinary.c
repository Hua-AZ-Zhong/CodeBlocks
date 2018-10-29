#include <stdio.h>

int main()
{
    int num=0;
    printf("Please input a integer:");
    scanf("%d", &num);

    char *p=(char *)&num;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<8;j++)
        {
            if((*p) & (0x80>>j))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
        p++;
    }
    puts("");
}
