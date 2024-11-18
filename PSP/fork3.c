#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {

  pid_t pid, pid1, pid2, pid3, pid4;
  int pidP=getppid();
  
  pid=fork();
  
  if(pid==0)
  {
  	int pHijo=getppid();
  	if(pidP>1)
  	{
  		printf("Pid del proceso actual: %d\n",getpid());
  		printf("Pid del abuelo: %d\n",pidP);
  	}
  	else
  	{
  		printf("Pid del proceso actual: %d\n",getpid());
  	}
  	
  	pid1=fork();
  	
  	if(pid1==0)
  	{
  		int pHijoHijo=getppid();
  		if(pHijo>1)
  		{
  		printf("Pid del proceso actual: %d\n",getpid());
  		printf("Pid del abuelo: %d\n",pHijo);
  		}
  	 	else
  		{
  		printf("Pid del proceso actual: %d\n",getpid());
  		}
  		
  		pid3=fork();
	  		if(pid3==0)
 		 	{
 	 		
  			if(pHijoHijo>1)
	  		{
 	 			printf("Pid del proceso actual: %d\n",getpid());
		  		printf("Pid del abuelo: %d\n",pHijoHijo);
	  		}
  		 	else
  			{
  				printf("Pid del proceso actual: %d\n",getpid());
  			}
  			exit(0);				
  			}
  	else
  	{
  		wait(NULL);
  	}
  		exit(0);				
  	}
  	
  	else
  	{
  		wait(NULL);
  	}
  	
  	pid2=fork();
  	
  	if(pid2==0)
  	{
  		int pHijoHijo2=getppid();
  		if(pHijo>1)
  		{
  		printf("Pid del proceso actual: %d\n",getpid());
  		printf("Pid del abuelo: %d\n",pHijo);
  		}
  	 	else
  		{
  		printf("Pid del proceso actual: %d\n",getpid());
  		}
  		
  		pid4=fork();
	  		if(pid4==0)
 		 	{
 	 		
  			if(pHijoHijo2>1)
	  		{
 	 			printf("Pid del proceso actual: %d\n",getpid());
		  		printf("Pid del abuelo: %d\n",pHijoHijo2);
	  		}
  		 	else
  			{
  				printf("Pid del proceso actual: %d\n",getpid());
  			}
  			exit(0);				
  			}
  	else
  	{
  		wait(NULL);
  	}
  		exit(0);				
  	}
  	
  	else
  	{
  		wait(NULL);
  	}
  	exit(0);
  }
  else
  {
  	wait(NULL);
  } 
   

}
