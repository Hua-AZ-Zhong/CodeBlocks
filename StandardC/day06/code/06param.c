/*
     变量练习
*/
#include <stdio.h>
int shu_zi = 3;
int main() {
    {
        printf("shu_zi是%d\n", shu_zi);
    }
    int shu_zi = 4;
    printf("shu_zi是%d\n", shu_zi);
    {
        int shu_zi = 5;
        {int shu_zi = 6;}
        printf("shu_zi是%d\n", shu_zi);
    }
    {
        printf("shu_zi是%d\n", shu_zi);
    }
    return 0;
}
