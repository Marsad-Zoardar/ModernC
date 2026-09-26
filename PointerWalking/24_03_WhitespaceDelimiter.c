//Author: Md Marsad Zoardar
//September 26, 2026
//Program 24: In this program, I will try to create my own tokenizer that behave like strtok() when finds a whitespace

/***********************************Design decisions*****************************************/
/*
Step 1: Read a string
Step 2: Insert a null terminator '\0' at space between words
Step 3: If found multiple spaces, it sets the first space to '\0' and keeps pointing to it
Step 4: When looking for the next word, it skips additional spaces and moves to the next available character
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

static char *nextPtr = NULL;
static int finished = 0;

char *newStartPtr(char *ptr);

int main(void){
    
    char string[] = "   ";
    /*
     * Test cases
     * "It will be heck of a programming day!"
     * "Hello world" -->prints "Hello"
     * "  Hello world" --> prints "  Hello" //Problematic
     * "Hello   world" --> prints "Hello"
     * "Hello world  " --> prints "Hello"  
     */
     
    printf("Result: %s\n", newStartPtr(string));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    printf("Result: %s\n", newStartPtr(NULL));
    
    
    return 0;
}

char *newStartPtr(char *ptr){
    
    char *sPtr = NULL;
    //This check needs to happen before it checks for ptr == NULL
    
    if(finished || (ptr == NULL && nextPtr == NULL)){
        return NULL;
    }
    if(ptr == NULL && nextPtr != NULL){
        ptr = nextPtr;
    }
  
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
            ptr++;//If space is found, increment pointer to the next memory location
        }else{
            sPtr = ptr;
            //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                while(!isspace((unsigned char)*ptr)){
                    //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                    ptr++;
                        if(*ptr == '\0'){
                            //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                            //nextPtr = ptr;
                            finished = 1;
                            //printf("Finished = %d and nextPtr = %p\n", finished, (void*) nextPtr);
                            return sPtr;
                        }
                }
            *ptr = '\0';
            //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
            ptr++;
                while(isspace((unsigned char)*ptr)){
                    //printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                    ptr++;
                }
                if(*ptr == '\0'){
                    nextPtr = NULL;
                }else{
                 nextPtr = ptr;   
                }
            //printf("Finished = %d and nextPtr = %p\n", finished, (void*) nextPtr);
            return sPtr;
            
        }
    }
    
    //printf("Finished = %d and nextPtr = %p\n", finished, (void*) nextPtr);
        
    return sPtr;
}