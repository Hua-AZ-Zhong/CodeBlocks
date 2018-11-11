#include <stdio.h>
#include <unistd.h>

int var_A = 6;

int main()
{
	int var_B = 7;
	if(fork()==0)
	{
		var_A++;
		var_B++;
		printf("In child: var_A=%d, var_B=%d\n", var_A, var_B);
	}
	else
	{
		var_B--;
		printf("In parent: var_A=%d, var_B=%d\n", var_A, var_B);
	}
	printf("var_A=%d, var_B=%d\n", var_A, var_B);
	return 0;
}
