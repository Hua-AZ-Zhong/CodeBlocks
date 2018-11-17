/*************************************************************************
> File Name: SizeofStruct.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月14日 星期五 11时22分15秒
*************************************************************************/

#include <stdio.h>
/** 64 Bit System Size of Primer is 8 **/

int main()
{
    struct S
	{
		char c; 
		int k;
	} s;

    struct A 
	{
		char c[9]; 
		double d;
	} a;

    struct B 
	{
		char *c[9]; 
		double *d;
	} b;

    struct C 
	{
		char c[8]; 
		double d;
	} c;

    printf("%d,%d,%d,%d \n",sizeof(s),sizeof(a),sizeof(b),sizeof(c));
    return 0;
}
