/*
    模拟登陆练习
*/
#include <stdio.h>
#include <string.h>
int main() {
    char yong_hu[] = "admin\n";
    char mi_ma[] = "123456\n";
    char ming[10], ma[10];
    int xun_huan = 0;
    for (xun_huan = 0; xun_huan < 3; xun_huan++) {
        printf("请输入用户名：");
        fgets(ming, 10, stdin);
        if (strcmp(ming, yong_hu)) {
            printf("用户名错误\n");
            continue;
        }
        printf("请输入密码：");
        fgets(ma, 10, stdin);
        if (strcmp(ma, mi_ma)) {
            printf("密码错误\n");
            continue;
        }
        break;
    }
    if (xun_huan < 3) {
        printf("登陆成功\n");
    }
    else {
        printf("登陆失败\n");
    }
    return 0;
}



