#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define COLUMNS 80
#define ROWS 25

char m[ROWS][COLUMNS];
long delay[COLUMNS];
int row_b[COLUMNS];

pthread_attr_t attrib;
pthread_t draw_thread[COLUMNS];
pthread_t erase_thread[COLUMNS];
pthread_t refresh_thread;

void *EraseCol(void *ptr) {
    int row, col=(int) (long)ptr;

    for(row=0; row<ROWS; row++) {
        m[row][col] = ' ';
        usleep(delay[col]);
    }
}

void *DrawCol(void *ptr) {
    int row, col=(int) (long)ptr;

    delay[col] = 50000+rand()%450000;
    if(rand()%10 > 4) {
        usleep(delay[col]*ROWS);
    } else {
        for(row=0; row<ROWS; row++) {
            row_b[col] = row;
            m[row][col] = 32+rand() %94;
            usleep(delay[col]);
        }
    }
}

void *Refresh (void *ptr) {
    int row, col;
    char order[20];
    while(1) {
        write(1,"\033[1;1f\033[1;40;32m",16); // Back to left-up corner, Green text
        for (row=0; row<ROWS; row++) {
            write(1,m[row],COLUMNS); write(1,"\n",1); // Refresh row
        }
        write(1,"\033[1;37m",7); // White text
        for (col=0; col<COLUMNS; col++) {
            sprintf(order,"\033[%d;%df%c",row_b[col]+1,col+1,m[row_b[col]][col]);
            // Rewrite in white the last character in column col
            if (row_b[col]<ROWS-1) write(1,order,strlen(order));
        }
        usleep(100000);
        // Wait 0,1s before refreshing again
    }
}

int main() {
    int col;
    memset(m, ' ', ROWS*COLUMNS);
    write(1, "\033[2J\033[?251", 10);

    pthread_attr_init(&attrib);

    // Crear un hilo que dibuje cada columna
    for(col=0; col<=COLUMNS; col++) {
        pthread_create(&draw_thread[col], &attrib, DrawCol, (long)col);
    }

    // Crear un hilo que refresque la pantalla
    pthread_create(&refresh_thread, &attrib, Refresh, NULL);

    // Esperar a todos los hilos que dibujan
    for(col=0; col<COLUMNS; col++){
        pthread_join(draw_thread[col], NULL);
    }
    //pthread_join(refresh_thread, NULL);

    write(1, "\033[0m\033[?25h\r",11);
}
