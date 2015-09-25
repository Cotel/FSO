#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>

#define NPROCESOS 4

/* Se crean hijos de 1 en 1 en forma de cascada y no de arbol */

int main(void) {
    pid_t pid;
    int i;
    for(i=0; i<NPROCESOS; i++) {
        pid = fork();
        if(pid != 0) break;
        printf("Soy el hijo con PID %ld con padre %ld\n",
            (long)getpid(), (long)getpid());
    }
    sleep(5);
    return 0;
}
