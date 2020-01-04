/** 将一个int型整数打印成对应的二进制数 **/
#include <stdio.h>

int main()
{
    unsigned int num = 0;
    char *p = (char *)&num;

    printf("Please input the integer: ");
    scanf("%d", &num);

    for(int i = 0; i < sizeof(int); i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if((*p) & 0x80)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
            (*p)<<=1;
        }
        printf(" ");
        p++;
    }
    printf("\nnum is [%d]\n", num);

    return 0;
}
