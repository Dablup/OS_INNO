#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

int main(){

  //Opening the files
  int initial_file = open("ex1.txt",O_RDWR);
  int file_to_copy = open("ex1.memcp.txt",O_RDWR);

  //getting the statistic of the ex1.txt file
  struct stat statistic;
  fstat(initial_file,&statistic);


  //Creating a mapping in the virtual adress space
  char *mapping_for_first_file, *mapping_for_second_file;
  mapping_for_first_file =  mmap(NULL, sizeof(char)*18, PROT_READ, MAP_SHARED, initial_file,0);
  mapping_for_second_file = mmap(NULL, sizeof(char)*18, PROT_WRITE, MAP_SHARED, file_to_copy,0);
  
  ftruncate(initial_file,sizeof(char)*18);
  ftruncate(file_to_copy,sizeof(char)*18);
  //Copying the n bytes from memory area of the first file to the memory area of the second file
  memcpy(mapping_for_second_file,mapping_for_first_file,sizeof(char)*18);

  //Deleting the mappings for the adresses
  munmap(mapping_for_first_file,statistic.st_size);
  munmap(mapping_for_second_file,statistic.st_size);

  //Closing files
  close(initial_file);
  close(file_to_copy);
  return 0;
} 
