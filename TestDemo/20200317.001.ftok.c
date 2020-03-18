#include <stdio.h>  
#include <sys/sem.h>  
#include <stdlib.h>  

int main(int argc, char** argv, char** envp)
{
    key_t semkey;

    for(int i = 0; i < 256; i++)
    {
        semkey = ftok(argv[0], i);
        printf("ftok [%s] ok, semkey = 0x%08X\n", argv[0], semkey);
    }

    if((semkey = ftok("./test", 0))<0)
    {
        printf("ftok ./test failed\n");
        perror("ftok ./test failed");
        exit(EXIT_FAILURE);
    }
    else
    {
        printf("ftok ./test ok ,semkey = 0x%X\n", semkey);
    }
    return 0;
} 
