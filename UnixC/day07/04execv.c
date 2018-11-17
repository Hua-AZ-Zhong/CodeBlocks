#include <stdio.h>
#include <stdlib.h>

int main()
{//ls -l -d /bin
	char* argv[]={
		"/bin/ls",
		"-l",
		"-d",
		"/bin",
		NULL//必须用一个NULL作为结束元素
	};
	puts("......execute ls -l -d /bin......");
	execv("/bin/ls", argv);
	puts("------ERROR------");//看不到这个，除非出错
}




