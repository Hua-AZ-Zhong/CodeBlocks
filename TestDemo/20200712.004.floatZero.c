#include <stdio.h>
#include <math.h>

int main()
{
    float floatNum;

    printf("Please input a float number:");
    scanf("%f", &floatNum);
    printf("floatNum=[%0.16f]\n", floatNum);

    if(fabs(floatNum - 0.0) < 1e-6)
    {
        printf("floatNum is zero\n");
    }
    else if(floatNum > 1e-6)
    {
        printf("floatNum bigger than zero\n");
    }
    else if(floatNum < -1e-6)
    {
        printf("floatNum litter than zero\n");
    }

    return 0;
}
