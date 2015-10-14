#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  for (int i=1; i<=5; i++)
  {
    int val_return = fork();
    if (val_return==0)
    {
      printf("Hijo creado en iteración= %d",i);
      exit(i);
      break;
    }
    int returnStatus;
    waitpid(val_return, &returnStatus, 0);
  }
  sleep(10);
  exit(0);
  return 0;
}
