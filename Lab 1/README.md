# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o Lab1 Lab1.c # this will compile Lab1.c and output an executable called Lab1
```

# Execution Instructions

```bash
./<Lab1> # this will execute Lab1
```

# My Files

## Lab1.c

### main()

* Description: Driver code responsible for printing different cases and calling other two functions 
* Parameters: None
* Returns: 0

### isInteger(int *given_number)

* Description: Uses a pointer to check if given_number is an int. Also takes user input using scanf() [^1] [^2]
* Parameters: int *given_number pointer
* Returns: boolean true or false value based on the modulo

### isEven(int given_number)

* Description: Checks if given_number is even 
* Parameters: int *given_number pointer
* Returns: boolean true or false value based on modulo
* Sources: https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c

# Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%201/Screenshot%202024-01-12%20at%2012.53.01%E2%80%AFPM.png?raw=true "isEven() and isInteger()")

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%201/Screenshot%202024-01-12%20at%2012.53.41%E2%80%AFPM.png?raw=true "main()")

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%201/Screenshot%202024-01-12%20at%2012.54.20%E2%80%AFPM.png?raw=true "Outputs") [^3]


# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/c0cd20671775e55133cf8db9ca41ffc27e9576a1/Lab%201

# References

[^1]: https://www.geeksforgeeks.org/scanf-in-c/

[^2]: https://stackoverflow.com/questions/4072190/check-if-input-is-integer-type-in-c

[^3]: https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet#images