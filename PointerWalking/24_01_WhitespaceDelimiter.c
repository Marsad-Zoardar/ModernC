//Author: Md Marsad Zoardar
//September 19, 2026
//Program 24: In this program, I will try to create my own tokenizer that behave like strtok() when finds a whitespace

/***********************************Design decisions*****************************************/
/*
Step 1: Read a string
Step 2: Insert a null terminator '\0' at space between words
Step 3: If found multiple spaces, it sets the first space to '\0' and keeps pointing to it
Step 4: When looking for the next word, it skips additional spaces and moves to the next available character
*/

/**********************************Psudocode************************************************/
/*
--> Set pointer to the begininning of the first char
-->Starting from the first word, look for a whitespace. If found, set that pointer to '\0'.
-->Look for the next word and keep inserting '\0' when there's a single space found.

                                        Read string
                                            |
                                            |
                          ------------------------------------
                          |                 ^                 |
                     Char Found             |                 |
                          |                 |                 |
                          |                 |                 |
                Increment Pointer           |            Space Found
                          |                 |                 |
                          |                 |                 |
                     Space Found            |                Skip  
                          |                 |            
                          |                 |             
                    Set to '\0' ----------->                           
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

char *nextWord(char *ptr);
void insertNull(char *strPtr);

/**This program is conceptually right. But I need to accomplish it in one pass. Redoing it***/

//int main(void){
//    
//    char string[] = "It will be heck of a programming day!";
//    /*
//     * Test cases
//     * "It will be heck of a programming day!"
//     * "Hello world" -->prints "Hello"
//     * "  Hello world" --> prints "  Hello" //Problematic
//     * "Hello   world" --> prints "Hello"
//     * "Hello world  " --> prints "Hello"  
//     */
//    char *wordStarts = nextWord(string);
//    //printf("Word starts at = %p and the char is = %c\n", (void*) wordStarts, *wordStarts);
//    
//    insertNull(wordStarts);
//    
//    printf("Result: %s\n", nextWord(string));
//    
//    
//    return 0;
//}

//This function returns the pointer where the fist word starts.
char *nextWord(char *ptr){
    char *firstPtr = NULL;
    
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            ptr++;
        }else{
            firstPtr = ptr;
            return firstPtr;
        }
    }
    return firstPtr;
}

//This function inserts a null terminator '\0' after every word it finds.
void insertNull(char *strPtr){
    
    while(*strPtr != '\0'){
        if(isspace((unsigned char)*strPtr)){
            strPtr++;
        }else{
            strPtr++;
            if(isspace((unsigned char)*strPtr)){
                *strPtr = '\0';
                strPtr++;
            }
        }    
    }
}