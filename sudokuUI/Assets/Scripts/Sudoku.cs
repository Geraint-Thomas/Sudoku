using UnityEngine;

public class Sudoku : MonoBehaviour
{
    Grid gridScript;
    FileReadWrite fileScript;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        gridScript = gameObject.GetComponent<Grid>();
        fileScript = new FileReadWrite(gridScript);
        fileScript.ReadFile();
    }

    // Update is called once per frame
    void Update()
    {
        
    }



}
