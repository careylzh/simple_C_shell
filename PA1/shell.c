#include "shell.h"
#include <stdbool.h>

/*
 List all files matching the name in args[1] under current directory and subdirectories
*/
int shellFind(char **args)
{

  printf("shellFind is called!\n");

  /** TASK 4 **/
  pid_t pid = fork(); //fork first then overlay target prog with sys call 
  int status;
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call, meaning use execvp sys call
  if(pid<0){
    printf("fork failed. sad. \n");
    exit(1); //rmb to close prog properly
  }
  else if(pid == 0){
     // 2. Check if execvp is successful by checking its return value
    //progress fails to execute sucessfully
     if(execvp("./shellPrograms/find", args) < 0){
     printf("Invalid directory for target executable of Find\n");
     exit(1);
   }
   else{
     do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
  }
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellFind if execvp fails to allow loop to continue
}

/**
 Allows one to display the content of the file
 */
int shellDisplayFile(char **args)
{
  printf("shellDisplayFile is called!\n");

  /** TASK 4 **/
  pid_t pid = fork(); //fork first then overlay target prog with sys call 
  int status;
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call, meaning use execvp sys call
  if(pid<0){
    printf("fork failed. sad. \n");
    exit(1); //rmb to close prog properly
  }
  else if(pid == 0){
     // 2. Check if execvp is successful by checking its return value
    //progress fails to execute sucessfully
     if(execvp("./shellPrograms/display", args) < 0){
     printf("Invalid directory for target executable of DisplayFile\n");
     exit(1);
   }
  }
   else{
     do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  // 1. Execute the binary program 'display' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDisplayFile if execvp fails to allow loop to continue

  return 1;
}

/*
	List the items in the directory and subdirectory
*/
int shellListDirAll(char **args)
{

  printf("shellListDirAll is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'listdirall' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDirAll if execvp fails to allow loop to continue
  pid_t pid = fork(); //fork first then overlay target prog with sys call 
  int status;
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call, meaning use execvp sys call
  if(pid<0){
    printf("fork failed. sad. \n");
    exit(1); //rmb to close prog properly
  }
  else if(pid == 0){
     // 2. Check if execvp is successful by checking its return value
    //progress fails to execute sucessfully
     if(execvp("./shellPrograms/listdirall", args) < 0){
     printf("Invalid directory for target executable of ListDirAll\n");
     exit(1);
   }
  }
   else{
     do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

/*
	List the items in the directory
*/
int shellListDir(char **args)
{
  printf("shellListDir is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'listdir' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellListDir

  pid_t pid = fork(); //fork first then overlay target prog with sys call 
  int status;
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call, meaning use execvp sys call
  if(pid<0){
    printf("fork failed. sad. \n");
    exit(1); //rmb to close prog properly
  }
  else if(pid == 0){ //if pid no 0 means child process not done, go to do while
     // 2. Check if execvp is successful by checking its return value
    //progress fails to execute sucessfully
     if(execvp("./shellPrograms/listdir", args) < 0){
     printf("Invalid directory for target executable of ListDir\n");
     exit(1);
   }
  }
   else{
     do { 
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

/**
   Counts how many lines are there in a text file. 
   A line is terminated by \n character
**/
int shellCountLine(char **args)
{
  printf("shellCountLine is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'countline' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCountLine if execvp fails to allow loop to continue
  pid_t pid = fork(); //fork first then overlay target prog with sys call 
  int status;
  // 1. Execute the binary program 'find' in shellPrograms using execvp system call, meaning use execvp sys call
  if(pid<0){
    printf("fork failed. sad. \n");
    exit(1); //rmb to close prog properly
  }
  else if(pid == 0){
     // 2. Check if execvp is successful by checking its return value
    //progress fails to execute sucessfully
     if(execvp("./shellPrograms/countline", args) < 0){
     printf("Invalid file for target executable of CountLine\n");
     exit(1);
   }
  }
  else{
     do {
      waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }
  return 1;
}

/**
 * Allows one to create a daemon process
 */
int shellSummond(char **args)
{
  printf("shellDaemonize is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'summond' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellDaemonize if execvp fails to allow loop to continue
  pid_t pid;
  int status;
  if((pid = fork())<0){
    printf("Fork Failed\n");
    exit(1);
  }
  else if(pid == 0){
    if(execvp("./shellPrograms/summond", args)<0){
      printf("Invalid directory provided for Summond executable\n");
      exit(1);
    }  
  }
  else{
    do {
          waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }
  return 1;
  
}

/**
 * Allows one to check daemon process
 * 
 */
int shellCheckDaemon(char **args)
{
  printf("shellCheckDaemon is called!\n");

  /** TASK 4 **/
  // 1. Execute the binary program 'checkdaemon' in shellPrograms using execvp system call
  // 2. Check if execvp is successful by checking its return value
  // 3. A successful execvp never returns, while a failed execvp returns -1
  // 4. Print some kind of error message if it returns -1
  // 5. return 1 to the caller of shellCheckDaemon if execvp fails to allow loop to continue
  pid_t pid;
  int status;
  if((pid = fork())<0){
    printf("Fork Failed\n");
    exit(1);
  }
  else if(pid == 0){
    if(execvp("./shellPrograms/checkdaemon", args)<0){
      printf("Invalid directory provided for Summond executable\n");
      exit(1);
    }  
  }
  else{
    do {
          waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
      }
  return 1;
}

/**
   Allows one to change directory 
 */
int shellCD(char **args)
{
  printf("shellCD is called! \n");
  if (args[1] == NULL)
  {
    fprintf(stderr, "CSEShell: expected argument to \"cd\"\n");
  }
  else
  {
    // chdir() changes the current working directory of the calling process
    // to the directory specified in path.
    if (chdir(args[1]) != 0)
    { //use chdir
      perror("CSEShell:");
    }
  }

  return 1;
}

/**
   Prints out the usage and
   list of commands implemented
 */
int shellHelp(char **args)
{
  printf("shellHelp is called! \n");
  int i;
  printf("CSE Shell Interface\n");
  printf("Usage: command arguments\n");
  printf("The following commands are implemented:\n");

  for (i = 0; i < numOfBuiltinFunctions(); i++)
  {
    printf("  %s\n", builtin_commands[i]); //print all the commands that have been implemented in the shell program
  }

  return 1;
}

/**
  Returns 0, to terminate execution from the shellLoop
 */
int shellExit(char **args)
{
  return 0;
}

/*
  Builtin function implementations.
*/
int shellUsage(char **args)
{
  int functionIndex = -1;

  // Check if the commands exist in the command list
  for (int i = 0; i < numOfBuiltinFunctions(); i++)
  {
    if (strcmp(args[1], builtin_commands[i]) == 0)
    {
      //pass it to the functions
      functionIndex = i;
    }
  }

  switch (functionIndex)
  {
  case 0:
    printf("Type: cd directory_name\n");
    break;
  case 1:
    printf("Type: help\n");
    break;
  case 2:
    printf("Type: exit\n");
    break;
  case 3:
    printf("Type: usage command\n");
    break;
  case 4:
    printf("Type: display filename\n");
    break;
  case 5:
    printf("Type: countline filename\n");
    break;
  case 6:
    printf("Type: listdir\n");
    printf("Type: listdir -a to list all contents in the current dir and its subdirs\n");
    break;
  case 7:
    printf("Type: listdirall\n");
    break;
  case 8:
    printf("Type: find filename_keyword\n");
    break;
  case 9:
    printf("Type: summond \n");
    break;
  case 10:
    printf("Type: checkdaemon \n");
    break;
  default:
    printf("Command %s not found\n", args[0]);
    break;
  }

  return 1;
}
/*
  End of builtin function implementations.
*/

/**
   Execute inputs when its in the default functions
   Otherwise, print error message and return to loop
 */
int shellExecuteInput(char **args)
{
  /** TASK 3 **/
  bool argIsValid = false;
  int index = 0; //index to reference the built in command used
  // 1. Check if args[0] is NULL. If it is, an empty command is entered, return 1
  if (args[0] == NULL)
  {
    return 1;
  }
  // 2. Otherwise, check if args[0] is in any of our builtin_commands, and that it is NOT cd, help, exit, or usage.
  else {
    for (int i = 0; i < (sizeof(builtin_commands) / sizeof(builtin_commands[0])); i++){ //compare first arg to each of the builtin_commands
      if (strcmp(args[0], builtin_commands[i]) == 0){
        argIsValid = true;
        index = i; }
    }
    // 3. If conditions in (2) are satisfied, perform fork(). Check if fork() is successful.
    if (argIsValid && index > 3) {
      pid_t pid_child = fork();
      pid_t parentid;
      int status;
      if (pid_child < 0) { 
        fprintf(stderr, "Fork failed.\n"); }
      else if (pid_child == 0) {
        builtin_commandFunc[index](args);
        exit(1); }
      else {
        fprintf(stderr, "Fork works, waiting for child process\n");
        parentid = waitpid(pid_child, &status, WUNTRACED); //turn value into pointer
        return parentid; }
    }
    else if (argIsValid && index < 3){
      //not forking but making a sys call (ie.e cd/usage etc etc)
      return builtin_commandFunc[index](args);}    
  }
 printf("Invalid command. Try again");
 return 1;
  // 4. For the child process, execute the appropriate functions depending on the command in args[0]. Pass char ** args to the function.
  // 5. For the parent process, wait for the child process to complete and fetch the child's return value.
  // 6. Return the child's return value to the caller of shellExecuteInput
  // 7. If args[0] is not in builtin_command, print out an error message to tell the user that command doesn't exist and return 1
}

/**
   Read line from stdin, return it to the Loop function to tokenize it
 */
char *shellReadLine(void)
{
  /** TASK 1 **/
  // read one line from stdin using getline()
  // 1. Allocate a memory space to contain the string of input from stdin using malloc. Malloc should return a char* that persists even after this function terminates.
  char *buffer = malloc(sizeof(int) * 10);
  size_t bufferSize = SHELL_BUFFERSIZE;
  // 2. Check that the char* returned by malloc is not NULL
  if (buffer == NULL)
  {
    exit(1);
  }
  // 3. Fetch an entire line from input stream stdin using getline() function. getline() will store user input onto the memory location allocated in (1)
  getline(&buffer, &bufferSize, stdin);
  return buffer; // 4. Return the char* //is a string tho
}

/**
 Receives the *line, and return char** that tokenize the line
**/
char **shellTokenizeInput(char *line)
{

  /** TASK 2 **/
  char **pointersOfPointersTokenAddress = malloc(sizeof(char *) * SHELL_BUFFERSIZE);
  // 1. Allocate a memory space to contain pointers (addresses) to the first character of each word in *line. Malloc should return char** that persists after the function terminates.
  char *token = strtok(line, SHELL_INPUT_DELIM);
  int index = 0;
  // 2. Check that char ** that is returend by malloc is not NULL
  if (pointersOfPointersTokenAddress == NULL)
  {
    exit(1);
  }
  //without these 2 lines, the function tokenises from 2nd arg onwards.
  pointersOfPointersTokenAddress[index] = token;
  index++;
  // 3. Tokenize the *line using strtok() function
  while (token != NULL)
  {
    token = strtok(NULL, SHELL_INPUT_DELIM);
    pointersOfPointersTokenAddress[index] = token;
    index++;
  }
  pointersOfPointersTokenAddress[index] = NULL;
  // 4. Return the char **
  return pointersOfPointersTokenAddress;
}

/**
  The main loop where one reads line,
  tokenize it, and then executes the command
 */
void shellLoop(void)
{
  //instantiate local variables
  char *line;  // to accept the line of string from user
  char **args; // to tokenize them as arguments separated by spaces
  int status = 1;  // to tell the shell program whether to terminate shell or not

  /** TASK 5 **/
  //write a loop where you do the following:
// 8. check if shellExecuteInput returns 1. If yes, loop back to Step 1 and prompt user with new input. Otherwise, exit the shell.
  while(status){
      // 1. print the message prompt
      // 2. clear the buffer and move the output to the console using fflush
    printf("CSEshell:");
    fflush(stdout);
    // 3. invoke shellReadLine() and store the output at line
    // 4. invoke shellTokenizeInput(line) and store the output at args**
    line =shellReadLine();
    args = shellTokenizeInput(line);
      // 5. execute the tokens using shellExecuteInput(args)
    status = shellExecuteInput(args);
  // 6. free memory location containing the strings of characters
  // 7. free memory location containing char* to the first letter of each word in the input string
    free(line);
    free(args);
    if(status == 0){
      printf("invalid command");
      break;

    }
      }
  exit(1);
}



int main(int argc, char **argv)
{
 
 printf("Shell Run successful. Running now: \n");
 
 shellLoop();
 
 return 0;
}

