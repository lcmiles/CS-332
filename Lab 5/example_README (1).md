<!--
NOTES:
This README is an example README for CS332/532 labs. This is a purely minimal example. It's written to emulate pure english representations of a set of documentation. As you start to write more "real world" documentation you will encounter certain standards and manners of writing that this README prepares you for
-->

# Compilation Instructions

If you're a make file
```bash
make # this will compile all the files
make run # this will run all the files

make run ARGS="<your args here>" # this will run the files with your args

make run ARGS="a.txt b.txt" # this will run the executable with the arguments of a.txt b.txt
```

If you're not using a make file
```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o gettime gettime.c # this will compile gettime.c and output an executable called gettime
```

# My Files
## gettime.c

### main()

This function calls on gettime from the header file and prints it's output

## gettime.h

### gettime(int x)
This function returns a double

This function takes an integer as a parameter

It creates a struct of a timeval object then gets the time of day and returns it

# Output screenshots
<put your screenshots here>

# References

https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/
I used this link to make a makefile for my project