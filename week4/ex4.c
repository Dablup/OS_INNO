/*
   In this programm we use getline to get line untill \0 but not untill first space.
   That is why now we can pass arguments with command and run a process in a background.

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(void){
  printf("Press CTRL+Z to quit from the programm.\n");
  while (1){
    printf(">");
    char *command;
    size_t commandSize = 100;
    command  = (char *)malloc(commandSize * sizeof(char));
    getline(&command, &commandSize, stdin);
    system(command);
  }

  return 0;
}
