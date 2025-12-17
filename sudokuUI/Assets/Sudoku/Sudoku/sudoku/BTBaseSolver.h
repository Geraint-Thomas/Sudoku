#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//Back Tracking Base Solver
class BTBaseSolver
{
public:
	BTBaseSolver(int grid[]);
	~BTBaseSolver();

	std::array<int, 81> solve();
	bool backTrackSolve();
	bool cellValid(int row, int col, int num);

	int grid[9][9];


private:

};