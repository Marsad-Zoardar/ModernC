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
    
    //char string[] = "   ";
    /*
     * Test cases
     * "It will be heck of a programming day!"
     * "Hello world" -->prints "Hello"
     * "  Hello world" --> prints "  Hello" //Problematic
     * "Hello   world" --> prints "Hello"
     * "Hello world  " --> prints "Hello"  
     */
     
//    printf("Result: %s\n", newStartPtr(string));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));
//    printf("Result: %s\n", newStartPtr(NULL));

    char string1[] = "Hello world";
    //char string2[] = "Good morning";

    printf("%s\n", newStartPtr(string1));
    printf("%s\n", newStartPtr(NULL));
    printf("%s\n", newStartPtr(NULL));

    //printf("%s\n", newStartPtr(string2));    
    
    return 0;
}

char *newStartPtr(char *ptr){
    
    char *sPtr = NULL;
    //This check needs to happen before it checks for ptr == NULL
    printf("Finished = %d\t\tptr = %p\t\tnextPtr = %p\n\n", finished, (void*) ptr, (void*) nextPtr);
    if(finished || (ptr == NULL && nextPtr == NULL)){
        printf("Finished = 1 || (ptr == NULL && nextPtr == NULL). \nReturning\n");
        return NULL;
    }
    
    if(ptr == NULL && nextPtr != NULL){
        printf("ptr == NULL && nextPtr != NULL\nSetting ptr = nextPtr\n");
        ptr = nextPtr;
        printf("ptr = %p\tcontent = %c\t|||nextPtr = %p\tcontent = %c\n", (void*)ptr, *ptr, (void*) nextPtr, *nextPtr);
    }
    
        
        while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
            ptr++;//If space is found, increment pointer to the next memory location
        }else{
            sPtr = ptr;
            printf("Char found is: \'%c\' at\t%p\n", *ptr, ptr);
                while(!isspace((unsigned char)*ptr)){
                    printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                    ptr++;
                        if(*ptr == '\0'){
                            printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                            nextPtr = ptr;
                            finished = 1;
                            printf("Finished = %d and nextPtr = %p\n", finished, (void*) nextPtr);
                            printf("1: Finished = %d\nptr = %p\tcontent = %c\nnextPtr = %p\tcontent = %c\n", finished, (void*) ptr, *ptr, (void*) nextPtr, *nextPtr);
                            return sPtr;
                        }
                }
            *ptr = '\0';
            printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
            ptr++;
                while(isspace((unsigned char)*ptr)){
                    printf("Char is: \'%c\' at\t%p\n", *ptr, ptr);
                    ptr++;
                }
                if(*ptr == '\0'){
                    printf("Found the end of the string. Setting nextPtr = NULL\n");
                    nextPtr = NULL;
                }else{
                 printf("Haven't reached the end of the string. nextPtr = ptr\n");   
                 nextPtr = ptr;
                 printf("*nextPtr = %c\tnextPtr = %p\t*ptr = %c\tptr = %p\n\n", *nextPtr, (void*) nextPtr, *ptr, (void*)ptr);   
                }
            //printf("Finished = %d and nextPtr = %p\n", finished, (void*) nextPtr);
            printf("1: Finished = %d\nptr = %p\tcontent = %c\nnextPtr = %p\tcontent = %c\n", finished, (void*) ptr, *ptr, (void*) nextPtr, *nextPtr);
            return sPtr;
            
        }
    }
    
    printf("1: Finished = %d\nptr = %p\tcontent = %c\nnextPtr = %p\tcontent = %c\n", finished, (void*) ptr, *ptr, (void*) nextPtr, *nextPtr);
    
    
        
    return sPtr;
}