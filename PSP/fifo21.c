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

void main() {
  int p;
  int fp, fp1;
  
  p=mkfifo("FIFO02", S_IFIFO|0666);//CREA FIFO02 CON PERMISOS DE LEER Y ESCRIBIR
  
   time_t t;
   int numero;
   srand((unsigned) time(&t));
   numero=rand() % 10; 
  
  
  fp=open("FIFO02", 1);
  write(fp,&numero,sizeof(numero));
  close(fp);
  
  fp1=open("FIFO02",0);
  int numF;
  read(fp1,&numF,sizeof(numF));
  printf("El resultado es %d\n",numF);
  close(fp1);
  
  unlink("FIFO02");
}

