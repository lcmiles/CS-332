/*
Name: Logan Miles
BlazerId: lcmiles
Project #: 2
To compile: 
gcc -Wall -g lcmiles_HW02.c -o lcmiles_HW02 -lm -fno-pie -no-pie 
OR
make
To run:
./lcmiles_HW02 
./lcmiles_HW02 -v 
./lcmiles_HW02 -L <size limit>
./lcmiles_HW02 -s <string pattern> <search depth>
OR
make run
make search s=<string pattern> d=<depth>
make verbose
make size limit L=<size limit>
*/

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <bits/getopt_core.h>
#include <ctype.h>

//function prototypes
int traverseDirectory(char *base_path, const int root, const int verbose, const int file_size_limit);
int traverseDirectoryWithSearch(char *base_path, const int root, const int verbose, const int file_size_limit, const char *search_pattern, const int search_depth);
void printFileInfo(const struct stat *file_stat, char *file_name);

int main(int argc, char *argv[]) {
    int verbose = 0;
    int file_size_limit = -1;
    char *search_pattern = NULL;
    int search_depth = -1;
    char *path;
    char *ptr;

    int opt;
    while ((opt = getopt(argc, argv, "vL:s:")) != -1) { //loop through command line options
        switch (opt)
        {
        case 'v': //verbose case
            verbose = 1; //set verbose flag
            break;
        case 'L': //size limit case
            ptr = optarg; //set pointer to argument
            while (*ptr) { //loop through argument characters
                if (!(isdigit(*ptr))) { //if the character is not a digit then return error code
                    fprintf(stderr, "Usage: %s [-v] [-L <file size (positive int in bytes)>] [-s <string pattern> <depth (positive int in directory depth)>] [directory]\n", argv[0]);
                    return -1;
                }
                ptr++;
            }
            file_size_limit = atoi(optarg); //convert to int and assign variable
            if (file_size_limit <= 0) { //if the file size limit is negative return error code
                fprintf(stderr, "Usage: %s [-v] [-L <file size (positive int in bytes)>] [-s <string pattern> <depth (positive int in directory depth)>] [directory]\n", argv[0]);
                return -1;
            }
            break;
        case 's': //search case
            search_pattern = optarg; //assign the argument to search pattern character array
            if (argv[optind] != NULL) { //if the search depth argument available assign it to variable
                search_depth = atoi(argv[optind]);
            }
            else { //else return error code
                fprintf(stderr, "Usage: %s [-v] [-L <file size (positive int in bytes)>] [-s <string pattern> <depth (positive int in directory depth)>] [directory]\n", argv[0]);
                return -1;
            }
            optind++;  
            break;
        default: //return error code by default
            fprintf(stderr, "Usage: %s [-v] [-L <file size (positive int in bytes)>] [-s <string pattern> <depth (positive int in directory depth)>] [directory]\n", argv[0]);
            return -1;
        }
    }

    if (optind < argc) { //if there is another argument after the switch case then set it to the path
        path = argv[optind];
    } 
    else { //otherwise set the default path to the working directory
        path = ".";
    }

    if (search_pattern == NULL && search_depth == -1) { //if the search_pattern and search_depth variables are set to their default values, execute traverseDirectory()
        traverseDirectory(path, 0, verbose, file_size_limit);
    }
    else traverseDirectoryWithSearch(path, 0, verbose, file_size_limit, search_pattern, search_depth); //otherwise execute traverseDirectoryWithSearch()

    return 0;
}

int traverseDirectory(char *base_path, const int root, const int verbose, const int file_size_limit) {
    
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

            if (file_size_limit != -1 && S_ISREG(file_stat.st_mode) && file_stat.st_size < file_size_limit) continue; //skip files above the size limit if the flag is set to anything but default

            char *file_name = dp->d_name; //set the file name

            for (i = 0; i < root; i++) { //print indentation per file based on the root level
                printf("\t");
            }
            
            if (verbose) printFileInfo(&file_stat, file_name); //print the file info if verbose flag set to true

            if (verbose == 0) printf("%s\n", dp->d_name); //print the file name if the verbose flag set to false

            if (S_ISDIR(file_stat.st_mode)) { //if the file is a directory recursively call traverseDirectory()
                traverseDirectory(path, root + 1, verbose, file_size_limit);
            }
        }
    }
    closedir(dir);
    return 0;
}

int traverseDirectoryWithSearch(char *base_path, const int root, const int verbose, const int file_size_limit, const char *search_pattern, const int search_depth) { //code is similar to traverseDirectory() except for file printing exclusion
    char path[1000];
    struct dirent *dp;
    DIR *dir = opendir(base_path);

    if (!dir) {
        perror("opendir");
        return -1;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {

            strcpy(path, base_path);
            strcat(path, "/");
            strcat(path, dp->d_name);

            struct stat file_stat;
            if (lstat(path, &file_stat) < 0) {
                perror("lstat");
                return -1;
            }

            if (file_size_limit != -1 && S_ISREG(file_stat.st_mode) && file_stat.st_size < file_size_limit)
                continue;

            char *file_name = dp->d_name;

            if (root <= search_depth) { //if the root is less than or equal to the search depth 

                if (strstr(file_name, search_pattern) != NULL) { //if the file name contains the search pattern
                    
                    if (verbose) printFileInfo(&file_stat, file_name);

                    if (verbose == 0) printf("%s\n", dp->d_name);
                }
            }

            if (S_ISDIR(file_stat.st_mode)) {
                traverseDirectoryWithSearch(path, root + 1, verbose, file_size_limit, search_pattern, search_depth);
            }
        }
    }
    closedir(dir);
    return 0;
}

void printFileInfo(const struct stat *file_stat, char *file_name) {
    char *time_string = ctime(&file_stat->st_atime); //create string containing date and time file was last accessed
    time_string[strcspn(time_string, "\n")] = '\0'; //remove newline character from time string
    if (S_ISDIR(file_stat->st_mode)) { //if the file is a directory, always print the file size as 0
        printf("%s (Size: 0, Permissions: %o, Last Access: %s)\n", file_name, (file_stat->st_mode & 0777), time_string); //print file information from stat structure
    } 
    else {
        printf("%s (Size: %lld, Permissions: %o, Last Access: %s)\n", file_name, (long long)file_stat->st_size, (file_stat->st_mode & 0777), time_string); //print file information from stat structure
    }
}