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
  	printf("Error al crear el proceso hijo\n");
  }
  if(pid1==0)
  {
  	if((getpid() % 2)==0)
  	{
  		printf("EL pid es: %d\n",getpid());
  		printf("EL pid de padre es: %d\n",getppid());
  	}
  	else
  	{
  		printf("EL pid es: %d\n",getpid());
  	}
  	exit(0);
  }
  
  pid2=fork();

  if(pid2==-1)
  {
  	printf("Error al crear el proceso hijo\n");
  }
  if(pid2==0)
  {
  	if((getpid() % 2)==0)
  	{
  		printf("EL pid es: %d\n",getpid());
  		printf("EL pid de padre es: %d\n",getppid());
  	}
  	else
  	{
  		printf("EL pid es: %d\n",getpid());
  	}
  	
  	pid3=fork();
  	
  	
  	 if(pid3==-1)
  	{
  		printf("Error al crear el proceso hijo\n");
  	}
  	if(pid3==0)
  	{
  	if((getpid() % 2)==0)
  	{
  		printf("EL pid es: %d\n",getpid());
  		printf("EL pid de padre es: %d\n",getppid());
  	}
  	else
  	{
  		printf("EL pid es: %d\n",getpid());
  	}
  	}
  	wait(NULL);
  	
  	
  	exit(0);
  }
  
  
  wait(NULL);
  wait(NULL);
}

