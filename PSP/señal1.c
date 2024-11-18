#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int tiempo;

void manejador()
{
tiempo=tiempo+5;
printf("Han transcurrido %d segundos \n",tiempo);

}

 void main() 
{ 
	signal(SIGALRM,manejador);
	
	alarm(5);
	
	while(1)
	{
		pause();
	}
} 
