 #include <stdio.h>

#define GRID_SIZE 5


void Grid(char grid[GRID_SIZE][GRID_SIZE]);
void Move(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY, char direction);

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };
    int playerX = 4, playerY = 4; // Initial player position
    char move;

    printf("Welcome to the Adventure Game!\n");
    printf("Controls: W = up, S = down, A = left, D = right, Q = quit\n");

    while (1) {
        Grid(grid);
        printf("Enter your move: ");
        scanf(" %c", &move);

        if (move == 'Q' || move == 'q') {
            printf("Exiting the game.\n");
            break;
        }

        Move(grid, &playerX, &playerY, move);
    }

    return 0;
}


void Grid(char grid[GRID_SIZE][GRID_SIZE]) {
    printf("\nCurrent Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move the player in the specified direction
void Move(char grid[GRID_SIZE][GRID_SIZE], int *playerX, int *playerY, char direction) {
    int newX = *playerX;
    int newY = *playerY;

    
    switch (direction) {
        case 'W':
        case 'w':
            newX -= 1;
            break;
        case 'S':
        case 's':
            newX += 1;
            break;
        case 'A':
        case 'a':
            newY -= 1;
            break;
        case 'D':
        case 'd':
            newY += 1;
            break;
        default:
            printf("Invalid move. Use W, S, A, D, or Q to quit.\n");
            return;
    }

    
    if (newX < 0 || newX >= GRID_SIZE || newY < 0 || newY >= GRID_SIZE) {
        printf("You can't move outside the grid!\n");
        return;
    }


    if (grid[newX][newY] == 'X') {
        printf("You can't move into an obstacle!\n");
        return;
    }

    
    if (grid[newX][newY] == 'I') {
        printf("You collected an item!\n");
    }

    
    grid[*playerX][*playerY] = ' ';  // Clear the old position
    grid[newX][newY] = 'P';          // Update to new position
    *playerX = newX;
    *playerY = newY;
}
