using System.Diagnostics;
using UnityEngine;


public class Sudoku : MonoBehaviour
{
    Grid gridScript;
    FileReadWrite fileScript;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        gridScript = gameObject.GetComponent<Grid>();
        fileScript = gameObject.GetComponent<FileReadWrite>();
        //fileScript.ReadFile(0);
    }

   public void generatePuzzle()
   {
        //path to exe
        //string path = System.IO.Path.Combine(Application.dataPath, "Sudoku/Sudoku/x64/Debug/sudoku.exe");
        string path = Application.dataPath + "/Sudoku/x64/Debug/sudoku.exe";
        //UnityEngine.Debug.Log(path);
        string input = "TYPE MAKE \nSIZE " +fileScript.width.ToString() + " " +fileScript.height.ToString() +"\nBLOCK " + fileScript.blockWidth.ToString() + " " + fileScript.blockHeight.ToString() +"\nDIFFICULTY " +fileScript.difficulty.ToString();
        fileScript.changeInput(input, 0);
        
        Process p = new Process();
        p.StartInfo.FileName = path;
        p.Start();

        p.WaitForExit();
        fileScript.ReadFile(1);
            
   }

    public void solvePuzzle()
    {
        //path to exe
        //string path = System.IO.Path.Combine(Application.dataPath, "Sudoku/Sudoku/x64/Debug/sudoku.exe");
        string path = Application.dataPath + "/Sudoku/x64/Debug/sudoku.exe";
        string input = "TYPE SIZE \nSIZE " + fileScript.width.ToString() + " " + fileScript.height.ToString() + "\nBLOCK " + fileScript.blockWidth.ToString() + " " + fileScript.blockHeight.ToString() +"\nSOLVER 0\n" +fileScript.getPuzzle();
        fileScript.changeInput(input, 1);

        Process p = new Process();
        p.StartInfo.FileName = path;
        p.Start();

        p.WaitForExit();
        fileScript.ReadFile(2);
    }

}
