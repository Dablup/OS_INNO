#include <stdio.h>

void swapFunction(int *n1, int *n2){
 int temp = *n1;
 *n1 = *n2;
 *n2 = temp;
}

int main(void){
 int n1 , n2;
 printf("Please enter two numbers ");
 scanf("%d%d",&n1,&n2);
 printf("You entered n1 = %d and n2 = %d \n", n1,n2);
 printf("Now we are using swap function\n"); 
 swapFunction(&n1,&n2);
 printf("Printing n1 = %d and n2 =  %d \n",n1,n2);

}
