#include <stdio.h>
#include <stdlib.h>
int main() {
    int N = 0;
    //Ask user to enter the size of the array
    printf("Please enter the size of the array:");
    scanf("%d",&N);

    //Dynamically allocate memory for the array of size N
    int *array = malloc(N*sizeof(int));

    //Fill in the array with values from 0 to N
    for (int i =0; i< N; i++){
        array[i] = i;
    }

    //Printing the array
    printf("Printing the array:\n");
    for (int i = 0; i < N; i++){
        printf("%d ",array[i]);
    }

    //Deallocate memory that we used for the array
    printf("\n\nAnd now we deallocate the memory\n");
    free(array);
    return 0;
}

