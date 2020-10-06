
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void) {
  //100 MB = 104857600 B;
  struct rusage our_rusage;
  for (int i =0;i<10;i++){
    void *allocation_part = malloc(104857600);
    if (allocation_part != NULL){
        memset(allocation_part,0,104857600);
	if (getrusage(RUSAGE_SELF, &our_rusage) == 0) {
		printf("%ldKB\n", our_rusage.ru_maxrss);
	}
       // printf("Allocation 10 Mb memory for %d time\n", i);
    }else if (allocation_part == NULL){
      printf("I can not allocate memory!");
    }
    sleep(1);
  }
  return 0;
}



