//Author: Md Marsad Zoardar
//October 15, 2026
//Program: 
/*
challenge: Detecting a hardware fault
Suppose a microcontroller has the following 8-bit status register:
Bit:    7   6   5   4   3   2   1   0
       +---+---+---+---+---+---+---+---+
       | 0 | 1 | 0 | 1 | 0 | 0 | 1 | 0 |
       +---+---+---+---+---+---+---+---+
           |       |           |
           |       |           +-- Bit 1: READY
           |       +-------------- Bit 4: OVERHEAT
           +---------------------- Bit 6: LOW_VOLTAGE

In C:
uint8_t status = 0b01010010;

The system can operate only when:
1. READY (bit 1) is set.
2. OVERHEAT (bit 4) is clear.
3. LOW_VOLTAGE (bit 6) is clear.
Your task: Write a single if condition that checks all three requirements.
You can use &, |, !, and && as needed.
One hint: Since both OVERHEAT and LOW_VOLTAGE must be clear, you can combine their masks and test them together.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define FAULT_MASK 0x50u
#define READY_MASK 0x2u

bool canSystemRun(uint8_t status);

int main(void){
    
    uint8_t status1 = 0b01010010;//decimal 82
    uint8_t status2 = 0x02u;
    uint8_t status3 = 0b01000010;
    uint8_t status4 = 0b00010010;
    //uint8_t status = 0b00000010;//
    
    bool result1 = canSystemRun(status1);
    bool result2 = canSystemRun(status2);
    bool result3 = canSystemRun(status3);
    bool result4 = canSystemRun(status4);
    
    printf("%d\n", result1);
    printf("%d\n", result2);
    printf("%d\n", result3);
    printf("%d\n", result4);

    
    return 0;
}


//longer version
//bool canSystemRun(uint8_t status){
//    
//    if(((status & FAULT_MASK) == 0u) && ((status & READY_MASK) != 0u)){
//        return true;
//    }else{
//        return false;
//    }
//    
//}

//shorter version
bool canSystemRun(uint8_t status){
    
    return ((status & FAULT_MASK) == 0u) && 
           ((status & READY_MASK) != 0u);
        
    
}