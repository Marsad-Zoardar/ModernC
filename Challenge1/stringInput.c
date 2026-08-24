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
void inputChar5(){
    
    char *pInput5;
    
    pInput5 = (void*)malloc(100*sizeof(char));
    
    printf("Write something you want to print out: ");
    fgets(pInput5, 100, stdin);
    
    printf("What you wrote is: %s\n", pInput5);
    
    //free(pInput5);
}

 
int main(){
     
     //inputChar();
     //inputChar2();
     //inputChar3();
     //inputChar4();
     inputChar5();
     
     return 0;
}