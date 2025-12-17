using NUnit.Framework;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using UnityEngine.Windows;

public class FileReadWrite : MonoBehaviour
{
    string inputPath = "Assets/Sudoku/Sudoku/Input.txt";
    string outputPath = "Assets/Sudoku/Sudoku/Output.txt";
    string genPuzzlePath = "Assets/Sudoku/Sudoku/Puzzle.txt";
    Grid gridScript;
    public int height = 9;
    public int width = 9;
    public int blockHeight = 3;
    public int blockWidth = 3;
    public int difficulty =3;

    void Start()
    {
        gridScript = gameObject.GetComponent<Grid>();
    }

    public FileReadWrite(Grid grid)
    {
        gridScript = grid;
    }

    public void clearFile(string path)
    {
        using (var writer = new StreamWriter(path))
        {
            writer.WriteLine("");
        }
    }

    public void changeInput(string input, int check)
    {
        if (check == 0)
        {
            using (var writer = new StreamWriter("Assets/Sudoku/x64/Debug/Input.txt"))
            {
                writer.WriteLine(input);
            }
        }
        else if (check == 1)
        {
            using (var writer = new StreamWriter("Assets/Sudoku/x64/Debug/Input.txt"))
            {
                writer.WriteLine(input);
            }
        }
    }

    public void changeOutput(string output)
    {
        outputPath = output;
    }

    public void ReadFile(int file)
    {
        string readFile = "Assets/Sudoku/x64/Debug/Input.txt";
       
        if (file == 1)
        {
            readFile = "Assets/Sudoku/x64/Debug/Puzzle.txt";
           
        }
        else if (file == 2)
        {
            readFile = "Assets/Sudoku/x64/Debug/Output.txt";
        }
            List<int> grid = new List<int>();

        //setup reader
        Debug.Log(readFile);
        using (StreamReader reader = new StreamReader(readFile))
        {
            //while there are lines to read
            while (!reader.EndOfStream)
            {
                //read next line
                string line = reader.ReadLine();
                //Debug.Log("Line: " + line);

                //split line on every space to seperate data
                string[] parts = line.Split(' ');

                foreach (string part in parts)
                {
                    /*
                    Debug.Log(part);
                    if (parts[0] == "SIZE")
                    {
                        gridScript.gridHeight = int.Parse(parts[1]);
                        gridScript.gridWidth = int.Parse(parts[2]);
                    }
                    else if (parts[0] == "BLOCK")
                    {
                        gridScript.blockHeight = int.Parse(parts[1]);
                        gridScript.blockWidth = int.Parse(parts[2]);
                    }
                    //otherwise its a number
                    else
                    {
                        grid.Add(int.Parse(parts[0]));
                    }
                    */
                    grid.Add(int.Parse(parts[0]));
                }


            }
        }
        //return grid.ToArray();

        
        gridScript.updateGrid(grid.ToArray());

    }

    public string getPuzzle()
    {
        string readFile = "Assets/Sudoku/x64/Debug/Puzzle.txt";

        
        string grid = "";

        //setup reader
        Debug.Log(readFile);
        using (StreamReader reader = new StreamReader(readFile))
        {
            //while there are lines to read
            while (!reader.EndOfStream)
            {
                //read next line
                string line = reader.ReadLine();
                //Debug.Log("Line: " + line);

                //split line on every space to seperate data
                string[] parts = line.Split(' ');

                foreach (string part in parts)
                {

                    grid += parts[0] +"\n";
                }
            }
        }

        return grid;
        
    }

    public void changeGridSize()
    {
        gridScript.changeGridSize(width, height);
    }
}
