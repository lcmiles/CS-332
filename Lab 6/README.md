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

### cmpName()

* Description: This function is called in qsort() as a function pointer as the sorting parameters used to sort by host_name
* Parameters: 
    * const struct listing *p1 - The first item in the structure array to be compared
    * const struct listing *p2 - The second item in the structure array to be compared
* Returns: int - result of strcmp(p1->host_name,p2->host_name)


### main()

* Description: Driver code responsible for performing reading input file, calling qsort(), and writing to new files
* Parameters: None
* Returns: 0

# Code/Output screenshots

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141802.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141830.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141741.png?raw=true)

![alt text](https://github.com/lcmiles/CS-332/blob/main/Lab%206/Screenshot%202024-02-15%20141713.png?raw=true)

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/a0c6a3b41988376b6ddd691ba9133f7cb408b2d2/Lab%206