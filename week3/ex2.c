#include <stdio.h>
void bubble_sort(int *arr, int size){
    int temp;
    for (int i = 0; i < size; i++){
        for(int j = 0; j < size-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int main() {
    int size;
    printf("Please enter the size of the array:");
    scanf("%d",&size);
    int arr[size];
    printf("Enter the elements of the array:");
    for (int i = 0; i < size; i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,size);
    printf("The array after sorting is: ");
    for (int i = 0; i < size; i++){
        printf("%d ",arr[i]);
    }
    return 0;
}

