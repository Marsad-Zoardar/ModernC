//Author: Md Marsad Zoardar
//August 23, 2026
//Implementation of a simple circular buffer provided by claude


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#define CAP 5   //defining a global variable
//
//
////using typedef makes it simpler 
//typedef struct{
//    int start;
//    int len;
//    int data[CAP]; //plain fixed-size array - no malloc, no opaque type
//}circular_buffer;
//
////Initialization function of the circular_buffer
//void cb_init(circular_buffer *c){
//    
//    c->start = 0; //initialize the first element to 0
//    c->len = 0;   //initialize the buffer length to 0
//}
//
////Function to add elements to the circular_buffer
//void cb_append(circular_buffer *c, int value){ //The user gives an input of type int
//    
//    int next = (c->start + c->len) % CAP; //This is to set the index position of the data array
//    //i.e. start = 0 and len = 1
//    c->data[next] = value;
//    c->len++;
//}
//
////Function to drop elements out of the buffer
//int cb_pop(circular_buffer *c){
//    
//    int value = c->data[c->start];
//    c->start = (c->start + 1) % CAP;
//    c->len --;
//    
//    return value;
//}
//
//int main(int argc, char **argv){
//    
//    circular_buffer c;
//    cb_init(&c);
//    cb_append(&c, 10);
//    cb_append(&c, 20);
//    cb_append(&c, 30);
//    
//    printf("%d\n", cb_pop(&c));
//    printf("%d\n", cb_pop(&c));
//    
//    return 0;
//}

