# Compilation Instructions

If you're a make file
```bash
make # this will compile all the files

make run # this will run Lab5.c and print all files in its directory

make run d=<directory> # this will run Lab5.c and print all files in the directory given in as an argument
```

If you're not using a make file
```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o Lab5 Lab5.c # this will compile Lab5 and return Lab5
```

# My Files
## Lab5.c

### main()

* Description: This function is responsible for taking command-line arguments, setting the directory path, and calling traverseDirectory()
* Parameters:
    * int argc - The number of command-line args
    * char **argv - Character string containing command-line args
* Returns: 0

### main()

* Description: This function recursively traverses directories and prints them and the files contained within
* Parameters:
    * char *path - The path of the directory to be traversed
    * int root - An integer counting the directory depth from the root
* Returns: 0

# Output screenshots



# References

