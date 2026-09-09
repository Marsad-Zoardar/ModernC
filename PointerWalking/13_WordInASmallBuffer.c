//Author: Md Marsad Zoardar
//September 09, 2026
//Program 13: This program finds where the longest word and saves the word in another buffer. But, this time, the buffer size is
//small. We are doing it intentionally to see what happens and how to tackle the problem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const char *findTheLongestWord(const char *src);
size_t largestWordLength(const char *src);
void copyToBuffer(const char *src, char dest);

int main(void){
    
    char string[] = "It's programming day!";
    
    printf("The longest word starts at address:  %p\n", findTheLongestWord(string));
    printf("The length of the largest word: %zu\n\n", largestWordLength(string));
    
    return 0;
}


//This function finds the pointer address where the longest word starts
const char *findTheLongestWord(const char *src){
    
    const char *longestWordStart = NULL;//This pointer stores the starting point of the longest word
    size_t maxLength = 0;
    size_t count = 0;
    
    //printf("While loop starts.................\n\n");
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            src++;
        }else{
            count++;
            src++;
            if(isspace((unsigned char)*src)){
                if(count > maxLength){
                    maxLength = count;
                    longestWordStart = src - count;
                }
            }
            count = 0;
        }
    }
    //printf("While loop ends............\n\n");
    if(count != 0){
        if(count > maxLength){
            maxLength = count;
            longestWordStart = src - count;
        }
    }
    
    
    return longestWordStart;
}

//This funciton returns the length of the largest word to help determine the buffer size
size_t largestWordLength(const char *src){
    
    
    size_t maxLength = 0;
    size_t count = 0;
    
    //printf("While loop starts.................\n\n");
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            //printf("Found a space! Skipping...\n");
            src++;
        }else{
            //printf("Found a word! Counting....\n");
            count++;
            src++;
            if(isspace((unsigned char)*src)){
                //printf("Found another space after a word. Current count = %zu\n", count);
                if(count > maxLength){
                    //printf("Setting max length to count\n\n");
                    maxLength = count;
                }
                //printf("Max length = %zu\n", maxLength);
                //printf("Resetting count to 0\n\n");
                count = 0;
            }
        }
    }
    //printf("While loop ends............\n\n");
    
    if(count != 0){
        //printf("The string didn't end with a space. Current count = %zu\n", count);
        if(count > maxLength){
            //printf("Setting max length to count\n\n");
            maxLength = count;
        }
    }
    //printf("Max length = %zu\n", maxLength);
    
    return maxLength;
}

//We have got the length and the starting point of the largest word. nex we need to write a function that will copy
//the word to a new buffer