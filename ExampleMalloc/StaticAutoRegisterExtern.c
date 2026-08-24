//Author: Md Marsad Zoardar
//August 23, 2026
//In this program, we will implement a heap allocated circular buffer using a pointer and not a fixed size array


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void foo(){
    
    //register int percent; //variable that is frequently used and resides in the CPU memory. Never call with a pointer, gives error
    //extern int tax; //This variable may exist in another file
    static int callCount = 0; //Static variable retains the memory and uses the previous value in every function call
    int localVar = 0; //Normal variable, resets at every function call
    callCount++;
    localVar++;
    printf("%d\n", callCount);
    printf("%d\n", localVar);
}

int main(){
    foo();
    foo();
    foo();
    
    return 0;
}