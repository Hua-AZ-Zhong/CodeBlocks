#include <stdio.h>
#include <string.h>

void my_strcat(char *string_a, char *string_B)
{
    char *p=string_a;
    while(*p)
    {
        p++;
    }
    while((*p++=*string_B++)!='\0')
    {
        ;
    }
}

void my_strcpy(char *dest, char *src)
{
    while((*dest++ = *src++)!='\0')
        ;
}

void reverse(char *src)
{
    char tmp[1024]={0};
    char *p=tmp;
    puts(tmp);
    int num=0;
    while(*src!='\0')
    {
        src++;
        num++;
    }

    for(int i=0;i<num;i++)
    {
        *p++=*(--src);
    }

    my_strcpy(src,tmp);
}

void reverse_new(char *src, char *dest)
{
    int num=0;
    while(*src!='\0')
    {
        src++;
        num++;
    }

    for(int i=0;i<num;i++)
    {
        --src;
        *dest = *src;
        printf("dest is [%c], src is [%c]\n", *dest, *src);
        dest++;
    }
}

int main()
{
    //char *string_A="hello";   //此种方式定义的字符串位于静态存储区，不允许通过指针修改内容
    char string_A[100]={"hello"};
    char *string_C="_world!";
    printf("strlen of A is [%d] cont is [%s]\n",strlen(string_A),string_A);
    my_strcat(string_A,string_C);
    printf("strlen of A is [%d] cont is [%s]\n",strlen(string_A),string_A);
    puts(string_A);

    memset(string_A,0x00,100);
    puts(string_A);
    my_strcpy(string_A,string_C);
    puts(string_A);

    reverse(string_A);
    puts(string_A);

    memset(string_A,0x00,100);
    reverse_new(string_C, string_A);
    puts(string_A);

    return 0;
}
