/** 用1、2、3、4四个数字组成互不相同且无重复数字的三位数，求出有多少个这样的三位数，并输出这些数 **/
#include <stdio.h>

int main()
{
    for(int num = 111; num < 444; num++)
    {
        static int count = 0;
        int a = num/100;
        int b = (num%100)/10;
        int c = num%10;

        if(a != 1 && a !=2 && a !=3 && a != 4)
                continue;
        if(b != 1 && b !=2 && b !=3 && b != 4)
                continue;
        if(c != 1 && c !=2 && c !=3 && c != 4)
                continue;

        if( (a != b) && (b != c) && (a != c))
        {
            count++;
            printf("num is [%d], count is [%03d]\n", num, count);
        }
    }
    return 0;
}
