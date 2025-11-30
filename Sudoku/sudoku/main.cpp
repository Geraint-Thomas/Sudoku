//stuff
#include <iostream>
#include "BaseSolver.h"
#include "BTBaseSolver.h"
#include "Cell.h"
#include <array>

using namespace std;

int main()
{
	//g_Scene = new Scene();

	ifstream inputFile;
	inputFile.open("TEST1.txt");

	//dissern which solver to use
	string stringEat;
	string puzzleType;
	int solverType;

	//read what type of puzzle it is
	inputFile >> stringEat >> puzzleType; 
	inputFile.ignore(256, '\n');
	//read what solver to use
	inputFile >> stringEat >> solverType;
	inputFile.ignore(256, '\n');

	//if type of puzzle is classic
	if (puzzleType == "CLASSIC")
	{
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