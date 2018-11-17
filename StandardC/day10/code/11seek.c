/*
    fseek练习
*/
#include <stdio.h>
int main() {
    FILE *p_file = NULL;
    char zi_fu = 0;
    p_file = fopen("a.txt", "r");
    if (p_file) {
        fseek(p_file, 6, SEEK_SET);   //把位置指针移动到从文件头开始向后6个字节的位置
        zi_fu = fgetc(p_file);
        printf("%c ", zi_fu);
        fseek(p_file, -2, SEEK_END);  //把位置指针移动到从文件尾开始向前2个字节的位置
        zi_fu = fgetc(p_file);
        printf("%c ", zi_fu);
        fseek(p_file, -3, SEEK_CUR);  //把位置指针移动到从文件位置指针当前位置向前3个字节的位置
        zi_fu = fgetc(p_file);
        printf("%c\n", zi_fu);
        printf("位置指针的位置是%ld\n", ftell(p_file));   //ftell可以获得当前文件位置指针的位置
        fclose(p_file);
        p_file = NULL;
    }
    return 0;
}
