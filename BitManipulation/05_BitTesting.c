//Author: Md Marsad Zoardar
//October 14, 2026
//Program: 
/*
Suppose you have: a 16 bit register.

You want to change only bits [10:6] to the value 0b00101, leaving all other bits unchanged.
You already know the two operations involved:
1. Clear the existing field.
2. Insert the new field value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MODE_MASK  0x1Fu
#define MODE_SHIFT 6u


int main(void){
    
    uint16_t control = 0xFFFFu;
    
    control &= ~(MODE_MASK << MODE_SHIFT);
    
    printf("Control value in hexadecimal: %#x\n", control);
    
    control |= (5u << MODE_SHIFT);
    printf("Control value in hexadecimal: %#x\n", control);
    
    return 0;
}