//Author: Md Marsad Zoardar
//September 27, 2026
//Program 1: This is the very first program in Bit manipulation.

/************************Program Requirements******************************
 Exercise: Configure an 8-bit Control Register

Assume this hardware register:-> uint8_t control = 0;
Its layout is:
Bit:   7   6   5   4   3   2   1   0
      +---+---+---+---+---+---+---+---+
      | E | E | M | M | S | S | I | I |
      +---+---+---+---+---+---+---+---+

       Enable   Mode     Speed    Interrupt
       [7:6]    [5:4]    [3:2]     [1:0]

Each field contains multiple bits.

Your tasks -> Write C code that performs these operations using only bitwise operators and shifts (&, |, ~, ^, <<, >>).
----------------------------------------------------------------------------------------------------------
1. Set Enable to 2
Enable is bits 7–6.
Enable = 2
binary  = 10
After setting it, what should the register look like?
-------------------------------------------------------
2. Set Mode to 1
Mode is bits 5–4.
Mode = 1
binary = 01
Don't accidentally overwrite Enable.
-------------------------------------------------------
3. Set Speed to 3
Speed is bits 3–2.
Speed = 3
binary = 11
-------------------------------------------------------
4. Read/extract the Mode field
Given:
uint8_t control = 0x9F;
Extract only bits 5–4 so that you get:
mode = 1
Hint: You'll need both & and >>.
-------------------------------------------------------
5. Change Speed without touching anything else
Given:
control = 10111110
Change Speed bits [3:2] to: 01
Your result should be: 10100110
The important part is that you clear the old field first, then insert the new value.
-------------------------------------------------------------------------------------
6. Challenge 🔥
Write these macros:
#define SET_BIT(value, bit)
#define CLEAR_BIT(value, bit)
#define TOGGLE_BIT(value, bit)
#define TEST_BIT(value, bit)

For example:
uint8_t value = 0;
SET_BIT(value, 3);
SET_BIT(value, 6);

printf("%u\n", value);
Expected: 72
For TEST_BIT, make it return a clean 0 or 1, rather than the mask value.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define SET_BIT(value, bit) do{((value) |= (1u << (bit)));} while(0)
#define CLEAR_BIT(value, bit) do{(value) &= ~(1u << (bit));} while(0)
#define TOGGLE_BIT(value, bit) do{(value) ^= (1u << (bit));} while(0)
//#define TEST_BIT(value, bit) do{(((value) & (1u << (bit))) >> (bit));} while(0)//This macro defines it and then throws it away
#define TEST_BIT(value, bit) (((value) & (1u << (bit))) >> (bit))
    
//int main(void){
//    
//    uint8_t control = 0;
//    
//    /**************Program 1**********************/
//    //Set Enable (bit 7, 6) to 2 -> 1000 0000
//    SET_BIT(control, 7);
//    printf("Control = %u\n", control); // 1000 0000 = 128
//    /*Verdict: This output is mathmetically correct, but I am not treating bit 7 & 6 together*/
//    /**************Improved Version**********************/
//    control = 0;
//    control |= (2u << 6);
//    printf("Control = %u\n", control);
    /*****************--:--**********************/
    
//    //Set mode (Bit 5, 4) to 1 -> 1001 0000
//    SET_BIT(control, 4);
//    printf("Control = %u\n", control); // 1001 0000 = 144
//    
//    //Set speed(bit 3, 2) to 3 -> 1001 1100
//    SET_BIT(control, 3);
//    SET_BIT(control, 2);
//    printf("Control = %u\n", control); // 1001 1100 = 156
//    
//    //Read/Extract the mode field
//    //Given the new control value -> 0x9F = 10011111
//    control = 0x9F;
//    //Step 1: & operation to make them 1
//    SET_BIT(control, 5);
//    SET_BIT(control, 4);
//    printf("Control = %u\n", control);//10111111 = 191
//    control = control >> 4;
//    printf("Control = %u\n", control);//0000 1011 = 11
//    
//    //Change Speed without touching anything else
//    //Given:
//    control = 0xBE; //10111110
//    //Change Speed bits [3:2] to: 01. Your result should be: 10110110
//    CLEAR_BIT(control, 3);
//    CLEAR_BIT(control, 2);
//    printf("Control = %u\n", control); //1011 0010 = 178
//    SET_BIT(control, 2);
//    printf("Control = %u\n", control); //1011 0110 = 182
//    
//    return 0;
//}