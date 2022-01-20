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
* <file with helper functions for the board generation>
*
*/

#include "board.h"

void generateBoard(char realBoard[][SIDE], char myBoard[][SIDE])
{
	for (unsigned i = 0; i < SIDE; i++)
	{
		for (unsigned j = 0; j < SIDE; j++)
		{
			realBoard[i][j] = myBoard[i][j] = CELL_CHARACTER;
		}
	}
}

void placeMines(char realBoard[][SIDE])
{
	srand((unsigned int)time(NULL)); // seed random number for rand()

	bool isMine[SIDE * SIDE];

	unsigned mines[MINES][2]; // stores (x,y) coordinates of all mines

	for (unsigned i = 0; i < SIDE * SIDE; i++)
		isMine[i] = false;

	unsigned currentMineIndex = 0;
	while (currentMineIndex < MINES)
	{
		unsigned random = rand() % (SIDE * SIDE); // random number corresponding to the mine's position on the board
		int x = random / SIDE; // takes x coordinate of the mine
		int y = random % SIDE; // takes y coordinate of the mine

		if (isMine[random] == false)
		{
			mines[currentMineIndex][0] = x;
			mines[currentMineIndex][1] = y;

			realBoard[mines[currentMineIndex][0]][mines[currentMineIndex][1]] = MINE_CHARACTER;
			isMine[random] = true;
			currentMineIndex++;
		}
	}
}

void printBoard(char myBoard[][SIDE])
{
	std::cout << "  ";

	for (unsigned i = 0; i < SIDE; i++)
		std::cout << i << " ";
	std::cout << std::endl;

	for (unsigned i = 0; i < SIDE; i++)
	{
		std::cout << i << " ";
		for (unsigned j = 0; j < SIDE; j++)
		{
			std::cout << myBoard[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void showMines(const char realBoard[][SIDE], char myBoard[][SIDE])
{
	for (unsigned i = 0; i < MINES * MINES; i++)
	{
		for (unsigned j = 0; j < MINES * MINES; j++)
		{
			if (realBoard[i][j] == MINE_CHARACTER)
			{
				myBoard[i][j] = MINE_CHARACTER;
			}
		}
	}
}
