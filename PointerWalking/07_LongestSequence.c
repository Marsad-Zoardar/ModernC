//Author: Md Marsad Zoardar
//September 05, 2026
//Program 7: This program finds the longest sequence of characters(word) in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t longestSequence(const char *ptr);

int main(void){
    
    char string[] = "  Today is a good day to code!";
    
    printf("The longest word has %zu characters\n", longestSequence(string));
    
    return 0;
}

size_t longestSequence(const char *ptr){
    
    
    size_t count = 0;
    size_t currentLength = 0;
    size_t maxLength = 0;

    
    while(*ptr != '\0'){
        if(!isspace((unsigned char)*ptr)){
            count++;
            ptr++;
        }else{
            currentLength = count;
            if(currentLength > maxLength){
                maxLength = currentLength;
            }
            ptr++;
            count = 0;
        }
    }
    
    return maxLength;
    
}