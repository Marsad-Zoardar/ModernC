//Author: Md Marsad Zoardar
//September 16, 2026
//Program 21: This program copy exactly the number of chars given by the user

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/*******************Design Decisions************************

The program can be accomplished using only one function.
 * The function will read a string, get the input from the user for its copied portion
 * and copy it to a buffer.

*/


int main(void){
    
    char string[] = "What a great day to program!";
    size_t capacity = 5;
    char *buffer = malloc(capacity*sizeof(char));
    
    
    /*How do I see the allocated size here? I could only see a pointer 8 bytes and a *pointer 1 byte*/
    
    return 0;
}


