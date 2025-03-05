using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bar : MonoBehaviour
{
    public float MaxX;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        //Move bar to the mouse position
        Vector3 mousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);
        //Check for out of bounds
        if (Mathf.Abs(transform.position.x + mousePosition.x) < MaxX)
        {
            transform.position = new Vector3(mousePosition.x, transform.position.y);
        } 
    }
}
