#include <stdio.h>
#include <stdlib.h>
#include "generalFunctions.h"

void swap(int* a, int* b)			// Swapping between two values
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int randomNum(int min, int max)					// Returning a number between the defined range
{
	return min+(rand()%(max-min+1));
}

void ShowMatrix(const int* mat, int rows, int cols)			// Printing the matrix
{
	for (int i=0; i < rows; i++)
	{
		for (int j=0; j < cols; j++)
		{
			printf("%5d", *(mat+(i*cols)+j));
		}
		printf("\n");
	}
	printf("\n");
}

