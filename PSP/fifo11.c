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
 p=mkfifo("FIFO1", S_IFIFO|0666 );
 

 time_t t;
 int numero1;
 srand((unsigned) time(&t));
 numero1=rand() % 10; 
 
 printf("Escribiendo en FIFO1\n");
 
 fp=open("FIFO1",1);
 
 write(fp,&numero1,sizeof(numero1));
 close(fp);
 
 fp1=open("FIFO2",0);
 int mos;
 read(fp1,&mos,sizeof(mos));
 printf("El resultado es: %d\n",mos);
 close(fp1);
}

