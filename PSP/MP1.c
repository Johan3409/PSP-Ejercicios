#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
  pid_t pid;
 
  pid = fork();

  if (pid == -1 ) //Ha ocurrido un error 
  {
    printf("ERROR !!! No se ha podido crear el proceso hijo...");   
    exit(-1);   
  }
  if (pid == 0 )  //Nos encontramos en Proceso hijo 
  {        
    printf("Soy el proceso hijo: %d\n",getpid());	 
    printf("EL nombre del alumno es: Johan\n");
    sleep(5);
  }
  else    //Nos encontramos en Proceso padre 
  { 
   pid= wait(NULL); //espera la finalización del proceso hijo
   
   printf("Soy el proceso padre: %d\n",getpid());  
    printf("Soy el proceso hijo:%d\n",pid);           
  }
   exit(0);
}

