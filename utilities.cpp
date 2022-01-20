/**
*
* Solution to course project # 13
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Mihaylov
* @idnumber 3MI0600047
* @compiler VC
*
* <file with utility functions>
*
*/

#include "utilities.h"

bool isInBounds(int row, int column)
{
	return (row >= 0) && (column >= 0) && (row < SIDE) && (column < SIDE);
}

bool isMine(const char realBoard[][SIDE], int row, int column)
{
	return realBoard[row][column] == MINE_CHARACTER;
}

unsigned my_strlen(const char* text)
{
	unsigned length = 0;
	while (text[length] != 0)
	{
		length++;
	}
	return length;
}

// A function to check whether the user has entered a correct command
bool isCorrectCommand(const char* command, const char* correctCommand)
{
	unsigned i = 0;
	unsigned correctCommandLen = my_strlen(correctCommand);

	while (command[i] != '\0')
	{
		if (command[i] != correctCommand[i])
			return false;
		i++;
	}

	// true only if the strings have the same number of characters
	return correctCommandLen == i;
}

// A function to check whether the user's move is valid
bool isValidMove(char* command, int row, int column)
{
	return ((isCorrectCommand(command, "open") || isCorrectCommand(command, "mark")
		|| isCorrectCommand(command, "unmark")) && isInBounds(row, column));

}