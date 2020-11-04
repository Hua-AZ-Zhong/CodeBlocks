#include <stdio.h>

union i_or_f
{
    int n;
    float x;
};

int main()
{
    union i_or_f var;
    var.n = 100;
    printf("var.n = %d, var.x = %f\n", var.n, var.x);
    var.x = 100.0;
    printf("var.n = %d, var.x = %f\n", var.n, var.x);
    return 0;
}
