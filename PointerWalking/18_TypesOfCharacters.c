//Author: Md Marsad Zoardar
//September 14, 2026
//Program 18: This program finds the number of different types of characters in a string
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


void typesOfChars(const char *ptr){
    
    size_t alphaCount = 0;
    size_t digitCount = 0;
    size_t spaceCount = 0;
    size_t punctCount = 0;
    
    while(*ptr != '\0'){
        if(isalpha((unsigned char)*ptr)){
            alphaCount++;
        }
        if(isdigit((unsigned char)*ptr)){
            digitCount++;
        }
        if(isspace((unsigned char)*ptr)){
            spaceCount++;
        }
        if(ispunct((unsigned char)*ptr)){
            punctCount++;
        }
        ptr++;
    }
    
    printf("Number of Alphabetic characters: %zu\n", alphaCount);
    printf("Number of digit characters: %zu\n", digitCount);
    printf("Number of space characters: %zu\n", spaceCount);
    printf("Number of punctuation characters: %zu\n", punctCount);
}

//int main(void){
//    
//    char string[] = "What a gorgeous day to code today on September 14th, 2026!";
//    
//    typesOfChars(string);
//    
//    return 0;
//}