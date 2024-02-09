#include <stdio.h> 
#include <stdlib.h>
#include <dirent.h> 
#include <sys/stat.h>
#include <bits/getopt_core.h>
#include <string.h>

int traverseDirectory(char *base_path, const int root);
int (*func_ptr)(char *, int) = &traverseDirectory;

int main (int argc, char **argv) { 

    DIR *parentDir;
    char *path;


    if (optind < argc) { //if there is another argument after the switch case then set it to the path
        path = argv[optind];
    } 
    else { //otherwise set the default path to the working directory
        path = ".";
    }

    if (argc < 2) { 
        printf ("Usage: %s <dirname>\n", argv[0]); 
        exit(-1);
    } 
    parentDir = opendir (argv[1]); 
    if (parentDir == NULL) { 
        printf ("Error opening directory '%s'\n", argv[1]); 
        exit (-1);
    } 

    struct stat file_stat; //get the file status and store it in a structure
    if (lstat(path, &file_stat) < 0) { //return error code if the file cannot be accessed
        perror("lstat");
        return -1;
    }

    if (S_ISDIR(file_stat.st_mode)) { //if the file is a directory recursively call traverseDirectory()
        (func_ptr)(path, 0);
    }

  closedir (parentDir); 
  return 0; 
} 

int traverseDirectory(char *base_path, const int root) {
    
    int i;
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(base_path);
    

    if (!dir) { //if the directory is not successfully opened then return error code
        perror("opendir");
        return -1;
    }

    while ((dp = readdir(dir)) != NULL) { //loop through directory entries
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) { //exclude the "." and ".." directories

            strcpy(path, base_path); //copy the base path to the path

            strcat(path, "/"); //append "/" to the path
            strcat(path, dp->d_name); //append directory name to the path

            struct stat file_stat; //get the file status and store it in a structure
            if (lstat(path, &file_stat) < 0) { //return error code if the file cannot be accessed
                perror("lstat");
                return -1;
            }

            for (i = 0; i < root; i++) { //print indentation per file based on the root level
                printf("\t");
            }

            printf("%s\n", dp->d_name);

            if (S_ISDIR(file_stat.st_mode)) { //if the file is a directory recursively call traverseDirectory()
                traverseDirectory(path, root + 1);
            }
        }
    }
    closedir(dir);
    return 0;
}