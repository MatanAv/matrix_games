#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "numGame.h"
#include "generalFunctions.h"

// --- FUNCTIONS --- //

void GetRowsAndColsFromUser(int* rows, int* cols)
{

	do
	{
	printf("Please enter the number of rows: ");
		scanf("%d", rows);
		if (*rows < 1)
			printf("Wrong input!\n"); 		
	} while(*rows < 1);

	do
	{	
	printf("Please enter the number of columns: ");
		scanf("%d", cols);
		if (*cols < 1)
			printf("Wrong input!\n"); 
	} while(*cols < 1);
	
	printf("\n");

}

int* CreateBoard(int* mat, int rows, int cols)
{

	int size = rows*cols;
	int* zeroP = mat+size-1;						// Pointer of last cell
	*zeroP = 0;								// Last cell is now "0"

	for (int i=0; i < size-1; i++)					// Filling the board in ascending order
		*(mat+i) = i+1;

	for (int i=0; i < SHUFFLE_COUNT; i++)					// Shuffeling the board "SHUFFLE_COUNT" times
		zeroP = ShuffleBoard(mat, rows, cols, zeroP);

	return zeroP;

}

int* ShuffleBoard(int* mat, int rows, int cols, int* zeroP)			// Moving the 0 cell and returning the new address of the 0 cell
{
	
	int size = rows*cols;
	int direction = randomNum(1,4);

	if (direction == 1 && zeroP != mat && !((zeroP-mat) % cols == 0))			// Moving 0 to left
												// *** zeroP-mat = index of zeroP ***
	{
		swap(zeroP,zeroP-1);
		return zeroP-1;
	}
	else if (direction == 2 && zeroP != (mat+size-1) && !(((zeroP+1)-mat) % cols == 0))		// Moving 0 to right
	{
		swap(zeroP,zeroP+1);
		return zeroP+1;
	}
	else if (direction == 3 && mat <= (zeroP-cols))			// Moving 0 to up
	{
		swap(zeroP,zeroP-cols);
		return zeroP-cols;
	}
	else if (direction == 4 && mat+(size-1) >= (zeroP+cols))		// Moving 0 to down
	{
		swap(zeroP,zeroP+cols);
		return zeroP+cols;
	}
	else	
		return zeroP;
}

int CheckAscendingOrder(const int* mat, int size)
{

	for (int i=1; i <= size-1; i++, mat++)
		if (*mat != i)
			return 0;
	return 1;

}

int* MakeStep(int* mat, int rows, int cols, int* zeroP, int* checkStep)
{

	int choice;
	int size = rows*cols;
	
	printf("Your step: ");
	scanf("%d", &choice);
	
	if (choice > 0 && choice < size)							// Now we'll check if the step is valid and then execute him
	{
		
		if (zeroP != mat && choice == *(zeroP-1) && !((zeroP-mat) % cols == 0))	// Moving 0 to left
												// *** zeroP-mat = index of zeroP ***
		{
			swap(zeroP,zeroP-1);
			*checkStep = 1;							// Updating zero pointer			
			return zeroP-1;
		}
		else if (zeroP != (mat+size-1) && choice == *(zeroP+1) && !(((zeroP+1)-mat) % cols == 0))		// Moving 0 to right
		{
			swap(zeroP,zeroP+1);
			*checkStep = 1;
			return zeroP+1;
		}
		else if (mat <= (zeroP-cols) && choice == *(zeroP-cols))			// Moving 0 to up
		{
			swap(zeroP,zeroP-cols);
			*checkStep = 1;
			return zeroP-cols;
		}
		else if (mat+(size-1) >= (zeroP+cols) && choice == *(zeroP+cols))		// Moving 0 to down
		{
			swap(zeroP,zeroP+cols);
			*checkStep = 1;
			return zeroP+cols;
		}
		else
		{
			*checkStep = 0;
			return zeroP;
		}
		
	}
	else
	{
		*checkStep = 0;
		return zeroP;
	}	
	
}

// --- THE GAME --- //

void NumberGame()
{
	
	int rows, cols;					// Getting measurements from the user
	GetRowsAndColsFromUser(&rows, &cols);
	int board[rows][cols];
	int checkStep = 0;
	
	int* zeroP = CreateBoard((int*)board, rows, cols);		// Creating the board to be ready for the game and return an updated zero pointer
	ShowMatrix((int*)board, rows, cols);
	
	do
	{
		do
		{
			zeroP = MakeStep((int*)board, rows, cols, zeroP, &checkStep);	// A valid step returns the updated 0 cell
												// invalid returns the old cell
			if (!checkStep)
				printf("Invalid step!\n");
				
		} while(!checkStep);
		
		ShowMatrix((int*)board, rows, cols);
	
	} while(!CheckAscendingOrder((int*)board,rows*cols));
	
	printf("You've won! The game is over!\n\n");
	
}
