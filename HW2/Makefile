FILE = lcmiles_HW02

build: $(FILE).c
	#compiles with all warnings on, debug info, and links math lib
	gcc -Wall -g $(FILE).c -o $(FILE) -lm -fno-pie -no-pie


.PHONY: db

db:
	gdb -tui $(FILE)

run:
	#runs and prints all files in directory
	./$(FILE) 
	

search:
	#runs and prints all files in directory containing the string up to a certain depth
	#call: make search s=<string pattern> d=<depth>
	./$(FILE) -s $(s) $(d)

verbose:
	#runs and prints all files in directory with detailed information
	#call: make verbose
	./$(FILE) -v 

size limit:
	#runs and prints all files in directory less than or equal to the given size limit
	#call: make size limit L=<size limit>
	./$(FILE) -L $(L)
	