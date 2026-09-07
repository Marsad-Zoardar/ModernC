//Author: Md Marsad Zoardar
//September 06 & 07, 2026
//Program 8: This program finds the shortest word in a string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


size_t shortestWord(const char *ptr);

//int main(void){
//    
//    
//    char string[] = "Today is a good day to code!";
//    
//    printf("The shortest word in the string has %zu characters\n", shortestWord(string));
//    
//    return 0;
//}

size_t shortestWord(const char *ptr){
    
    const char *origin = ptr;
    
    size_t shortestLength = 0;
    size_t currentLength = 0;
    size_t firstWordLength = 0;
    size_t count = 0;
//    size_t index = 0;
 
//This loop finds the length of the very first word to compare the length with other words if there's any   
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            ptr++;
        }else{
            count++;
            ptr++;
            if(isspace((unsigned char)*ptr)){//If it finds a space, it breaks out. Otherwise the the loop ends at '\0'
                break;
            }
        }
    }
    //The count is already set to whatever the length with or without a break.
//    printf("Pointer is at %p pointing the character %c\n", (void*) ptr, *ptr);
    
    firstWordLength = count;
    count = 0;
    
    ptr = origin;
//    printf("After reset: Pointer is at %p pointing the character %c\n\n", (void*) ptr, *ptr);
    
    printf("The length of the first word is: %zu characters\n\n", firstWordLength);

    
    while(*ptr != '\0'){
        if(isspace((unsigned char)*ptr)){
            ptr++;
        }
        else{
            count++;
            ptr++;
            if(isspace((unsigned char)*ptr)){
                currentLength = count;
                count = 0;
                if(currentLength < firstWordLength){
                    shortestLength = currentLength;
                    firstWordLength = shortestLength;
                }else{
                    shortestLength = firstWordLength;
                }
            }
        }       
    }
    if(count != 0){
    currentLength = count;
    
                if(currentLength < firstWordLength){
                    shortestLength = currentLength;
                    firstWordLength = shortestLength;
                    
                }else{
                    shortestLength = firstWordLength;
                    
                }
                
    }else{
        return shortestLength;
    }
    
    
      return shortestLength;
}  
    
//    while(*ptr != '\0'){
//        if(!isspace((unsigned char)*ptr)){
//            count++;
//            ptr++;
//        }else{
////          printf("%c", *ptr);//prints each character of a word
//            currentLength = count;
//            printf("Current length = %zu\n", currentLength);
//                if(currentLength < firstWordLength){
//                      shortestLength = currentLength;
//                      printf("Shortest length = %zu\n", shortestLength);
//                      firstWordLength = shortestLength;
//                      printf("First word length now is = %zu\n", firstWordLength);
//                  }
////                printf(" = %zu", count);//prints the  word's char count
////                printf("\n");
//                count = 0;
//                ptr++;
//            
//        }
//        
//    }
//    currentLength = count;
//    printf("This is after the while loop. currentLength = %zu\n", currentLength);
//    printf("This is after the while loop. firstWordLength = %zu\n", firstWordLength);
//    if(currentLength < firstWordLength){
//        shortestLength = currentLength;
//    }
//    printf("This is after the while loop. shortestLength = %zu\n", shortestLength);
////    printf(" = %zu", count);
////    printf("\n");
        


/* printf("Entered into the first 'if' block cause I found a space!\n");
 * printf("Entered into the first 'else' block, cause I found a character! Counting....\n"); 
 * printf("Entered into the 2nd 'if' block, cause I found a space after character/s\n");
 * printf("Current count = %zu\n", count); 
 * printf("Current length is set to count\n");
 * printf("Count has been resetted to 0!\n");
 * printf("Entered into the 3rd 'if' block to compare the current length with the first word length!\n");
 * printf("Shortest length has been set to current length as it was smaller than the first word length!\n");
 * printf("First word length is now set as the shortest word for the next iteration.\n\n");
 * printf("Entered into the 2nd 'else' block as the currentLength was not smaller than the first word length!\n");
 * printf("Shortest length has been set to the first word length\n\n");
 * printf("We are done with the while loop. The current value of count is = %zu\n\n", count);
 * printf("Current length is set to count\n");
 * printf("Entered into the 4th 'if' block to compare the current length with the first word length!\n");
 * printf("Shortest length has been set to current length as it was smaller than the first word length!\n");
 * printf("First word length is now set as the shortest word for the next iteration.\n\n");
 * printf("Entered into the 3rd 'else' block as the currentLength was not smaller than the first word length!\n");
 * printf("Shortest length has been set to the first word length\n\n");
*/