//stuff
#include <iostream>
#include "BaseSolver.h"
#include "BTBaseSolver.h"
#include "Cell.h"
#include <array>
#include <vector>

using namespace std;

//global variables
ifstream inputFile;

//function prototypes
void loadFile();



int main()
{
	//g_Scene = new Scene();
	
	//add different grix sizes, center dot, asterisk, X (cross), XV (add to 10 or 5), Killer (cage add to number), own implimentable grid (like center dot and asterisk)

	
	inputFile.open("TEST1.txt");

	loadFile();
	
	
}

void loadFile()
{
	//dissern which solver to use
	string stringEat;
	string puzzleType;
	int solverType;
	

	//read what type of puzzle it is
	inputFile >> stringEat >> puzzleType;
	inputFile.ignore(256, '\n');

	if (puzzleType == "SIZE")
	{
		int size[2];
		int block[2];

		//read grid width and height
		inputFile >> stringEat >> size[0] >> size[1];
		inputFile.ignore(256, '\n');

		//read grid block sizes
		inputFile >> stringEat >> block[0] >> block[1];
		inputFile.ignore(256, '\n');

		//read what solver to use
		inputFile >> stringEat >> solverType;
		inputFile.ignore(256, '\n');

		int gridSize = size[0] * size[1];
		//use backtrack solver
		if (solverType == 0)
		{

			std::vector<int> read(size[0] * size[1]);
			for (int i = 0; i < 81; i++)
			{
				inputFile >> read[i];

			}

			BTBaseSolver solver = BTBaseSolver(read); //make class that can solve with variable grid size
			std::array<int, 81> output = solver.solve();

			ofstream outputFile("output.txt");
			for (int i = 0; i < 81; i++)
			{
				printf(" output = %d \n", output[i]);
				outputFile << output[i] << '\n';
			}
		}
		//use Possibility checking solver
		else if (solverType == 1)
		{
			int read[81];
			for (int i = 0; i < 81; i++)
			{
				inputFile >> read[i];

			}

			BaseSolver solver = BaseSolver(read);
			std::array<int, 81> output = solver.solve();

			ofstream outputFile("output.txt");
			for (int i = 0; i < 81; i++)
			{
				printf(" output = %d \n", output[i]);
				outputFile << output[i] << '\n';
			}
		}
	}

	



	//if type of puzzle is classic
	if (puzzleType == "CLASSIC")
	{
		//read what solver to use
		inputFile >> stringEat >> solverType;
		inputFile.ignore(256, '\n');

		//use backtrack solver
		if (solverType == 0)
		{
			int read[81];
			for (int i = 0; i < 81; i++)
			{
				inputFile >> read[i];

			}

			BTBaseSolver solver = BTBaseSolver(read);
			std::array<int, 81> output = solver.solve();

			ofstream outputFile("output.txt");
			for (int i = 0; i < 81; i++)
			{
				printf(" output = %d \n", output[i]);
				outputFile << output[i] << '\n';
			}
		}
		//use Possibility checking solver
		else if (solverType == 1)
		{
			int read[81];
			for (int i = 0; i < 81; i++)
			{
				inputFile >> read[i];

			}

			BaseSolver solver = BaseSolver(read);
			std::array<int, 81> output = solver.solve();

			ofstream outputFile("output.txt");
			for (int i = 0; i < 81; i++)
			{
				printf(" output = %d \n", output[i]);
				outputFile << output[i] << '\n';
			}
		}
	}
}