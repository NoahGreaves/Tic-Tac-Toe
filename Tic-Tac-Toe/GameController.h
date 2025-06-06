#pragma once
#include "GameBoard.h"
#include "Player.h"

class GameController {
private:
	GameBoard _board;
	Player _players[2];
	int _currentPlayerIndex;

public:
	GameController();

	Player& getCurrentPlayer();
	void switchTurn();
	void play();
};