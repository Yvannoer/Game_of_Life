#include <iostream>
#include <SFML/Graphics.hpp>

#include "Cell.h"
#include "Conv.h"

using namespace std;

Cell::Cell(int x, int y, int size, int state) {
	
	x_ = x;
	y_ = y;

	size_ = size;

	state_ = state;

	rectangle_.setSize(sf::Vector2f((float) size_, (float) size_));
	rectangle_.setPosition((float) x_, (float) y_);

}

Cell::~Cell() {}


void Cell::setPos(int x, int y, int size) {
	x_ = x;
	y_ = y;

	size_ = size;

	rectangle_.setSize(sf::Vector2f((float)size_, (float)size_));
	rectangle_.setPosition((float)x_, (float)y_);
}



int Cell::changeState() {

	if (state_ == 0) {
		state_ = 1;
		return state_;
	}

	else {
		state_ = 0;
		return state_;
	}
}

int Cell::getState() const{

	if (state_ == 0) {
		cout << "dead" << endl;
		return 0;
	}

	else {
		cout << "alive" << endl;
		return 1;
	}
}

