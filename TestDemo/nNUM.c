#include <stdio.h>

/** 从键盘输入n个整数，求其中的最大数 **/
int main()
{
    int n = 0, num = 0, max = 0;
    printf("Please input the count of numbers which you want to input: ");
    scanf("%d", &n);
    if(n <= 0)
    {
        printf("Please re-run the program & input a positive number\n");
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        printf("%02d. please input a number: ", i);
        scanf("%d", &num);
        if(max < num)
        {
            max = num;
        }
    }
    printf("max is [%d]\n", max);
    return 0;
}
