/*
     求最大公约数的练习
*/
#include <stdio.h>

int yue(int xiao, int da) {
    if (!(da % xiao)) {
        return xiao;
    }
    else {
        return yue(da % xiao, xiao);
    }
}

int main() {
    int xiao = 0, da = 0;
    printf("请输入两个数字：");
    scanf("%d %d", &xiao, &da);
    printf("最大公约数是%d\n", yue(xiao, da));
    return 0;
}
