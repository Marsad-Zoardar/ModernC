//Author: Md Marsad Zoardar
//September 12, 2026
//Program 16: This program finds the last occurance of a char in the string and returns the pointer address

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


const char *lastOccurance(const char *ptr, char target);

//int main(void){
//    
//    const char string[] = "Today is another good day to code!";
//
//    
////    printf("The length of the string is: %d\n", stringLength);
//    
//    const char *result = lastOccurence(string, 'x');
//    
//    if(result == NULL){
//        printf("The character doesn't exist in the string provided.\n\n");
//    }else{
//        printf("The character found at %p\n\n", result);
//    }
//    
//    return 0;
//}

const char *lastOccurence(const char *ptr, char target){
        
    //int count = 0;
    const char *start;
    //const char *lastOccurence = NULL;
    //const char *buffer = NULL;
    //int stringLength = strlen(ptr);
    
    start = ptr;
    //printf("The value of start: %c and address is: %p\n", *start, start);
        
    while(*ptr != '\0'){
        //printf("Pointer at = %p and the char is: %c\n", ptr, *ptr);
        printf("Address: %p\n", ptr);
        ptr++;
    
        //count++;
    }
    //printf("count = %zu\n", count);
    //printf("Pointer = %p\n", ptr);
    ptr = ptr -1;
    
    while(ptr >= start){
        //printf("Got into the while loop\n\n");
        if(*ptr == target){
            //printf("*ptr == target found\n\n");
            //lastOccurence = ptr;
            //printf("lastOccurence = %p\n", lastOccurence);
            return ptr;
        }
        if(ptr == start){
            break;
        }
        ptr--;
        
    }

//    printf("Pointer = %p\n", ptr);
//    printf("strlen = %zu\n", strlen(ptr));
    //This inplementation uses the count variable
//    for(int i = count; i > 0; i--){
//        //printf("Iteration number = %d\t", i);
//        if(*ptr == target){
//            lastOccurence = ptr;
//            return lastOccurence;
//        }
//        //printf("Found the char = %c\n", *ptr);
//        
//        ptr--;
//    }
    
    return NULL;
    
}