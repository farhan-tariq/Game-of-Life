#include <stdio.h>
#include <stdlib.h>

/*
Game of Life Rules
-Any live cell with fewer than two live neighbours 
die, as if caused by under population.
-Any live cell with two or three live neighbours lives on to the next generation.
-Any live cell with more than three live neighbours dies, as if by overpopulation.
-Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
*/

void printGrid(char **grid, int r, int c);

int countNeighbours(char **grid, int r, int c, int i, int j);

void freeMemory(char **grid, char **grid2, int r);

int main() {
    int rowSize;
    int columnSize;
    int generations;
    int i = 0;
    int j = 0;
    int k = 0;
    int n;
    char state;
    char **oldGrid;
    char **copyGrid;


    scanf("%d %d %d", &rowSize, &columnSize, &generations);

    oldGrid = (char **) malloc(rowSize * sizeof(char *));
    copyGrid = (char **) malloc(rowSize * sizeof(char *));

    for (i = 0; i < rowSize; i++) {
        oldGrid[i] = malloc(columnSize * sizeof(char));
        copyGrid[i] = malloc(columnSize * sizeof(char));
        for (j = 0; j < columnSize; j++) {
            scanf(" %c", &oldGrid[i][j]);
        }
    }

    for (i = 0; i <= generations; i++) {
        for (j = 0; j < rowSize; j++) {
            for (k = 0; k < columnSize; k++) {
                state = oldGrid[j][k];
                n = countNeighbours(oldGrid, rowSize, columnSize, j, k);

                if (state == 'X') {
                    if (n == 2 || n == 3) copyGrid[j][k] = 'X';
                    else copyGrid[j][k] = '.';
                } else {
                    if (n == 3) copyGrid[j][k] = 'X';
                    else copyGrid[j][k] = '.';
                }
            }
        }

        for (j = 0; j < rowSize; j++) {
            for (k = 0; k < columnSize; k++) {
                oldGrid[j][k] = copyGrid[j][k];
            }
        }
    }

    printGrid(oldGrid, rowSize, columnSize);
    freeMemory(oldGrid, copyGrid, rowSize);
    return 0;
}

// Method to print the grid after 'n' generations
void printGrid(char **grid, int r, int c) {
    int i, j;
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%c", grid[i][j]);
        }
        if (i < r - 1)
            printf("\n");
    }
}

// Method to count the neighbours
int countNeighbours(char **grid, int r, int c, int i, int j) {
    int count = 0;
    if (i > 0) {
        if (j > 0 && grid[i - 1][j - 1] == 'X') count++;
        if (grid[i - 1][j] == 'X') count++;
        if (j + 1 < c && grid[i - 1][j + 1] == 'X') count++;
    }
    if (j > 0 && grid[i][j - 1] == 'X') count++;
    if (j + 1 < c && grid[i][j + 1] == 'X') count++;

    if (i + 1 < r) {
        if (j > 0 && grid[i + 1][j - 1] == 'X') count++;
        if (grid[i + 1][j] == 'X') count++;
        if (j + 1 < c && grid[i + 1][j + 1] == 'X')count++;
    }
    return count;
}

// Method to free memory
void freeMemory(char **grid, char **grid2, int r) {
    int i;
    for (i = 0; i < r; i++) {
        free(grid[i]);
        free(grid2[i]);
    }
    free(grid);
    free(grid2);
}


	
