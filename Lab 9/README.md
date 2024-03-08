# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o Lab9 Lab9.c # this will compile Lab9.c and output an executable called Lab9
```

# Execution Instructions

```bash
./<Lab9> <bash command> # this will execute Lab9 with the provided bash command
```

# My Files

## Lab9.c

### sigUsr() [^1]

* Description: Function responsible for handling signals
* Parameters:
    * int signo - The given signal number
* Returns: 0

### sigChld()

* Description: Function responsible for handling the status of the child process
* Parameters:
    * int signo - The given signal number
* Returns: 0

### main() [^1] [^2] [^3]

* Description: Driver code responsible for spawning the child process with the provided command line args and error handling
* Parameters:
    * int argc - The number of command-line args
    * char **argv - Character array representing command-line args
* Returns: 0

# Code/Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%209/Screenshot%202024-03-08%20at%2012.41.23%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%209/Screenshot%202024-03-08%20at%2012.44.37%E2%80%AFPM.png?raw=true)

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/497fc03b4de7697c1257fc12686b3478d473d65a/Lab%209

# Sources:

[^1]: https://www.geeksforgeeks.org/signals-c-language/

[^2]: https://stackoverflow.com/questions/61571675/sending-signal-to-child-process-on-pause

[^3]: https://www.linuxquestions.org/questions/programming-9 how-can-you-pause-child-parent-processes-in-c-and-execute-another-function-574479/