#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid1, pid2;
 
  pid1 = fork();//Creamos el hijo de p1
  
  if(pid1== -1)
  {
  printf("ERROR");
  exit(-1);
  }
  if (pid1==0)
  {
  pid2=fork();//Creamos el procesos hijo del hijo de pid1 por lo tanto el nieto de pid1
  	if(pid2==0)
  	{
  	printf("Soy el proceso hijo de pid2 y el nieto de pid1: %d\n",getpid());
  	printf("Soy el proceso padre de pid3: %d\n",getppid());
  	}
  	else
  	{
  	pid2=wait(NULL);
  	printf("Soy el proceso padre de pid3: %d\n",getpid());
  	printf("Soy el proceso hijo de pid2: %d\n",getppid());
  	}
  }
  else
  {
  pid1=wait(NULL);
  printf("Soy el proceso padre y abuelo: %d\n",getpid());
  printf("Soy el proceso hijo: %d\n",pid1);
  }
    
}

