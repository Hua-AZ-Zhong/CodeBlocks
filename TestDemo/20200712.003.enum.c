#include <stdio.h>

enum weekday
{
    Sun, Mon=9, Tue, Wed, Thu, Fir=-2, Sat
};

enum weekday a, b, c, d, e, f, g;

int main()
{
    a=Sun;
    b=Mon;
    c=Tue;
    d=Wed;
    e=Thu;
    f=Fir;
    g=Sat;
    printf("a=%d, b=%d, c=%d, d=%d, e=%d, f=%d, g=%d\n", a, b, c, d, e, f, g);
    return 0;
}
