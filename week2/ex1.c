#include <stdio.h>
#include <float.h>
#include <limits.h>

int main(void){

 int integerVariable;
 float floatVariable;
 double doubleVariable;

 integerVariable = INT_MAX;
 floatVariable = FLT_MAX;
 doubleVariable = DBL_MAX;

 // Print sizes and values of i, f and d
 printf("Size of integerVariable is %lu and the value is %d\n",sizeof(integerVariable),integerVariable);
 printf("Size of floatVariable is %lu and the value is %f\n", sizeof(floatVariable), floatVariable);
 printf("Size of doubleVariable is %lu and the value is %f\n",sizeof(doubleVariable),doubleVariable);

 return 0;

}
