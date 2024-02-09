#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertionSort(char *arr[], int array_size) {
    
    int i,j;
    char *temp;

    for (i = 1; i < array_size; i++) { //iterate over the array from the second position to the last
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && strcmp(arr[j], temp) > 0) { //while the previous element is greater than or equal to 0 and strcmp() outputs the previous element's ASCII value is greater than the first
            arr[j + 1] = arr[j]; //shift characters
            j--; //iterate down one
        }
        arr[j + 1] = temp;
    }
}

void main() {
    
    int array_size;
    printf("Please enter the number of elements for the array: \n");
    scanf("%d",&array_size); //take user input as character array

    char **arr = (char**) malloc(array_size * sizeof(char *));
    for (int i = 0; i < array_size; i++) { //take user input as many times as the array size
        printf("Please enter element %d of array: \n",(i+1));
        char input[100]; //assuming a maximum input length of 100 characters
        scanf("%s",input); //take user input as character array
        arr[i] = strdup(input); //set index in array to converted user input
    }
    printf("The array before sorting is: \n");
    for (int i = 0; i < array_size; i++) { //print each element in the array
        printf("%s\n",arr[i]);
    }
    insertionSort(arr,array_size);

    printf("The array after sorting is: \n");
    for (int i = 0; i < array_size; i++) { //print each element in the array
        printf("%s\n",arr[i]);
    }
}