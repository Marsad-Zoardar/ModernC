//Author: Md Marsad Zoardar
//August 17, 2026
//Function-like Macros

#include <stdio.h>
#include <stdlib.h>

//A function-like macro that is correctly parentesized 
#define SQUARE(x) ((x) * (x))

//The same macro without proper parenteses (intentionally broken)
#define BAD_SQUARE(x) x*x

//Swap variable values 
#define SWAP(a, b) do {int temp = a; a = b; b = temp;} while(0)
    
//conditional compilation
#define DEBUG_Mode


int main(){
    
    printf("The correct square is: %d\n", SQUARE(1+2));
    printf("The bad square is: %d\n", BAD_SQUARE(1+2));
    
    
    int x = 10;
    int y = 20;
    
    SWAP(x, y);
    
    printf("The value of a: %d and the value of b: %d after the swap\n", x , y);
    
    
    #ifdef DEBUG_MODE
        printf("Debug mode is on\n");
    #else
        printf("Debug mode is off\n");
    #endif
    
    
    return 0;
}