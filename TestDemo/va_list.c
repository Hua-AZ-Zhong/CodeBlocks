#include <stdio.h>
#include <stdarg.h>

int OTraceDebug(const char *va_alist, ...) {
    char msg2file[10000]="";
    va_list args;
    char* format;

    va_start(args,va_alist);
#if 0
    format = va_arg(args, char* );
    vsprintf(msg2file, format, args);
    printf("format is [%s]\n", format);
#endif
    vsprintf(msg2file, va_alist, args);
    printf("msg2file is: %s", msg2file);
}

int main() {
    char *name = "zhonghua";
    int age = 30;
    OTraceDebug("hello world! name is %s,\n\t age is %d\n", name, age);
}
