/** Programa de ejemplo "Hola mundo" con pthreads.
* Para compilar: gcc hola.c -lpthread -o hola
**/

#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

void *Imprime(void *ptr) {
    char *men;
    men = (char*)ptr;

    //Ejercicio1.b
    usleep(2000000);
    write(1,men,strlen(men));
}

int main() {
    pthread_attr_t attrib;
    pthread_t hilo1, hilo2;

    pthread_attr_init(&attrib);

    pthread_create(&hilo1, &attrib, Imprime, "Hola \n");
    pthread_create(&hilo2, &attrib, Imprime, "mundo \n");

    //Ejercicio1.a
    usleep(1000000);
    // pthread_exit(0);
    // pthread_join(hilo1, NULL);
    // pthread_join(hilo2, NULL);
}
