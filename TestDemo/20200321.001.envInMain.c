#include <stdio.h>

int main(int argc, char * argv[], char * envp[])
{
    int i;
    printf("argc=%d\n", argc);
    for(i = 0; i < argc; i++)
    {
        printf("argv[%d] : %s\n", i, argv[i]);
    }
    printf("The envpironment srings on this system are:\n");
    for(i=0; *envp != NULL; i++)
    {
        printf("envp[%02d]: %s\n", i, *(envp++));
    }
}
