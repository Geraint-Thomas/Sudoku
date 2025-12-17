#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;
//Back Tracking Base Solver
class MakePuzzle
{
public:
	MakePuzzle( int difficulty,  int width, int height, int blockHeight, int blockWidth, int range);
	~MakePuzzle();

	//bool classic;
	//bool size;
	//bool other;
	int difficulty;
	int height;
	int width;
	int blockHeight;
	int blockWidth;
	int range;

	vector<int> createPuzzle();
	bool fillGrid();
	bool cellValid(int row, int col, int num);
	void removeCells();
	bool Solvable(int input[]);

	vector<vector<int>> grid;


private:

};
