using UnityEngine;

public class Grid : MonoBehaviour
{
    [SerializeField] GameObject gridParent;
    public GameObject[] grid;
    public int gridWidth = 9;
    public int gridHeight = 9;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        grid = new GameObject[gridWidth * gridHeight];
        for (int i = 0; i <gridWidth * gridHeight; i++)
        {
            //fill array with the chid grid cells
            grid[i] = gridParent.transform.GetChild(i).gameObject;
        }
    } // later versions will instantiate cells from a prefab to fill array

    // Update is called once per frame
    void Update()
    {
        
    }
}
