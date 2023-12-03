#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_RED 12
#define MAX_GREEN 13 
#define MAX_BLUE 14

int isImpossible(char* string) {
    char game_label[3];
    strncpy(game_label, string + 5, 3); //eliminates 'Game ' 
    printf("\n%s", game_label); 
    int game_id = atoi(game_label);
    char *game_sets = strstr(string, ": ") + 2;  //eliminates ": "

    while (game_sets != NULL) {
        //per game set
        int i = 0;
        int num = 0;

        while (game_sets[i] != ';' && game_sets[i] != '\0') {
            if (isdigit(game_sets[i])) {
                num = (num*10) + (game_sets[i] - '0'); //gets the numbers before the color 
            }
            else if (game_sets[i] == 'r' && game_sets[i+1] == 'e' && game_sets[i+2] == 'd') {
                int red = num;
                printf("red: %d\n", red);
                if (red > MAX_RED) {
                    return 0;
                }
                num = 0;
            } 
            else if (game_sets[i] == 'g' && game_sets[i+1] == 'r' && game_sets[i+2] == 'e' && game_sets[i+3] == 'e') {
                int green = num;
                printf("green: %d\n", green);
                if (green > MAX_GREEN) {
                    return 0;
                }
                num = 0;
            } 
            else if (game_sets[i] == 'b') {
                int blue = num;
                  printf("blue: %d\n", blue);
                if (blue > MAX_BLUE) {
                    return 0;
                }
                num = 0;
            }
            i++;
        }
        //next game set
        game_sets = strstr(game_sets, ";");
        if (game_sets != NULL) {
            game_sets += 2; //eliminates "; "
        }
    }
    return game_id;
}

int main(void) {
    //FILE* fptr = fopen("test.txt", "r");
    FILE* fptr = fopen("input.txt", "r");
    char buff[255];
    int result = 0;
    while(fgets(buff, 255, fptr)) {
        result += isImpossible(buff);
    }
    fclose(fptr);
    printf("\n[Day 2 | Part 1] Solution: %d\n", result);
}

