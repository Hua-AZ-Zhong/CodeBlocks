/*
    文件操作练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    char zi_fu = 0;
    p_file = fopen("a.txt", "r");
    if (p_file) {
        while (zi_fu != EOF) {
            zi_fu = fgetc(p_file);
            if (zi_fu != EOF) {
                printf("%c", zi_fu);
            }
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
