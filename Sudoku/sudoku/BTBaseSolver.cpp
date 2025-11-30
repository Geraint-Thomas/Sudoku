#include <list>
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include "BTBaseSolver.h"

//Back Tracking Base Solver
BTBaseSolver::BTBaseSolver(int inputGrid[])
{
	for (int i = 0; i < 81; i++)
	{
		//row col
		int rowNum = floor(i / 9);
		int colNum = i % 9;
		//fill local 2d array with input values
		grid[rowNum][colNum] = inputGrid[i];
	}
}

BTBaseSolver::~BTBaseSolver()
{

}

std::array<int, 81> BTBaseSolver::solve()
{
    if (backTrackSolve())
    {
        std::array<int, 81> solvedGrid;
        for (int i = 0; i < 81; i++)
        {
            //row col
            int rowNum = floor(i / 9);
            int colNum = i % 9;
            //fill local 2d array with input values
            solvedGrid[i] = grid[rowNum][colNum];
        }
        return solvedGrid;
    }
    else
    {
        std::array<int, 81> unsolvedGrid;
        for (int i = 0; i < 81; i++)
        {
            unsolvedGrid[i] = 0;
        }
        return unsolvedGrid;
    }

	
}

bool BTBaseSolver::backTrackSolve()
{
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }

    // No unassigned position is found, puzzle solved
    if (isEmpty) {
        return true;
    }

    // Try digits from 1 to 9
    for (int num = 1; num <= 9; num++) {
        // Check if it is safe to place the number
        if (cellValid(row, col, num)) {
            grid[row][col] = num;
            // Return true if solving the rest of the grid is successful
            if (backTrackSolve()) {
                return true;
            }
            // Failure, unmake and try again
            grid[row][col] =0;
        }
    }

    return false; // Triggers backtracking
}

bool BTBaseSolver::cellValid(int row, int col, int num)
{
    for (int x = 0; x < 9; x++) {
        //if the number appers in the same
        //  row                     columb                  or 3x3 block
        if (grid[row][x] == num || grid[x][col] == num || grid[row - row % 3 + x / 3][col - col % 3 + x % 3] == num) {
            //the cell is not valid return false
            return false;
        }
    }
    return true;
}

