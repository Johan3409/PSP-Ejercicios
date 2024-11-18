#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int sonar;
int repetir;
int i=0; 
void manejador()
{
	time_t ahora = time(NULL);
	struct tm *horaLocal = localtime(&ahora);
	printf("Señal de alarma recibida a las:  %02d:%02d:%02d\n",
           horaLocal->tm_hour,
           horaLocal->tm_min,
           horaLocal->tm_sec);  
        
        i=i+1;   
        if(i<sonar)
        {
        	alarm(repetir);
        }  
        else
        {
        	printf("Alarma desactivada\n");
        	exit(0);
        
        }
}

 void main() 

{	
	
	printf("¿Cuántas veces sonará la alarma?\n");
	scanf("%d",&sonar);
	printf("¿Cada cuántos segundos se repetirá la alarma?\n");
	scanf("%d",&repetir);
	
	printf("Alarma activada\n");
	
	signal(SIGALRM,manejador);
	alarm(repetir);
	
	
	
	while(1)
	{
		pause();
	}
} 
