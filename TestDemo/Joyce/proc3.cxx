#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[4];  //joyce:I only use one now. meaning one ZP process one thread and single txn per thread. you need to run a stress test to see if single thread tid[0] is enough or not
int counter=0;
pthread_mutex_t lock;
FILE *fp;
int startProc();


void* writeLog(void *arg)
{
    pthread_mutex_lock(&lock); //joyce:before writing, lock the process first,no else can write except this process


    if(counter>1000)
	    counter=0;  //joyce:just to control from getting too big. reset here
    counter += 1;

    printf("\nProc3 PID[%d]-Write Job %d started.\n",getpid(),counter);
   
    char str[120]={};
   memset(str,0x00,sizeof(str));

   sprintf(str,"PID[%d]-Proc3 write task[%d]\n",getpid(),counter);

   if(fp==NULL)
	   printf("File pointer null \n");

   //joyce:can use fwrite,fprint, whichever you prefer
   fwrite(str , 1 , sizeof(str) , fp );
   fflush(fp); //i want to see the output right away :-)

   printf("\nProc3 PID[%d]-Write Job %d finished\n",getpid(),counter);

   pthread_mutex_unlock(&lock); //joyce: need to unlock here so that can be used by the next write procedure p

   return NULL;
}

int main(void)
{

    if (!(fp = fopen("file.txt", "a+")))
    {
         printf("\nError Opening File\n");
         return 1;
    }

    if (pthread_mutex_init(&lock, NULL) != 0) //joyce:initial mutex here
    {
          printf("\n mutex init failed\n");
          return 1;
    }
    else
	    printf("Mutex initialize. I'll begin the synchronization \n");


    startProc(); //joyce:this part is like formatter, consistently waiting for txn to process

    pthread_mutex_destroy(&lock);//joyce:must destroy to release the mutex pointer when progrm exit

    fclose(fp);

    return 0;
}

int startProc()
{
	for(;;) //joyce:just to simulate formatter scenario infinite logging procedure
	{
		   
		int i=0;  //every incoming or outgoing message starts a new
		int err;
		        
		err = pthread_create(&(tid[i]), NULL, &writeLog, NULL); 
        	
		if (err != 0)
            		printf("\ncan't create thread :[%s]", strerror(err));
        	else
            		printf("\nThread created \n");

		pthread_join(tid[i], NULL); //logging happens here for this thread. will call whatever in writeLog

		sleep(5);
	}

	return 0;

}
