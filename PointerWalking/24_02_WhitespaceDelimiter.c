//Author: Md Marsad Zoardar
//September 19 & 22, 2026
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

static char *nextPtr = NULL;
//static size_t spaceCount = 0;

char *startPtr(char *ptr);

int main(void){
    
    char string[] = "  It    will be heck of a programming day!";
    /*
     * Test cases
     * "It will be heck of a programming day!"
     * "Hello world" -->prints "Hello"
     * "  Hello world" --> prints "  Hello" //Problematic
     * "Hello   world" --> prints "Hello"
     * "Hello world  " --> prints "Hello"  
     */
     
    printf("Result: %s\n", startPtr(string));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    printf("Result: %s\n", startPtr(NULL));
    
    return 0;
}

char *startPtr(char *ptr){
    
    char *sPtr = NULL;
    size_t i = 1;
    
    if(ptr != NULL){
    //Step 1: Read through the string
        //printf("Step 1: String is not NULL. Reading the string\n---------------------------\n");
        while(*ptr != '\0'){
            //printf("While loop iteration %zu\n", i);
            i++;
            //Step 2: If find a space in the beginning, Skip
            //printf("Step 2: Checking for space/s\n---------------------------\n");
            if(isspace((unsigned char)*ptr)){
                //printf("Space found. Skipping....\n");
                //printf("Pointer is at \"%p\" and the content is \"%c\"\n", ptr, *ptr);
                ptr++;//If space is found, increment pointer to the next memory location
            }else{
            //Step 3: If another space found after the char, set that pointer to '\0'
                sPtr = ptr;
                while(*ptr != ' '){
                    ptr++;
                    if(*ptr == '\0'){
                        nextPtr = ptr;
                        break;
                    }
                }
                *ptr = '\0';
                ptr++;
                while(*ptr == ' '){
                    ptr++;
                }
            nextPtr = ptr;
            //printf("ptr = %p and nextPtr = %p and content = %c\n", ptr, nextPtr, *nextPtr);
            
            return sPtr;
            
            }
            i = 0;
        }  
    }else{
        //printf("Entered \"string(NULL)\"\nExecuting ptr = nextPtr : %p = %p\n", ptr, nextPtr);
        ptr = nextPtr;
        //printf("Now ptr = %p and content = %c\nIncrementing ptr\n", ptr, *ptr);
        while(*ptr != '\0'){
        
            if(isspace((unsigned char)*ptr)){
                ptr++;//If space is found, increment pointer to the next memory location
            }else{
            //Step 3: If another space found after the char, set that pointer to '\0'
            sPtr = ptr;
                while(*ptr != ' '){
                    ptr++;
                        if(*ptr == '\0'){
                            nextPtr = ptr;
                            break;
                        }
                }
                
            *ptr = '\0';
            ptr++;
                while(*ptr == ' '){
                    ptr++;
                }
            nextPtr = ptr;
            return sPtr;
            //printf("ptr = %p and nextPtr = %p and content = %c\n", ptr, nextPtr, *nextPtr);
            }
    
        }
    }
        
    return sPtr;
}