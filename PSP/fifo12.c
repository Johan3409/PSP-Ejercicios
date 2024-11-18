#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h> 
int factorial(int numero)
{
	int resultado=1;
	for(int i=1;i<=numero;i++)
	{
		resultado=resultado*i;
	}
	return resultado;
}


void main() {
  int fp, fp1;
  int p;
  
  p=mkfifo("FIFO2", S_IFIFO|0666);
  
  printf("Escribiendo en el FIFO2\n");
    
  fp=open("FIFO1", 0);
  int resultado;
  read(fp,&resultado,sizeof(resultado));
  close(fp);
  
  int numFac=factorial(resultado);
  
  fp1=open("FIFO2",1);
  
  write(fp1,&numFac,sizeof(numFac));
  close(fp1);
}

