/*
    rewind函数练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    char zi_fu = 0;
    p_file = fopen("a.txt", "r");
    if (p_file) {
        zi_fu = fgetc(p_file);
        printf("%c ", zi_fu);
        rewind(p_file);
        zi_fu = fgetc(p_file);
        printf("%c ", zi_fu);
        rewind(p_file);
        zi_fu = fgetc(p_file);
        printf("%c\n", zi_fu);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
