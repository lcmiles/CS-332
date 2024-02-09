# Compilation Instructions

If you're a make file
```bash
make # this will compile the file

make run # this will run Lab5 executable and print all files in its directory

make run d=<directory> # this will run Lab5 executable on the directory given as an argument
```

If you're not using a make file
```bash
gcc -o Lab5 Lab5.c # this will compile Lab5 and return Lab5

./Lab5 <directory> #this will run Lab5 executable on the directory given as an argument
```

# My Files
## Lab5.c

### main()

* Description: This function is responsible for taking command-line arguments, setting the directory path, and calling traverseDirectory()
* Parameters:
    * int argc - The number of command-line args
    * char **argv - Character string containing command-line args
* Returns: 0

### traverseDirectory() [^1]

* Description: This function recursively traverses directories and prints them and the files contained within
* Parameters:
    * char *path - The path of the directory to be traversed
    * int root - An integer counting the directory depth from the root
* Returns: 0

# Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%205/Screenshot%202024-02-09%20at%2010.39.18%E2%80%AFAM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%205/Screenshot%202024-02-09%20at%2010.38.20%E2%80%AFAM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%205/Screenshot%202024-02-09%20at%2010.28.20%E2%80%AFAM.png?raw=true)

# Link to GitHub Repository

https://github.com/lcmiles/CS-332/tree/835047ea8d3371148b60dfed32c936995481ce79/Lab%205

# References

[^1] https://www.geeksforgeeks.org/function-pointer-in-c/