/*
    格式化文件操作练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    int value = 0;
    char a_char = 0;
    float a_float = 0.0f;
    //p_file = fopen("d.txt", "w");
    p_file = fopen("d.txt", "r");
    if (p_file) {
        //fprintf(p_file, "%d %c %g\n", 15, 't', 1.8f);
        fscanf(p_file, "%d %c %g", &value, &a_char, &a_float);
        printf("%d %c %g\n", value, a_char, a_float);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
