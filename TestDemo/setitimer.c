#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
 
void catch_all_signal();
void signalHandler(int signo);
 
int main(int argc, char *argv[])
{
	#if 0
	signal(SIGALRM, signalHandler);
	#endif
	catch_all_signal();
	     
        struct itimerval new_value, old_value;
	new_value.it_value.tv_sec = 0;
	new_value.it_value.tv_usec = 1;
	new_value.it_interval.tv_sec = 0;
	new_value.it_interval.tv_usec = 200000;
	setitimer(ITIMER_REAL, &new_value, &old_value);
				        
	for(;;);
					     
	return 0;
}

void catch_all_signal()
{

   signal(SIGINT, signalHandler);  //Control X Signal 2 interrupt, generated from terminal
   signal(SIGQUIT, signalHandler); //Control D Signal 3 quit, generated from terminal special
   signal(SIGTSTP, signalHandler); // Signal 18 interactive stop
   signal(SIGKILL, signalHandler); //Signal 9 kill cannot be trapped, so this line is useless
   signal(SIGHUP, signalHandler); //Signal 1 - Hangup
   signal(SIGCHLD, signalHandler); //Signal 20 sent to parent on child stop or exit
   signal(SIGIO, signalHandler); // Signal 23 - I/O possible, or completed
   signal(SIGSEGV, signalHandler); // Signal 11 - Core Dump
   signal(SIGTERM, signalHandler); // Signal 15 - Software terminate
   signal(SIGURG, signalHandler); // Signal - Software terminate
   signal(SIGALRM, signalHandler);

   #if 0
   for(int i=1; i <= 49 ; i++)
   {   
	signal(i,signalHandler);     
   }
   #endif

}

void signalHandler(int signo)
{
	switch (signo){
		case SIGALRM:
			printf("Caught the SIGALRM signal!\n");
			break;
		default:
			printf("Caugth the signal [%d]\n", signo);
			break;
	}
}
