# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o HW1 HW1.c -lm # this will compile HW1.c and output an executable called HW1
```

# Execution Instructions

```bash
./<HW1> # this will execute HW1
```

# My Files

## HW1.c

### primeCheck() [^1] [^3]

* Description: This function takes an integer and determines whether it is prime or not.
* Parameters: 
    * int n - The integer that is checked to see if it is prime
* Returns:
    * Boolean value

### numberTransform() [^2] [^4] [^5]

* Description: This function returns a different string based the integer entered as a parameter.
* Parameters:
    * int n - The integer that is checked for different qualities
* Returns:
    * char *return_phrase - A character array (or string) representing if any of the if statements checking for a quality of the number passed true

### UABNumber()

* Description: This function takes user input and determines if the integer entered is a "UAB number" or a number whos positive integer divisors' sum equal the number.
* Parameters: 
    * None
* Returns:
    * Boolean value

### reverseNum() [^6] [^7]

* Description: This function takes an integer n3 and returns a string representation of the reversed number.
* Parameters: 
    * int n3 - The integer to be reversed
* Returns: 
    * int rev_num - Reversed integer 

### smallerThanIndex()

* Description: This function iterates through an array of 5 integers and returns the number of integers that have an index larger than their value.
* Parameters: 
    * int numbers[5] - The array of integers to be iterated through
* Returns:
    * int count - The number of integers that have an index larger than their value

### arrayDetails()

* Description: This function takes an array of 6 integers, iterates over it to find the min, max, and mean, then prints another array of 5 integers containing the min, min index, mean, max, and max index.
* Parameters: 
    * int array[6] - The array iterated over to find the min, max, and mean
* Returns:
    * Nothing

### main()

* Description: Driver code responsible for taking user input, calling insertionSort(), and printing the array 
* Parameters: None
* Returns: 0


# Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%201/Screenshot%202024-01-22%20at%202.16.37%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%201/Screenshot%202024-01-22%20at%202.17.41%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%201/Screenshot%202024-01-22%20at%202.17.56%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%201/Screenshot%202024-01-22%20at%202.18.03%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%201/Screenshot%202024-01-22%20at%202.18.12%E2%80%AFPM.png?raw=true)


# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/blob/6e2837704468080b808df935b7cd876dc0752715/HW%201/Screenshot%202024-01-22%20at%202.18.12%E2%80%AFPM.png

# References

[^1]: https://www.geeksforgeeks.org/c-program-to-check-whether-a-number-is-prime-or-not/ (Used similar logic in primeCheck())

[^2]: https://www.geeksforgeeks.org/c-program-to-find-whether-a-no-is-power-of-two/ (Used in numberTransform() to check for powers of two in the second if statement)

[^3]: https://stackoverflow.com/questions/14564813/how-to-convert-an-integer-to-a-character-array-using-c (Used in numberTransform() and reverseNum() to convert integers to character arrays)

[^4]: https://stackoverflow.com/questions/64185029/how-to-find-the-nearest-prime-for-a-given-number-using-for-loop-in-c (Used in the second if statement in numberTransform())

[^5]: https://www.log2base2.com/c-examples/loop/split-a-number-into-digits-in-c.html (Used in numberTransform() to split integers into digits)

[^6]: https://stackoverflow.com/questions/34115900/reversing-char-array-in-c-programming (Used in reverseChar() to reverse character arrays)

[^7]: https://stackoverflow.com/questions/10204471/convert-char-array-to-a-int-number-in-c (Used to convert char array to int in reversNum())