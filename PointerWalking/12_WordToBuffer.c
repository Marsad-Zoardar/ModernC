//Author: Md Marsad Zoardar
//September 08, 2026
//Program 12: This program finds where the longest word and saves the word in another buffer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void wordToBuffer(const char *src, char *dest, size_t destSize);

int main(void){
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
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            //Skips the space by incrementing the pointer
            src++;
        }else{
            count++;
            src++;
            if(isspace((unsigned char)*src)){
                currentLength = count;
                if(currentLength > maxLength){
                    maxLength = currentLength;
                    longestWordStart = src;
                }
                count = 0;
            }
        }
    }
    
}