# Llamadas al sistema UNIX

---------------------------------

## Identificación de procesos

**PID del proceso**. Cada proceso tiene un ID, el proceso creador es el padre y el creado es el hijo. Para conocerlos **getpid()** y **getppid()**.

------------------------

## Creación de procesos

Unix utiliza un mecanismo de cración por copia:

* El proceso hijo es **una réplica exacta de su padre**.
* El proceso hijo **hereda** la mayoría de atributos del padre:
    - Imagen de memoria
    - UID, GID
    - Directorio actual
    - Descriptores de ficeros abiertos
* Unix asigna a cada proceso un PID
* Todo proceso conoce el identificador de su proceso padre: PPID
* La ejecución del hijo es concurrente e independiente
* En UNIX existe una **jerarquía de procesos**

El programa **fork** sirve para la creación de procesos con código idéntico al padre (es decir, un programa con un printf y un fork hará una impresión por pantalla y creará un hijo que imprimirá por pantalla también).

Para crear hijos que hagan cosas distintas a los padres se utiliza el **exec**, este carga el código de un nuevo programa en la imagen de memoria del proceso. De entre todas las variantes (execl, execlp, execle, execv, execvp, execve) la llamada genuina es **execv**.

------------------------

## Espera de procesos

Un padre debe esperar hasta que el hijo finalice. La llamada **wait** detiene la ejecución del padre hasta que el hijo acabe o hasta que se reciba una señal. La llamada **waitpid** espera a un hijo en particular.

----------------------

## Terminación de procesos

Con la llamada **exit** un proceso termina completamente, el valor que se le pasa como parámetro comunica la forma en la que el proceso ha acabado.

Un proceso **zombie** es aquel que finaliza antes de que el padre llame a **wait**. Un proceso **huérfano** es aquel cuyo padre ha acabado antes que el hijo, que es "adoptado" por el init.

----------------------------

## Señales

Una **señal** es el mecanismo que el SO usa para **informar a los procesos** de determinados sucesos.
