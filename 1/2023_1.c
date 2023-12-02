#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findNum(char buff[], int ifFirst) {
    size_t i = ifFirst ? 0 : strlen(buff) - 1;
    while (buff[i] != '\0' && i >= 0) {
        char c = buff[i];
        if (c > '0' && c <= '9') {
            char* temp = &c;
            //printf("The first num in %s is %d\n", string, num);
            return c - 48;
        }
        if (ifFirst) {
            i++;
        } else {
            i--;
        }
    }
}

int main(void) {
    // FILE* file = fopen("test.txt", "r");
    FILE* fptr = fopen("input.txt", "r");

    char buff[255];
    int result = 0;
    while(fgets(buff, 255, fptr)) {
        int firstNumber = findNum(buff, 1);
        int lastNumber = findNum(buff, 0);
        result += (firstNumber* 10) + lastNumber;
        //printf("\n%s [%d,%d]", buff, firstNumber, lastNumber);
    }
    fclose(fptr);
    printf("\n[Day 1 | Part 1] Solution: %d\n", result);
}
