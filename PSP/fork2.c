#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1, pid2, pid3;
  
  pid1=fork();
  
  if(pid1==-1)
  {
  	printf("Error al crear el proceso");
  }
  if(pid1==0)
  {
  	
  	int suma=getpid()+getppid();
  	printf("El pid del proceso: %d\n",getpid());
  	printf("El pid padre del proceso: %d\n",getppid());
  	printf("Suma de los pid:  %d\n",suma);
  	
  	pid2=fork();
  	if(pid2==-1)
       {
  		printf("Error al crear el proceso");
  	}
  	if(pid2==0)
  	{
  		
  		int suma=getpid()+getppid();
  		printf("El pid del proceso: %d\n",getpid());
  		printf("El pid padre del proceso: %d\n",getppid());
  		printf("Suma de los pid:  %d\n",suma);
  	
  		pid3=fork();
  		if(pid3==-1)
 		 {
  			printf("Error al crear el proceso");
  		}
  		if(pid3==0)
  		{
  			int suma=getpid()+getppid();
  			printf("El pid del proceso: %d\n",getpid());
  			printf("El pid padre del proceso: %d\n",getppid());
  			printf("Suma de los pid:  %d\n",suma);
  			exit(0);
  		}
  		wait(NULL);
  		exit(0);
  	}
  	wait(NULL);
  	exit(0);
  	
  }
	wait(NULL);
  
}

