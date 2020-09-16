#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(){
  char str[100];
  printf(">");
  while(scanf("%s",str) > 0){
     if (strcmp(str,"quit") == 0){
	printf("See you later in Dablup's shell\n");
	return 0;
     }
     system(str);
     printf(">");
  }

 return 0;



}
