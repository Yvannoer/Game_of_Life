#include <iostream>
#include <vector>

#include "Cell.h"

using namespace std;


vector<vector<int>> convolution(vector<vector<Cell>> grid) {

	int n = (int) grid.size();

	vector<vector<int>> res = {{0}};

	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			for (int k = -1; k < 2; k++) {
				for (int h = -1; h < 2; h++) {
					if (h != k) {
						res[i][j] += grid[i][j].getState();
					}
				}
			}			
		}
		res.push_back({0});
	}
	return res;
}
