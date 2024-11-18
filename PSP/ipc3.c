
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> 
 #include <time.h>


//padre escribe, hiijo lee y escribe segun lo que le pasa el padre. 0 leer, 1 escribir
void main()
{
    int fd[2];
    char buffer[30];

    pid_t pid;
    pipe (fd);

    pid = fork();
    if (pid == 0)
    {
        time_t t;
 	int numero1;
 	int numero2;
	srand((unsigned) time(&t));
	//Generamos numero aleatorio entre 1 y 50
	numero1=rand() % 50; 
	numero2=rand() % 50;
	
	close(fd[0]);
	write(fd[1],&numero1, 10);
	write(fd[1],&numero2, 10);
    }
    else
    {
      int numero1, numero2;
      wait(NULL);
      close(fd[1]);
      read(fd[0],&numero1,10);
      
      read(fd[0],&numero2,10);
      
      int suma=numero1+numero2;
      int resta=numero1-numero2;
      int multiplicacion=numero1*numero2;
      int division=numero1/numero2;
      
      printf("%d + %d = %d\n",numero1,numero2,suma);
      printf("%d - %d = %d\n",numero1,numero2,resta);
      printf("%d * %d = %d\n",numero1,numero2,multiplicacion);
      printf("%d / %d = %d\n",numero1,numero2,division);
 	
    }
   
}

