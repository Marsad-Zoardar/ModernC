//Author: Md Marsad Zoardar
//September 05, 2026
//Program 6: This program calculates the length of the very first word in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t firstWordLength(const char *ptr){
    
    size_t length = 0;
    
    while(*ptr != '\0'){
          if(isspace((unsigned char)*ptr)){
              if(length > 0){
                  return length;
              }
              ptr++;
          }else{
              length++;
              ptr++;
          }
          
    }
    return length;
}
    


//int main(void){
//    
//    char string[50];
//    
//    printf("Please enter a string\n>>");
//    
//    fgets(string, sizeof(string), stdin);
//
//    
//    printf("The length of the first word in the string: %zu \n\n", firstWordLength(string));
//    
//    
//    return 0;
//}