/*
 * /home/pura0273/homework/03/mshTokenize.c
 * cs-240.wilder..........gcc..........jenna-luz pura
 * october 31, 2022.......pura0273@vandals.uidaho.edu
 *
 * tokenizes a stream of input (buffer) modifies bufferArgc in msh.c.
 * uses enum STATUS values to return SUCCESS (0) upon proper completion and ERROR (-1) when malloc() fails.
 * first finds the number of arguments in buffer.
 * then assigns the value of each arugment and stores it in a 'two dimensional array' (bufferArgv).
 *
 */

    /*system-defined includes*/
#include<stdio.h>   //perror()
#include<stdlib.h>  //malloc()
#include<ctype.h>   //isspace()
#include<string.h>  //strlen() strncpy()

    /*user-define includes*/
#include"mshTokenize.h"

    /*function define*/
int mshTokenize(char *buffer, char ***bufferArgv, int *bufferArgc) { //buffer is user input
        //initialize variables
    int start = 0;
    int end = 0;
    int length = strlen(buffer);    //gets the length of the user input string

        //first find the number of arguments
    for (end = 0; end < length; end++) {
            //looks for first non-white space char. ie., checks for leading spaces
        while ((isspace(buffer[end]) != 0) && (end < length)) {
            end++;
        }

            //checks if input was only white-spaces
        if (end == length) {
            break;
        }

            //should be at a letter right now. finds next white-space
        while ((isspace(buffer[end]) == 0) && (end < length)) {
            end++;
        }

            //increment bufferArgc
        (*bufferArgc)++;
    }

        //deferences bufferArgv to be equal to argv in main and allocates the amount of arguments
    *bufferArgv = (char**)malloc(sizeof(char*) * (*bufferArgc + 1)); //*bufferArgc + 1 because execvp() needs a char array whose last argument is a NULL pointer

        //if malloc fails
    if (*bufferArgv == NULL) {
        perror("error: could not malloc\n");
        return ERROR;
    }

        //reinitialize variables
    start = 0;
    end = 0;
    int argSize = 0;

        //next, assign the value of each argument
    int i = 0;
    for (i = 0; i < *bufferArgc; i++) {
            //looks for first non-white space char. ie., checks for leading spaces
        while ((isspace(buffer[end]) != 0) && (end < length)) {
            end++;
        }
        start = end;

            //finds the end of the first word
        while ((isspace(buffer[end]) == 0) && (end < length)) {
            end++;
        }

            //allocate space for each argument
        argSize = end - start;
        (*bufferArgv)[i] = (char*)malloc(sizeof(char) * (argSize + 1)); //should allocate length of the argument + 1 for the null char

            //if malloc does not work
        if ((*bufferArgv)[i] == NULL) {
            printf("error: could not malloc\n");
            return ERROR;
        }

            //copy argument in corresponding bufferArgv
        strncpy((*bufferArgv)[i], &buffer[start], argSize); //&buffer[start] is the location of the source at index start
        (*bufferArgv)[i][argSize] = '\0';

        end++;
        start = end;
    }

        //create null pointer argument
    (*bufferArgv)[*bufferArgc] = NULL; //execvp() needs a char **arr whose last arugment is a null pointer

    return SUCCESS;
}
