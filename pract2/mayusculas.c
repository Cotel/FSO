#include <stdio.h> 
#define TAM_CADENA 200
main() {
  // Puntero a caracter para copiar las cadenas
  char *p1, *p2;
  // A) Definir las variables cadena y cadena2 
  char cadena[TAM_CADENA], cadena2[TAM_CADENA];
  // B) Leer cadena de consola
  scanf("%s", cadena);
  // C) Convertir a mayúsculas
  p1 = cadena;
  p2 = cadena2;
  while(*p1 != '\0'){
    if(*p1 >= 97 && *p1 <= 122) {
      *p2 = *p1 - 32;
    } else {
      *p2 = *p1;
    }
    p1++;
    p2++;
  }
  // D) Sacar por consola la cadena2.
  printf("%s\n", cadena2);
}