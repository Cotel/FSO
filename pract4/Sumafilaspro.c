#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIMFILA 100
#define NUMFILAS 20

typedef struct fila{
        int vector[DIMFILA];
        long suma;
} fila;

fila matriz[NUMFILAS];


int main()
{
  int i,j,k;
  long suma_total=0;
  

  //se inicializan a 1 todos los elementos de todos los vectores
  for(i=0;i<NUMFILAS;i++) {
      for(j=0;j<DIMFILA;j++) 
         matriz[i].vector[j]=1;
         matriz[i].suma=0;
      
  }
  

  //Se suman todas las filas y se rellena matriz
  for(i=0;i<NUMFILAS;i++){
    int val_result = fork();
    if(val_result==0){
      for(k=0;k<DIMFILA; k++){
        matriz[i].suma += matriz[i].vector[k];
      }
      printf("La suma de la fila %ld es %ld\n",i,matriz[i].suma);
      exit(matriz[i].suma);
    }
    int status;
    wait(&status); 
    printf("Status de %ld: %ld\n", i, status);
    suma_total += status;
  }
  printf(  "La suma es %ld\n",suma_total);

}

