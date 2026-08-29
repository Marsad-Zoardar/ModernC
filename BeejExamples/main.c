//Author: Md Marsad Zoardar
//August 29, 2026
//Example program from Beej's Guide to C programming


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//structure to be sorted
struct animal{
    char *name;
    int legCount;
};

//creating a comparison function will be called by qsort()
//We will sort an array of struct, animal by leg count

int compare(const void *elem1, const void *elem2){
    
    //as we are sorting struct animal, we need to make both arguments pointers to be the struct type
    const struct animal *animal1 = elem1;
    const struct animal *animal2 = elem2;
    
    
    if(animal1->legCount > animal2->legCount){
        return 1;
    }
    if(animal1->legCount < animal2->legCount){
        return -1;
    }
    
    return 0;
}

void printValue(const int *ptr){
    printf("%d\n", *ptr);
    //*ptr = 100;
}

int main(){
    
    struct animal a[7] = {
        {.name = "Dog", .legCount = 4},
        {.name = "Monkey", .legCount = 2},
        {.name = "Antelope", .legCount = 4},
        {.name = "Snake" , .legCount = 0},
        {.name = "Ant", .legCount = 6},
        {.name = "Spider", .legCount = 8},
        {.name = "Maria", .legCount = 2}
    };
    
    qsort(a, 7, sizeof(struct animal), compare);

    for(int i = 0; i < 7; i++){
        printf("%d: %s\n", a[i].legCount, a[i].name);
    }
    
    int value = 42;
    printValue(&value);
    
    
    return 0;
}