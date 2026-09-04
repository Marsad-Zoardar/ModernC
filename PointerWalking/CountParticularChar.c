//Author: Md Marsad Zoardar
//September 04, 2026
//Program 2: Count a particular character

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//This program asks the user for a string input and the occurance of a particular char in that string 
size_t particularCharCount(const char *ptr, char target){
    
    size_t count = 0;
    
    while(*ptr != '\0'){
        if(*ptr == target){
            count++;
        }
        ptr++;
    }
    
    
    return count;
}

int main(void){
    
    char string[100];
    char target;
    printf("Please enter a string\n>>");
    
    fgets(string, sizeof(string), stdin);
    
    printf("Please enter your target character\n>>");
    scanf("%c", &target);
    
    printf("The char '%c' in the string you provided occured: %zu times\n\n",target, particularCharCount(string, target));
    
    return 0;
}