#pragma once
#include <SFML/Graphics.hpp>

using namespace std;

class Cell
{

	int x_;
	int y_;

	int size_;

	int state_ = 0;



public:

	sf::RectangleShape rectangle_;

	Cell(int x = 1, int y = 1, int size = 1);
	void setPos(int x, int y, int size);
	~Cell();

	void changeState();
	void getState() const;

};

