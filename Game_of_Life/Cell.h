#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace std;

class Cell{

	int x_;
	int y_;

	int size_;

	int state_;



public:

	sf::RectangleShape rectangle_;

	Cell(int x = 0, int y = 0, int size = 1, int state = 0);
	~Cell();
	
	void setPos(int x, int y, int size);
	int changeState();
	int getState() const;

};

