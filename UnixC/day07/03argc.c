#include <stdio.h>

int main(int argc, char* argv[], char* env[])
{
	int cnt=0;
	while(argv[cnt]!=NULL) ++cnt;
	printf("cnt=%d, argc=%d\n", cnt, argc);
}

