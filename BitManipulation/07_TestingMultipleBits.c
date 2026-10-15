//Author: Md Marsad Zoardar
//October 15, 2026
//Program: 
/*
Challenge: Testing multiple bits
Let's move to something slightly different.
Suppose a microcontroller status register contains:
uint8_t status = 0b10110110;

You want to check whether both bit 7 and bit 5 are set.
Here's the catch: I want you to do it using one bitwise AND operation, rather than two separate conditions joined by &&.
Think about these questions:
1. How would you construct a mask that selects both bit 7 and bit 5?
2. How would you use that mask to determine whether both bits are set, rather than just one of them?
You can write your answer as a C if statement.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

//int main(void){
//    
//    uint8_t status = 0b10110110;
///**************The problem with this piece of code is this modifies the status bit******************/    
////    status &= (5u<<5);
////    
////    //printf("Status value in hex: %#x\n", status);
////    
////    if(status == 0xa0){
////        printf("Both bits are set!\n");
////    }
///*********************************************************************/ 
//
//    uint8_t mask = (1u << 7) | (1u << 5);
//    
//    if((status & mask) == mask){
//        printf("Both bits are set.\n");
//    }
//
//   
//    return 0;
//}