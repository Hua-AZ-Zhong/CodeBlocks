/*
     文件操作练习
*/
#include <stdio.h>
int main() {
    FILE * p_file = NULL;
    char str[] = "Hello World!";
    int xun_huan = 0;
    p_file = fopen("a.txt", "w");
    if (p_file) {
        while (str[xun_huan]) {
            if (EOF == fputc(str[xun_huan], p_file)) {
                break;
            }
            xun_huan++;
        }
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
