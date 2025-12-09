#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include "BTSolver.h"



//Back Tracking Base Solver
BTSolver::BTSolver(int inputGrid[], int w, int h, int blockw, int blockh, int r)
{
    width = w;
    height = h;
    blockWidth = blockw;
    blockHeight = blockh;
    range = r;

    for (int i = 0; i < width*height; i++)
    {
        //row col
        int rowNum = floor(i / height);
        int colNum = i % width;
        //fill local 2d array with input values
        grid[rowNum][colNum] = inputGrid[i];
    }
}

BTSolver::~BTSolver()
{

}

std::vector<int> BTSolver::solve()
{
    if (backTrackSolve())
    {
        std::vector<int> solvedGrid;
        for (int i = 0; i < width*height; i++)
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
        std::vector<int> unsolvedGrid;
        for (int i = 0; i < width * height; i++)
        {
            unsolvedGrid[i] = 0;
        }
        return unsolvedGrid;
    }


}

bool BTSolver::backTrackSolve()
{
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < height; row++) {
        for (col = 0; col < width; col++) {
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
    for (int num = 1; num <= range; num++) {
        // Check if it is safe to place the number
        if (cellValid(row, col, num)) {
            grid[row][col] = num;
            // Return true if solving the rest of the grid is successful
            if (backTrackSolve()) {
                return true;
            }
            // Failure, unmake and try again
            grid[row][col] = 0;
        }
    }

    return false; // Triggers backtracking
}

bool BTSolver::cellValid(int row, int col, int num)
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

    //check row
    for (int i = 0; i < width; i++)
    {
        if (grid[row][i] == num)
        {
            return false;
        }
    }
    //check col
    for (int i = 0; i < height; i++)
    {
        if (grid[i][col] == num)
        {
            return false;
        }
    }

    //check box
    int rowOffset = row - (row % height);
    int colOffset = col - (col % width);
    for (int i = 0; i < blockWidth; i++)
    {
        for (int j = 0; j < blockHeight; j++)
        {
            if (grid[rowOffset + i][colOffset + j] == num)
            {
                return false;
            }
        }
    }

    //if reached this point the number is valid (for now)
    return true;
}

