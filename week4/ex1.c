#include "stdio.h"
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
 int n;
 sscanf(argv[1],"%d",&n);
 int id = fork();
 if (id == 0){
  printf("Hello from child [%d - %d]\n",getpid(),n);
 } else if (id > 0){
  printf("Hello from parent [%d - %d]\n",getpid(),n);

 }

  return 0;
}
