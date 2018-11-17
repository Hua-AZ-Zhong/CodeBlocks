#include <stdio.h>

int main()
{
    int x=0,y=0,z=0;
    for(x=1;x<=9;x++)
    {
        for(y=0;y<=9;y++)
        {
            for(z=0;z<=9;z++)
            {
                if(x*x*x+y*y*y+z*z*z == 100*x+10*y+z)
                    printf("%d\n",100*x+10*y+z);
            }
        }
    }
}
