#include <stdio.h> 
#include <signal.h> 
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int tiempo;

void manejador()
{
	  time_t ahora = time(NULL);
	FILE *fichero=fopen("Fichero.txt","a");
	
	struct tm *horaLocal = localtime(&ahora);
	fprintf(fichero,"Señal SIGNINT recibida a las:  %02d:%02d:%02d\n",
           horaLocal->tm_hour,
           horaLocal->tm_min,
           horaLocal->tm_sec);
        printf("Señal SIGNINT recibida a las:  %02d:%02d:%02d\n",
           horaLocal->tm_hour,
           horaLocal->tm_min,
           horaLocal->tm_sec);
        fclose(fichero);
           
           

}

 void main() 
{ 
	signal(SIGINT,manejador);
	
	while(1)
	{
		pause();
	}
} 
