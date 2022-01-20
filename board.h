#pragma once

#include <iostream>
#include "constants.h"


void generateBoard(char realBoard[][SIDE], char myBoard[][SIDE]);

void placeMines(char realBoard[][SIDE]);

void printBoard(char myBoard[][SIDE]);

// A function that places the mines on the playing board in case of game over
void showMines(const char realBoard[][SIDE], char myBoard[][SIDE]);


