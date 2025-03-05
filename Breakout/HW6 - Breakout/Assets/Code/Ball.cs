using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UIElements;
using TMPro;

public class Ball : MonoBehaviour
{
    private float MaxX = 15.5f;
    private bool newlife = true;
    private Rigidbody2D rb;
    public float Speed = 13.5f;
    private int Balls = 5;
    private int Score = 0;

    public TextMeshProUGUI ScoreText;
    public GameObject[] LivesImages;
    public GameObject GameOverPanel;
    public GameObject WinPanel;
    int numBricks;

    AudioManager audioManager;
    private void Awake()
    {
        audioManager = GameObject.FindGameObjectWithTag("Audio").GetComponent<AudioManager>();
    }
    // Start is called before the first frame update
    void Start()
    {
        rb = GetComponent<Rigidbody2D>();
        numBricks = FindObjectOfType<LevelBuilder>().transform.childCount;
        //Debug.Log("NUMBER OF BRICKS:" + bricks);
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 MousePosition = Camera.main.ScreenToWorldPoint(Input.mousePosition);

        //Stick to the Padddel if its a new ball
        if (newlife && Mathf.Abs(transform.position.x + MousePosition.x) < MaxX)
        {
            transform.position = new Vector3(MousePosition.x, -3.5f);
        }
        //Launch the ball up
        if (Input.GetMouseButtonDown(0) && newlife == true)
        {
            rb.velocity = Vector3.up * Speed;
            newlife = false;
        }
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        //Break brick
        if (collision.gameObject.CompareTag("Brick"))
        {
            audioManager.PlaySFX(audioManager.SFX);
            Destroy(collision.gameObject);
            Score += 10;
            ScoreText.text = Score.ToString("0000");
            numBricks--;
            if (numBricks == 0)
            {
                YouWin();
            }
        }
        //Check for game over and reset ball and update UI
        if (collision.gameObject.CompareTag("Death"))
        {
            if (Balls <= 0)
            {
                GameOver();
            }
            else
            {
                rb.velocity = Vector3.zero;
                newlife = true;
                Balls--;
                LivesImages[Balls].SetActive(false);
            }
        }
    }

    private void GameOver()
    {
        GameOverPanel.SetActive(true);
        Time.timeScale = 0;
        Destroy(gameObject);
    }
    private void YouWin()
    {
        WinPanel.SetActive(true);
        Time.timeScale = 0;
    }
}
