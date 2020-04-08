#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX(a,b,c) (a)>(b)?((a)>(c)?(a):(c)):((b)>(c)?(b):(c))
#define pi 3.1415926

void mmain()
{
int x=0;
int y=0;
while(x<15) y++,x+=++y,printf("y=%d,x=%d\n",y,x);
printf("y=%d,x=%d\n",y,x);

x=0;
int s=0;
while(!x!=0)s+=x++;
printf("%d\n",x);


printf("%-7.2f%c\n",pi,'|');

#if 0
int k=10;
while(k=1)
{
	k=k-1;
	printf("hello world\n");
}
#endif
system("pause");
} 