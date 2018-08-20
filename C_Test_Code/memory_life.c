#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Getmemory(char **p, int num); /** 由于要传递的参数是指针的地址，所以使用二级指针 **/
char *GetMemory(void);

int main()
{
    printf("NULL's address is %p\n",NULL);
    char *str=NULL;
    Getmemory(&str,100);
    strcpy(str,"hello");
    printf("%p %s\n",str,str);

    str=NULL;
    str=(char *)malloc(10);
    strcpy(str,"hello");
    free(str);   /** 手动释放仅释放内存，地址不释放 **/
    if(str!=NULL)
        strcpy(str,"world");
    printf("%p %s\n",str,str);

    str=GetMemory();
    printf("%p %s\n",str,str);

    return 0;
}

void Getmemory(char **p, int num)
{
    *p = (char *)malloc(num); /** malloc动态内存返回的内存首地址，不会在函数执行完成后释放 **/
}

/** char*代表返回char*类型指针，即地址 **/
char *GetMemory(void)
{
    char p[]="hello world";
    return p; /** 返回局部变量地址，地址被释放，最终return NULL **/
}
