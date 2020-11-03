#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int number_of_files = 0;
  int file_descriptors[argc];
  char is_a_parameter = 0;
  char c;

  // Check whether we have -a and calculation number of files passed as arguments 
  // Also we assign unique number for all file_descriptors since in future we need to open files in right order
  if (argc >=2 ) {
    for (int i = 1; i < argc; i++) {
      if (strcmp(argv[i], "-a") == 0) {
         is_a_parameter = 1;
       } else {
         file_descriptors[number_of_files] = i;
         number_of_files++;
       }
     }
  }

  // Open files
  // O_RDWR means that we can read and write, O_APPEND means that we can append file)
  for (int i = 0; i < number_of_files; i++) {
     if (is_a_parameter == 1) {
       file_descriptors[i] = open(argv[file_descriptors[i]], O_RDWR | O_APPEND);
     } else {
       file_descriptors[i] = open(argv[file_descriptors[i]], O_RDWR);
     }
  }


  //Since we need also output to the stdout we are creting file_descriptor with STDOUT_FILENO;
  //We assign all the 'number_of_files - 1' file_descriptors and the file_descriptors[number_of_files) is used for stdout
  file_descriptors[number_of_files] = STDOUT_FILENO;

  // Read stdin, write to stdout and files
  // We put everything from STDIN_FILENO into variable c
  // Then we write c into every file
  while (read(STDIN_FILENO, &c, 1) > 0) {
     for (int i = 0; i <= number_of_files; i++) {
       write(file_descriptors[i], &c, 1);
     }
  }
  for (int i = 0; i < number_of_files; i++) {
      close(file_descriptors[i]);
  }
  return 0;
}
