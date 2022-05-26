#include <iostream>
#include <vector>
#include "Game.h"

using namespace std;



/*void Game::rules(int i, int j) {

	int a = current_[i - 1][j - 1].getState();
	int b = current_[i][j - 1].getState();
	int c = current_[i + 1][j - 1].getState();
	int d = current_[i - 1][j].getState();
	int f = current_[i + 1][j].getState();
	int g = current_[i - 1][j + 1].getState();
	int h = current_[i][j + 1].getState();
	int ii = current_[i + 1][j + 1].getState();

	int sum = a + b + c + d + f + g + h + ii;

	if (sum < 2) {
		if (current_[i][j].getState() == 1) {
			next_[i][j].changeState();
		}
	}
	else if (sum < 3);
	else if (sum < 4) {
		if (current_[i][j].getState() == 0) {
			next_[i][j].changeState();
		}
	}
	else {
		if (current_[i][j].getState() == 1) {
			next_[i][j].changeState();
		}
	}
}


void Game::setInit(vector<vector<Cell>> init) {
	init_ = init;
}

void Game::setNext() {
	for (int i = 1; i < current_.size() - 1; i++) {
		for (int j = 1; j < current_.size() - 1; j++) {
			next_[i][j].rules();
		}
	}
}


void Game::setCurrent() {

}



void Game::setPast() {
	
}




void Game::game(vector<vector<Cell>> init) {
	

	if (turn_ == 0) {
		setInit(init);
		past_ = init_;
		current_ = init_;
		setNext();
	}
	else {

	}

	turn_++;


}*/