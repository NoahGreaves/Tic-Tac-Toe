#include <iostream>
#include "GameController.h"

using namespace std;

GameController::GameController() : _currentPlayerIndex(0)
{
	_players[0] = Player('X', "Player X");
	_players[1] = Player('O', "Player O");
}

Player& GameController::getCurrentPlayer()
{
	return _players[_currentPlayerIndex];
}

void GameController::switchTurn()
{
	_currentPlayerIndex = (_currentPlayerIndex + 1) % 2;
}

void GameController::play()
{
	int row, col;
	cout << "Welcome to Tick-Tac-Toe!" << endl;

	while (!_board.isFull()) {
		_board.drawBoard();
		Player& currentPlayer = getCurrentPlayer();

		while (true) 
		{
			cout << currentPlayer.getName() << " (" << currentPlayer.getSymbol() << "), enter row (1-3) and column (1-3), e.g 1 3: ";
			cin >> row >> col;

			// Input Validation
			if (std::cin.fail()) {
				std::cin.clear(); // Clear the error flag
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore the rest of the line
				std::cout << "Invalid input, please enter an integer." << std::endl;
			}

			if (_board.isMoveValid(row, col)) {
				break;
			}
			else {
				cout << "Invalid Move. Please Try Again." << endl;
			}
		}

		_board.makeMove(row, col, currentPlayer.getSymbol());

		if (_board.checkWin(currentPlayer.getSymbol()))
		{
			_board.drawBoard();
			cout << currentPlayer.getName() << " wins!" << endl;
			return;
		}

		switchTurn();

		_board.drawBoard();
		cout << "Its a draw!" << endl;
	}
}
