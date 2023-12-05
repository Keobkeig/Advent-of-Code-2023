#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int calcPoints(char* s);

int main(void) {
    //FILE* fptr = fopen("input.txt", "r");
    FILE* fptr = fopen("test.txt", "r");

    char buff[256];
    int total_points = 0;

    while (fgets(buff, 256, fptr) != NULL) {
        total_points += calcPoints(buff);
    }
    printf("[Day 4 Part 1] Total points: %d\n", total_points);
    return 0;
}

int calcPoints(char* s) { 
    s = strcpy(s, s + 8); 
    int picks[10] = {0};
    int i = 0;
    int num = 0;
    //get the picks
    while(*s != '\0') {
        if (*s == '|') {
            break;
        }
        if (isdigit(*s)) {
            num = num * 10 + (*s - '0');
        }
        else if (*s == ' ') {
            picks[i] = num;
            num = 0;
            i++;
        }
        s++;
    }
    
    //get the winning numbers
    int winning[39] = {0};
    int j = 0;
    while(*s != '\0') {
        if (isdigit(*s)) {
            num = num * 10 + (*s - '0');
        }
        else if (*s == ' ') {
            winning[j] = num;
            num = 0;
            j++;
        }
        s++;
    }
    printf("winning %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", winning[0], winning[1], winning[2], winning[3], winning[4], winning[5], winning[6], winning[7], winning[8], winning[9]);


    int matches = 0;
    // //compare the picks and winning numbers
    // for (int i = 0; i < 10; i++) {
    //     for (int j = 0; j < 39; j++) {
    //         printf("Comparing %d and %d\n", picks[i], winning[j]);
    //         if (picks[i] == winning[j]) {
    //             matches++;
    //         }
    //         break;
    //     }
    // }

    return pow(2, matches);

}