#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(int arr[], int array_size) {
    
    int i, temp;

    for (i = 1; i < array_size; i++) { //iterate over the array from the second position to the last
        while (i > 0 && arr[i-1] > arr[i]) { //while the current position is greater than 0 and less than the next position
            temp = arr[i]; //set temp value to current value
            arr[i] = arr[i - 1]; //swap current for next 
            arr[i-1] = temp; //swap next for temp (current)
            i--; //iterate down one
        }
    }
}

int main() {
    
    char *input_array_size = malloc(100); //allocate 100 bytes for character pointer

    printf("Please enter the number of elements for the array: \n");
    fgets(input_array_size, 100, stdin); //take user input as character array 
    int array_size = atoi(input_array_size); //convert char array to int
    char* str = malloc(100); //allocate 100 bytes for character pointer
    int arr[array_size]; //initialize array
    for (int i = 0; i < array_size; i++) { //take user input as many times as the array size
        printf("Please enter element %d of array: \n",(i+1)); 
        fgets(str, 100, stdin); //take user input as character array
        arr[i] = atoi(str); //set index in array to converted user input
    }
    printf("The array before sorting is: \n");
    for (int i = 0; i < array_size; i++) { //print each element in the array
        printf("%d\n",arr[i]);
    }
    insertionSort(arr,array_size);

    printf("The array after sorting is: \n");
    for (int i = 0; i < array_size; i++) { //print each element in the array
        printf("%d\n",arr[i]);
    }
}