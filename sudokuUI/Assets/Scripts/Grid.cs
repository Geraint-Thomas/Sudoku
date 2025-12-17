using UnityEngine;
using UnityEngine.UI;

public class Grid : MonoBehaviour
{
    [SerializeField] GameObject gridParent;
    private GridLayoutGroup gridLayout;
    public GameObject cellPrefab;
    public int gridWidth = 9;
    public int gridHeight = 9;
    public int blockHeight = 3;
    public int blockWidth = 3;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        gridLayout = gridParent.GetComponent<GridLayoutGroup>();
        
        int[] temp = new int[81];
        for(int i = 0; i< gridWidth * gridHeight; i++)
        {
            temp[i] = i;
        }
        //clearGrid();
        //updateGrid(temp);
        //setGridPosition();
    } 

    
    public void clearGrid()
    {
        if (gridParent.transform.GetChild(3) != null)
        {
            for (int i = 0; i < gridWidth * gridHeight; i++)
            {
                Destroy(gridParent.transform.GetChild(i).gameObject);
            }
        }
    }

    public void updateGrid(int[] grid)
    {
        clearGrid();
        gridLayout.enabled = true;
        //set constraint to new grid size
        gridLayout.constraintCount = gridWidth;

        for(int i = 0; i < gridHeight * gridWidth;i++)
        {
            GameObject cell = Instantiate(cellPrefab, gridParent.transform);
            cell.GetComponent<Cell>().setNumber(grid[i]);
        }

        
    }

    public void changeGridSize(int gridWidth, int gridHeight)
    {
        //get rid of existing cells
        clearGrid();

        gridLayout.enabled = true;
        //set constraint to new grid size
        gridLayout.constraintCount = gridWidth;

        for (int i = 0; i < gridHeight * gridWidth; i++)
        {
            GameObject cell = Instantiate(cellPrefab, gridParent.transform);
            cell.GetComponent<Cell>().setNumber(0);
        }
    }


}
