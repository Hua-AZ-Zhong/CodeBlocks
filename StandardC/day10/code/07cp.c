/*
    文件复制练习
*/
#include <stdio.h>
int main() {
    FILE *p_src = NULL, *p_dest = NULL;
    char zi_fu = 0;
    p_src = fopen("a.txt", "r");
    if (p_src) {
        p_dest = fopen("b.txt", "w");
        if (p_dest) {
            while (EOF != zi_fu) {
                zi_fu = fgetc(p_src);
                if (EOF != zi_fu) {
                    fputc(zi_fu, p_dest);
                }
            }
            fclose(p_dest);
            p_dest = NULL;
        }
        fclose(p_src);
        p_src = NULL;
    }
    return 0;
}
