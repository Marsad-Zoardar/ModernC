//Author: Md Marsad Zoardar
//September 16 & 17, 2026
//Program 21: This program copy exactly the number of chars given by the user

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


/*******************Design Decisions************************

The program can be accomplished using only one function.
 * The function will read a string, get the input from the user for its copied portion
 * and copy it to a buffer.

*/


//int main(void){
//    
//    char string[] = "What a great day to program!";//Given string
//    char *ptr = string;//pointer to walk through the string
//    size_t capacity = 5;//Initial capacity
//    size_t userInput = 10;//How many chars to be copied
//    size_t count = 0;//variable to track the number of iteration
//    char *buffer = malloc(capacity*sizeof(*buffer));//allocating memory
//    
//    if(buffer == NULL){//check for successful memory allocation
//        printf("Memory allocation failed!\n");
//        return -1;
//    }
//    char *writePtr = buffer;
//    
//    
//    //printf("Entering while loop\n---------------------\n");
//    while(*ptr != '\0'){//read through the string
//    
//    
//        if(count >= capacity){//reallocating memory if the userInput is more than the capacity
//            //printf("count > capacity. reallocating memory\n\n");
//            capacity *= 2;
//            char *temp = realloc(buffer, capacity*sizeof(*buffer));
//                if(temp != NULL){
//                    //printf("temp != NULL, hence setiing buffer = temp\n");
//                    buffer = temp;
//                    //This part wasn't a part of my first solution. In terminal, it gave the correct output
//                    //But, when checked with valgrind, I noticed there's significant memory leak and some
//                    //undefined memory behavior. This was due to the realloc(), buffer moved to a new memory
//                    //location and now writePtr didn't actually know where to copy the character.
//                    writePtr = buffer + count;
//                }else{
//                printf("Memory allocation failed!\n");
//                return -1;
//                }
//
//        }
//        //printf("buffer = %p and content = %c\n", buffer, *buffer);
//        //printf("ptr = %p and content = %c\n", ptr, *ptr);
//        *writePtr = *ptr;//sets buffer pointer with the value of string pointer
//        //printf("buffer = ptr. Now buffer = %p and content = %c\n\n", buffer, *buffer);
//        ptr++;//increment to continue
//        //printf("ptr++ and ptr = %p, content = %c\n", ptr, *ptr);
//        writePtr++;//increment to continue
//        //printf("buffer++ and buffer = %p, content = %c\n", buffer, *buffer);
//        count++;//increment to continue
//        //printf("count++ and current count = %zu\n", count);
//        
//        if(count == userInput){
//            //printf("count == userInput. Breaking out of the loop\n\n");
//            break;
//        }
//        
//    }
//    //printf("buffer = %p and content = %c\n", buffer, *buffer);
//    
//    //printf("Entering for loop\n");
//    char *readPtr = buffer;
//    
//    for(size_t i = 0; i < count; i++){
//        printf("%c", *readPtr);
//        readPtr++;
//    }
//    printf("\n\n");
//    
//    free(buffer);
//    
//    return 0;
//}


