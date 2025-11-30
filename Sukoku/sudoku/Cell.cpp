#include "Cell.h"

Cell::Cell()
{
	number = 0;
	for (int i = 0; i < 9; i++)
	{
		possible[i] = i+1;
	}
}

Cell::~Cell()
{

}

void Cell::notPossible(int index)
{
	possible[index-1] = 0;
}