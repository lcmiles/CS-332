# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o Lab11 Lab11.c # this will compile Lab11.c and output an executable called Lab11
```

# Execution Instructions

```bash
./<Lab11> <bash command> # this will execute Lab11 with the provided bash command
```

# My Files

## Lab11.c

### compute() [^3]

* Description: This function is responsible for calculating the sum of elements assigned to a particular thread
* Parameters:
    * void *arg - Acts as a pointer to ThreadArgs struct when launching the threads
* Returns: 0

### main() [^1] [^2] [^3]

* Description: Driver code responsible for parsing command-line args, creating and launching threads, and calculating the final sum
* Parameters:
    * int argc - The number of command-line args
    * char **argv - Character array representing command-line args
* Returns: 0

# Code/Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%2011/Screenshot%202024-03-29%20at%2012.19.02%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%2011/Screenshot%202024-03-29%20at%2012.20.19%E2%80%AFPM.png?raw=true)

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/blob/4b4aa3106e3c598f686078ec22d132f358fef76c/Lab%2011/Screenshot%202024-03-29%20at%2012.20.19%E2%80%AFPM.png

# Sources:

[^1]: https://www.geeksforgeeks.org/multithreading-in-c/

[^2]: https://stackoverflow.com/questions/41359435/find-partial-sum-of-x-numbers-in-array-in-c

[^3]: https://stackoverflow.com/questions/20196121/passing-struct-to-pthread-as-an-argument