# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o Lab6 Lab6.c # this will compile Lab6.c and output an executable called Lab6
```

# Execution Instructions

```bash
./<Lab6> # this will execute Lab6
```

# My Files

## Lab6.c

### getfields()

* Description: This function is responsible for tokenizing a line from the CSV at each "," character and assigns each substring to a variable of the structure
* Parameters: char* line - Character array read from the CSV file
* Returns: struct listing item - Structure containing info about the item on the given line

### cmpPrice()

* Description: This function is called in qsort() as a function pointer as the sorting parameters price
* Parameters: 
    * const struct listing *p1 - The first item in the structure array to be compared
    * const struct listing *p2 - The second item in the structure array to be compared
* Returns: int - result of p1->price > p2->price

### cmpName() [^1]

* Description: This function is called in qsort() as a function pointer as the sorting parameters used to sort by host_name
* Parameters: 
    * const struct listing *p1 - The first item in the structure array to be compared
    * const struct listing *p2 - The second item in the structure array to be compared
* Returns: int - result of strcmp(p1->host_name,p2->host_name)


### main() [^2] [^3] [^4] [^5]

* Description: Driver code responsible for performing reading input file, calling qsort(), and writing to new files
* Parameters: None
* Returns: 0

# Code/Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141802.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141830.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141741.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141713.png?raw=true)

# Sources:

[^1] https://www.scaler.com/topics/c/string-comparison-in-c/

[^2] https://stackoverflow.com/questions/19429138/append-to-the-end-of-a-file-in-c

[^3] https://discuss.codechef.com/t/sorting-structure-in-c-using-qsort/49541/3

[^4] https://stackoverflow.com/questions/6105513/need-help-using-qsort-with-an-array-of-structs

[^5] https://stackoverflow.com/questions/59890582/how-to-sort-an-int-array-in-c-with-native-qsort

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/a0c6a3b41988376b6ddd691ba9133f7cb408b2d2/Lab%206