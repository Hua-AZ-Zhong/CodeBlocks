/*
    条件编译练习
*/
#include <stdio.h>
//#define ZHAOBENSHAN
int main() {
    int cai = 0;
    printf("请点菜：");
    scanf("%d", &cai);
/*
#ifdef ZHAOBENSHAN
    if (1 == cai) {
        printf("这个真没有\n");
    }
    else {
        printf("这个菜没有\n");
    }
#else
    printf("这个菜有\n");
#endif
*/
#if defined(ZHAOBENSHAN)
    if (1 == cai) {
        printf("这个真没有\n");
    }
    else {
        printf("这个菜没有\n");
    }
#else
    printf("这个菜有\n");
#endif
    return 0;
}
