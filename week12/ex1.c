#include <stdio.h>

int main(){

  char line[20];

  FILE *file_for_random = fopen("/dev/random","r");
  FILE *file_for_output = fopen("ex1.txt","w");

  fgets(line,20,file_for_random);
  fprintf(file_for_output,"%s",line);

  fclose(file_for_random);
  fclose(file_for_output);


  return 0;


}
