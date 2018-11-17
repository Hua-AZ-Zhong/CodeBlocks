/*************************************************************************
> File Name: h3c04.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2015年03月30日 星期一 18时15分11秒
*************************************************************************/

#include <stdio.h>

int main()
{
  int i, a = 0;
  i = (a = 2*3, a | 0x11),(a*5, a & 0x1);
  printf("i = %d\n", i);




  /** Test Result **/
  a=0;
  printf("%d\n", a | 0x11);
  a=0;
  i=0;
  printf("%d\n", i=( a = 2*3, a | 0x11));
  a=6;
  printf("%d\n", a=(a*5, a & 0x1));
  printf("%d\n", (23,17));
  return 0;
}
