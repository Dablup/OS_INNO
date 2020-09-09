#include <stdlib.h>
#include <stdio.h>

int main(){
  char str[100];
  printf(">");
  while(scanf("%s",str) > 0){
     system(str);
     printf(">");
  }

 return 0;



}
