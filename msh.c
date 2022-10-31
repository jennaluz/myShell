/*
 * /home/pura0273/homework/03/msh.c
 * cs-240.wilder..........gcc..........jenna-luz pura
 * october 31, 2022.......pura0273@vandals.uidaho.edu
 *
 * executes msh (myshell) and gets Linux commands from user.
 * uses enum STATUSCODE to determine how to exit the program
 *      returns SUCCESS (0) if no ERROR (-1) occurred.
 *      returns FAILURE (1) if ERROR (-1) occurred.
 * with each command, the msh fork() and exec() to emulate Linux commands.
 * when the user types exit, msh terminates.
 *
 */

    /*macros*/
#define BUFFERLENGTH 256    //length of user input buffer

    /*system-defined includes*/
#include<stdio.h>   //printf()
#include<stdlib.h>  //free()
#include<string.h>  //strcmp()

    /*user-defined includes*/
#include"mshStatusCode.h"
#include"mshGetInput.h"
#include"mshTokenize.h"
#include"mshForkExec.h"
#include"mshFree.h"

    /*main*/
int main()
{
        //status code
    STATUS = SUCCESS;

        //variable defines
    char buffer[BUFFERLENGTH + 1] = ""; //+1 accounts for null terminating char
    char **bufferArgv = NULL;           //stores the user arguments
    int bufferArgc = 0;                 //number of user arguments, used for freeing

    printf("MyShell\n");
    while (1) { //will always run until program specifies a return
            //reinitialize variables
        bufferArgc = 0; //if not, the bufferArgc will continuously increase with each user prompt

            //get user input
        printf(">: "); //user prompt
        mshGetInput(buffer);

            //tokenize user input and store into bufferArgv
        STATUS = mshTokenize(buffer, &bufferArgv, &bufferArgc);
        if (STATUS == ERROR) {  //malloc() in mshTokenize() failed
            mshFree(&bufferArgv, bufferArgc);
            return FAILURE;
        }

        if (strcmp(bufferArgv[0], "exit") == 0) {   //user wishes to exit
            mshFree(&bufferArgv, bufferArgc);
            return SUCCESS;
        }

            //attempt to execute user-specified Linux command
        STATUS = mshForkExec(bufferArgv);
        mshFree(&bufferArgv, bufferArgc);

            //STATUS == ERROR if exec failed (user gave invalid command). still in the child process so it must be exited and terminated
        if (STATUS == ERROR) {
            return FAILURE;
        }
    }

    return SUCCESS;
}
