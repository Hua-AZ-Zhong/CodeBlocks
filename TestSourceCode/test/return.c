/*************************************************************************
> File Name: return.c
> Author: zhonghua
> Mail:   zhonghua-881008@163.com 
> Created Time: 2014年02月24日 星期一 15时10分08秒
*************************************************************************/

#include <stdio.h>

int swap(int a, int b)
{
	int c = 0;
	int nReturnCode = 0;
	c = a;
	a = b;
	b = c;
	nReturnCode = 1;
	if (nReturnCode)
	{
		printf("swap error, nReturnCode = [%d]\n", nReturnCode);
	}
	return -2;
	if (nReturnCode)
	{
		printf("swap error twice, nReturnCode = [%d]\n", nReturnCode);
	}
}

int print()
{
	int a = 9, b = 10;
	int nReturnCode = 0;
	nReturnCode = swap(a, b);
	if (nReturnCode)
	{
		printf("print error, nReturnCode = [%d]\n", nReturnCode);
	}
	return nReturnCode;
	if (nReturnCode)
	{
		printf("print error twice, nReturnCode = [%d]\n", nReturnCode);
	}
}

int main()
{
	int a = 4, b = 5;
	int nReturnCode = 0;
	nReturnCode = print();
	if(nReturnCode)
	{
		printf("main error, nReturnCode = [%d]\n", nReturnCode);
		return nReturnCode;
		printf("main error twice, nReturnCode = [%d]\n", nReturnCode);
	}
	printf("This Step !");
}
