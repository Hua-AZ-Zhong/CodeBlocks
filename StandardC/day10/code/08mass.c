/*
    文件批量处理练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    int values[3] = {1, 2, 3}, num = 0;
    p_file = fopen("a.bin", "w+b");
    if (p_file) {
        num = fwrite(values, sizeof(int), 3, p_file);
        printf("写入%d个整数\n", num);
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
