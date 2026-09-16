//Author: Md Marsad Zoardar
//September 15, 2026
//Program 20: This program finds where the word ends and returns the pointer

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

const char *findTheWordEnd(const char *str);

//int main(void){
//    
//    char string[] = "   Hello world";
//    
//    printf("The last char of the first word is at: %p\n", findTheWordEnd(string));
//    
//    return 0;
//}


const char *findTheWordEnd(const char *str){
    
    while(*str != 0){
        if(isspace((unsigned char)*str)){
            printf("Space Found! Pointer is at: %p\n", str);
            str++;
        }else{
            printf("Char %c and Pointer is at: %p\n", *str, str);
            str++;
            if(isspace((unsigned char)*str)){
                return str - 1;
            }
        }
        
    }
    if(*str == '\0'){
        return str - 1;
    }
    
    return NULL;
}