/*
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 1  1  34896 776296   5588 104096    0    6     1     8    4    7  0  1 99  0  0
 0  0  34888 678652   5588 104104    8    0     8     0   34  388  1  2 97  1  0
 0  0  34888 576164   5588 104104    0    0     0     0   51  474  1  4 96  0  0
 0  0  34888 473552   5588 104104    0    0     0     0   38  429  1  3 97  0  0
 1  0  34888 370940   5588 104104    0    0     0     0   37  443  1  2 98  0  0
 0  0  34888 268312   5588 104104    0    0     0     0   23  343  1  3 97  0  0
 0  1  34888 165640   5596 104096    0    0     0    60   37  372  0  4 96  1  0
 0  0  34888  63216   5596 104104    0    0     0     0   36  418  0  3 94  3  0
 0  0 125156  74988   1388  79444   88 90280   264 90292 6041 1350  0 18 71 10  0
 0  0 239108  77652    952  78760  344 114144   348 114144 7750 1149  1 18 70 12  0
 2  0 260628  52072    552  77100    0 22356     0 22356 3229  579  1  7 93  0  0
 0  0 363684  95376    552  77048    0 102224     0 102224 3531  814  0 12 84  4  0
 0  0  35412 812576    556  77436   44    0   436     0   41  399  0  2 97  1  0
 0  0  35412 812576    564  77436    0    0     0    20   55  437  0  1 96  4  0
 0  0  35412 812576    564  77436    0    0     0     0   42  362  0  0 100  0  0

Using this table we can see that when the free virtual memory is not enough to allocate 100 MB then we swap 90280 B FROM the DISK to the swapped memory. 

*/


#include <stdio.h>
#include <string.h>
int main(void) {
  //100 MB = 104857600 B;
  for (int i =0;i<10;i++){
    void *allocation_part = malloc(104857600);
    if (allocation_part != NULL){
        memset(allocation_part,0,104857600);
       // printf("Allocation 10 Mb memory for %d time\n", i);
    }else if (allocation_part == NULL){
      printf("I can not allocate memory!");
    }
    sleep(1);
  }
  return 0;
}