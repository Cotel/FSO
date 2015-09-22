#include <stdio.h>

int a = 0; /* variable global */

// Esta función incrementa el valor de la variable global en 1
void inc_a(void) {
    // int a; No hay que iniciar otra variable con el mismo nombre de forma local para no liar al programa
    a++;
}

/* Esta función devuelve el valor anterior
    y guarda el nuevo valor v */
int valor_anterior(int v) {
    int temp;
    // declarar aquí la variable s estática.
    static int s;
    temp = s;
    s = v;
    // return b; No funciona porque b es variable local en main
    return temp;
}

void main() {
    int b = 2;
    inc_a();
    valor_anterior(b);
    printf("a= %d, b= %d\n", a, b);
    a++;
    b++;
    inc_a();
    b = valor_anterior(b);
    printf("a= %d, b= %d\n", a, b);
}
