#pragma once

#include "constants.h"

bool isInBounds(int row, int column);


bool isMine(const char realBoard[][SIDE], int row, int column);

unsigned my_strlen(const char* text);


// A function to check whether the user has entered a correct command
bool isCorrectCommand(const char* command, const char* correctCommand);


// A function to check whether the user's move is valid
bool isValidMove(char* command, int row, int column);