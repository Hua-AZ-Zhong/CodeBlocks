/*
    sprintf和sscanf函数练习
*/
#include <stdio.h>
int main() {
    char a_char = 't';
    int value = 27;
    float a_float = 3.8f;
    char str[20];
    sprintf(str, "%c %d %g\n", a_char, value, a_float);
    printf("%s", str);
    a_char = 0;
    value = 0;
    a_float = 0.0f;
    sscanf(str, "%c %d %g", &a_char, &value, &a_float);
    printf("%c %d %g\n", a_char, value, a_float);
    return 0;
}
