#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  int acumulador=getpid();
  pid_t pid1, pid2, pid3, pid4;
  
  printf("Pid padre: %d\n",getpid());
  pid1=fork();
  if(pid1==0)
  {
  	if((getpid() % 2)==0)
  	{
  		acumulador=acumulador+10;
  		printf("Numero: %d\n",acumulador);
  	}
  	else
  	{
 	 	acumulador=acumulador-100;
  		printf("Numero: %d\n",acumulador);
  	}
  	
  	pid3=fork();
  	
  	if(pid3==0)
  	{
 	 	if((getpid() % 2)==0)
  		{
  		acumulador=acumulador+10;
  		printf("Numero: %d\n",acumulador);
  		}
	  	else
 	 	{
 	 	acumulador=acumulador-100;
  		printf("Numero: %d\n",acumulador);
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
  	pid1=wait(NULL);
  }
  
  
  
  
  pid2=fork();
  if(pid2==0)
  {
  	if((getpid() % 2)==0)
  	{
  		acumulador=acumulador+10;
  		printf("Numero: %d\n",acumulador);
  	}
  	else
  	{
 	 	acumulador=acumulador-100;
  		printf("Numero: %d\n",acumulador);
  	}
  	
  	pid4=fork();
  	
  	if(pid4==0)
  	{
 	 	if((getpid() % 2)==0)
  		{
  		acumulador=acumulador+10;
  		printf("Numero: %d\n",acumulador);
  		}
	  	else
 	 	{
 	 	acumulador=acumulador-100;
  		printf("Numero: %d\n",acumulador);
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
  wait(NULL);
  }
