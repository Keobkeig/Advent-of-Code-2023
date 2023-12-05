#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLS 142 
#define MAX_ROWS 140 

static int max(const int num1, const int num2);
static int min(const int num1, const int num2);
static int is_special(const char c);

int main() {
    //FILE *file = fopen("test.txt", "r");
    FILE *file = fopen("input.txt", "r");

    char rows[MAX_COLS];
    char matrix[MAX_ROWS][MAX_COLS];
    int row_count = 0;

    while (fgets(rows, sizeof(rows), file) != NULL) {
      strcpy(matrix[row_count], rows);
      row_count++;
    }

    fclose(file);

    int result = 0;
    int num = 0;

    for (int i = 0; i < row_count; i++) {
      for (int j = 0; matrix[i][j] != '\0'; j++) {
        if (isdigit(matrix[i][j])) {
          int start_col, end_col, is_valid;
          start_col = j;
          is_valid = 0;
      
          while (isdigit(matrix[i][j])) {
            num = (num * 10) + (matrix[i][j] - '0');
            j++;
          }

          end_col = j - 1;  //CRUCIAL LINE: set j back to the last digit as end_col

          // 0s and row_count, MAX_COLS are the boundaries
          int srch_row_start = max(i - 1, 0);
          int srch_col_start = max(start_col - 1, 0);
          int srch_row_end = min(i + 1, row_count);
          int srch_col_end = min(end_col + 1, MAX_COLS);

          for (int row = srch_row_start; row <= srch_row_end; row++) {
            for (int col = srch_col_start; col <= srch_col_end; col++) {
              if (is_special(matrix[row][col])) {
                result += num;
                break;
              }
            }
          }
          num = 0;
        }
      }
    }
    //printf("[Day 3 Part 1 Test] Adjacency Sum: %d == 4361\n" , result);
    printf("[Day 3 Part 1] Total num is %d\n", result);
}


int max(const int num1, const int num2) {
    return (num1 > num2) ? num1 : num2;
}

int min(const int num1, const int num2) {
    return (num1 < num2) ? num1 : num2;
}
  
int is_special(const char c) {
    return c!='.' && ispunct(c) ? 1 : 0;
}