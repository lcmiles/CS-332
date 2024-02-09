# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o Lab3 Lab3.c # this will compile Lab3.c and output an executable called Lab3
```

# Execution Instructions

```bash
./<Lab3> # this will execute HW1
```

# My Files

## Lab3.c

### insertionSort() [^4]

* Description: This function iterates over the array, compares each string element to every proceeding string element using strcmp(), placing it in the correct position alphebetically
* Parameters:
    * char *arr - The array to be sorted
    * int array_size - The size of the array in number of elements
* Returns: void

### main() [^1] [^2] [^3] [^5]

* Description: Driver code responsible for taking user input, calling insertionSort(), and printing the array 
* Parameters: None
* Returns: void

# Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%203/Screenshot%202024-01-27%20154009.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%203/Screenshot%202024-01-27%20154219.png?raw=true)



# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/0ca9bd2776a80839178804050d788049db3f7c67/Lab%203

# References

[^1]: https://stackoverflow.com/questions/9726922/how-to-print-the-array
(Used to print array before and after sorting)

[^2]: https://stackoverflow.com/questions/32573382/how-to-take-ints-from-user-using-fgets-in-c
(Used to take user input)

[^3]: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
(Used to allocated memory for character pointers)

[^4]: https://stackoverflow.com/questions/36019668/c-alphabetical-sorting-of-array-of-character-arrays 
(Used elements from this in insertionSort())

[^5]: https://stackoverflow.com/questions/252782/strdup-what-does-it-do-in-c
(Used in main() to add user input to array)