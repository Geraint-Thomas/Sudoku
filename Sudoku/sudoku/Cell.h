#pragma once
#include <list>
#include <string>
#include <fstream>
#include <iostream>


using namespace std;



class Cell
{
public:
	Cell();
	~Cell();
	int number;
	int possible[9];
	void notPossible(int index);
	void setNumber(int num);



protected:


};