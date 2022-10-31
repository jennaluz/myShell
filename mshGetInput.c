/*
 * /home/pura0273/homework/03/mshGetInput.c
 * cs-240.wilder..........gcc..........jenna-luz pura
 * october 31, 2022.......pura0273@vandals.uidaho.edu
 *
 * uses getchar() to read in user input character by character.
 *
 */

    /*macros*/
#define BUFFERLENGTH 256    //length of user input buffer

    /*system-defined includes*/
#include<stdio.h>   //printf() getchar()

    /*user-defined includes*/
#include"mshGetInput.h"

    /*function define*/
void mshGetInput(char *buffer)
{
        //variable defines
    char input = '\0';  //single char input

        //get the first char to check if first char is '\n'
    input = getchar();
    int idx = 0;    //index of buffer
    for (idx = 0; input != '\n' && idx < BUFFERLENGTH; idx++) {
        buffer[idx] = input;
        input = getchar();
    }

        //null terminate buffer
    buffer[idx] = '\0';
}
