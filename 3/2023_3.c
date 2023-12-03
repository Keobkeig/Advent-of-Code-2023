#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int findGearRatio(char* string);

int main(void) {
    FILE* fptr = fopen("test.txt", "r");
    //FILE* fptr = fopen("input.txt", "r");
    char buff[255];
    int result = 0;
    while (fgets(buff, strlen(buff), fptr)) {
        result += findGearRatio(buff); 
    }
    return 0;
}

int findGearRatio(char* string) {
    
}