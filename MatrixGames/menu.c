#include <stdio.h>
#include <ctype.h>
#include "menu.h"
#include "numGame.h"
#include "picGame.h"

void ShowOptions(char* choice)		// printing the options and getting choice from the user
{
	printf("Please choose one of this following options:\n");
	printf("P/p - Picture Manipulation\n");
	printf("N/n - Number Game\n");
	printf("E/e - Quit\n\n");
	printf("Enter your choice: ");
	
	do
	{
		scanf("%c", choice);
	} while(isspace(*choice));
	
	*choice = (char)toupper((int)*choice);		// this function requires casting char into int
	printf("\n");
}

void ExecuteMenu()		// Main Menu
{

	char choice;

	printf("Hello! Welcome to the menu.\n\n");			
	do
	{
		ShowOptions(&choice);
		switch(choice)
		{
			case 'P':
				PictureGame();
				break;
			case 'N':
				NumberGame();
				break;
			case 'E':
				printf("Bye Bye!\n\n");
				break;
			default:
				printf("Wrong input!\n\n");
		}
	} while (choice != 'E');
	
}
