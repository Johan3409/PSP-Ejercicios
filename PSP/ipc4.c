
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> 
 #include <time.h>


//padre escribe, hiijo lee y escribe segun lo que le pasa el padre. 0 leer, 1 escribir
int factorial(int numero)
{
	int resultado=1;
	for(int i=1; i<=numero;i++)
	{
		resultado=resultado*i;
	}
	return resultado;
}


int numeroA;
void main()
{
    int fd1[2];
    int fd2[2];
    char buffer[30];

    pid_t pid;
    pipe (fd1);
    pipe (fd2);

    pid = fork();
    if (pid == 0)
    {
    	int numero1;
    	close(fd1[1]);
    	read(fd1[0],&numero1,10);
    	
    	int factorialN=factorial(numero1);
    	close(fd2[0]);
	write(fd2[1],&factorialN, 10);
    	
      
    }
    else
    {
     	time_t t;
 	int numeroA;
	srand((unsigned) time(&t));
	numeroA=rand() % 10; 
	close(fd1[0]);
	write(fd1[1],&numeroA, 10);
	printf("EL proceso padre genera el numero %d en el pipe 1\n",numeroA);
	wait(NULL);
	
	int resultado;
    	close(fd2[1]);
    	read(fd2[0],&resultado,10);
    	printf("El factorial calculado por el proceso hijo: %d != %d\n",numeroA,resultado);
	
    }
   
}

