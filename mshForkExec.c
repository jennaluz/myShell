/*
 * /home/pura0273/homework/03/mshForkExec.c
 * cs-240.wilder..........gcc..........jenna-luz pura
 * october 31, 2022.......pura0273@vandals.uidaho.edu
 *
 * uses fork() to spawn a new process.
 * uses execvp() to overlay the spawned process with a user-specified Linux command.
 * returns enum STATUS of ERROR when fork() or exec() fails and SUCCESS when both are successful.
 *
 */

    /*system-defined includes*/
#include<stdio.h>       //perror()
#include<stdlib.h>      //malloc() free()
#include<unistd.h>      //fork()
#include<sys/wait.h>    //waitpid()

    /*user-define include*/
#include"mshForkExec.h"

    /*function define*/
int mshForkExec(char **bufferArgv)
{
        //status code
    STATUS = SUCCESS;

        //fork a new process
    pid_t childPID = fork();
    if (childPID == -1) {
        perror("error: fork failed");
        return ERROR;
    }
    else if (childPID == 0) {
            //exec new process
        STATUS = execvp(bufferArgv[0], bufferArgv);
        if (STATUS == ERROR) {
            printf("error: '%s' is not a valid command\n", bufferArgv[0]);
        }
        return STATUS;
    }
    else {
        int childStatus;
        (void)waitpid(childPID, &childStatus, 0);
    }

    return STATUS;
}
