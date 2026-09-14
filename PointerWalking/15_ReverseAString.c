//Author: Md Marsad Zoardar
//September 11, 2026
//Program 15: This program finds where the longest word and prints it in reverse

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void printReverese(const char *ptr);

//int main(void){
//    
//    const char string[] = "Today is a good day to code!";
//    
//    printReverese(string);
//    
//    return 0;
//}

void printReverese(const char *ptr){
    
    size_t count = 0;
    
    
    //Read the string
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
        count++;
    }
    printf("\n\n");
    //Count down from the current pointer position to print it in reverse
    for(size_t i = 0; i < count; i++){
        printf("%c", *(ptr-1));//pointer is pointing at ptr = '\0', hence (ptr-1)
        ptr--;
    }

    printf("\n\n");
}