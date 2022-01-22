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
* <file with functions to implement the user's move>
*
*/

#include "move.h"

// A function tho take the user's input
void makeMove(char* command, int& row, int& column)
{
	while (1)
	{
		std::cin >> row >> column;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1024, '\n');
			std::cout << "Invalid entry! Try again!\n\n";
			continue;
		}

		std::cin.ignore();

		std::cin.getline(command, MAX_CHARACTERS_IN_A_COMMAND + 2);


		if (isValidMove(command, row, column))
		{
			break;
		}

		std::cout << "Invalid entry! Try again!\n\n";
	}
}

// A function to delete the mine from (row, column) and place it in the first vacant cell on the board
void replaceMine(char realBoard[][SIDE], int row, int column)
{
	for (unsigned i = 0; i < SIDE; i++)
	{
		for (unsigned j = 0; j < SIDE; j++)
		{
			if (realBoard[i][j] != MINE_CHARACTER)
			{
				realBoard[i][j] = MINE_CHARACTER;
				realBoard[row][column] = CELL_CHARACTER;

				return;
			}
		}
	}
}

// A function to count the number of mines in adjacent cells
int numberOfAdjacentMines(const char realBoard[][SIDE], int row, int column)
{
	/*
		The adjacent cells are:


		N.W  N  N.E
		  \  |  /
		W - Cell - E
		  /  |  \
		S.W  S  S.E

		Cell	-> (row, column)
		North	-> (row-1, column)
		South	-> (row+1, column)
		East	-> (row, column+1)
		West	-> (row, column-1)
		North-East ->  (row-1, column+1)
		North-West ->  (row-1, column-1)
		South-East ->  (row+1, column+1)
		South-West ->  (row+1, column-1)
	*/

	unsigned count = 0;

	for (int i = row - 1; i <= row + 1; i++)
	{
		for (int j = column - 1; j <= column + 1; j++)
		{
			if (isInBounds(i, j))
			{
				if (isMine(realBoard, i, j))
					count++;
			}
		}
	}

	return count;
}

// A function to implement the user's input; returns true if it would lead to game over
bool implementMove(const char realBoard[][SIDE], char myBoard[][SIDE], int row, int column,
	const char* command, unsigned& movesLeft, unsigned& flagsLeft)
{
	if (isCorrectCommand(command, "open"))
	{
		// The cell is unmarked and unopened
		if (myBoard[row][column] == CELL_CHARACTER)
		{
			// The cell has a mine on it
			if (realBoard[row][column] == MINE_CHARACTER)
			{
				showMines(realBoard, myBoard);

				printBoard(myBoard);
				std::cout << "\nYou lost!\n";

				return true;
			}

			else
			{
				int count = numberOfAdjacentMines(realBoard, row, column);
				movesLeft--;

				myBoard[row][column] = count + '0';

				if (count == 0)
				{
					// There are no adjacent mines
					// Open all adjacent cells (if they are valid cells, are unmarked and are unopened)

					for (int i = row - 1; i <= row + 1; i++)
					{
						for (int j = column - 1; j <= column + 1; j++)
						{
							if (isInBounds(i, j) && myBoard[i][j] == CELL_CHARACTER)
							{
								myBoard[i][j] = numberOfAdjacentMines(realBoard, i, j) + '0';
								movesLeft--;
							}
						}
					}
				}

				return false;
			}
		}
		// The cell is marked
		else if (myBoard[row][column] == FLAG_CHARACTER)
		{
			std::cout << "You can't open a marked cell!\n";
			return false;
		}

		// The cell is already opened
		else
		{
			std::cout << "This cell is already opened!\n";
			return false;
		}
	}

	else if (isCorrectCommand(command, "mark"))
	{
		if (flagsLeft == 0)
		{
			std::cout << "You have no flags left!\n";
			return false;
		}

		else if (myBoard[row][column] == FLAG_CHARACTER)
		{
			std::cout << "This cell is already marked!\n";
			return false;
		}

		else if (myBoard[row][column] == CELL_CHARACTER)
		{
			myBoard[row][column] = FLAG_CHARACTER;
			flagsLeft--;
			std::cout << "Flags left: " << flagsLeft << std::endl;
			return false;
		}

		// The cell has been opened
		else
		{
			std::cout << "You can't mark this cell!\n";
			return false;
		}
	}

	else if (isCorrectCommand(command, "unmark"))
	{
		if (myBoard[row][column] != FLAG_CHARACTER)
		{
			std::cout << "This cell is not marked!\n";
			return false;
		}
		else
		{
			myBoard[row][column] = CELL_CHARACTER;
			flagsLeft++;
			std::cout << "Flags left: " << flagsLeft << std::endl;
			return false;
		}
	}
	return false;
}
