#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  printf("Father process %ld \n", (long)getpid());
  fork();
  printf("I am %ld process, my father is %ld\n",(long)getpid(), (long)getppid());
  sleep(15);
  return 0;
}
