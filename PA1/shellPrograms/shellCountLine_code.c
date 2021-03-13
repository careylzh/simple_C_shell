#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{
    char* buffer = malloc(sizeof(int) * 32); //temp store for file pointer
    size_t linePointerSize = sizeof(buffer);
    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this

    char *lineBuffer = NULL; //dk whether to malloc or not
    size_t lineBuffer_size = 0; //when overflow will expand according so yolo dc
    int lineCount = 0;
    ssize_t linePointer; 
    //this is the file pointer, contains address to file
    FILE* fp = fopen(args[1], "r");  // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    if(!fp){
        printf("file not found");
        exit(1);     // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    }
    linePointer = getline(&lineBuffer, &lineBuffer_size, fp);  // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    while (linePointer > -1) //if file still has non-null lines then go on to next line. when getline returns -ve means no more lines
    {   
        lineCount++;
        linePointer = getline(&lineBuffer, &lineBuffer_size, fp);
    }
    free(lineBuffer); //free contents of a memory address stated in target pointer
    lineBuffer = NULL;    
    fclose(fp);     // 6. Close the FILE*
    printf("There are %d lines in %s \n", lineCount, args[1]);     // 7. Print out how many lines are there in this particular filename
    return 1;     // 8. Return 1, to exit program
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}