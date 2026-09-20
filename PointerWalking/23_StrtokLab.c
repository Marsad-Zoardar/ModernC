//Author: Md Marsad Zoardar
//September 19, 2026
//Program 23: This program uses the strtok() function to split a string and investigates what happens in different scenarios


/*********************************My initial understanding*************************************************/
/*
-->What does it return?
    --> It separates each word based on punctuation
-->What happens to the original string?
    --> The original string is lost and each token act as an independent string
-->What happens after the first call?
    --> It tokenizes a word and add a null terminator '\0' at the end. The pointer keeps pointing at the newly created null terminator.
-->What happens if you pass NULL?
    --> Passing an empty string doesn't throw an error. The output is empty as well. String[] cannot be initialized to NULL
-->What happens with multiple spaces?
    --> multiple spaces, tabs, are handled perfectly without any problem.
-->Can you pass a const char * to it?
    -->/home/vboxuser/Workspaces/ModernC/PointerWalking/23_StrtokLab.c:37:25: warning: passing argument 1 of 'strtok' discards 'const' qualifier from pointer target type [-Wdiscarded-qualifiers]
        37 |     constToken = strtok(str, delim);
           |                         ^~~
        In file included from /home/vboxuser/Workspaces/ModernC/PointerWalking/23_StrtokLab.c:19:
        /usr/include/string.h:356:39: note: expected 'char * restrict' but argument is of type 'const char *'
       356 | extern char *strtok (char *__restrict __s, const char *__restrict __delim)
           |                      ~~~~~~~~~~~~~~~~~^~~
-->What does it do to delimiters?
    --> The delimiter is destroyed and replaced with a null terminator. But in case of multiple spaces and tabs, it skips the rest after 
    --> replacing the very first one. It simply jumps over.
*/

/*********************************Corrected understanding****************************************************/
/*
What does it return?
 * A pointer to the beginning of the next token, or NULL when there are no more tokens.
What happens to the original string?
 * The original array still exists. What strtok() does is modify the original array. No allocation happened. 
 * strtok() doesn't create a new heap allocation for every token. It simply modifies the existing buffer and returns pointers into it.
What happens after the first call?
 * The internal state maintained by strtok() remembers where it should continue searching.
What happens if you pass NULL?
 * Continue tokenizing the string from where the previous strtok() call left off.
What happens with multiple spaces?
 * Every character in delim[] is considered a delimiter.
Can you pass a const char * to it?
 * The first call already violates the function's requirements because str is const. Your compiler warns you, 
 * but the program's behavior is not something you should rely on. If you actually run it, you may get a segmentation 
 * fault because the implementation may attempt to write '\0' into read-only storage.
What does it do to delimiters?
 * 

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


//int main(void){
//    
//    char string[] = "Another beautiful day to write some 'C' program!";
//    //const char str[] = "Hello, world!";
//    const char delim[] = " ,.!'";
//    char *token;
//    //char *constToken;
//    
////Extract the first token
//    token = strtok(string, delim);
//    printf("%s\n", token);
//    
////Experiment with const char str[]
//    //constToken = strtok(str, delim);
//    //printf("%s\n", constToken);
//    
//    
////    while(token != NULL){
////        
////        printf("%s\n", token);
////        token = strtok(NULL, delim);//The NULL here points the token to current pointer. if 'string' were used, it would reset the 
////        //token and get into an infinite loop.
////    }
//
//    printf("------------------------------\n");
//    
////    while(constToken != NULL){
////        
////       printf("%s\n", constToken);
////       constToken = strtok(NULL, delim);//The NULL here points the token to current pointer. if 'string' were used, it would reset the 
////        //token and get into an infinite loop.
////    }
//
//    char newString[] = "Hello,world;again!";
//    const char newDelim[] = ",;!";
//    char *newToken;
//    
//    newToken = strtok(newString, newDelim);
//    //printf("%s\n", newToken);
//    
//    while(newToken != NULL){
//        printf("%s\n", newToken);
//        newToken = strtok(NULL, newDelim);
//    }
//    
//    
//    return 0;
//}