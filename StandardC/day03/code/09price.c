/*
    计算电影票价格的练习
*/
#include <stdio.h>
int main() {
    int jia_ge = 30, ge_shu = 3, xun_huan = 0;
    for (xun_huan = 0;xun_huan < 3;xun_huan++) {
        printf("请输入电影票单价和张数：");
        scanf("%d %d", &jia_ge, &ge_shu);
        if (ge_shu <=  0) {
            printf("张数数据不合理\n");
            continue;
        }
        if (jia_ge <= 0) {
            printf("价格不合理\n");
            continue;
        }
        break;
    }
    if (xun_huan < 3) {
        printf("总价格是%d\n", jia_ge * ge_shu);
    }
    else {
        printf("笨死你算了。\n");
    }
    return 0;
}




