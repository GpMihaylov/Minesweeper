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
* <file with helper functions to play the game>
*
*/

#include "play.h"

void printMenu()
{
	std::cout << "Play by choosing (x, y) coordinates of the cell; \n";
	std::cout << "Then choose command: open, mark, unmark\n";
	std::cout << "Good luck!\n";
}


void playMinesweeper()
{
	bool gameOver = false;

	// A board which stores the locations of the mines
	// and a board on which the user plays
	char realBoard[SIDE][SIDE], myBoard[SIDE][SIDE];

	unsigned movesLeft = SIDE * SIDE - MINES, flagsLeft = MINES;

	int row, column;

	char command[MAX_CHARACTERS_IN_A_COMMAND + 1];

	generateBoard(realBoard, myBoard);

	placeMines(realBoard);

	printMenu();

	bool isFirstMove = true;
	while (!gameOver)
	{
		std::cout << std::endl;
		printBoard(myBoard);
		std::cout << std::endl;

		makeMove(command, row, column);

		// If the first opened cell contains a mine, replace the mine
		if (isFirstMove == true && isCorrectCommand(command, "open") && myBoard[row][column] != FLAG_CHARACTER)
		{
			if (isMine(realBoard, row, column))
				replaceMine(realBoard, row, column);
			isFirstMove = false;
		}

		// Game is over only if the user opens a mine
		gameOver = implementMove(realBoard, myBoard, row, column, command, movesLeft, flagsLeft);


		if (!gameOver && movesLeft == 0)
		{
			showMines(realBoard, myBoard);
			printBoard(myBoard);
			std::cout << "\nCongratulations! You win!\n";
			gameOver = true;
		}
	}
}
