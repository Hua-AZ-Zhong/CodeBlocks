#include <sys/select.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	mkfifo("pipe1",0644);
	mkfifo("pipe2",0644);
	int fd1 = open("pipe1", O_RDWR);
	int fd2 = open("pipe2", O_RDWR);
	fd_set fs;
	struct timeval timeout={0,0};
	for(;;){
		FD_ZERO(&fs);
		FD_SET(fd1,&fs);
		FD_SET(fd2,&fs);
		FD_SET(STDIN_FILENO,&fs);
		char buf[1000];
		if(select(fd2+1,&fs,NULL,NULL,&timeout)>0){
			if(FD_ISSET(0,&fs)){//键盘有输入数据
				scanf(" %[^\n]", buf);
				if(strcmp(buf,"quit")==0) break;
				puts(buf);
			}
			if(FD_ISSET(fd1,&fs)){//管道pipe1有数据
				int n=read(fd1, buf, sizeof(buf)-1);
				buf[n] = '\0';
				printf("pipe1:%s", buf);
			}
			if(FD_ISSET(fd2,&fs)){//管道pipe2有数据
				int n=read(fd2, buf, sizeof(buf)-1);
				buf[n] = '\0';
				printf("pipe2:%s", buf);
			}
		}
	}
	close(fd1);
	close(fd2);
	unlink("pipe1");
	unlink("pipe2");
}







