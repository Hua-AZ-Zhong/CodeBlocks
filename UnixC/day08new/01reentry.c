#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

void func(int sig)
{//...
	getpwnam("root");
	//...
}
int main()
{
	signal(SIGINT,func);
	struct passwd* p = getpwnam("tarena");
	sleep(100);
	printf("uid=%d\n", p->pw_uid);
}

