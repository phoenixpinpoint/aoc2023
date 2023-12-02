#include <stdio.h>
#include <string.h>

/*
 *	ASCII Numbers are between 48 and 58
 *	ASCII LF 10
 */

char wordToNumberAsString(char* word)
{
	if (strcmp(word, "one") == 0)
	{
		return '1';
	}
	else if (strcmp(word, "two") == 0)
	{
		return '2';
	}
	else if (strcmp(word, "three") == 0)
	{
		return '3';
	}
	else if (strcmp(word, "four") == 0)
	{
		return '4';
	}
	else if (strcmp(word, "five") == 0)
	{
		return '5';
	}
	else if (strcmp(word, "six") == 0)
	{
		return '6';
	}
	else if (strcmp(word, "seven") == 0)
	{
		return '7';
	}
	else if (strcmp(word, "eight") == 0)
	{
		return '8';
	}
	else if (strcmp(word, "nine") == 0)
	{
		return '9';
	}
	else if (strcmp(word, "zero") == 0)
	{
		return '0';
	}
	else {
		return 'e';
	}
}

int isValidStartChar(int ch)
{
	switch(ch){
		case 101:
			return 1;
		case 110:
			return 1;
		case 111:
			return 1;
		case 114:
			return 1;
		case 115:
			return 1;
		case 116:
			return 1;
		default:
			return 0;
	}
	return 0;
}

void partOne()
{
	// Open the file
	FILE *inputFilePtr;
	inputFilePtr = fopen("trebuchet.txt", "r");
	
	//Create a int to store the ASCII Value
	int character = getc(inputFilePtr);
	
	//Create Our String
	char numberAsString[3];

	//Add A Null Term for ATOI
	numberAsString[2] = '\0';

	int hiddenNumber;
	int index = 0;
	int total = 0;

	//While the char that is being read is not EOF
	while(character != EOF) {
		//If the character is 0-9
		if(character >= 48 && character <= 58)
		{
			if (index == 0)
			{
				numberAsString[0] = character;
				numberAsString[1] = character;
			}
			else {
				numberAsString[1] = character;
			}
			index++;	
		}

		//If the character is LF
		if(character == 10)
		{
			index = 0;
			hiddenNumber = atoi(numberAsString);
			numberAsString[0] = '\0';
			numberAsString[1] = '\0';
			total = total + hiddenNumber;
		}

		//Get the next char
		character = getc(inputFilePtr);
	}
	
	printf("Total: %d\n", total);
	
	fclose(inputFilePtr);
	
}

void partTwo()
{
	FILE *file;
	file = fopen("trebuchet2.txt", "r");

	int character = getc(file);

	char numberAsString[3];
	numberAsString[2] = '\0';

	int hiddenNumber = 0;
	int index = 0;
	int total = 0;

	int processingWordFlag = 0;
	int charsRead = 1;
	
	char word = ["\0", "\0", "\0", "\0", "\0"];

	while(character != EOF)
	{
		//If it is a number
		if(character >= 48 && character <= 58)
		{
			if (index == 0)
			{
				numberAsString[0] = character;
				numberAsString[1] = character;
				index++;
			}
			else {
				numberAsString[1] = character;
			}
		}
		//If it is a lowercase letter
		else if (character >= 97 && character <= 122){
			if (processingWordFlag == 0)
			{
				if(isValidStartChar(character))
				{
					processingWordFlag = 1;
					printf("Valid Start Char Fond. Begin Processing\n");
				}
			}
		}
		//If it is a LF
		else if (character == 10)
		{
			
		}
		
		printf("%c", character);
		character = getc(file);
	}
}

int main()
{
	printf("Part One: \n");
	partOne();
	printf("Part Two: \n");
	partTwo();
	return 0;

}
