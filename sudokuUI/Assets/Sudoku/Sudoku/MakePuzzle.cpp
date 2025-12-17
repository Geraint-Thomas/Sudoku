#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <array>
#include "MakePuzzle.h"
#include "BaseSolver.h"
#include <cstdlib>
#include <ctime>
#include <chrono>


using namespace std;

MakePuzzle::MakePuzzle(int dif, int w, int h, int bh, int bw, int r)
{
	//classic = c;
	//size = s;
	difficulty = dif;
	height = h;
	width = w;
    blockHeight = bh;
    blockWidth = bw;
	range = r;
}

MakePuzzle::~MakePuzzle()
{

}

vector<int> MakePuzzle::createPuzzle()
{
    grid.resize(height);
    for (int i = 0; i < height; i++)
    {
        grid[i].resize(width);
    }

    for (int i = 0; i < height * width; i++)
    {
        int rowNum = floor(i / height);
        int colNum = i % width;
        
        
        grid[rowNum][colNum] = 0;
    }

    int seed = std::chrono::system_clock::now().time_since_epoch().count();

    srand(seed);

    fillGrid();

    removeCells();

    vector<int>* solvedGrid = new vector<int>;
    solvedGrid->resize(width * height);
    for (int i = 0; i < width * height; i++)
    {
        //row col
        int rowNum = floor(i / height);
        int colNum = i % width;

        //fill local 2d array with input values
        (*solvedGrid)[i] = grid[rowNum][colNum];
    }
    return *solvedGrid;
}

bool MakePuzzle::fillGrid()
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

    //gets a random number in the range and increments it untill it is valid
    int randomNumber = rand() % range;
    // Try digits from 1 to 9
    for (int num = randomNumber; num < range +randomNumber; num++) {
        int check = (num % range) + 1;
        // Check if it is safe to place the number
        if (cellValid(row, col, check)) {
            grid[row][col] = check;
            // Return true if solving the rest of the grid is successful
            if (fillGrid()) {
                return true;
            }
            // Failure, unmake and try again
            grid[row][col] = 0;
        }
    }

    return false; // Triggers backtracking
}

bool MakePuzzle::cellValid(int row, int col, int num)
{
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
    int rowOffset = row - (row % blockHeight);
    int colOffset = col - (col % blockWidth);
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

void MakePuzzle::removeCells()
{
    int temp[81];
    
    do {
        //set temp to grid before cells are removed
        for (int i = 0; i < 81; i++)
        {
            int rowNum = floor(i / height);
            int colNum = i % width;
            temp[i] = grid[rowNum][colNum];
        }

       
        //select random number of cells (based on difficulty)
        int random = (rand() % 8) + 3;
        for(int i=0; i<random *difficulty;i++)
        {
            //remove number from cell
            temp[(rand() % (height * width))] = 0;
        }

        //if cell is not solvable try again
    } while (!Solvable(temp));

    for (int i = 0; i < height * width; i++)
    {
        int rowNum = floor(i / height);
        int colNum = i % width;

        //set grid to new grid with removed cells
        grid[rowNum][colNum] = temp[i];
    }
}

bool MakePuzzle::Solvable(int input[])
{
    BaseSolver solver = BaseSolver(input);
    array<int,81> returnArray = solver.solve();

    if (returnArray[0] == 0)
    {
        return false;
    }
    else
        return true;
}