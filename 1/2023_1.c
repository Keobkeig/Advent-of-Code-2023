#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int findFirstNum(char buff[]) {
        size_t i = 0;
        while(buff[i] != '\0' && i >= 0) {
            char c = buff[i];
            if (c == '\0' || c == '\n' || c == '\r') {
                break;  //reached end of line 
            }
             if (c > '0' && c <= '9') {
                char* temp = &c;
                //printf("The first num in %s is %d\n", string, num);
                return c - 48;
            }
            i++;
        }
        return 0;
    }

int findLastNum(char buff[]) {
    size_t i = strlen(buff) - 1;
    while(buff[i] != '\0' && i >= 0) {
        char c = buff[i];

        if (c > '0' && c <= '9') {
            char* temp = &c;
            //printf("The first num in %s is %d\n", string, num);
            return c - 48;
        }
        i--;
    }
    return 0;
}


int main(void) {
    // FILE* file = fopen("test.txt", "r");
    FILE* fptr = fopen("input.txt", "r");

    char buff[255];
    int result = 0;
    while(fgets(buff, 255, fptr)) {
        int firstNumber = findFirstNum(buff);
        int lastNumber = findLastNum(buff);
        result += (firstNumber* 10) + lastNumber;
        //printf("\n%s [%d,%d]", buff, firstNumber, lastNumber);
    }
    fclose(fptr);
    printf("\n[Day 1 | Part 1] Solution: %d\n", result);

}
