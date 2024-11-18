#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void manejador()
{
time_t hora;
char *fecha ;
time(&hora);
fecha = ctime(&hora) ;

printf("Fin del proceso %d: %s\n",getpid(),fecha);
}

 void main() 
{ 
	time_t hora;
	char *fecha ;
	time(&hora);
	fecha = ctime(&hora) ;
	
	printf("Inicio del proceso %d: %s\n",getpid(), fecha);
	
	signal(SIGINT,manejador);
	
	while(1)
	{
		pause();
	}
} 
