#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
   pid_t pid1, pid2;

    // Primer fork: Creación del primer hijo (P2)
    pid1 = fork();
    if (pid1 == -1) {
        printf("ERROR al crear el primer hijo\n");
        exit(1);
    }

    if (pid1 == 0) {  // Proceso hijo 1 (P2)
        sleep(10);
        printf("Despierto\n");
       
    }

    // Segundo fork: Creación del segundo hijo (P3)
    pid2 = fork();
    if (pid2 == -1) {
        printf("ERROR al crear el segundo hijo\n");
        exit(1);
    }

    if (pid2 == 0) {  // Proceso hijo 2 (P3)
        printf("Soy el proceso hijo mi pid es: %d\n", getpid());
        printf("Soy el proceso padre mi pid es: %d\n", getppid());
      
    }

    // Proceso padre (P1)
    wait(NULL);  // Espera a que el primer hijo termine
    wait(NULL);  // Espera a que el segundo hijo termine
    printf("Soy el proceso padre. Mi PID es: %d\n", getpid());
}

