/* 
Project 4 - Clone Utility
By: Paul Kafka
Description: Perform copy, remove, and file attribute operations using API functions.
*/ 

// Libraries
#include <stdio.h>				// for input and output
#include <string.h>				// for string functions
#include <stdlib.h>				// std functions
#include <unistd.h>				// getcwd()
#include <sys/stat.h>			// mkdir()
#include <dirent.h>				// readdir()
#include <errno.h>				// error
#include <sys/types.h>			// read write
#include <fcntl.h>					// O_WRONLY
#include <stdio.h>				// to remove file

// Prototypes
int IsFile(const char* file, int* info_mode, int* user_id, int* group_id);					// Checks to see if file exists
static void Copy(const char *source, const char *destination);
static void RemoveExtras(const char* source, const char* destination);

int main(int argc, char *argv[]) {		//clone.x <source> <dest>  

	//variables
	char source_dir[100];
	char destination_dir[100];
	char temp_path[100];
	int  info_mode, user_id, group_id;

	// Read in command arguments
	if (argv[1] != NULL)
		strcpy(source_dir, argv[1] );
	else {
		printf("Arguments missing\n");
		exit(0);
	}
	if (argv[2] != NULL)
		strcpy(destination_dir, argv[2] );
	else {
		printf("Argument 2 missing\n");
		exit(0);
	}
	
	getcwd(temp_path, sizeof(temp_path));				// Get absolute path
	
	//(1) If the source directory doesn't exist, print an error.
	if (chdir(source_dir)) {	// try to change directory
		printf("%s is not a valid source directory.\n", source_dir);
		exit(0);
	}
	else
		getcwd(source_dir, sizeof(source_dir));				// Get absolute path

	//(2) If the destination directory doesn't exist, create it.
	if (chdir(destination_dir) <0) { 	// try to change directory
		chdir(temp_path);// the directory is in the source file right now
		mkdir(destination_dir, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		if (chdir(destination_dir) <0) {
			printf("%s is not a valid destination_dir.\n", destination_dir);
			return;
		}
		getcwd(destination_dir, sizeof(destination_dir));		// Get absolute path
		printf("Creating directory %s\n", destination_dir);
	}
	else 
		getcwd(destination_dir, sizeof(destination_dir));		// Get absolute path
	
	if (strcmp(destination_dir, source_dir)) {	// check if the source and destination =
		IsFile(source_dir, &info_mode, &user_id, &group_id);
		printf("Setting permissions for %s: %03o\n", destination_dir,  info_mode  & 07777);
		chmod(destination_dir, info_mode);
		printf("Setting user and group for %s: %d, %d\n", destination_dir,  user_id, group_id);
		chown(destination_dir, user_id, group_id);

		// printf("%s      %s\n\n", source_dir, destination_dir);  // for deugging
		
		//(3) Copy all files / directories in the source directory to the destination directory (recursively).
		//(4) Set permissions, owner, and group for each destination file / directory to that of the source file / directory. 
		Copy(source_dir, destination_dir);

		//(5) For 10 points extra credit, remove any files / directories in the destination directory not
		// in the source directory (recursively).
		RemoveExtras(source_dir, destination_dir) ;
	}
	return 0;
}
/* ---------------------------------------------------------------------- */
static void Copy(const char *source, const char *destination)
// This function performs the copying
{
	int  info_mode, user_id, group_id;
	char source_file[100];
	char destination_file [100];
    DIR *dirp;
    struct dirent *dp;
	int fd_to, fd_from;
	char buf[4096];
    ssize_t nread;
    int saved_errno;
	mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    if ((dirp = opendir(source)) == NULL) {
        perror("couldn't open '.'");
        return;
    }
    do {
        errno = 0;
        if ((dp = readdir(dirp)) != NULL) {
					// Create Full Path for source file
					strcpy(source_file, source);
					strcat(source_file, "/");
					strcat (source_file, dp->d_name);
					
					// Create Full Path for dest file
					strcpy(destination_file, destination);
					strcat(destination_file, "/");
					strcat(destination_file, dp->d_name);
				if (IsFile(source_file, &info_mode, &user_id, &group_id)) {// if file, then read and write
					// Open the files
					fd_from = open(source_file, O_RDONLY);
					if (fd_from < 0)
						printf("fuck1");
					
					fd_to = open(destination_file, O_WRONLY | O_CREAT  | O_TRUNC) ; 
						if (fd_to < 0)
							printf("fuck2");
					
					printf("Copying %s to %s\n", source_file, destination_file);
							//	printf("(%04o)", info_mode  & 07777);
					printf("Setting permissions for %s: %03o\n", destination_file,  info_mode  & 07777);
					chmod(destination_file, info_mode);
					printf("Setting user and group for %s: %d, %d\n", destination_file,  user_id, group_id);
					chown(destination_file, user_id, group_id);
					
					// Read and write the Files
					 while (nread = read(fd_from, buf, sizeof (buf)), nread > 0) {
						char *out_ptr = buf;
						ssize_t nwritten;
						do {
							nwritten = write(fd_to, out_ptr, nread);
							
							if (nwritten >= 0) {
								nread -= nwritten;
								out_ptr += nwritten;
							}
						} while (nread > 0);
					}
					
					// Close the files
					close(fd_from);
					close(fd_to);
				}
				else {// its a folder mkdir()
						if (( strcmp (dp->d_name, "..") ==1 ) && ( strcmp (dp->d_name, ".") ==1 ) ) {
							printf("Creating directory %s\n", destination_file);
							mkdir(destination_file, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
							printf("Setting permissions for %s: %03o\n", destination_file,  info_mode  & 07777);
							chmod(destination_file, info_mode);
							printf("Setting user and group for %s: %d, %d\n", destination_file,  user_id, group_id);
							chown(destination_file, user_id, group_id);
							Copy(source_file, destination_file);
						}
				}
	
			  continue;
            (void) closedir(dirp);
                return;
        }
    } while (dp != NULL);

    if (errno != 0)
        perror("error reading directory");
    else
       // (void) printf("failed to find %s\n", arg);
    (void) closedir(dirp);
    return;
}

/* ---------------------------------------------------------------------- */
int IsFile(const char* file , int* info_mode, int* user_id, int* group_id) {
// Description: Check if path is file

	struct stat info;
	stat(file, &info);
	*info_mode = (info.st_mode);
	*user_id = (info.st_uid);
	*group_id = (info.st_gid);
	//	printf("(%04o)", info_mode  & 07777);
	return (!stat(file, &info) && S_ISREG(info.st_mode));
}
/* ---------------------------------------------------------------------- */
static void RemoveExtras(const char* source, const char* destination) {
// Removes those unwanted files Recursively
	
	// Variables
	int found=0;		// Keeps track of if a file is found
	char source_file[100];
	char destination_file [100];
	int  info_mode, user_id, group_id;
	DIR *dirp1;
    struct dirent *dp1;
	DIR *dirp2;
    struct dirent *dp2;

	// Open files	
	
	if ((dirp2 = opendir(destination)) == NULL) {
        perror("couldn't open destination");
        return;
    }
    if ((dirp1 = opendir(source)) == NULL) {
        perror("couldn't open source");
        return;
    }

	// Double loop through the destination files
	// If a destination file isnt in the source directory, delete it
	// If it is a file. then recurse using this function.
	do {
		errno = 0;
        if ((dp2 = readdir(dirp2)) != NULL) {
			//printf("Destination: %s\n", dp2->d_name);
			found =0;
			do {
				 if ((dp1 = readdir(dirp1)) != NULL) {
				   //printf(" Source: %s\n", dp1->d_name); 
				   if ((strcmp(dp2->d_name, dp1->d_name) == 0)	
						&& ( strcmp (dp2->d_name, "..") ==1 ) && ( strcmp (dp2->d_name, ".") ==1 ))	 {// if they  are same
						found = 1;	// tracker enabled
					}
					continue;
					(void) closedir(dirp1);
				}
					// if the destination file wasnt found in the source dir, then delete it.
					if ((found != 1)  && ( strcmp (dp2->d_name, "..") ==1 ) && ( strcmp (dp2->d_name, ".") ==1 )){
						
						// Get Full path
						strcpy(source_file, source);
						strcat(source_file, "/");
						strcat (source_file, dp2->d_name);
						// Get Full path
						strcpy(destination_file, destination);
						strcat(destination_file, "/");
						strcat(destination_file, dp2->d_name); 
						
						// Remove File
						if (IsFile(destination_file, &info_mode, &user_id, &group_id)) {// if file read and write
							printf("Removing %s\n", destination_file);
							remove(destination_file);
						}
						else {// Recursively Remove Folder
							// Created a blank file so that the destination file is compared to 
							//nothing (so everything is removed).
							mkdir(source_file, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
							RemoveExtras(source_file, destination_file);	// Recursive Call
							remove(source_file);			// remove blank source dir
							remove(destination_file);	// remvoes unwanted destination dir
							printf("Removing %s\n", destination_file);
						}
					}
					found =0; // reset tracker
			} while (dp1 != NULL);
		
		if ((dirp1 = opendir(source)) == NULL) {
						return;
		}		
		continue;
		(void) closedir(dirp2);
		return;
        }
    } while (dp2 != NULL);

    if (errno != 0)
        perror("error reading directory");

    (void) closedir(dirp1);
	 (void) closedir(dirp2);
    return;
}