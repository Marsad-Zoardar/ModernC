//Author: Md Marsad Zoardar
//September 04, 2026
//Program 1: Count characters

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//This function takes a string and counts the total number of characters including spaces
size_t charCount(const char *ptr){
    
    size_t count = 0;
    
    while(*ptr != '\0'){//iterate through the text until it finds the null terminating character
        count++;
        ptr++;//increment pointer to continue
    }

    return count;
    
}


//int main(void){
//    
//    char string[] = "Today is a good day to code! By the grace of almighty Allah, hopefully I will be able to make it"
//                    "a good productive day";
//    
//    printf("Total number of characters: %zu\n", charCount(string));
//    
//    //Next step: get a dynamically allocated string input from the user
//    
//    return 0;
//}