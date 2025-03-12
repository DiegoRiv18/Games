using TMPro;
using UnityEngine;
using UnityEngine.UI;

public class UIManager : MonoBehaviour
{
    [SerializeField]
    private Text scoreText;
    private int score;

    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        scoreText.text = "0";
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    public void updateScore()
    {
        score += 1;
        scoreText.text = score.ToString();
    }
}
