//Author: Md Marsad Zoardar
//September 04, 2026
//Program 4: This program finds all the spaces in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t spaceCount(const char *ptr){
    
    size_t spaces = 0;
    
    while(*ptr != '\0'){
//        if(*ptr == ' '){
//            spaces++;
//        }
        if(isspace((unsigned char)*ptr)){
            spaces++;
        } 
        ptr++;
    }
    
    return spaces;
}

//int main(void){
//    
//    char string[100];
//    
//    printf("Please enter a string\n>>");
//    
//    fgets(string, sizeof(string), stdin);
//    
//    printf("The number of spaces in the string: %zu times \n\n", spaceCount(string));
//    
//    
//    return 0;
//}
