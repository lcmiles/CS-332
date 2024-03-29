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

### compute()

* Description: This function is responsible for calculating the sum of elements assigned to a particular thread
* Parameters:
    * void *arg - Acts as a pointer to ThreadArgs struct when launching the threads
* Returns: 0

### main()

* Description: Driver code responsible for parsing command-line args, creating and launching threads, and calculating the final sum
* Parameters:
    * int argc - The number of command-line args
    * char **argv - Character array representing command-line args
* Returns: 0

# Code/Output screenshots

![alt text]()


# Link to GitHub reopository:



# Sources:

[^1]: 