#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
void main() {
pid_t pid;

time_t hora;
char *fecha ;
time(&hora);
fecha = ctime(&hora) ;


char buffer[30];
int fd[2];


pipe(fd);

pid=fork();


if(pid==0)
{
 close(fd[1]);
 read(fd[0],buffer,10);
 printf("Soy el proceso hijo con pid: %d\n",getpid());
 printf("La fecha enviada es: %s\n",buffer);
 exit(0);
}
else
{
 close(fd[0]);
 write(fd[1],fecha,10);
 wait(NULL);
}
}

