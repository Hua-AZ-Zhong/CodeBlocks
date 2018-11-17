/*
    折扣练习
*/
#include <stdio.h>
int main() {
#if defined(JINGPING)
     printf("120%%\n");
#elif !defined(GONGCHANG)
    printf("100%%\n");
#else
    printf("80%%\n");
#endif
    return 0;
}
