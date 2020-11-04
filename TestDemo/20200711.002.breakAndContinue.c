#include <stdio.h>

int main()
{
    int x, y=0, z=0, t;
    do
    {
        scanf("%d", &x);
        t=x>0;
        switch(t)
        {
            case 0:
                break;
            case 1:
                y+=x;
                continue;
        }
        z+=x;
    }
    while(x);
    printf("%d,%d\n",y,z);
}
