//Author: Md Marsad Zoardar
//August 17, 2026
//Function-like Macros
//
//#include <stdio.h>
//#include <stdlib.h>
//
//
//#define MINSIZE(X, Y) (sizeof(X) < sizeof(Y) ? sizeof(X) : sizeof(Y))
//#define BYTECOPY(T, S) memcopy(&(T), &(S), MINSIZE(T, S))
//
//#if NDEBUG
//#define TRACE_PRINT0(F, X) do{/*Nothing*/} while(false)
//#else
//#define TRACE_PRINT0(F, X) fprintf(stderr, F, X)
//#endif
//
////This macro avoids the problem of mixing types, the output should always be either 1 or 0
//#ifdef NDEBUG
//#define TRACE_ON 0
//#else
//#define TRACE_ON 1
//#endif
//
////A simple version of the macro that ensures the fprintf call is always evaluated
//#define TRACE_PRINT2(F, X)\
//do{if(TRACE_ON) fprintf(stderr, ""F"\n", X );}\
//while(false)
//
////Tricks to trace a pointer without specifying the format
////If we add 0 to it, we can convert the type to the specified type
//#define TRACE_VALUE(HEAD, X) TRACE_PRINT2(HEAD, " %lg", (X)+0.0L)
//
////Using a cast of X to void*
//#define TRACE_PTR0(HEAD, X) TRACE_PRINT2(HEAD, " %lg", (void*) (X))
//
////This implements traces a pointer by assigned to a void* first
//#define TRACE_PTR1(HEAD, X) TRACE_PRINT2(HEAD " %p", ((void*) {(X)})) 
////
////int main(){
////    
////    return 0;
////}