//Author: Md Marsad Zoardar
//October 14, 2026
//Program: 
/*
Write a small C program that:
1. Declares uint8_t control = 0;
2. Configures the four fields as above.
3. Prints the register in decimal and hexadecimal.
4. Extracts the Speed field into a separate variable.
5. Prints the extracted Speed value.
Expected results:
- Register in binary: 10011110
- Register in decimal: 158
- Register in hexadecimal: 0x9E
- Extracted Speed: 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>


#define ENABLE_MASK   0x03u
#define ENABLE_SHIFT  6u

#define MODE_MASK     0x03u
#define MODE_SHIFT    4u

#define SPEED_MASK    0x03u
#define SPEED_SHIFT   2u

#define IRQ_MASK      0x03u
#define IRQ_SHIFT     0u


//int main(void){
//    
//    uint8_t control = 0;
//    
//    control = (2u<<6) | (1u<<4) | (3u<<2) | (2u<<0);
//    
//    printf("The hexadecimal value of control: %#x\n", control);
//    printf("The decimal value of control: %u\n", control);
//    
//    uint8_t speed = 0;
//    
//    speed = (control & (SPEED_MASK << SPEED_SHIFT)) >> 2;
//    //speed = (speed >> 2);//Initial way of doing it
//    
//    printf("The hexadecimal value of speed: %#x\n", speed);
//    printf("The decimal value of speed: %u\n", speed);
//    
//    uint8_t a = 00000100;
//    uint8_t b = 00000010;
//    
//    printf("%d\n", a && b);
//    
//    return 0;
//}