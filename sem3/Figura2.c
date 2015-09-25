#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

/* En este ejemplo padre e hijo ejecutan distinto codigo */

int main(){
    pid_t val;
    int var = 0;
    printf("PID antes fork(): %d\n", (int)getpid());

    if(val = fork()){
        printf("Padre PID: %d\n", (int)getpid());
        var++;
    } else {
        printf("Hijo PID: %d\n", (int)getpid());
    }
    printf("Proceso [%d]-> var=%d\n", (int)getpid(), var);
    return 0;
}
