#include <stdio.h>
#include <string.h>
int main(void){

 char arr[512];

 printf("Enter something: ");

 if (fgets(arr, sizeof arr, stdin)){
  for (int i = strlen(arr)-1; i >= 0; --i){
    printf("%c",arr[i]);
  }
  return 0;
 }
}
