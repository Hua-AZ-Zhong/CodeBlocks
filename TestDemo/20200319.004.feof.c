#include <stdio.h>
#include <string.h>
 
int main()
{
    FILE *fp = NULL;
    char str[] = "Hello worlD!";
    char buffer[20];
 
    /* 打开文件用于读写 */
    fp = fopen("test.log", "w+");
 
    /* 写入数据到文件 */
    fwrite(str, strlen(str) + 1, 1, fp);
 
    fseek(fp, -3, SEEK_END);
    while(!feof(fp))
    {
        printf("%02X\n", fgetc(fp));
    }

    fseek(fp, 0, SEEK_END);
    while(!feof(fp))
    {
        printf("%02X\n", fgetc(fp));
    }

    if(feof(fp))
    {
        printf("The Document End!\n");
    }

    /* 查找文件的开头 */
    fseek(fp, 0, SEEK_SET); // 等同于 rewind(fp);
    /**
        SEEK_SET = 0： 文件开头
        SEEK_CUR = 1： 当前位置
        SEEK_END = 2： 文件结尾
    **/
 
    /* 读取并显示数据 */
    fread(buffer, strlen(str) + 1, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);

    return(0);
}
