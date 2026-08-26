//Author: Md Marsad Zoardar
//August 24, 2026

/*This is the first part of the challenge program. I will do a divide and conquer method to develop a complete program
 * --> I will get a string input from the user, store it in an array, and display it.*/
 
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 /***************Function 1 - Get a char input and displays it*************************************/
//void inputChar(){
//     
//     char input;
//     printf("Enter a character: ");
//     scanf("%c", &input);
//     
//     printf("You entered: %c\n", input);
// }

/***************Function 2 - This function keeps taking a character until it hits its limit or entered x by the user, then it prints out*****************/ 
// void inputChar2(){
//     
//     char input2[50];
//     
//     for(int i = 0; i <= sizeof(input2); i++){
//         printf("Enter a character: ");
//         scanf("%s", &input2[i]);
//         
//         if(input2[i] == 'x' || input2[i] == 'X')
//             break;
//     }
//     
//     printf("%s\n", input2);
// }
// 

/*************Function 3 - This function takes a string input from the user and prints out******************************/
//void inputChar3(){
//    
//    char input3[100];
//    printf("Write something you want to print out: ");
//    scanf("%[^\n]s", input3);
//    
//    printf("What you wrote is: %s\n", input3);
//} 

/*************Function 4 - This function takes a string input from the user using fgets() and prints out******************************/
//void inputChar4(){
//    
//    char input4[100];
//    printf("Write something you want to print out: ");
//    fgets(input4, sizeof(input4), stdin);
//    
//    printf("What you wrote is: %s\n", input4);
//}

/*************Function 5 - This function uses a pointer array, dynamically allocates its memory, and then stores the user input******************************/
//void inputChar5(){
//    
//    char *pInput5;
//    
//    pInput5 = malloc(100*sizeof(char));
//    
//    if(pInput5 == NULL){
//        printf("Memory allocation failed\n");
//    }
//    
//    printf("Write something you want to print out: ");
//    fgets(pInput5, 100, stdin);
//    
//    printf("What you wrote is: %s\n", pInput5);
//    
//    free(pInput5);
//}

/*************Function 6 - This function has a 2D array that can store 5 strings, each with a size of 100 characters************************/
#define INITIAL_CAPACITY 5
#define BUFFER 100

//void arrayString(){
//    
//    char userInput[INITIAL_CAPACITY][BUFFER];
//    
//    for(int i = 0; i < 5; i++){
//        printf("Enter your command %d: ", i + 1);
//        fgets(userInput[i], sizeof(userInput[i]), stdin);
//        
//    }
//
//    printf("\tYou entered\n");
//    printf("---------------------------------\n");
//    
//    for(int j = 0; j < 5; j++){
//        printf("%s", userInput[j]);
//    }
//    
//}
/*************Function 7 - This function has a 2D array where malloc is used to allocate the size***********************/
//void arrayString2(){
//    
//    char (*pUserInput)[BUFFER];
//    
//    pUserInput = malloc(INITIAL_CAPACITY*sizeof(*pUserInput));
//    
//    if(pUserInput == NULL){
//        printf("Memory allocation failed!\n");
//    }
//    
//    for(int i = 0; i < INITIAL_CAPACITY; i++){
//        printf("Enter your command %d: ", i + 1);
//        fgets(pUserInput[i], sizeof(pUserInput[i]), stdin);
//    }
//    
//    printf("\tYou entered\n");
//    printf("---------------------------------\n");
//    
//    for(int j = 0; j < 5; j++){
//        printf("%s", pUserInput[j]);
//    }
//    
//    free(pUserInput);
//}    
/*************Function 8 - This function has a 2D array, where malloc and realloc were both used************************/
//void arrayString3(){
//    
//    char (*pUserInput)[BUFFER];
//    size_t capacity = INITIAL_CAPACITY;
//    size_t count = 0;
//    
//    pUserInput = malloc(INITIAL_CAPACITY*sizeof(*pUserInput));
//    
//    if(pUserInput == NULL){
//        printf("Memory allocation failed!\n");
//        return;
//    }
//    
//    for(int i = 0; i < capacity; i++){
//        printf("Enter your command %d: ", i + 1);
//        fgets(pUserInput[i], sizeof(pUserInput[i]), stdin);
//        pUserInput[i][strcspn(pUserInput[i], "\n")] = '\0';
//    
//        
//        if(strcmp(pUserInput[i], "exit") == 0){
//            break;
//        }
//        
//        count++;
//        
//        if(count == capacity){
//            capacity *= 2;
//            
//            char (*temp)[BUFFER];
//            temp = realloc(pUserInput, capacity*sizeof(*pUserInput));
//            
//            if(temp == NULL){
//                printf("Memory allocation failed to temp!\n");
//                free(pUserInput);
//                return;
//            }else{
//            
//            pUserInput = temp;
//            
//            }
//
//        }
//        
//    }
//    
//    printf("\tYou entered\n");
//    printf("---------------------------------\n");
//    
//    for(int j = 0; j < count; j++){
//        printf("%s\n", pUserInput[j]);
//        
//    }
//    
//    free(pUserInput);
//}     
/*************Function 8 - This function has a 2D array, where malloc and realloc were both used************************/
void arrayString4(){
    
    char **pUserInput; //char --> one character, char* --> one string, char** --> array of strings

    
    size_t commandCapacity = INITIAL_CAPACITY;
    size_t count = 0;
    size_t stringCapacity = INITIAL_CAPACITY;
    size_t i = 0;
    
    pUserInput = malloc(commandCapacity*sizeof(*pUserInput));
    //check if memory allocation for the string array were successful or not
        if(pUserInput == NULL){
            printf("Memory allocation failed!");
            return;
        }
    
    while(1){
        printf("Enter your command\n> ");
        
        pUserInput[i] = malloc(stringCapacity);
        //Check if malloc were successful or not
            if(pUserInput[i] == NULL){
                printf("Memory allocation failed!");
                return;
            }
        
        size_t length = 0;
        while(1){
            if(fgets(pUserInput[i] + length, stringCapacity - length, stdin) == NULL){
                printf("String read error!");
                free(pUserInput);
                free(pUserInput[i]);
                return;
            }
        
                if(strchr(pUserInput[i] + length, '\n') != NULL){
                    break;
                }
            length = strlen(pUserInput[i]);
            
            stringCapacity *= 2;
            char *temp;
            temp = realloc(pUserInput[i], stringCapacity);
                if(temp == NULL){
                    printf("Memory allocation failed!");
                    free(pUserInput[i]);
                    return;
                }
            pUserInput[i] = temp;
        }
        stringCapacity = INITIAL_CAPACITY;
        
        
            pUserInput[i][strcspn(pUserInput[i], "\n")] = '\0';
        
                if(strcmp(pUserInput[i], "exit") == 0){
                    free(pUserInput[i]);
                    break;
                }
        
        count++;
        i++;
        
        if(count == commandCapacity){
            char **temp2;
            commandCapacity *= 2;
            
            temp2 = realloc(pUserInput, commandCapacity*sizeof(*pUserInput));
            if(temp2 == NULL){
                printf("Memory allocation failed!");
                free(pUserInput[i]);
                return;
            }
            
            pUserInput = temp2;
 
        }
 
    }
    
    printf("\tYou entered\n");
    printf("---------------------------------\n");
    
    for(size_t j = 0; j < count; j++){
        printf("%s\n", pUserInput[j]);
        free(pUserInput[j]);
        
    }
    
    
    free(pUserInput);
    
}    
 
int main(){
     
     //inputChar();
     //inputChar2();
     //inputChar3();
     //inputChar4();
     //inputChar5();
     //arrayString();
     //arrayString2();
     //arrayString3();
     arrayString4();
     
     
     return 0;
}