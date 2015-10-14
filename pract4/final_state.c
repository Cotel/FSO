#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
  int final_state;
  pid_t val_return;

  for (int i=0; i<4; i++)
  {
    val_return= fork();
    if (val_return==0)
    {
      printf("Son %ld created in iteration %d\n", (long) getpid(),i);
      sleep(1);
      exit(i);
    } else
    {
      printf("PID: %d. stat_loc: %d\n", wait(&final_state), final_state);

    }
  }
}
