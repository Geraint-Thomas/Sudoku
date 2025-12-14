using NUnit.Framework;
using System.IO;
using UnityEngine;
using System.Collections.Generic;

public class FileReadWrite : MonoBehaviour
{
    string inputPath = "Assets/Sudoku/TEST2.txt";
    string outputPath = "Assets/Sudoku/OUTPUT.txt";
    Grid gridScript;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        
    }
    public FileReadWrite(Grid grid)
    {
        gridScript = grid;
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void changeInput(string input)
    {
        inputPath = input;
    }

    public void changeOutput(string output)
    {
        outputPath = output;
    }

    public void ReadFile()
    {
        List<int> grid = new List<int>();
        int height = 0; 
        int width = 0;
        //setup reader
        using (StreamReader reader = new StreamReader(inputPath))
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
                }


            }
        }
        //return grid.ToArray();

        
        gridScript.updateGrid(grid.ToArray());

    }
}
