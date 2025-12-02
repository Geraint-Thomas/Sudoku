#include "BaseSolver.h"
#include "Cell.h"
#include <cmath>
#include <array>
#include <iostream>

BaseSolver::BaseSolver(int grid[])
{
	for (int i = 0; i < 81; i++)
	{
		cells[i] = new Cell();
		cells[i]->number = grid[i];
		printf(" cells = %d \n", cells[i]->number);
	}
}

BaseSolver::~BaseSolver()
{

}

std::array<int,81> BaseSolver::solve()
{
	while (!checkIfSolved())
	{
		for (int i = 0; i < 81; i++)
		{
			if (cells[i]->number == 0)
			{
				searchBlock(i);
				if (cells[i]->number != 0)
				{
					printf("");
				}
				searchLines(i);
				if (cells[i]->number != 0)
				{
					printf("");
				}
				checkPossible(i);
				if (cells[i]->number != 0)
				{
					printf("");
				}
				//blockPossible and horizontalPossible stack around variable was corrupted
				blockElimination(i);
				if (cells[i]->number != 0)
				{
					printf("");
				}
				lineElimination(i);
				if (cells[i]->number != 0)
				{
					printf("");
				}
				//this ends up in an infinate loop of unsolvable grid with 72 cells solved
				//this must mean that some are being placed in the wrong cells or that the puzzle is too complex for the current checks

			}
			
			
		}
		
	}

	//output stuff
	std::array<int,81> solvedGrid;
	printf("SOLVED \n");
	for (int i = 0; i < 81; i++)
	{
		solvedGrid[i] = cells[i]->number;
		printf(" cells = %d \n", cells[i]->number);
	}
	return solvedGrid;
}

bool BaseSolver::checkIfSolved()
{
	int size = gridHeight * gridWidth;
	int count = 0;
	//loop through grid 
	for (int i = 0; i < size; i++)
	{
		//if cell is not blank increment count
		if (cells[i]->number != 0)
		{
			count++;
		}
	}

	//if all cells are filled the grid is solved
	if (count == size) 	{
		//cout << count;
		return true;
	}
	//if any are blank the grid is not solved
	else
	{
		//cout << count;
		return false;
	}
}

void BaseSolver::searchBlock(int index)
{
	int offset = 0;
	cells[index]->possible[0];
	
	//offset based on how many rows have been passed
	offset = floor(index / gridWidth);
	//offset by max of 3 rows for the block
	offset = offset % 3;
	//offset by grid width
	offset = offset * gridWidth;
	//add offset of columb
	offset += index % 3;

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (cells[(i * gridWidth) + j - offset + index]->number != 0)
			{
				
				cells[index]->notPossible(cells[(i * gridWidth) + j - offset + index]->number);
			}
		}
	}
	cells[index]->possible[0];
}

void BaseSolver::searchLines(int index)
{
	int x = index % 9;
	int y = floor(index / 9);
	cells[index]->possible[0];
	//horizontal check
	for (int i = 0; i < 9; i++)
	{
		if (x != i)
		{
			if (cells[i + (y * gridWidth)]->number != 0)
			{
				
				cells[index]->notPossible(cells[i + (y * gridWidth)]->number);
			}
		}
	}

	//vertical check
	for (int i = 0; i < 9; i++)
	{
		if (y != i)
		{
			if (cells[x + (i * gridWidth)]->number != 0)
			{
				
				cells[index]->notPossible(cells[x + (i * gridWidth)]->number);
			}
		}
	}
	cells[index]->possible[0];
}

void BaseSolver::blockElimination(int index)
{
	//check if current cell is only cell in block that could be a specific number
	int blockPossible[9] = { 0,0,0,0,0,0,0,0,0 };

	int offset = 0;
	

	//offset based on how many rows have been passed
	offset = floor(index / gridWidth);
	//offset by max of 3 rows for the block
	offset = offset % 3;
	//offset by grid width
	offset = offset * gridWidth;
	//add offset of columb
	offset += index % 3;

	//loop thorugh block
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			//if cell is blank
			if (cells[(i * gridWidth) + j - offset + index]->number == 0)
			{
				for (int x = 0; x < 9; x++)
				{
					//add possible numbers to array
					if (cells[(i * gridWidth) + j - offset + index]->possible[x] !=0)
					{
						blockPossible[x]++;
					}
				}
				
			}
		}
	}

	//for all possible numbers in current cell
	for (int i = 0; i < 9; i++)
	{
		if (cells[index]->possible[i] != 0)
		{
			//if the block only has a number that can only go in the current cell
			if (blockPossible[i] == 1)
			{
				//fill that cell with the only possible number
				cells[index]->number = cells[index]->possible[i];
				return;
			}
		}
	}
}

void BaseSolver::lineElimination(int index)
{
	//check if current cell is only cell in block that could be a specific number
	int horizontalPossible[9] = { 0,0,0,0,0,0,0,0,0 };
	int verticalPossible[9] = { 0,0,0,0,0,0,0,0,0 };

	int x = index % 9;
	int y = floor(index / 9);

	//horizontal check
	for (int i = 0; i < 9; i++)
	{
		/*
		if (x != i)
		{
			if (cells[i + (y * gridWidth)]->number == 0)
			{
				for (int x =0;x<9;x++)//: cells[i + (y * gridWidth)]->possible)
				{
					if (cells[i + (y * gridWidth)]->possible[x] != 0)
					{
						horizontalPossible[x]++;
					}
				}
			}
		}*/

		if (cells[i + (y * gridWidth)]->number == 0)
		{
			for (int x = 0; x < 9; x++)//: cells[i + (y * gridWidth)]->possible)
			{
				if (cells[i + (y * gridWidth)]->possible[x] != 0)
				{
					horizontalPossible[x]++;
				}
			}
		}
	}

	x = index % 9;
	y = floor(index / 9);

	//vertical check
	for (int i = 0; i < 9; i++)
	{
		/*
		if (y != i)
		{
			if (cells[x + (i * gridWidth)]->number == 0)
			{
				for (int y =0;y<9;y++)//: cells[x + (i * gridWidth)]->possible)
				{
					if (cells[x + (i * gridWidth)]->possible[y] != 0)
					{
						verticalPossible[x]++;
					}
				}
			}
		}*/

		if (cells[x + (i * gridWidth)]->number == 0)
		{
			for (int y = 0; y < 9; y++)//: cells[x + (i * gridWidth)]->possible)
			{
				if (cells[x + (i * gridWidth)]->possible[y] != 0)
				{
					verticalPossible[x]++;
				}
			}
		}

	}

	//for all possible numbers in current cell
	for (int i = 0; i < 9; i++)
	{
		if (cells[index]->possible[i] != 0)
		{
			//if the block only has a number that can only go in the current cell
			if (horizontalPossible[i] == 1)
			{
				//fill that cell with the only possible number
				cells[index]->number = cells[index]->possible[i];
				return;
			}
			else if (verticalPossible[i] == 1)
			{
				cells[index]->number = cells[index]->possible[i];
				return;
			}
		}
	}
}


void BaseSolver::checkPossible(int index)
{
	int numCheck = 0;
	int numOfZeros = 0;
	for (int i = 0; i < 9; i++)
	{
		if (cells[index]->possible[i] != 0)
		{
			numCheck = cells[index]->possible[i];
		}
		else
		{
			numOfZeros++;
		}
	}
	if (numOfZeros == 8)
	{
		cells[index]->number = numCheck;
	}
}