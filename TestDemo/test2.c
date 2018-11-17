/*************************************************************************
> File Name: test2.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年11月10日 星期二 22时53分29秒
*************************************************************************/

#include <stdarg.h>
#include <stdio.h>

int Prompt(const char *args, ...)
{
        int ret;
        va_list ap;
        char buf[81] ;

        va_start(ap, args);
        ret = vsprintf(buf, args, ap);
        printf("%s\n", buf);
        va_end(ap );

        return ret;
}

int main(int argc, char *argv[])
{
        Prompt("argc=%d argv[0]=%s\n", argc, argv[0]);
        return 0;
}
