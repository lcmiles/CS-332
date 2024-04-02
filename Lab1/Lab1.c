#include <stdio.h>
#include <stdbool.h>

/*
Description: Checks if given_number is even 
Parameters: int *given_number pointer
Returns: boolean true or false value based on modulo
Sources: https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c
*/
bool isEven(int given_number) {
    return(given_number % 2 == 0); //uses modulo to check if even, returning true if so and false if not
}

/*
Description: Uses a pointer to check if given_number is an int. Also takes user input using scanf()
Parameters: int *given_number pointer
Returns: boolean true or false value based on the modulo
*/
bool isInteger(int *given_number) { //parameter is pointer towards given_number
    if (scanf("%d", given_number) == 1) { //checks if the user input is an int
        return true;
    }
    else {
        return false;
    }
}

/*
Description: Driver code responsible for printing different cases and calling other two functions 
Parameters: None
Returns: 0
*/
int main() {
    int given_number;
    printf("Please enter an integer.\n");
    if (isInteger(&given_number)) { //if the value of the pointer towards given_number is an int then the other if statement executes
        if (isEven(given_number)) { //prints correct statement based on the boolean output of isEven()
        printf("The number is an even number.\n");
        }
        else printf("The number is an odd number.\n");
    }
    else {
        printf("Invalid input. Please enter an integer.\n"); 
    }
    return 0;
}