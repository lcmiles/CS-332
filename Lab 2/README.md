# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o Lab2 Lab2.c # this will compile Lab2.c and output an executable called Lab1
```

# Execution Instructions

```bash
./<Lab2> # this will execute Lab2
```

# My Files

## Lab2.c

### main()

* Description: Driver code responsible for taking user input, calling insertionSort(), and printing the array 
* Parameters: None
* Returns: 0
* References: [^1] [^2] [^3] [^4]

### insertionSort()

* Description: This function iterates over the array given by the user and sorts it utilizing the insertion sort algorithm
* Parameters: 
    - int[] arr - The array given by the user
    - int array_size - The size of arr
* Returns: void

# Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%202/Screenshot%202024-01-19%20at%2010.04.07%E2%80%AFAM.png?raw=true "insertionSort() and main()")

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%202/Screenshot%202024-01-19%20at%2010.05.45%E2%80%AFAM.png?raw=true "Results")

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/2060cd0ce5c33409a259ae28532f66692b581eb0/Lab%202

# References

[^1]: https://stackoverflow.com/questions/9726922/how-to-print-the-array
(Used to print array before and after sorting)

[^2]: https://stackoverflow.com/questions/32573382/how-to-take-ints-from-user-using-fgets-in-c
(Used to take user input)

[^3]: https://www.geeksforgeeks.org/dynamic-memory-allocation-in-c-using-malloc-calloc-free-and-realloc/
(Used to allocated memory for character pointers)

[^4]: https://www.geeksforgeeks.org/convert-string-to-int-in-c/
(Used to convert character pointers to strings)