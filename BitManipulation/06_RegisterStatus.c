//Author: Md Marsad Zoardar
//October 15, 2026
//Program: 
/*
Need to check if a register is ready and has no error.
 * An 8 bit register where bit 3 is ready and bit 5 is error
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MASK 0x01u
#define READY_SHIFT 3u
#define ERROR_SHIFT 5u


//int main(void){
//    
//    uint8_t status = 0b00101000;
//    int ready = 0;
//    int error = 0;
//    //Bit 3: Ready
//    //Bit 5: Error
//    // && !(status & (MASK << ERROR_SHIFT))
//    
//    if(status & (MASK << READY_SHIFT)){
//        ready = 1;
//        printf("The register is ready!\n");
//    }else{
//        printf("The register is not ready.\n");
//    }
//    
//    if(status & (MASK << ERROR_SHIFT)){
//        error = 1;
//        printf("The register has an error in it!\n");
//    }else{
//        printf("The register has no error.\n");
//    }
//    
//    if(ready && error){
//        printf("The register is ready but cannot run due to an error!\n");
//    }else if(ready && !error){
//        printf("The register is ready to run...............\n");
//    }
//    
//    
//    return 0;
//}