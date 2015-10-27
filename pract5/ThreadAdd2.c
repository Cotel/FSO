/** Programa SequentialAdd.c
* Para compilar: gcc SequentialAdd.c -o SeqAdd -lm
**/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define DIMROW 1000000
#define NUMROWS 20
#define CORES sysconf(_SC_NPROCESSORS_ONLN)

typedef struct row {
    int vector[DIMROW];
    long addition;
} row;

struct row matrix[NUMROWS];

void *AddRow(void *ptr) {
    int k;
    row *fi;
    fi = (row *)ptr;

    fi->addition = 0;
    for(k=0; k<DIMROW; k++) {
        fi->addition += exp((k*(fi->vector[k])+(k+1)*(fi->vector[k]))/(fi->vector[k]+2*k))/2;
    }
}

int main() {
    int i,j;
    long total_addition = 0;
    pthread_t threads[NUMROWS];
    pthread_attr_t attrib;

    //Elementos del vector inicializados a 1
    for(i=0; i<NUMROWS; i++) {
        for(j=0; j<DIMROW; j++) {
            matrix[i].vector[j] = 1;
        }
    }

    //Inicializacion de los atributos de los hilos
    pthread_attr_init(&attrib);

    // Ejercicio2.a
    for(i=0; i<NUMROWS; i+=CORES) {
        for(j=0; j<CORES; j++)
            pthread_create(&threads[j], &attrib, AddRow, &matrix[i+j]);
          //  usleep(20000);
         for(j=0; j<CORES; j++)
            pthread_join(threads[j], NULL);
    }

    for(i=0; i<CORES; i++) {
        for(j=0; j<CORES; j++)
            pthread_join(threads[i], NULL);
    }

    //Ejercicio2.b
    for(i=0; i<NUMROWS; i++) {
        total_addition += matrix[i].addition;
    }

    printf("La suma total es: %ld \n", total_addition);
    //printf("Numero de cpus: %d\n", CORES);
}
