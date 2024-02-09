#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

bool primeCheck(int n) {
    int flag = 1;
    for (int i = 2; i <= sqrt(n); i++) { //iterate from 2 to the square root of the number
        if (n % i == 0) { //check if the number divided by the current iterator is a whole number
            flag = 0; //if so set the flag to false and break the loop
            break;
        }
    }
    if (flag == 1) { //if the flag is unchanged return true
        return true;
    }
    else return false;
}


char* numberTransform(int n) { 
    char return_phrase[] = "Go Blazers"; //initialize return string
    if (primeCheck(n) == true && n != 3 && n != 5) { //if the number is prime and is not 3 or 5
        printf("%s\n",return_phrase);
        return return_phrase;
    }

    if (ceil(log2(n)) == floor(log2(n))) { //if the rounded up value of the base 2 log of the number is the same as it is rounded down
        int i;
        int result;
        for (i = 0 ;; i++) { //iterate forward until a prime number is found then break
            if (primeCheck(n-i)) {
                break;
            }
        }
        result = (n - i) + n; //add the prime number and the number
        printf("%d\n",result); 
        sprintf(return_phrase,"%d",result); //set the return phrase to the result
        return return_phrase;
    }

    if (n % 3 == 0 && n % 5 == 0) { //if the number is divisible by 3 or 5
        char return_phrase[] = "UAB CS 332&532"; //change return phrase and return it
        printf("%s\n",return_phrase);
        return return_phrase;
    }

    int digit_sum = 0;
    while (n > 0) { //while the number is greater than 0
        int digit = n % 10; //take the current highest digit
        digit_sum += digit; //add it to the digit sum
        n /= 10; //divde by 10 to get to next digit
    }
    if (digit_sum % 3 == 0) { //if the sum of the digits are divisible by 3
        char return_phrase[] = "CS"; //set return phrase
        printf("%s\n",return_phrase);
        return return_phrase;
    }

    else {
        int digit_square = digit_sum * digit_sum; //square the digit sum
        char return_phrase[100];
        sprintf(return_phrase,"%d",digit_square); //set the return phrase to the digit sum
        printf("%s\n",return_phrase);
        return return_phrase;
    }
}

bool UABNumber() {
    int n2 = 0;
    int div_sum = 0;
    printf("Please enter a number: ");
    scanf("%d",&n2); //taking user input
    for (int i = 1; i < n2; i++) {
        if (n2 % i == 0) { //if the current iterator is a divisor add the divisor to the divisor sum
            div_sum += i;
        }
    }
    if (div_sum == n2) { 
        printf("True\n");
        return true;
    }
    printf("False\n");
    return false;
}

int reverseNum(int n3) {
    int size = log10(n3) + 1; //take the log of the number + 1 to get the number of digits
    char *num_array = calloc(size,sizeof(char)); //initialize the character arrays
    char *rev_array = calloc(size,sizeof(char));
    sprintf(num_array,"%ld",n3); //add the number to the character array
    for (int j = 0; j < size; j++) { //iterate ove the character array
        rev_array[j] = num_array[size - 1 - j]; //swap the indices of the digits
    }
    printf("Original number: %d\n",n3);
    int rev_num;
    sscanf(rev_array,"%d",&rev_num); //convert char array to int
    printf("Reversed number: %d\n",rev_num);
    return rev_num;
}

int smallerThanIndex(int numbers[5]) {
    int count = 0;
    for (int i = 0; i < 5; i++) { //iterate over the array
        if (i > numbers[i]) { //if the current index is higher than the value at the index
            count++; //increment count
        }
    }
    printf("Elements with values smaller than their index: %d\n",count);
    return count;
}

void arrayDetails(int array[6]) {
    int min_val = array[0];
    int min_index = 0;
    int max_val = array[0];
    int max_index = 0;
    int sum = 0;
    for (int i = 0; i < 6; i++) { //iterate over the array
        if (array[i] < min_val) { //if the value at the current index is less than the min
            min_val = array[i]; //set new min and min index
            min_index = i;
        }
        if (array[i] > max_val) { //if the value at the current index is greater than the max
            max_val = array[i]; //set new max and max index
            max_index = i;
        }
        sum += array[i]; //add each value to sum
    }

    float avg = sum / 6.0; //divide the sum by the number of elements as a float
    printf("Array Details: [%d,%d,%.2f,%d,%d]\n",min_val,min_index,avg,max_val,max_index);
}

int main() { //call all functions
    numberTransform(3);
    numberTransform(64);
    numberTransform(17);
    numberTransform(10);
    numberTransform(30);
    UABNumber();
    UABNumber();
    UABNumber();
    UABNumber();
    reverseNum(1234);
    reverseNum(29);
    reverseNum(10001);
    int numbers[5] = {-4,-3,2,1,0};
    smallerThanIndex(numbers);
    int array[6] = {-8,18,103,1,-4,631};
    arrayDetails(array);
    return 0;
}