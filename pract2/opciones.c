#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[]) {
    if(argc < 2 || argc > 4) {
        printf("-c  Mostrará 'Compilar'\n");
        printf("-E  Mostrará 'Preprocesar'\n");
        printf("-i/ruta  Mostrará 'Incluir + ruta'\n");
    } else {
        int i;
        for(i=1; i<argc; i++){
            printf("Argumento %d es ", i);
            char* route;
            switch (argv[i][1]) {
                case 'c':
                    printf("Compilar\n");
                    break;
                case 'E':
                    printf("Preprocesar\n");
                    break;
                case 'i':
                    route = malloc(sizeof(argv[i]+1));
                    strcpy(route, argv[i]+2);
                    printf("Incluir %s\n", route);
                    break;
                default:
                    printf("Argumento no válido\n");
            }
        }
    }
}
