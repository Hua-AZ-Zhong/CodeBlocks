#include <stdio.h>
#include <string.h>

int main()
{
    char array[3][6]={"abc","defgh","zhong"};   //其实等同于存放指针的数组char *array[3]
    char *array_new[3]={"abc","defgh","zhong"}; //指针数组定义后，无法知道列长度，适合未知长度的字符串
    for(int i=0;i<3;i++)
    {
        printf("addr of array[%d] is %p, content is ", i, array[i]);
        puts(array[i]);
    }

    printf("array[2][4] is %c\n",*(*(array+2)+4));
    printf("array[0][0] is %c\n",**array);
    printf("array[1][2] is %c\n",*(array[1]+2));

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<6;j++)
        {
            printf("array[%d][%d] is %02X\n", i, j, array[i][j]);
        }
    }

    char str[][20]={"One*World","One*Dream!","NEW BALANCE"};
    char *p = str[1];
    printf("%d,",strlen(str[1]));
    printf("%s\n",str[1]);
    printf("size of str is %d\n",sizeof(str));
    int x=12,y=8,z;
    printf("%d\n",z=0.9+x/y);

    char *pb="abcdefghuvw";
    printf("%.0s\n",pb);
    printf("%c %c %c\n",*pb++,*pb++,*++pb);
    return 0;
}
