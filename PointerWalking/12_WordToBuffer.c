//Author: Md Marsad Zoardar
//September 08, 2026
//Program 12: This program finds where the longest word and saves the word in another buffer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void wordToBuffer(const char *src, char *dest, size_t destSize);

int main(void){
    
    size_t destSize = 50;
    char src[] = "  ";
    char dest[destSize];
    
    wordToBuffer(src, dest, destSize); 
    
    return 0;
}

void wordToBuffer(const char *src, char *dest, size_t destSize){
    
    //Design decision
    //Step 1: There will be a a srting given or take from the user
    //Step 2: Read the string and find the longest word
    //Step 3: Find the starting pointer of the longest word
    //Step 4: Copy the longest word to destination buffer
    //Step 5: Print the word
    
    const char *longestWordStart = NULL;//This pointer will hold the starting pointer of the word. Return NULL when string empty
    size_t maxLength = 0;//This variable stores the length of the longest word found
    size_t currentLength = 0;//Though this variable is unnecessary, it is only there to understand the algorithm. Holds the current count
    size_t count = 0;//This is to count the current word
    
    //This while loop reads through the string
    printf("Entering while loop......\n\n");
    printf("--------------------------------------\n\n");
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            //Skips the space by incrementing the pointer
            printf("Space detected! Skipping >>>>>\n");
            src++;
        }else{
            printf("Word found! Counting\n");
            count++;
            src++;
            if(isspace((unsigned char)*src)){
                printf("Word ends. Length of the word: %zu\n", count);
                currentLength = count;
                if(currentLength > maxLength){
                    printf("Current length is longer than max length. Setting max length to current length\n\n");
                    maxLength = currentLength;
                    printf("Current address is: %p----->\n", src);
                    longestWordStart = src - currentLength;
                    printf("Current longest word starting at: %p------>\n", longestWordStart);
                    printf("Current value of the *longestWordStart = %c\n", *longestWordStart);
                }
                printf("Resetting count to 0!\n\n");
                count = 0;
            }
        }
    }
    printf("While loop ends!\n");
    printf("------------------------------\n\n");
    if(count != 0){
        printf("The string ended properly. Count is greater than 1. Checking for new max length\n\n");
        currentLength = count;
                if(currentLength > maxLength){
                    printf("Current length is longer than max length. Setting max length to current length\n\n");
                    maxLength = currentLength;
                    printf("Current address is: %p----->\n", src);
                    longestWordStart = src - currentLength;
                    printf("Current longest word starting at: %p------>\n", longestWordStart);
                    printf("Current value of the *longestWordStart = %c\n", *longestWordStart);
                }
    }
    printf("Checking if max length is greater than 0 or not.....\n\n");
    if(maxLength > 0){
        printf("Current value of the *longestWordStart = %c\n", *longestWordStart);
        for(size_t i = 0; i < maxLength; i++){
            //printf("dest[i] = %c\t *longestWordStart = %c\n", dest[i], *longestWordStart);
            dest[i] = *(longestWordStart + i);
            printf("dest[i] = %c\t *longestWordStart = %c\n", dest[i], *(longestWordStart + i));
        }
        dest[maxLength] = '\0';
        printf("The longest word is: %s\n", dest);
    }else{
        printf("The string is empty!\n\n");
    }
    
    
}