/*
    文件批量处理练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    int values[3] = {0}, num = 0;
    p_file = fopen("a.bin", "rb");
    if (p_file) {
        num = fread(values, sizeof(int), 3, p_file);
        printf("读出%d个整数\n", num);
        printf("%d %d %d\n", values[0], values[1], values[2]);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
