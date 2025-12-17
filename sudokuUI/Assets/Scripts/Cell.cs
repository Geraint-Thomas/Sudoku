using TMPro;
using UnityEngine;

public class Cell : MonoBehaviour
{
    public TextMeshProUGUI _text;

    private void Start()
    {
        GameObject child = gameObject.transform.GetChild(0).gameObject;
        _text = child.GetComponent<TextMeshProUGUI>();
    }
    public void setNumber(int num)
    {
        if (_text != null)
        {
           if(num == 0)
           {
                _text.text = "";
           }
            else
                _text.text = num.ToString();
        }

    }
}
