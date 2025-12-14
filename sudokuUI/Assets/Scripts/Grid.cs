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
        for (int i = 0; i < gridWidth * gridHeight; i++)
        {
            Destroy(gridParent.transform.GetChild(i).gameObject);
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

    /*
    public void setGridPosition()
    {
        gridLayout.enabled = false;
        for (int y = 0; y < gridHeight; y++)
        {
            for (int x = 0; x < gridWidth; x++)
            {
                //set horizontal
                if (x % 3 == 0)
                {
                    
                    GameObject go = gridParent.transform.GetChild(x + (y * gridWidth)).gameObject;
                    Debug.Log(go.GetComponent<RectTransform>().pivot.x);
                    go.GetComponent<RectTransform>().pivot.Set(go.GetComponent<RectTransform>().pivot.x + 0.05f, go.GetComponent<RectTransform>().pivot.y);
                    Debug.Log(go.GetComponent<RectTransform>().pivot.x);
                }
                else if (x % 3 == 2)
                {
                    GameObject go = gridParent.transform.GetChild(x + (y * gridWidth)).gameObject;
                    go.GetComponent<RectTransform>().pivot.Set(go.GetComponent<RectTransform>().pivot.x - 0.05f, go.GetComponent<RectTransform>().pivot.y);
                }

                //set vertical
                if (y % 3 == 0)
                {
                    GameObject go = gridParent.transform.GetChild(x + (y * gridWidth)).gameObject;
                    go.GetComponent<RectTransform>().pivot.Set(go.GetComponent<RectTransform>().pivot.x, go.GetComponent<RectTransform>().pivot.y + 0.05f);
                }
                else if (y % 3 == 2)
                {
                    GameObject go = gridParent.transform.GetChild(x + (y * gridWidth)).gameObject;
                    go.GetComponent<RectTransform>().pivot.Set(go.GetComponent<RectTransform>().pivot.x, go.GetComponent<RectTransform>().pivot.y - 0.05f);
                }
            }
        }
        gridLayout.enabled = true;
    }
    */
}
