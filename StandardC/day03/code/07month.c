/*
     计算某一年的某一月一共有多少天
*/
#include <stdio.h>
int main() {
    int nian = 0, yue = 0;
    printf("请输入年份和月份：");
    scanf("%d %d", &nian, &yue);
    /*if ( !(yue - 1) ||
         !(yue - 3) ||
         !(yue - 5) ||
         !(yue - 7) ||
         !(yue - 8) ||
         !(yue - 10) ||
         !(yue - 12)) {
        printf("一共有31天\n");
    }
    else if ( !(yue - 4) || 
              !(yue - 6) ||
              !(yue - 9) || 
              !(yue - 11)) {
        printf("一共有30天\n");
    }
    else if(!(yue - 2)) {
        if ((!(nian % 4) && (nian % 100)) || 
            !(nian % 400)) {
            printf("一共有29天\n");
        }
        else {
            printf("一共有28天\n");
        }
    }*/
    switch(yue % 12) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 0:
        printf("一共有31天\n");
        break;
    case 2:
        if ((!(nian % 4) && (nian % 100)) || 
            !(nian % 400)) {
            printf("一共有29天\n");
        }
        else {
            printf("一共有28天\n");
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        printf("一共有30天\n");
        break;
    default:
        printf("你有病吧\n");
        break;
    }
    return 0;
}




