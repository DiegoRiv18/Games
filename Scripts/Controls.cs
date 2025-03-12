using System.Collections;
using System.Collections.Generic;
using TMPro.EditorUtilities;
using UnityEngine;

public class Controls : MonoBehaviour
{
    private Rigidbody2D rb;
    public UIManager manager;
    public int jumpPower = 4;
    public int horizontalSpeed = 5;
    public int score;
    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        rb.linearVelocity = new Vector2(horizontalSpeed,rb.linearVelocity.y);
        if (Input.GetButtonDown("Jump"))
        {
            rb.linearVelocity = new Vector2(rb.linearVelocity.x, jumpPower);
        }
    }

    //If the bird comes into contact with an obsticle, it dies
    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.CompareTag("Barrier"))
        {
            Debug.Log("PLAYER COLLIDED WITH PIPE");
            Destroy(this.gameObject);
        }

        if (collision.collider.CompareTag("Score"))
        {
            Debug.Log("PLAYER COLLIDED WITH SCORE FIELD");
            manager.updateScore();
            Destroy(collision.collider.gameObject);
        }
    }
}
