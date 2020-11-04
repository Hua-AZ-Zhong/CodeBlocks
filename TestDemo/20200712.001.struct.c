#include <stdio.h>

int main()
{
    struct stu
    {
        int num;
        char *name;
        char sex;
        float score;
    } boy1, boy2;
    printf("sizeof(stu) is [%ld]\n", sizeof(struct stu));
    boy1.num = 102;
    boy1.name="Zhang ping";
    printf("input sex and score:\n");
    scanf("%c %f", &boy1.sex, &boy1.score);
    boy2 = boy1;
    printf("Number=%d\nName=%s\n", boy2.num, boy2.name);
    printf("Sex=%c\nScore=%2.2f\n", boy2.sex, boy2.score);
    return 0;
}
