/*
    fputs和fgets练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    p_file = fopen("c.txt", "w");
    if (p_file) {
        fputs("xyz abc", p_file);  //失败返回EOF
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
