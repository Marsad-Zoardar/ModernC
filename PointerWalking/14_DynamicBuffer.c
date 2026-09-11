//Author: Md Marsad Zoardar
//September 11, 2026
//Program 14: This program finds where the longest word and saves the word in another buffer. But, this time, the buffer size is
//smaller than the word size. The memory needs to be dynamically allocated based on the length of the word.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


int main(void){
    
    
    const char string[] = "Today is an excellent day to code!";//String to be evaluated
    //
    const char *ptr;
    ptr = string;
    const char *longestWordStart = NULL;
    
    size_t maxLength = 0;
    size_t count = 0;
    
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            ptr++;
        }else{
            count++;
            ptr++;
            if(isspace((unsigned char)*ptr)){
                if(count > maxLength){
                    maxLength = count;
                    longestWordStart = ptr - count;
                }
                count = 0;
            }
        }
    }
    //This is to know the last count as the while loop exits before the last operation of max length checking
    if(count != 0){
        if(count > maxLength){
            maxLength = count;
            longestWordStart = ptr - count;
        }
    }
    printf("Longest word starts at address; %p\n", longestWordStart);
    printf("Length of the longest word: %zu\n", maxLength);
    
    if(maxLength > 0){
        char *buffer = malloc((maxLength + 1) * sizeof(*buffer));//used sizeof(buffer) which was using 8x the memory
            if(buffer == NULL){
                printf("Memory allocation failed!\n\n");
                return -1;
            }
    
    
        for(size_t i = 0; i < maxLength; i++){
            buffer[i] = *(longestWordStart + i);
            //printf("buffer[i] = %c\n", buffer[i]);
        }
        buffer[maxLength] = '\0';
        //printf("buffer[maxLength] = %c\n", buffer[maxLength]);
    
        printf("The longest word: %s\n", buffer);
        free(buffer);
        buffer = NULL;
        
    }else{
        printf("The string is empty!\n\n");
    }
    
    
    
    return 0;
}



