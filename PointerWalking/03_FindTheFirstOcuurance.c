//Author: Md Marsad Zoardar
//September 04, 2026
//Program 3: This program finds the first occurance of a character

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


const char *firstOccurance(const char *ptr, char target){
    
    
    while(*ptr != '\0'){
        
        if(*ptr == target){
            return ptr;
        }else{
            ptr++;
        }
    
    }
    
    return NULL;
}

//int main(void){
//    
//    char string[100];
//    char target;
//    printf("Please enter a string\n>>");
//    
//    fgets(string, sizeof(string), stdin);
//    
//    printf("Please enter your target character\n>>");
//    scanf("%c", &target);
//    
//    printf("The char '%c' in the string you provided occured at the address: %p \n\n",target, firstOccurance(string, target));
//    
//    
//    return 0;
//}

