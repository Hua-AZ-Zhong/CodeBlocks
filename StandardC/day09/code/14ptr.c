/*
     二级指针练习
*/
#include <stdio.h>
#include <stdlib.h>
void chai_fen(char * zi_fu_chuan, char ** pp_zi_fu) {
    int xun_huan = 0;
    char *p_zi_fu = NULL;
    while (*(zi_fu_chuan + xun_huan) != ':') {
        xun_huan++;
    }
    p_zi_fu = (char*)malloc(xun_huan + 1);
    xun_huan = 0;
    while (*(zi_fu_chuan + xun_huan) != ':') {
        *(p_zi_fu + xun_huan) = *(zi_fu_chuan + xun_huan);
        xun_huan++;
    }
    *(p_zi_fu + xun_huan) = 0;
    *pp_zi_fu = p_zi_fu;
}

int main() {
    char zi_fu_chuan[] = "1234:5678:9012";
    char *p_zi_fu = NULL;
    chai_fen(zi_fu_chuan, &p_zi_fu);
    printf("拆分后的结果字符串是%s\n", p_zi_fu);
    free(p_zi_fu);
    p_zi_fu = NULL;
    return 0;
}
