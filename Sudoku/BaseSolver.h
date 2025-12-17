#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include "Cell.h"
#include <array>


using namespace std;


//Note quite a proper scene graph but this contains data structures for all of our bits and pieces we want to draw
class BaseSolver
{
public:
	BaseSolver(int grid[]);
	~BaseSolver();

	std::array<int,81> solve();
	void searchBlock(int index);
	void searchLines(int index);

	void blockElimination(int index);
	void lineElimination(int index);

	void checkPossible(int index);


	bool checkIfSolved();
	int gridHeight = 9;
	int gridWidth = 9;

	Cell* cells[81];

	int lastCount;
	int currentCount;
	int countCounter; //the name kinda fits LOL

protected:
	
	
};


