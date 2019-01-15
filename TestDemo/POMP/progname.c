#include <stdio.h>

extern char *__progname;

int main(int argc, char **argv)
{
    printf("By progname: the process name is [%s]\n", __progname);
    printf("By argv[0]:  the process name is [%s]\n", argv[0]);
    return 0;
}
