/*
     strcpy的练习
*/
#include <stdio.h>

char *str_cpy(char *p_zi_fu_chuan, char *p_zi_fu_chuan_1) {
    if (!p_zi_fu_chuan || !p_zi_fu_chuan_1) {
        return p_zi_fu_chuan;
    }
    char * p = p_zi_fu_chuan;
    while (*p_zi_fu_chuan_1) {
        *p_zi_fu_chuan = *p_zi_fu_chuan_1;
        p_zi_fu_chuan++;
        p_zi_fu_chuan_1++;
    }
    *p_zi_fu_chuan = '\0';
    return p;
}

int main() {
    char zi_fu_chuan[10] = "abc";
    printf("%s\n", str_cpy(zi_fu_chuan, "xy"));
    return 0;
}
