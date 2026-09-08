//Author: Md Marsad Zoardar
//September 08, 2026
//Program 11: This program finds where the longest word starts, returns the first char of the longest word, as well as the longest word

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const char *longestWordStartAndLength(const char *ptr);

//int main(void){
//    
//    char string[] = "";
///*"Today is programming day"
//"programming"
//""
//"     "
//"hi"
//"hi hello"
//"hello hi"
//"hello     hi"
//"   hello hi   "
//*/
//    
//    printf("The longest word starts at: %p\n\n", longestWordStartAndLength(string));
//    
//    return 0;
//}

const char *longestWordStartAndLength(const char *ptr){
    
    const char *longestWordStart = NULL;
    size_t maxLength = 0;
    size_t currentLength = 0;
    size_t count = 0;
    
    
    //printf("Entering while loop...\n\n");
    while(*ptr != 0){
        
        if(isspace((unsigned char)*ptr)){
            //printf("Found a space! Skipping...\n");
            //printf("Current pointer address = %p\n", ptr);
            ptr++;
        }else{
            printf("%c", *ptr);
            //printf("Found a character. Counting...\n");
            count++;
            //printf("Current pointer address = %p\n", ptr);
            ptr++;
            if(isspace((unsigned char)*ptr)){
                //printf("Found a space! Stopping to separate a word\n");
                //printf("Setting current length = count\n");
                currentLength = count;
                //printf("Current length = %zu\n", currentLength);
                if(currentLength > maxLength){
                    //printf("Current length is bigger than max length. Setting max to current\n");
                    maxLength = currentLength;
                    //printf("Current pointer address =  %p\n", ptr);
                    //printf("current Length = %zu\n", currentLength);
                    //printf("Setting longest word start to \"ptr - currentLength\" = %p\n", ptr - currentLength);
                    longestWordStart = ptr - currentLength;
                }
                //printf("Setting count = 0\n\n");
                count = 0;
                //printf("longestWordStart = %p\n\n", longestWordStart);
            }
        }
    }
    //printf("While loop ends\n\n");
    if(count != 0){
        //printf("Current count = %zu\n", count);
        currentLength = count;
               if(currentLength > maxLength){
                   maxLength = currentLength;
                   //printf("Current pointer address =  %p\n", ptr);
                   //printf("current Length = %zu\n", currentLength);
                   //printf("Setting longest word start to \"ptr - currentLength\" = %p\n", ptr - currentLength);
                   longestWordStart = ptr - currentLength;
               }
    }
    if(maxLength > 0){
        printf("Max Length = %zu\n", maxLength);
        //printf("longestWordStart = %p\n\n", (void*)longestWordStart);
        printf("First char of the longest word = %c\n", *longestWordStart);
        printf("The longest word = ");
    
//      printf("Longest word start = %s", longestWordStart);
        for(size_t i = 0; i < maxLength; i++){
            printf("%c", *(longestWordStart + i));
        }
        printf("\n\n");
    }else{
        printf("The string is empty!\n\n");
    }
    
    return longestWordStart;
}