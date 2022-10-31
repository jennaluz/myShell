/*
 * /home/pura0273/homework/03/mshFree.c
 * cs-240.wilder..........gcc..........jenna-luz pura
 * october 31, 2022.......pura0273@vandals.uidaho.edu
 *
 * uses free() to deallocate memory in bufferArgv and all of its arguments.
 *
 */

    /*system-defined includes*/
#include<stdlib.h>  //free()

    /*user-define includes*/
#include"mshFree.h"

    /*function define*/
void mshFree(char ***bufferArgv, int bufferArgc)
{

    // check for null pointers
    int i = 0;
    for (i = 0; i < bufferArgc; i++) {
        if ((*bufferArgv)[i] != NULL) {
            free((*bufferArgv)[i]);
            (*bufferArgv)[i] = NULL;
        }
    }

    if ((*bufferArgv) != NULL) {
        free(*bufferArgv);
        *bufferArgv = NULL;
    }
}
