FILE = Lab6

build: $(FILE).c
	#next line compiles with all warnings on, debug info, and links math lib
	gcc -Wall -g $(FILE).c -o $(FILE) -lm -fno-pie -no-pie

.PHONY: db

db:
	gdb -tui $(FILE)

run:
	#runs the file
	./$(FILE)