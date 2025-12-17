using System.Drawing;
using UnityEngine;

public class UIScript : MonoBehaviour
{
    public FileReadWrite frw;
    public Sudoku sud;
    public Grid grid;
   
    public void changeSize(int size)
    {
        if(size == 0)
        {
            frw.height = 9;
            frw.width = 9;
            frw.blockWidth = 3;
            frw.blockHeight = 3;
        }
        else if (size == 1)
        {
            frw.height = 6;
            frw.width = 6;
            frw.blockWidth = 3;
            frw.blockHeight = 2;
        }
        else if (size == 2)
        {
            frw.height = 8;
            frw.width = 8;
            frw.blockWidth = 4;
            frw.blockHeight = 2;
        }

        frw.changeGridSize();
    }

    public void changeDifficulty(int difficulty)
    {
        if (difficulty == 0)
        {
            frw.difficulty = 3;
        }
        else if (difficulty == 1)
        {
            frw.difficulty = 4;
        }
        else if (difficulty == 2)
        {
            frw.difficulty = 5;
        }
    }

    public void clearGrid()
    {
        frw.changeGridSize();
    }

    public void generatePuzzle()
    {
        sud.generatePuzzle();
    }

    public void solvePuzzle()
    {
        sud.solvePuzzle();
    }

}
