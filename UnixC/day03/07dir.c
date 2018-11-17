#include <dirent.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	DIR* p = opendir(".");//打开当前目录
	//if(p==NULL){...}
	struct dirent* q;
	while( (q=readdir(p))!=NULL ){//逐项读取
		if(q->d_name[0]=='.') continue;//跳过隐藏文件
		printf("%s\t", q->d_name);//显示
	}
	printf("\n");
	closedir(p);//关闭目录
}

