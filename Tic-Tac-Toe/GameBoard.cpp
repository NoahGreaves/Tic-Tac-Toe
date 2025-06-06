#include <iostream>
#include <string>
#include "GameBoard.h"

using namespace std;

GameBoard::GameBoard()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_grid[i][j] = ' ';
		}
	}
}

void GameBoard::drawBoard() const
{
	system("cls"); // clear the screen

	cout << "-------------" << endl;
	for (int i = 0; i < BOARD_SIZE; i++) {
		cout << "| ";
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			cout << _grid[i][j] << " | ";
		}
		cout << endl << "-------------" << endl;
	}
}

bool GameBoard::isMoveValid(int row, int col) const
{
	return (row >= 0 && row < BOARD_SIZE && col >= 0 && col <= BOARD_SIZE && _grid[row][col] == ' ');
}

void GameBoard::makeMove(int row, int col, char symbol)
{
	if (isMoveValid(row, col))
	{
		_grid[row][col] = symbol;
		_filledCells++;
	}
}

bool GameBoard::checkWin(char symbol) const
{
	// check rows
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (_grid[i][0] == symbol && _grid[i][1] == symbol && _grid[i][2] == symbol)
			return true;
	}

	// check columns
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		if (_grid[0][i] == symbol && _grid[1][i] == symbol && _grid[2][i])
			return true;
	}

	// check diaganoals
	if (_grid[0][0] == symbol && _grid[1][1] == symbol && _grid[2][2] == symbol)
		return true;

	if (_grid[0][2] == symbol && _grid[1][1] == symbol && _grid[2][0] == symbol)
		return true;

	return false;
}

bool GameBoard::isFull() const
{
	return _filledCells == 9;
}

int GameBoard::getFilledCellsCount() const
{
	return _filledCells;
}
