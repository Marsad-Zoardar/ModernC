//Author: Md Marsad Zoardar
//August 26, 2026
//Printing out pointers to better understand 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 
int main(){
    /*
     *                  **pPtr = a pointer that points to another pointer 
     *                    
     * 
     * 
     * */
    int value = 20;
    int *pointer;
    int **pPtr;
    int ***pPt;
    
    pointer = &value;

    pPtr = &pointer;
    
    pPt = &pPtr;

    
    printf("value1 = %d\t\t\t", value);
    printf("Size of value = %ld\n", sizeof(value));
    printf("*pointer = %d\t\t\t", *pointer);
    printf("Size of *pointer = %ld\n", sizeof(*pointer));
    printf("pointer = %p\t", pointer);
    printf("Size of pointer = %ld\n", sizeof(pointer));
    
    printf("---------------------------\n\n");
    
    printf("**pPtr = %d\t\t\t", **pPtr);
    printf("Size of **pPtr = %ld\n", sizeof(**pPtr));
    printf("*pPtr = %p\t\t", *pPtr);
    printf("Size of *pPtr = %ld\n", sizeof(*pPtr));
    printf("pPtr = %p\t\t", pPtr);
    printf("Size of pPtr = %ld\n", sizeof(pPtr));
    
    printf("---------------------------\n\n");
    
    printf("***pPt = %d\t\t\t", ***pPt);
    printf("Size of ***pPt = %ld\n", sizeof(***pPt));
    printf("**pPt = %p\t\t", **pPt);
    printf("Size of **pPt = %ld\n", sizeof(**pPt));
    printf("*pPt = %p\t\t", *pPt);
    printf("Size of *pPt = %ld\n", sizeof(**pPt));
    printf("pPt = %p\t\t", pPt);
    printf("Size of pPt = %ld\n", sizeof(pPt));
    
    printf("---------------------------\n\n");
    
    
    char first = 'A';
    char *pChar;
    
    pChar = &first;
    
    printf("first = %c\t\t", first);
    printf("Size of first = %ld\n", sizeof(first));
    
    printf("*pChar = %c\t\t", *pChar);
    printf("Size of *pChar = %ld\n", sizeof(*pChar));
    
    printf("pChar = %p\t\t", pChar);
    printf("Size of pChar = %ld\n", sizeof(pChar));
    
    return 0;
}