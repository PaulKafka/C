/* 
Project 1 - UNIX Shell
By: Paul Kafka
Description:  shell that behaves similar to the tcsh shell in linprog
*/ 

// Libraries
#include <stdio.h>				// for input and output
#include <string.h>				// for string functions
#include <pwd.h>				// for pwd
#include <stdlib.h>				// std functions
#include <unistd.h>				// for chdir()
#include <sys/stat.h>			// for stat()
#include <sys/types.h>		// for fork()
#include <sys/wait.h>			// for wait()
#include <fcntl.h>				// for fcntl

// Deffinitions
#define _GNU_SOURCE
#define MAX_COMMAND_ARGS 9
#define MAX_COMMAND_SIZE 80
#define MAX_JOBS_SIZE 100

// Command Line Struct
typedef struct{
	int argc;				// Number of Arguments
	char* argv[MAX_COMMAND_ARGS + 1];
	char* outputFile;		// Outputfile Name
	char* inputFile;		// Input Filename
	char* BG_bool; 		// BG Processs?
} Command;

// Process Struct
typedef struct{
	int JID;							// Job ID
	int PID;						// Process ID
	char Command[20];	// User Command
} Job;

// Function Prototypes
int IsFile(const char* file);		// Checks to see if file exists
void FindExternal(const Command* command, Job* jobs, int *jobs_size); // Finds external
void PrintPrompt();																// Prints the Prompt
void FileRedirect(const Command* command);					// Handles File Redirection
void Cd(const Command* command);								// Handles CD
void Echo(const Command* command);							// Handles Echo
void Exit(const Command* command);								// Handles Exit
int ParseCommand(char* buffer, Command* command);	// Parces Command Input
void ExecuteExternal(const char* fullPath, const Command* 		// Handles External Commands
									command,Job* jobs, int *jobs_size);
void CreateBGProcess(Job* jobs, int *jobs_size, int pid,char* command);	// Creates BG Proc
void PrintBGProcess(const Job* jobs, int jobs_size);		// PRints BG Proc List

// Main Function
int main() {

	// Variables
	char buffer[MAX_COMMAND_SIZE + 1];	// Command Line Buffer
	Command command;									// Command Line Info
	Job jobs[MAX_JOBS_SIZE];						// BG Process Info
	int jobs_size = 0;											// Stores num of BG processes
	int i=0;					// Used for loops
	pid_t id;				// Used to check PID

	while (1) {		// loop forever

		//check bgprocess
		do {
			id = waitpid(-1, NULL, WNOHANG);		// Poll the processes for completion
			
			i =0;
			int x = 0; 
			if (id > 0) {	// If process completed
				for (i; i< jobs_size; i++) {						// Loop through job array
						if (jobs[i].PID == id) {					// If a job is complete
							x = i;											// Print which job
							printf("[%d] Done %s \n \n",jobs[i].JID, jobs[i].Command); 
						}
				}  
				// Shift the jobs down
				for (x; x< (jobs_size-1); x++) {
					jobs[x].PID = jobs[x+1].PID;
					jobs[x].JID = jobs[x+1].JID;
					strcpy(jobs[x].Command ,jobs[x+1].Command);
				} 
				jobs_size	= jobs_size -1;	// decrement counter
			}
		} while (id > 0);		// Do while the Process is finished
		
		// Print the Prompt
		PrintPrompt();
		
		// Read in the command line
		if (!fgets(buffer, MAX_COMMAND_SIZE, stdin)) {
			fprintf(stderr, "* fgets(): unable to gather command input.\n");
			continue;
		}
		buffer[strlen(buffer) - 1] = 0; // Adds the Null

		// Parse the Input Command
		if (!ParseCommand(buffer, &command))
			continue;

		if (command.argv[0] != NULL) {		// Check if anything typed

			// if token = exit
			if (strcmp("exit", command.argv[0]) == 0) {
				Exit(&command);
			}

			// if token = echo
			else if (strcmp("echo", command.argv[0]) == 0) {
				Echo(&command);
			}

			// if token = cd
			else if (strcmp("cd", command.argv[0]) == 0) {
				Cd(&command);
			}

			// if token = jobs
			else if (strcmp("jobs", command.argv[0]) == 0) {
				PrintBGProcess(jobs, jobs_size); 
			}

			// if external command
			else { 
				FindExternal(&command, jobs, &jobs_size);
			}
		}	// End of If Stmt
	}	// End of While Loop

	return 0;
	
}	// End of Main Function

/* 
-------------------------------------------------------------------------
-                   FUNCTION DEFINITIONS                     -
-------------------------------------------------------------------------
*/
/* ---------------------------------------------------------------------- */
void PrintPrompt() {
// Description: Print the Shell Prompt

	char * user = getenv("USER");		// Gets the current user
	char cwd[100];
	getcwd(cwd, sizeof(cwd));						// Get the current working directory
	printf("%s@myshell:%s> ",user, cwd);	// prints the prompt
}
/* ---------------------------------------------------------------------- */
void FileRedirect(const Command* command) {
// Description: Handles file redirection

	// If output redirection
	if (command->outputFile) {
		int out = open(command->outputFile, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);

		if (out == -1) {
			printf("%s: No such file or directory.\n", command->outputFile);
			exit(EXIT_FAILURE);
		}
		dup2(out, 1);
		close(out);
	}

	// If input redirection
	if (command->inputFile) {
		int in = open(command->inputFile, O_RDONLY);

		if (in == -1) {
			printf("%s: No such file or directory.\n", command->inputFile);
			exit(EXIT_FAILURE);
		}
		dup2(in, 0);
		close(in);
		}
}
/* ---------------------------------------------------------------------- */
void Exit(const Command* command) {
// Decription: Exits the Shell

	if (command->argc < 2)
		exit(0);
	else {
		printf("exit: Expression Syntax.\n");
	}
}
/* ---------------------------------------------------------------------- */
void Cd(const Command* command) {
// Description: Perfroms directory change

	char* cwd;
	if (command->argc > 2)
		printf("cd: Too many arguments.\n");
	else {
		if (command->argc == 1)
			cwd = getenv("HOME");
		else
			cwd = command->argv[1];
		if (chdir(cwd))
			printf("%s: No such file or directory.\n", cwd);
	}
}
/* ---------------------------------------------------------------------- */
void Echo(const Command* command) {
// Description: Performs Echo Command

	int i=1;
	for (i; i < command->argc; ++i)
		printf("%s ", command->argv[i]);
	printf("\n");
}
/* ---------------------------------------------------------------------- */
int ParseCommand(char* buffer, Command* command) {
// Parses the command line from white spaces

	char* tokens[MAX_COMMAND_ARGS];
	char* whitespace = " \n\r\f\t\v";
	int tokenNum = 0;

	// Initialize the command
	command->argc = 0;
	command->outputFile = NULL;
	command->inputFile = NULL;
	command->BG_bool = "0";

	// Aquire first token
	tokens[tokenNum] = strtok(buffer, whitespace);

	// Aquire other tokens
	while (tokens[tokenNum]) {
		++tokenNum;
		if (tokenNum == MAX_COMMAND_ARGS)
			break;
		tokens[tokenNum] = strtok(0, whitespace);
	}

	//setup the command structure.
	int i=0;
	for (i ; i < tokenNum; ++i) {

		/* First, look for special characters indicating
		redirect files or environment variables and & */
		if (!strcmp(tokens[i], ">"))
			command->outputFile = tokens[++i];		// the output file is before the >
		else if (!strcmp(tokens[i], "<"))
			command->inputFile = tokens[++i];		// the input file is before <
		else if (!strcmp(tokens[i], "&"))
			command->BG_bool = "1";						// & was found for BGprocess
		else if (tokens[i][0] == '$') { 							// Environmental Variable
			char* var = getenv((const char*)&tokens[i][1]);
			if (!var) {
				printf("%s: Undefined variable.\n", tokens[i]);
				return 0;
			}
			else {
				command->argv[command->argc] = var;
				++(command->argc);
			}
		}
		// Otherwise, assume a normal command argument.
		else {
			command->argv[command->argc] = tokens[i];
			++(command->argc);
		}
	}
	command->argv[command->argc] = 0;
	return 1;
}
/* ---------------------------------------------------------------------- */
void ExecuteExternal(const char* fullPath, const Command* 
									command, Job* jobs, int* jobs_size) {
// Description: Perfrom external commands

	pid_t pid = fork(); // create new child process

	if (pid < 0) // if failed to create process
		fprintf(stderr, "* ExecuteExternal(): fork() failed.\n");

	else if (pid == 0) {	// Child Process
		FileRedirect(command); // ceck if needs redirect

		//execute the external command.
		execv(fullPath, command->argv); 
		fprintf(stderr, "* ExecuteExternal(): unable to run command.\n");
		exit(EXIT_FAILURE);
	}

	// Not a BGprocess
	if (command->BG_bool == "0") { 
	waitpid(pid, 0, 0);		// parent process waits 
	}
	// Yes a BGprocess
	else if (command->BG_bool == "1") {
		CreateBGProcess(jobs, jobs_size, pid,(*command->argv));
	}
}
/* ---------------------------------------------------------------------- */
void FindExternal(const Command* command, Job* jobs, int *jobs_size) {
// Decription: Find the path to an external command.

	// Variables
	char* paths;
	char* pathsCopy;
	char* fullPath;
	char* tokenPtr;

	// If the command has a / in it, run it directly.
	if (strchr(command->argv[0], '/')) {
		if (IsFile(command->argv[0]))
			ExecuteExternal(command->argv[0], command, jobs, jobs_size );
	else
		printf("%s: Command not found.\n", command->argv[0]);
	}

	// Otherwise, search for the command.
	else {
		//Get the paths and make a copy of them. */
		paths = getenv("PATH");
		if (paths)
			pathsCopy = (char*)malloc(strlen(paths) + 1);
		else{
			fprintf(stderr, "* FindExternal(): unable to get paths.\n");
			return;
		}

		if (pathsCopy)
			strcpy(pathsCopy, paths);
		else {
			fprintf(stderr, "* FindExternal(): unable to copy paths.\n");
			return;
		}

		//Tokenize the path, assuming a : delimiter.
		tokenPtr = strtok(pathsCopy, ":");
		while (tokenPtr) {
			// Make room for the path, command, null character, and slash. */
			fullPath = (char*)malloc(strlen(tokenPtr) + strlen(command->argv[0]) + 2);

			if (!fullPath) {
				fprintf(stderr, "* FindExternal(): unable to create full path.\n");
				return;
			}

			//Create full path 
			strcpy(fullPath, tokenPtr);
			strcat(fullPath, "/");
			strcat(fullPath, command->argv[0]);

			// If the path exists, run the command.
			if (IsFile(fullPath)) {
				ExecuteExternal(fullPath, command, jobs, jobs_size);
				free(fullPath);
				free(pathsCopy);
				return;
			}
			free(fullPath);
			tokenPtr = strtok(0, ":");
		}
		free(pathsCopy);

		// Command isn't found in any path
		printf("%s: Command not found.\n", command->argv[0]);
	}
}
/* ---------------------------------------------------------------------- */
int IsFile(const char* file) {
// Description: Check if path is file

	struct stat info;
	return (!stat(file, &info) && S_ISREG(info.st_mode));
}
/* ---------------------------------------------------------------------- */
void CreateBGProcess(Job* jobs, int *jobs_size, int pid, char*command) {
// Description: When a fork is called for a background process, this
// function adds the process to the job array and prints a message
// prints [JID] [PID]

	// if first new process
	if (*jobs_size == 0) {
		jobs[*jobs_size].JID = 1;
		printf("[%d] ",jobs[*jobs_size].JID);
		jobs[*jobs_size].PID = pid;
		printf("[%d] \n \n",jobs[*jobs_size].PID);
		strcpy(jobs[*jobs_size].Command ,command);
	}

	else { 
		// find max JID
		int i =0;
		int maxJID = 0;
		for (i; i< *jobs_size; i++) {
			if ( jobs[i].JID > maxJID) 
				maxJID = jobs[i].JID;
		}
		// new JID is incremented from maxJID
		if ( maxJID >0) {
			jobs[*jobs_size].JID = maxJID+1;
			printf("[%d] ",jobs[*jobs_size].JID);
			jobs[*jobs_size].PID = pid;
			printf("[%d] \n \n",jobs[*jobs_size].PID);
			strcpy(jobs[*jobs_size].Command ,command);
		}
	}
	*jobs_size = *jobs_size +1;		// Increments the job size
}
/* ---------------------------------------------------------------------- */
void PrintBGProcess(const Job* jobs, int jobs_size) {
// Description: When the users types "jobs", this function 
// prints the running jobs

// prints [JID] tab [PID] tab Command
	int i = 0;
	for (i; i<jobs_size; i++)
		printf("[%d] \t [%d] \t %s \n", jobs[i].JID, jobs[i].PID, jobs[i].Command);
}
/* ---------------------------------------------------------------------- */