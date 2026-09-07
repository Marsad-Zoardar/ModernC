//Author: Md Marsad Zoardar
//September 07, 2026
//Program 9: This program finds the shortest word in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t longestWord(const char *ptr);

int main(void){
    
    char string[] = "Today is a good day to code!";
    
    printf("The longest word length is: %zu\n\n", longestWord(string));
    
    return 0;
}

size_t longestWord(const char *ptr){
    
    size_t longestWord = 0;
    size_t currentLength = 0;
    size_t count = 0;
    
    printf("Entering while loop..\n\n\n");
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            printf("Space found! Skipping...\n");
            ptr++;
        }else{
            printf("Found a character. Counting..\n");
            count++;
            printf("Incrementing pointer..\n");
            ptr++;
            if(isspace((unsigned char)*ptr)){
                printf("Found space after a word. Current length is setting to count.\n\n");
                currentLength = count;
                printf("Resetting count to 0\n");
                count = 0;
                printf("Checking the longest word.\n");
                if(currentLength > longestWord){
                    printf("Current length is bigger than the longest word. Setting the longestWord to currentLength\n\n");
                    longestWord = currentLength;
                }
            }
        }
    }
    printf("Checking for count after the while loop.\n\n");
                currentLength = count;
                printf("Checking the longest word.\n");
                if(currentLength > longestWord){
                    printf("Current length is bigger than the longest word. Setting the longestWord to currentLength\n\n");
                    longestWord = currentLength;
                }
    
    
    return longestWord;
}