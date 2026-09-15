//Author: Md Marsad Zoardar
//September 14, 2026
//Program 17: This program finds the number of characters in a string. Though I have written this program many times, AI wanted to
//evaluate some other fundamental understanding of pointers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


size_t numberOfChars(const char *ptr){
    
    size_t count = 0;
    
    while(*ptr != '\0'){
        count++;
        ptr++;
    }
    
    return count;
}

//int main(void){
//    
//    char string[] = "hello world";
//    
//    printf("The number of characters in the string: %zu\n", numberOfChars(string));
//    
//    return 0;
//}