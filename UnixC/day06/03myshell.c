#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
int isvar(const char* beg, const char* end)
{return 1;}//检查是否符合变量命名规则
int main()
{
	puts("欢迎使用quange shell");
	char cmd[256];
	char* p=NULL;
	for(;;){
		printf("qs> ");
		scanf(" %[^\n]",cmd);//空格表示跳过空白字符直到遇到非空白为止
		if(strcmp(cmd,"furong")==0) break;
		if(strncmp(cmd,"cd ",3)==0)//"cd hello"
			chdir(cmd+3);
		else if((p=strchr(cmd,'='))&&isvar(cmd,p)){//检查命令中是否有=而且等号左边是否是个合法的变量名，也就是检查用户是否是想设置环境变量
			*p = '\0';//把字符串切割成变量名和变量值
			setenv(cmd,p+1,1);//设置环境变量
		}
		else
			system(cmd);
	}
	puts("感谢使用qsh!");
}

