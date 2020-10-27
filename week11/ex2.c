#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
  char *str = "Hello";
  // when we are using printf we insert characters into the buffer and this buffer will be flushed only when the programm exit.
  for (int i = 0; i < 5; ++i) {
    printf("%c",str[i]);
    sleep(1);
   }
  return 0;
}


