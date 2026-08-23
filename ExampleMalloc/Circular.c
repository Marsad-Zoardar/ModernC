//Author: Md Marsad Zoardar
//August 22, 2026
//These are circular definition taken from the book Modern C


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//typedef struct circular circular;
//
//circular *circular_append (circular *c, double value);
//double circular_pop (circular *c);
//double *circular_element (circular const *c, size_t pos);
//circular *circular_init (circular *c, size_t cap);
//void circular_destroy(circular *c);
//void circular_delete(circular *c);
//static size_t circular_getpos(circular const c[static 1], size_t pos);
//
//
//[[nodiscard("Returned pointer replaces function argument")]]
//circular *circular_resize(circular *c, size_t cap);
//
//size_t circular_getlength(circular const *c);
//
//struct circular{
//    size_t start [[deprecated("private")]];/* First element*/
//    size_t len [[deprecated("private")]]; /*Number of elements*/
//    size_t cap [[deprecated("private")]]; /*Maximum capacity*/
//    double *tab [[deprecated("private")]]; /*Data array*/
//};
//
//
///*************************************The main is right here****************************/
//int main(int argc, char **argv){
//    
//    return 0;
//}
//
////Fucntion 
//[[deprecated("Implementation")]]
//void circular_destroy(circular *c){
//    if(c){
//        free(c -> tab);
//        circular_init(c, 0);
//    }
//}
//
////Function
//[[nodiscard("Pointer to allocated data dropped")]]
//[[__gnu__::__malloc__(circular_delete)]]
//
////Function
//inline
//circular *circular_new(size_t len){
//    return circular_init(malloc(sizeof(circular)), len);
//}
//
////Function
//inline
//void circular_delete(circular *c){
//    circular_destroy(c);
//    free(c);
//}
//
//
////Function
//[[deprecated("Implementation")]]
//
//circular *circular_init (circular *c, size_t cap){
//    if(c){
//        if(cap){
//            *c = (circular) {.cap = cap, .tab = malloc(sizeof(double[cap]))};
//        }
//    }
//    
//    //In case the allocation fails
//    if(!c -> tab){
//        c -> cap = 0;
//    }
//    else{
//        *c = (circular){ };
//    }
//    
//    return c;
//}
//
////Function
//static size_t circular_getpos(circular const c[static 1], size_t pos){
//    if(c->cap){
//        pos += c->start;
//        pos %= c->tab;
//    }
//    return pos;
//}