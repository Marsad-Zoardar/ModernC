//Author: Md Marsad Zoardar
//September 17, 2026
//Program 22: This program finds the first word's starting pointer, ending pointer, and copies the first word in a new buffer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/*******************Design Decisions************************

This program requires 3 functions;
 * 1. function to return the starting pointer:-> char *firstPointer(const char *ptr)
 * 2. function to return the ending pointer:->   char *lastPointer(const char *ptr)
 * 3. function to copy the word to a new buffer. The buffer needs to be dynamically allocated
*/

const char *firstPointer(const char *ptr);
const char *lastPointer(const char *ptr);
size_t wordLength(const char *ptr1);

int main(void){
    
    char string[] = "123456789";
    //Embedded systems is the most fun thing in the world!
/*Test cases
"hi"
"hello"
"hello world"
"     hello"
"hello     "
"   hello   "
""
"12345"
"123456"
"123456789"
 * */
    char *ptr = string;
    const char *wordBegin = firstPointer(string);
        if(wordBegin == NULL){
            printf("Error! The string is empty.\n\n");
            return -1;
        }
    const char *wordEnd = lastPointer(string);
    size_t capacity = 5;
    size_t count = 0;
    char *buffer = malloc(capacity*sizeof(*buffer));
    if(buffer == NULL){
        //printf("Memory allocation failed!\n");
        return -1;
    }
/*******************************************************************************************************************/    
    size_t firstWordLength = wordLength(string);
    char *writePtr = buffer;
    
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            ptr++;
        }else{
            *writePtr = *ptr;
            ptr++;
            writePtr++;
            count++;
        }
        if(count >= capacity){
            capacity *= 2;
            char *temp = realloc(buffer, capacity*sizeof(*buffer));
                if(temp == NULL){
                    printf("Memory allocation failed!\n");
                    return -1;
                }else{
                    buffer = temp;
                    writePtr = buffer + count;
                }
        }
        if(ptr == wordEnd + 1){
            break;
        }
    }
    buffer[count] = '\0';//Forgot to add this. It is important to have to make it a string
    
    char *readPtr = buffer;
    
    printf("The first word of the string is: ");
    
    for(size_t i = 0; i < firstWordLength; i++){
        printf("%c", *readPtr);
        readPtr++;
    }
    printf("\n\n");
    
    free(buffer);
    
    return 0;
}

//Function to return the first pointer**********************************************************************************
const char *firstPointer(const char *ptr){
    
    const char *firstPtr = NULL;
    printf("Entering firstPointer while loop\n----------------\n");
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            //printf("Space found. Pointer at = %p\n", ptr);
            ptr++;
        }else{
            //printf("Char found. Pointer at = %p\n", ptr);
            firstPtr = ptr;
            return firstPtr;
        }
    }
    printf("firstPointer done! Returning\n----------------\n");
    return firstPtr;
}

//Function to return the last pointer************************************************************************************
const char *lastPointer(const char *ptr){
    
    const char *lastPtr = NULL;
    size_t count = 0;
    printf("Entering lastPointer while loop\n----------------\n");
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            printf("Space found. Pointer at = %p\n", ptr);
            ptr++;
        }else{
            printf("Char found. Pointer at = %p\tcontent = %c\n", ptr, *ptr);
            ptr++;
            count++;
            if(isspace((unsigned char)*ptr)){
                lastPtr = ptr -1;
                return lastPtr;
            }
        }
    }
    if(count != 0){
            lastPtr = ptr -1;
    }
    printf("lastPointer done! Returning\n----------------\n");
    return lastPtr;
}

//This function subtracts the start pointer from end pointer and finds the length of the word.*******************************
size_t wordLength(const char *ptr){
    
    size_t length = 0;
    const char *startingPtr = firstPointer(ptr);
        if(startingPtr == NULL){
            printf("The string is empty!\n\n");
            return 0;
        }
    printf("startingPtr = %p and the content = %c\n", startingPtr, *startingPtr); 
    //printf("firstPointer(string) = %p\n", firstPointer(string));
/***********************************************************************************************/    
    const char *endingPtr = lastPointer(ptr);
        if(endingPtr == NULL){
            printf("The string is empty!\n\n");
            return 0;
        }
    printf("endingPtr = %p and the content = %c\n", endingPtr, *endingPtr);
    //printf("lastPointer(string) = %p\n", lastPointer(string));
/*********************************************************************************************/
        if(startingPtr != NULL && endingPtr != NULL){
            length = (endingPtr - startingPtr) + 1; 
        }

    printf("wordLength = %zu\n\n", length);
    
    return length;
    
}




/*
 * while(*ptr != '\0'){
        //printf("Entered while loop\n----------------------\n");
        printf("ptr = %p\tstartingPtr = %p\n", ptr, startingPtr);
        if(*ptr == *startingPtr){
            printf("ptr == startingPtr, Entered if loop\n-------------\n");
            printf("*writePtr = %c\t*ptr = %c\n", *writePtr, *ptr);
            *writePtr = *ptr;
            //ptr++;
            writePtr++;
            count++;
            if(count >= capacity){
                //printf("Entered reallocation!\n");
                capacity *= 2;
                char *temp = realloc(buffer, capacity*sizeof(*buffer));
                    if(temp == NULL){
                        //printf("Memory allocation failed!\n");
                        return -1;
                    }else{
                        //printf("Reallocation successful!\n");
                        buffer = temp;
                        writePtr = buffer + count;
                    }
            }
            if(count == wordLength){
                break;
            }
        
        }
        printf("Before increment\n---------------------\nptr = %p\tstartingPtr = %p\n", ptr, startingPtr);
        ptr++;
        startingPtr++;
        printf("After increment\n******************\nptr = %p\tstartingPtr = %p\n", ptr, startingPtr);
    }*/