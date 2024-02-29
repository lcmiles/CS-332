# Compilation Instructions

```bash
gcc -o <executable name> <filename> # this will compile the filename and return an executable with the executable name

gcc -o lcmiles_HW03 lcmiles_HW03.c # this will compile lcmiles_HW03.c and output an executable called lcmiles_HW03
```

# Execution Instructions

```bash
./lcmiles_HW03 # this will execute lcmiles_HW03 and print all files in the directory

./lcmiles_HW03 -v # this will execute lcmiles_HW03 and print all files in the directory with detailed information

./lcmiles_HW03 -L <size limit> # this will execute lcmiles_HW03 and print all files in the directory equal to or less than the size limit in bytes

./lcmiles_HW03 -s <string pattern> <search depth> # this will execute lcmiles_HW03 and print all files in the directory that contain the string pattern up to the search depth

./lcmiles_HW03 -e <linux command string> # this will execute lcmiles_HW03 and call the given linux command on the file or directory

./lcmiles_HW03 -v -s <string pattern> <search depth> -L <size limit> #arguments can also be combined like so

OR

make run # this will execute lcmiles_HW03 and print all files in the directory

make search s=<string pattern> d=<depth> # this will execute lcmiles_HW03 and print all files in the directory that contain the string pattern up to the search depth

make verbose # this will execute lcmiles_HW03 and print all files in the directory with detailed information

make size limit L=<size limit> # this will execute lcmiles_HW03 and print all files in the directory equal to or less than the size limit in bytes
```

# My Files

## HW1.c

### main() [^1] [^2]

* Description: 
* Parameters:
    * int argc - The number of command-line arguments
    * char *argv[] - The character array containing the arguments used by getopt()
* Returns: 0

### traverseDirectory() [^5] [^6] [^7] [^8]

* Description: Recursively traverses the file hierarchy, printing the correct information based on command-line arguments
* Parameters:
    * char *base_path - The starting path of the traversal
    * const int root - Constant int used as a counter for traversal recursion
    * const int verbose - Verbose argument flag applied when -v is used
    * const int file_size_limit - Size limit given in command-line arguments when -L is used
    * const char *linux_command - The command to be called on the given file or directory
* Returns: void

### traverseDirectoryWithSearch() [^3] [^5] [^6] [^7] [^8]

* Description: Recursively traverses the file hierarchy up to the given search depth, printing any files that match the search_pattern substring, as well as the correct information based on command-line arguments
* Parameters:
    * char *base_path - The starting path of the traversal
    * const int root - Constant int used as a counter for traversal recursion
    * const int verbose - Verbose argument flag applied when -v is used
    * const int file_size_limit - Size limit given in command-line arguments when -L is used
    * const char *search_pattern - Substring that is searched for throughout the file hiearchy
    * const int search_depth - The directory depth that will be traversed to when searching for files
    * const char *linux_command - The command to be called on the given file or directory
* Returns: void

### printFileInfo() [^4]

* Description: Prints file details based on the file status structure when the -v argument is applied
* Parameters:
    * const struct stat *file_stat - The file status structure passed from traverseDirectory() or traverseDirectoryWithSearch()
    * const char  *file_name - The name of the given file
* Returns: void

# Code/Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-28%20at%202.50.08%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-28%20at%202.50.58%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-28%20at%202.51.29%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-28%20at%202.56.37%E2%80%AFPM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-29%20at%208.05.41%E2%80%AFAM.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/HW%203/Screenshot%202024-02-29%20at%208.07.00%E2%80%AFAM.png?raw=true)

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/317fdd07c2ea709867a2e40e7b4079450337533a/HW%203

# References

[^1]: https://www.tutorialspoint.com/how-to-check-if-a-c-cplusplus-string-is-an-int#:~:text=Using%20built%2Din%20method%20isdigit,string%20does%20not%20contain%20int. (Used in main() for error handling of command-line arguments)

[^2]: https://pubs.opengroup.org/onlinepubs/009696799/functions/getopt.html (Used in main to derive command-line arguments)

[^3]: https://stackoverflow.com/questions/12784766/check-substring-exists-in-a-string-in-c (Used in traverseDirectoryWithSearch() to compare command-line arguments and file names)

[^4]: https://www.geeksforgeeks.org/ctime-function-in-c-c/ (Used in printFileInfo() to create the string containing date and time of file access)

[^5]: https://codeforwin.org/c-programming/c-program-to-list-all-files-in-a-directory-recursively (Used in both traverseDirectory() and traverseDirectoryWithSearch() to traverse the file directory)

[^6]: https://stackoverflow.com/questions/31132699/directory-traversing-in-c (Used in both traverseDirectory() and traverseDirectoryWithSearch() to traverse the file directory)

[^7]: https://stackoverflow.com/questions/3554120/open-directory-using-c (Used in both traverseDirectory() and traverseDirectoryWithSearch() to traverse the file directory)

[^8]: https://www.tutorialspoint.com/c_standard_library/c_function_system.htm (Used in both traverseDirectory() and traverseDirectoryWithSearch() to call linux functions)