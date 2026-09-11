//Author: Md Marsad Zoardar
//September 09 & 10, 2026
//Program 13: This program finds where the longest word and saves the word in another buffer. But, this time, the buffer size is
//small. We are doing it intentionally to see what happens and how to tackle the problem.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>


const char *findTheLongestWord(const char *src);
size_t largestWordLength(const char *src);

//int main(void){
//    
//    clock_t start = clock();
//    
//    char string[] = "As the single vector rotates in an anti-clockwise direction, its tip at point A will rotate one complete revolution" 
//    "of 360° or 2π radians representing one complete cycle. If the length of its moving tip is transferred at different angular intervals" 
//    "in time to a graph as shown above, a sinusoidal waveform would be drawn starting at the left with zero time. Each position along the" 
//    "horizontal axis indicates the time that has elapsed since zero time, t = 0. When the vector is horizontal the tip of the vector represents" 
//    "the angles at 0°, 180°, and at 360°. Likewise, when the tip of the vector is vertical it represents the positive peak value, (+Amax) at" 
//    "90° or π⁄2 and the negative peak value, (−Amax) at 270° or 3π⁄2. Then the time axis of the waveform represents the angle either in degrees" 
//    "or radians through which the phasor has moved. So we can say that a phasor represents a scaled voltage or current value of a rotating" 
//    "vector which is \"frozen\" at some point in time, (t) and in our example above, this is at an angle of 30°. Sometimes when we are" 
//    "analysing alternating waveforms we may need to know the position of the phasor, representing the alternating quantity at some particular" 
//    "instant in time especially when we want to compare two different waveforms on the same axis. For example, voltage and current. We have" 
//    "assumed in the waveform above that the waveform starts at time t = 0 with a corresponding phase angle in either degrees or radians. But" 
//    "if a second waveform starts to the left or to the right of this zero point, or if we want to represent in phasor notation the relationship" 
//    "between the two waveforms, then we will need to take into account this phase difference, Φ of the waveform. Consider the diagram below" 
//    "from the previous Phase Difference tutorial. As the single vector rotates in an anti-clockwise direction, its tip at point A will rotate one complete revolution" 
//    "of 360° or 2π radians representing one complete cycle. If the length of its moving tip is transferred at different angular intervals" 
//    "in time to a graph as shown above, a sinusoidal waveform would be drawn starting at the left with zero time. Each position along the" 
//    "horizontal axis indicates the time that has elapsed since zero time, t = 0. When the vector is horizontal the tip of the vector represents" 
//    "the angles at 0°, 180°, and at 360°. Likewise, when the tip of the vector is vertical it represents the positive peak value, (+Amax) at" 
//    "90° or π⁄2 and the negative peak value, (−Amax) at 270° or 3π⁄2. Then the time axis of the waveform represents the angle either in degrees" 
//    "or radians through which the phasor has moved. So we can say that a phasor represents a scaled voltage or current value of a rotating" 
//    "vector which is \"frozen\" at some point in time, (t) and in our example above, this is at an angle of 30°. Sometimes when we are" 
//    "analysing alternating waveforms we may need to know the position of the phasor, representing the alternating quantity at some particular" 
//    "instant in time especially when we want to compare two different waveforms on the same axis. For example, voltage and current. We have" 
//    "assumed in the waveform above that the waveform starts at time t = 0 with a corresponding phase angle in either degrees or radians. But" 
//    "if a second waveform starts to the left or to the right of this zero point, or if we want to represent in phasor notation the relationship" 
//    "between the two waveforms, then we will need to take into account this phase difference, Φ of the waveform. Consider the diagram below" 
//    "from the previous Phase Difference tutorial."; 
//    
//    
//    size_t destinationSize = largestWordLength(string) + 1;
//    char buffer[destinationSize];
//    //Added a pointer to call the "findTheLongestWord" once and assign the value to it
//    const char *ptr = findTheLongestWord(string);
//    
//    printf("The longest word starts at address:  %p\n", findTheLongestWord(string));
//    printf("The length of the largest word: %zu\n\n", largestWordLength(string));
//    printf("Current destinationSize: %zu\n", destinationSize);
//    
//    if(destinationSize > 1){
//        for(int i = 0; i < destinationSize - 1; i++){
//            //Here I made a mistake calling the function repeatedly, which slows doen the program.
//            buffer[i] = *(ptr + i);
//            //printf("buffer[i] = %c\n", buffer[i]);
//            //printf("Current pointer at = %p and the char is: %c\n", findTheLongestWord(string) + i, *(findTheLongestWord(string) + i));
//        }
//        buffer[destinationSize - 1] = '\0';
//    
//        printf("The largest word is: %s \n", buffer);
//        
//    }else{
//        printf("The string is empty!\n\n");
//    }
//    
//    clock_t end = clock();
//    double elapsedTime = (double)(end - start)/CLOCKS_PER_SEC;
//    
//    printf("Program execution time: %0.9f\n", elapsedTime);
//    
//    return 0;
//}


//This function finds the pointer address where the longest word starts
const char *findTheLongestWord(const char *src){
    
    const char *longestWordStart = NULL;//This pointer stores the starting point of the longest word
    size_t maxLength = 0;
    size_t count = 0;
    size_t currentLength = 0;
    
    //printf("While loop in the function \"Find largest Word\" starts.................\n\n");
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            //printf("Found a space. Pointer is at %p\n", src);
            src++;
        }else{
            //printf("Found a char. Pointer is at %p and the char is: %c\n", src, *src);
            count++;
            //printf("Current count; %zu\n", count);
            src++;
            if(isspace((unsigned char)*src)){
                currentLength = count;
                if(currentLength > maxLength){
                    maxLength = currentLength;
                    //printf("Found the longest word\n");
                    //printf("src = %p\n", src);
                    //printf("currentLength = %zu\n", currentLength);
                    longestWordStart = src - currentLength;
                    //printf("longestWordStart = %p\n", longestWordStart);
                    
                }
                count = 0;
            }
        }
    }
    //printf("While in the function \"Find largest Word\" loop ends............\n\n");
    
    if(count != 0){
        //printf("Checking for count after the while loop\n\n");
        currentLength = count;
        if(currentLength > maxLength){
            maxLength = currentLength;
            //printf("Max length = %zu\n", maxLength);
            longestWordStart = src - currentLength;
        }
    }
    
    
    return longestWordStart;
}

//This funciton returns the length of the largest word to help determine the buffer size
size_t largestWordLength(const char *src){
    
    
    size_t maxLength = 0;
    size_t count = 0;
    
    //printf("While loop in the function \"largestWordLength\" starts.................\n\n");
    while(*src != '\0'){
        if(isspace((unsigned char)*src)){
            //printf("Found a space! Skipping...\n");
            src++;
        }else{
            //printf("Found a word! Counting....\n");
            count++;
            src++;
            if(isspace((unsigned char)*src)){
                //printf("Found another space after a word. Current count = %zu\n", count);
                if(count > maxLength){
                    //printf("Setting max length to count\n\n");
                    maxLength = count;
                }
                //printf("Max length = %zu\n", maxLength);
                //printf("Resetting count to 0\n\n");
                count = 0;
            }
        }
    }
    //printf("While loop ends............\n\n");
    
    if(count != 0){
        //printf("The string didn't end with a space. Current count = %zu\n", count);
        if(count > maxLength){
            //printf("Setting max length to count\n\n");
            maxLength = count;
        }
    }
    //printf("Max length = %zu\n", maxLength);
    
    return maxLength;
}
