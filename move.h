#pragma once
#include <iostream>
#include "constants.h"
#include "utilities.h"
#include "board.h"

// A function tho take the user's input
void makeMove(char* command, int& row, int& column);

// A function to delete the mine from (row, column) and place it in the first vacant cell on the board
void replaceMine(char realBoard[][SIDE], int row, int column);

// A function to count the number of mines in adjacent cells
int numberOfAdjacentMines(const char realBoard[][SIDE], int row, int column);

// A function to implement the user's input; returns true if it would lead to game over
bool implementMove(const char realBoard[][SIDE], char myBoard[][SIDE], int row, int column,
	const char* command, unsigned& movesLeft, unsigned& flagsLeft);