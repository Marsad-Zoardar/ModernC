//Author: Md Marsad Zoardar
//October 15, 2026
//Program: 
/*
challenge: Checking whether multiple bits are clear
Let's reverse the problem.
Suppose: s  asdfgyuo
 * 
uint8_t status = 0b10010001;

We want to verify that both bit 5 and bit 3 are clear.
I want you to write:
1. A mask that selects bits 5 and 3.
2. A single if condition that checks whether both selected bits are 0.
One important requirement: Don't modify status.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//int main(void){
//    
//    uint8_t status = 0b10110001;
//    printf("Status: %u\n", status);
//    
//    uint8_t mask = (1u << 5) | (1u << 3);
//    printf("Mask: %u\n", mask);
//    
//    mask = ~(mask);
//    printf("Mask: %u\n", mask);
//    
//    status &= (mask);
//    printf("Status: %u\n", status);
//    
//    if((status & mask) == 0u){
//        printf("Both bits are cleared!\n");
//    }
//    
//    return 0;
//}