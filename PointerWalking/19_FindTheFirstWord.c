//Author: Md Marsad Zoardar
//September 14, 2026
//Program 19: This program finds the very first postion of a word in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

const char *firstPointer(const char *str);

int main(void){
    
    char string[] = "What a gorgeous day to code today on September 14th, 2026! ";
    
    printf("The first word starts at address: %p\n", firstPointer(string));
    
    return 0;
}

const char *firstPointer(const char *str){

    
    while(*str != '\0'){
        if(isspace((unsigned char)*str)){
            str++;
        }else{
            return str;
            }
    }

    return NULL;
}