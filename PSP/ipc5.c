
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 
#include <time.h>
#include <string.h> 
 #include <time.h>	



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
    	int dniS;
    	char resultado;
    	printf("Introduce el número de tu DNI:\n");
    	scanf("%d", &dniS);
    	
    	close(fd1[0]);
    	write(fd1[1],&dniS,10);
    	close(fd1[1]);
    	
    	close(fd2[1]);
    	read(fd2[0],&resultado,sizeof(resultado));
    	close(fd2[0]);
    	
    	printf("la letra del NIF es %c\n",resultado);
    
    }
    else
    {
    	

	int dniN;
    	close(fd1[1]);
    	read(fd1[0],&dniN,10);
    	 close(fd1[0]);
    	int dni;
	char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
	dni = dniN;
	dni %= 23;
	
	char letraD=letra[dni];
	
	close(fd2[0]);
    	read(fd2[1],&letraD,sizeof(letraD));
    	close(fd2[1]);
    	wait(NULL);
	
    }
   
}

