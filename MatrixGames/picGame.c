#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include "picGame.h"
#include "generalFunctions.h"

// --- FUNCTIONS --- //


int GetSizeFromUser()
{
	int size;
	do
	{	
	printf("Please enter the size of rows/columns in the square matrix: ");
		scanf("%d", &size);
		if (size < 1)
			printf("Wrong input!\n"); 		
	} while(size < 1);
	
	printf("\n");
	return size;
}

void UserOptions(int* choice)
{

	printf("Please choose one of this following options:\n");
	printf("1 - 90 degree clockwise\n");
	printf("2 - 90 degree counter clockwise\n");
	printf("3 - Flip Horizontal\n");
	printf("4 - Flip Vertical\n");
	printf("-1 - Quit\n\n");
	
	scanf("%d", choice);
	printf("\n");

}

void BuildMatrix(int* mat, int size)
{
	for (int i=0; i < size; i++, mat++)
		*mat = randomNum(1,99);
}	

void RotateCW(int* mat, int rows, int cols)
{

	int* t1, *t2, *t3, *t4;

	for (int i=0; i < rows/2; i++)
	{
		for (int j=i; j < cols-i-1; j++)
		{
			t1 = mat+(i*cols)+j;				// Top-Left edge
			t2 = mat+(j*cols)+rows-i-1;			// Top-Right edge
			t3 = mat+((rows-1-j)*cols)+i;			// Bottom-Left edge
			t4 = mat+((rows-1-i)*cols)+rows-j-1;		// Bottom-Right edge
			swap(t1,t3);
			swap(t3,t4);
			swap(t4,t2);
		}
	}

}

void RotateCCW(int* mat, int rows, int cols)
{

	int* t1, *t2, *t3, *t4;

	for (int i=0; i < rows/2; i++)
	{
		for (int j=i; j < cols-i-1; j++)
		{
			t1 = mat+(i*cols)+j;				// Top-Left edge
			t2 = mat+(j*cols)+rows-i-1;			// Top-Right edge
			t3 = mat+((rows-1-j)*cols)+i;			// Bottom-Left edge
			t4 = mat+((rows-1-i)*cols)+rows-j-1;		// Bottom-Right edge
			swap(t1,t2);
			swap(t2,t4);
			swap(t3,t4);
		}
	}

}

void FlipHorizontal(int* mat, int rows, int cols)
{

	for (int i=0; i < rows; i++)
		for (int j=0; j < cols/2; j++)
			swap(mat+(i*cols)+j, mat+(i*cols)+cols-1-j);

}

void FlipVertical(int* mat, int rows, int cols)
{

	for (int i=0; i < rows/2; i++)
		for (int j=0; j < cols; j++)
			swap(mat+(i*cols)+j, mat+((rows-1-i)*cols)+j);

}


// --- THE GAME --- //


void PictureGame()
{

	int size = GetSizeFromUser();
	int matrix[size][size];
	int choice;
	
	BuildMatrix((int*)matrix, size*size);
	ShowMatrix((int*)matrix, size, size);
		
	do
	{							// Switch-case menu
		UserOptions(&choice);				// getting choice from user
		switch(choice)
		{
			case 1:
				RotateCW((int*)matrix, size, size);
				ShowMatrix((int*)matrix, size, size);
				break;
			case 2:
				RotateCCW((int*)matrix, size, size);
				ShowMatrix((int*)matrix, size, size);
				break;
			case 3:
				FlipHorizontal((int*)matrix, size, size);
				ShowMatrix((int*)matrix, size, size);
				break;	
			case 4:
				FlipVertical((int*)matrix, size, size);
				ShowMatrix((int*)matrix, size, size);
				break;
			case -1:
				break;
			default:
				printf("Wrong input!\n\n");
		}
	} while (choice != -1);	
	
	printf("\n");
	
}

