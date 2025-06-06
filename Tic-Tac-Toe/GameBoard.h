#pragma once

class GameBoard
{
private:
	char _grid[3][3];
	int _filledCells = 0;
	const int BOARD_SIZE = 3;

public:
	// Constructor that initializes the board
	GameBoard();

	void drawBoard() const;
	bool isMoveValid(int row, int col) const;
	void makeMove(int row, int col, char symbol);
	bool checkWin(char symbol) const;
	bool isFull() const;
	int getFilledCellsCount() const;
};