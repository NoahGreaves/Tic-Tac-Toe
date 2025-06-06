#pragma once
#include <string>
using namespace std;

class Player {
private:
	char _symbol = 'a';
	string _name = "xxx";

public:
	Player(char sym = 'X', string n = "Player X");
	char getSymbol() const;
	string getName() const;
};