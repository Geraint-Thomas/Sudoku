#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;
//Back Tracking Base Solver
class BTSolver
{
public:
	BTSolver(int grid[], int width, int height, int blockW, int blockH, int range);
	~BTSolver();

	std::vector<int> solve();
	bool backTrackSolve();
	bool cellValid(int row, int col, int num);
	
	bool check(int row, int col, int num);
	
	std::vector<vector<int>> grid;
	int width;
	int height;
	int blockHeight;
	int blockWidth;
	int range;



private:

}; 
