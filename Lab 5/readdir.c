#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h> 

int main (int argc, char **argv) { 
  struct dirent *dirent; 
  DIR *parentDir; 

  if (argc < 2) { 
    printf ("Usage: %s <dirname>\n", argv[0]); 
    exit(-1);
  } 
  parentDir = opendir (argv[1]); 
  if (parentDir == NULL) { 
    printf ("Error opening directory '%s'\n", argv[1]); 
    exit (-1);
  } 
  int count = 1; 
  while((dirent = readdir(parentDir)) != NULL){ 
    printf ("[%d] %s\n", count, (*dirent).d_name); 
    count++; 
  } 
  closedir (parentDir); 
  return 0; 
} 
