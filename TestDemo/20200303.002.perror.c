#include <stdio.h>

int main()
{
    FILE *fp = fopen("/root/noexitfile","r+");
    if(fp == NULL)
    {
        perror("");
        perror("/root/noexitfile");
    }
    return 0;
}
