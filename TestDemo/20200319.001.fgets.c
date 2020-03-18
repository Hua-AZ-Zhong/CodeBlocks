# include <stdio.h>

int main(void)
{
    char str[20];  /*定义一个最大长度为19, 末尾是'\0'的字符数组来存储字符串*/
    printf("请输入一个字符串:");
    fgets(str, 7, stdin);  /*从输入流stdin即输入缓冲区中读取7个字符到字符数组str中*/
    /** stdin 也可以换成文件指针fp **/
    printf("%s\n", str); /** 当输入的字符少于7个字符时，则换行符也作为输入的字符，则输出结果会有一行空行 **/
    return 0;
}


