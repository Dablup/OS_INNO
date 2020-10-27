#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

  //Opening the file 
  int opened_file = open("ex1.txt",O_RDWR);

  //Creating struct stat for the getting the size of the file
  struct stat statistic;

  //Getting information about opened_file
  fstat(opened_file, &statistic);

  //Creating a new mapping in the virtual memory
  //addr is NULL => kernel chooses the address at which to create a mapping
  char *mapping_in_virtual_memory;
 
  mapping_in_virtual_memory = mmap(NULL,sizeof(char)*18,PROT_WRITE,MAP_SHARED,opened_file,0);
 
  ftruncate(opened_file,sizeof(char)*18);


  //We are copying the string to the mapping in virtual memory, number(st_size) of bytes are copied.
  memcpy(mapping_in_virtual_memory,"This is a nice day", sizeof(char)*18);

  //Deleting mappings
  munmap(mapping_in_virtual_memory,statistic.st_size);

  //Closing file
  close(opened_file);

  return 0;


}
