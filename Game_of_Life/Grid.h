#pragma once
#include <iostream>
#include "Cell.h"



using namespace std;


class Grid {
	int size_;
	int nbCells_;

	//vector<vector<Cell>> cell_;

public:

	Grid();
	//Grid(vector<vector<Cell>> cell);
	~Grid();



	const int setGridSize();
	const int cellNumber();

	void setGrid();
	//Cell getID(int i, int j);

	int size();

};



