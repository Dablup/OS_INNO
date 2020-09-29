#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void *my_own_realloc(void *ptr, size_t size){
    //If ptr is NULL, the call is equivalent to malloc(size)
    if (ptr == NULL){
        return malloc(size);

    //If size is equal to zero, the call is equivalent to free(ptr)
    } else if(size == 0){
        free(ptr);
        return NULL;

    //If pointer is not null and size is not 0 then we need to allocate memory for new array and copy the memory from the initial array to
    // new one. Then we need to deallocate the memory for the initial array and return new array.
    } else {
        char *new_array = malloc(size);
        memcpy(new_array,(char *)ptr, size);
        free(ptr);
        return new_array;
    }
}
int main(){
    //Testing
    //Creating array with the size of 10
    int *array = calloc(10,sizeof(int));
    //array = realloc(NULL,15*sizeof(int));
    //Fill in it with 1000's for every cell
    for (int i = 0; i < 10; i++){
        array[i] = 10005;
    }

    //Printing
    for (int i = 0; i < 10; i++){
        printf("%d ",array[i]);
    }

    //Reallocate the memory for the array of size 15
    array = my_own_realloc(array,15* sizeof(int));

    //Fill in new cells with 0
    for (int i = 10; i < 15;i++){
        array[i] = 0;
    }

    //Printing the array with new elements
    printf("\nAfter reallocationg memory\n");
    for (int i = 0; i < 15; i++){
        printf("%d ",array[i]);
    }

    //Test case if size is 0
    printf("\nFree the array:\n");
    array = my_own_realloc(array,0);
    printf("The memory has been freed\n");

    //Test case if ptr is NULL
    printf("Array with NULL ptr: \n");
    array = my_own_realloc(NULL, 15*sizeof(int));
    for (int i = 0; i < 15; i++){
        printf("%d ",array[i]);
    }



}
