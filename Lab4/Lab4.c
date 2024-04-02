#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define	BUFFSIZE 4096
#define SEEKSIZE 0

int main(int argc, char *argv[]) {
	int  readFileDescriptor, writeFileDescriptor;
	long int n;
	char buf[BUFFSIZE];
	
	if (argc != 3){ //error message for incorrect number of args
		printf("Usage: %s <source_filename> <destination_filename>\n", argv[0]);
		exit (-1);
	}
	
	readFileDescriptor = open(argv[2], O_RDONLY); //open 2nd file in read only mode and assign fd
    
    writeFileDescriptor = open(argv[1], O_CREAT|O_WRONLY, 0700); //open file in write only mode and assign file descriptor
	
    lseek(writeFileDescriptor, 0, SEEK_END); //point to end of the writeFileDescriptor file
	
	if (readFileDescriptor == -1 || writeFileDescriptor == -1){ //error message for when the file descriptor is not correctly assigned and the file is not opened
		printf("Error with file open\n");
		exit (-1);
	}

	while ((n = read(readFileDescriptor, buf, BUFFSIZE)) > 0){ //error message for when the buffer size is not equal to the size written to the file
		if (write(writeFileDescriptor, buf, n) != n){
			printf("Error writing to output file\n");
			exit (-1);
		}
	}

	if (n < 0){
		printf("Error reading input file\n"); //error message when the buffer size is not properly assigned, meaning the file was not read correctly
		exit (-1);
	}

	close(readFileDescriptor);
	close(writeFileDescriptor);

	return 0;
}