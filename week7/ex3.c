#include <stdlib.h>
#include <stdio.h>


int main(){
    //Allows you to generate random number
    srand(time(NULL));

    // Allows user to specify the original array size, stored in variable n1.
    printf("Enter original array size:");
    int n1=0;
    scanf("%d",&n1);

    //Create a new array of n1 ints
    int* a1 = malloc(n1 * sizeof(int));                         // Here I wrote malloc(n1 * sizeof(int)) to allocate memory for the array dynamically
    int i;
    for(i=0; i<n1; i++){
        //Set each value in a1 to 100
        a1[i]=100;                                              //Here we just set each value in a1 to 100

        //Print each element out (to make sure things look right)
        printf("%d ",a1[i]);
    }

    //User specifies the new array size, stored in variable n2.
    printf("\nEnter new array size:");
    int n2=0;
    scanf("%d",&n2);

    //Dynamically change the array to size n2
    a1 = realloc(a1, n2 * sizeof(int));                         //Here we are reallocating the memory for array with new size n2

    //If the new array is a larger size, set all new members to 0. Reason: dont want to use uninitialized variables.

    if (n2 > n1){						//Checking if the n2 is bigger than n1, if so then set values of array from n1 to n2 to 0.
        for (int i = n1;i < n2; i++){
            a1[i] = 0;
        }
    }


    for(i=0; i<n2;i++){
        //Print each element out (to make sure things look right)
        printf("%d ",a1[i]);
    }
    printf("\n");

    //Done with array now, done with program :D

    return 0;
}

