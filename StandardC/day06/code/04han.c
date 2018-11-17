/*
    汉诺塔练习
*/
#include <stdio.h>

void han(int ge_shu, char yuan, char zhong_zhuan, char mu_di) {
    if (1 == ge_shu) {
        printf("%d:%c-->%c\n", ge_shu, yuan, mu_di);
    }
    else {
        han(ge_shu - 1, yuan, mu_di, zhong_zhuan);     //把上面ge_shu - 1个盘子移动到中转柱子上去
        printf("%d:%c-->%c\n", ge_shu, yuan, mu_di);   //把最后一个盘子从初始柱子移动到目的柱子上
        han(ge_shu - 1, zhong_zhuan, yuan, mu_di);  //把中转柱子上的ge_shu - 1个盘子移动到目的柱子上
    }
}

int main() {
    int ge_shu = 0;
    printf("请输入盘子的个数：");
    scanf("%d", &ge_shu);
    han(ge_shu, 'A', 'B', 'C');
    return 0;
}
