# Compilation Instructions

```bash
gcc -o <executable name> <filename> -lm # this will compile the filename and return an executable with the executable name

gcc -o lcmiles_HW04 lcmiles_HW04.c # this will compile lcmiles_HW04.c and output an executable called lcmiles_HW04
```

# Execution Instructions

```bash
./<lcmiles_HW04> <bash command> # this will execute lcmiles_HW04 with the provided bash command
```

# My Files

## lcmiles_HW04.c

### main()

* Description: The main function of the program. It initializes the job queue, takes user commands, and executes them accordingly.
* Parameters: None
* Returns: 0

### queue_init()
* Description: Initializes a circular queue with the specified size.
* Parameters:
    * n: The size of the circular queue.
Returns: 
    * q: A pointer to the initialized queue structure.

### queue_insert()
* Description: Inserts an item into the circular queue.
* Parameters:
    * q: A pointer to the circular queue.
    * item: The item to be inserted into the queue.
Returns: 
    * q: The new count of elements in the queue after insertion, or -1 if the insertion fails.

### queue_delete()
* Description: Deletes an item from the circular queue.
* Parameters:
    * q: A pointer to the circular queue.
Returns: 
    * x: The deleted item from the queue, or -1 if the deletion fails.

### queue_destroy()
* Description: Destroys the circular queue and frees memory.
* Parameters:
    * q: A pointer to the circular queue to be destroyed.
Returns: Nothing.

### submit_jobs()
* Description: Submits a new job.
* Parameters:
    * command: A string representing the command to be executed.
Returns: Nothing.

### submit_jobs()
* Description: Displays the status of all jobs in the queue.
* Parameters: Nothing.
Returns: Nothing.

# Code/Output screenshots

![alt text]()

# Link to GitHub reopository:

https://github.com/lcmiles/CS-332/tree/e2fb900e812c9e0a168ff8dc15ae630ffd16a9b1/HW4

# Sources:

[^1]: 