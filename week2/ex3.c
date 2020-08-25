#include <stdio.h>

int main(int argc, char *argv[]){
 int n;
 sscanf(argv[1], "%d", &n);
 for (int i = 1; i < n + 1; i++){
   int numberOfSpaces = n  - i;
   int  numberOfStars = 2*i - 1;
   for (int j = 0; j < numberOfSpaces; j++){
    putchar(' ');
   }
   for (int j = 0; j < numberOfStars; j++){
    putchar('*');
   }
   putchar('\n');
 }
}

