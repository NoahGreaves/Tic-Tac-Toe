#include <string>
#include "Player.h"

Player::Player(char sym, string n) : _symbol(sym), _name(n) {}

char Player::getSymbol() const{ return _symbol; }

string Player::getName() const { return _name; }
