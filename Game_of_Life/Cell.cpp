#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.h"

using namespace std;

Cell::Cell(int x, int y, int size) {
	
	x_ = x;
	y_ = y;

	size_ = size;

	rectangle_.setSize(sf::Vector2f((float) size_, (float) size_));
	rectangle_.setPosition((float) x_, (float) y_);

}

void Cell::setPos(int x, int y, int size) {
	x_ = x;
	y_ = y;

	size_ = size;

	rectangle_.setSize(sf::Vector2f((float)size_, (float)size_));
	rectangle_.setPosition((float)x_, (float)y_);
}

Cell::~Cell() {}

void Cell::changeState() {

	if (state_ == 0) {
		state_ = 1;
	}

	else {
		state_ = 0;
	}
}

void Cell::getState() const{

	if (state_ == 0) {
		cout << "dead" << endl;
	}

	else {
		cout << "alive" << endl;
	}
}