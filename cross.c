 #include <stdio.h>
#include <string.h>

#define ROWS 6
#define COLS 5

void print_array(char array[ROWS][COLS + 1]) {
    for (int i = 0; i < ROWS; i++) {
        printf("%s\n", array[i]);
    }
}

int search_in_array(char array[ROWS][COLS + 1], const char *search_str) {
    int length = strlen(search_str);

    
    for (int i = 0; i < ROWS; i++) {
        if (strncmp(array[i], search_str, length) == 0) {
            return 1; 
        }
    }

    
    for (int j = 0; j < COLS; j++) {
        char column[ROWS + 1] = {0}; 
        for (int i = 0; i < ROWS; i++) {
            column[i] = array[i][j];
        }
        column[ROWS] = '\0'; 

        if (strncmp(column, search_str, length) == 0) {
            return 1; 
        }
    }

    return 0; 
}

int main() {
    
    char array[ROWS][COLS + 1] = {
        "EDDFR",
        "AFVAQ",
        "TEBST",
        "LJGT",
        "T",
        "1234" 
    };
    
    char search_str[100];
    int score = 0;

    printf("Current Array:\n");
    print_array(array);

    while (1) {
        printf("Enter a string to search (or type 'END' to exit): ");
        scanf("%s", search_str);

        if (strcmp(search_str, "END") == 0) {
            break; 
        }

        if (search_in_array(array, search_str)) {
            score++;
            printf("%s is present. Score: %d\n", search_str, score);
        } else {
            score--;
            printf("%s is not present. Score: %d\n", search_str, score);
        }
    }

    return 0;
}
