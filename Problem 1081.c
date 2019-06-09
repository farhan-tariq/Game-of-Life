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


void initialize_board(char ** grid,int r,int c);
void printGrid(char ** grid,int r,int c);
int countNeighbours(char ** grid,int r,int c ,int i,int j);
void freeMemory(char ** grid,char **grid2,int r);

int main(){
	int rowSize;				//no of rows
	int columnSize;				//no of columns
	int generations;			//no of generations
	int i=0;
	int	j=0;
	int k=0;
	int n;						//neighbour count
	char state;
	char **oldGrid;				//original grid for comparison
	char **copyGrid;			//grid to make changes to


	scanf("%d %d %d",&rowSize,&columnSize,&generations);				//take input

	oldGrid = (char**)malloc(rowSize * sizeof(char*));					//allocation of memory 
	copyGrid =(char**) malloc(rowSize * sizeof(char*));					//allocation of memory

	for(i=0; i<rowSize; i++){											//for the no of rows
		oldGrid[i] = malloc(columnSize * sizeof (char));				//allocation of memory 
		copyGrid[i] = malloc(columnSize * sizeof (char));				//allocation of memory 
		for(j=0; j<columnSize; j++){
			scanf (" %c", &oldGrid[i][j]);								//getting user input for each cell
		}
	}

	for(i=0;i<=generations;i++ ){									//for the no of generations
		for (j=0; j<rowSize; j++) {									//for the no of rows
			for (k=0; k<columnSize; k++) {							//for the no of columns
				state=oldGrid[j][k];								//state of the cell
				n=countNeighbours(oldGrid,rowSize,columnSize,j,k);	//count the no of neighbours

				if(state == 'X'){							//if the cell is alive
					if(n==2 || n==3) copyGrid[j][k] = 'X'; 	//if the cell has 2 or 3 neighbours then it lives
					else copyGrid[j][k]='.';				//else the cell dies

				}else{										//else (if) the cell is dead 
					if(n==3) copyGrid[j][k]='X';			//but has 3 neibours then the cell become alive
					else copyGrid[j][k]='.';				//else it dies
				}
			}
		}
	for (j=0; j<rowSize; j++) {									//for the no of rows
		for (k=0; k<columnSize; k++) {							//for the no of columns
			oldGrid[j][k] = copyGrid[j][k];						//copy the grid to which changes are made to the old one
		}
	}
}
	printGrid(oldGrid,rowSize,columnSize);						//print the grid
	freeMemory(oldGrid,copyGrid,rowSize);						//free the memory
	return 0;
}

void printGrid(char **grid,int r,int c){					//method to print the board
	int i,j;
	for (i=0; i<r; i++) {
		for (j=0; j<c; j++) {
			printf("%c",grid[i][j]);}
		if(i<r-1)
			printf("\n");}
}

	int countNeighbours(char **grid,int r,int c ,int i,int j){		//method to count the neighbours
		int count = 0; 
		if(i>0){ 
			if(j>0 && grid[i-1][j-1]=='X') 	 count++; 
			if(grid[i-1][j]=='X')			 count++; 
			if(j+1<c && grid[i-1][j+1]=='X') count++; 
		}
		if(j>0 && grid[i][j-1]=='X') 		count++; 
		if(j+1<c && grid[i][j+1]=='X') 		count++; 

		if(i+1<r){ 
			if(j>0 && grid[i+1][j-1]=='X') 	count++; 
			if(grid[i+1][j]=='X') 			count++; 
			if(j+1<c && grid[i+1][j+1]=='X')count++; 
		}
		return count;
	}

	void freeMemory(char **grid,char **grid2,int r)					//method to free memory
	{
		int i;
		for( i = 0; i < r; i++)
		{
			free(grid[i]);
			free(grid2[i]);
		}
		free(grid);
		free(grid2);
	}


	
