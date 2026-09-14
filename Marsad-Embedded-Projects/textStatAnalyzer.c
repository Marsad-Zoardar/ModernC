//Author: Md Marsad Zoardar
//August 29, 2026
/*Project: Text Statistics Analyzer
Build a program that reads a block of text (multiple lines) from the user and reports statistics about it
— word count, character count, longest word, and a simple word-frequency count — using pointer arithmetic 
and pointer-to-pointer patterns directly, rather than array-indexing syntax everywhere.
Core requirements:
-->Read multiple lines of text from the user until they enter a blank line (just pressing Enter with nothing typed) or type "done".
-->Store each line as an independently-allocated string — you already know this pattern cold from your last project.
-->Write a function that counts words in a string using pointer arithmetic, not arr[i] indexing. Walk through
   the string by advancing a char * pointer directly (ptr++), not by indexing into an array — this is the actual
   point of "pointer arithmetic" as a distinct skill from array indexing, even though they can achieve similar results.
-->Write a function that finds the longest word across all lines, returning a pointer to where that word starts 
   (you'll need to think about whether you return a pointer into the original text, or a freshly-allocated copy
   — justify your choice in your README).
-->Use const correctly on every function parameter that only reads its input and never modifies it. This is a direct,
   deliberate test of whether the const-correctness lesson actually sticks in practice, not just in prediction exercises.
-->Build a simple word-frequency structure: for every unique word, track how many times it appears. You'll need an array
   of pointers to strings (your char ** skill from last project) paired with an array of counts — or a struct combining both, your choice.
-->Print a summary: total word count, total character count (excluding whitespace), the longest word found, and the 
   top 3 most frequent words.
-->Free everything. Valgrind clean, as always.
-->One deliberate constraint, to force the pointer-arithmetic skill specifically: your word-counting function (#3) is not 
   allowed to use [] indexing syntax anywhere inside it — pointer arithmetic and dereferencing only (*ptr, ptr++, *(ptr + n)). 
   This is a bit artificial as a real-world constraint (indexing is often clearer in production code), but it's a deliberate 
   forcing function to make sure you're genuinely comfortable with pointer arithmetic itself, not just recognizing that it's 
   equivalent to indexing.

What to research yourself, similar to last time: how to reliably tokenize a string into words (there's a standard function for 
this, though it has some sharp edges worth understanding — look into what it modifies and why that matters for const-correctness), 
and how to structure a growable word-frequency collection given what you already know about dynamic arrays of strings.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define INITIAL_CAPACITY 5

void charCount(const char *ptr);
void wordCount(const char *ptr);
void longestWord(void);


//int main(int argc, char **argv){
//    
//   
//    
////    printf("Write something you like....\n>");
////    
////    fgets(string, sizeof(string), stdin);
//    
//    //newPtr = string; //I didn't have to do it this way, just did to remind myself
//
//    //charCount(string);
//    //wordCount(newPtr);
//    
//    longestWord();
//    
//    
//    return 0;
//}


//This function counts the number of characters and bytes in a string using pointer
void charCount(const char *ptr){
    
    size_t bytes = 0;
    
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
        bytes++;
    }
    
    
    printf("\nTotal number of characters: %zu\n", bytes);
    printf("Total number of bytes: %zu\n", bytes + 1);
    
    printf("\n\n");
    
    
}

//This function counts the number of words in a string based on finding space, tabs, new lines, etc.
void wordCount(const char *ptr){
    
    size_t wordCount = 0;
    int inWord = 0; //Mistake 1: Kept uninitialized, didn't get the right output
    
    
    while(*ptr != '\0'){
        
    
        if(isspace((unsigned char)*ptr)){ //Design decision changed: was only counting one whitespace
            inWord = 0;
        }   
        else if(!inWord){
            wordCount++;
            inWord = 1;
        }
        ptr++;
    }
    

    printf("Number of words: %zu\n", wordCount);
}


  
        
        

//This function reads a string and finds the longest word
void longestWord(void){
    
    int buffer = 100;
    //step 1 -> Read the string
    char string[] = "Today is a good day to code";
    
    char *ptr; //a pointer is required to iterate through the string [array of characters]
    
    ptr = string; //set the pointer at the first element of the string
    
    //To know the longest word in a string, I need to count characters in each word
    //counting word length
    int currentWordLength = 0;
    int longestWordLength = 0;
    char currentWordStart;
    char longestWordStart;
    
    while(*ptr != '\0'){

        while(*ptr != ' ' || *ptr != '\0'){
            currentWordLength++;
            ptr++;
             
                if(*ptr == ' ' || *ptr == '\0'){
                    longestWordLength = currentWordLength;
                    currentWordLength = 0;
                }
            if(currentWordLength > longestWordLength){
                longestWordLength = currentWordLength;
            }
        }
        
      ptr++;  
    }
    
}