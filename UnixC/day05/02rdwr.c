#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	umask(0);//不屏蔽权限
	int fd = open("id", O_RDWR|O_CREAT, 0777);
	if(fd<0){perror("open");return -1;}
	unsigned int id=0;
	read(fd, &id, sizeof(id));
	++id;//0001
	lseek(fd, 0, SEEK_SET);
	//lseek(fd, -4, SEEK_CUR);
	//lseek(fd, -4, SEEK_END);
	write(fd, &id, sizeof(id));
	close(fd);//00010002
	printf("id=%u\n", id);
	return 0;
}




