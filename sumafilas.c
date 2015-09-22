#include <stdio.h>
#define TAM_FILA 100
#define NUM_FILAS 10

struct FILA {
  float datos[TAM_FILA];
  float suma;
};
// A) Define una variable filas que sea un vector de estructuras FILA de tamaño NUM_FILAS
struct FILA filas[NUM_FILAS];

void suma_fila(struct FILA *pf) {
  // B) Implementar suma_fila
  int i;
  for(i = 0; i<TAM_FILA; i++){
      pf->suma += pf->datos[i];
  }
}
// Inicia las filas con el valor i*j
void inicia_filas() {
  int i, j;
  for (i = 0; i < NUM_FILAS; i++) {
    for (j = 0; j < TAM_FILA; j++) {
      filas[i].datos[j] = (float)i*j;
    }
  }
}
main() {
  int i;
  float suma_total;
  inicia_filas();
  // C) Completar bucle
  suma_total = 0;
  for (i = 0; i < NUM_FILAS; i++) {
    // Llamar a suma_fila
    suma_fila(&filas[i]);
    printf("La suma de la fila %d es %f\n", i, filas[i].suma);
    // sumar la fila a suma_total
    suma_total += filas[i].suma;
  }
  printf("La suma final es %f\n", suma_total);
}
