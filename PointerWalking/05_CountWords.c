//Author: Md Marsad Zoardar
//September 04, 2026
//Program 5: This program counts all the words in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t countWords(const char *ptr){
    
    size_t numberOfWords = 0;
    int inWord = 0;
    
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            inWord = 0;
        }else if(!inWord){
            numberOfWords++;
            inWord = 1;
        }
        ptr++;
    }
    
    return numberOfWords;
    
}


//int main(void){
//    
//    char string[100];
//    
//    printf("Please enter a string\n>>");
//    
//    fgets(string, sizeof(string), stdin);
//    
//    printf("The number of words in the string: %zu \n\n", countWords(string));
//    
//    
//    return 0;
//}