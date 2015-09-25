#include <stdio.h>
#include <unistd.h>

/* En este ejemplo padre e hijo ejecutan el mismo codigo */

int main(void){
    printf("Proceso %ld crea otro proceso\n", (long)getpid());
    fork();
    printf("Proceso %ld con padre %ld\n", (long)getpid(), (long)getppid());
    sleep(5);
    return 0;
}
