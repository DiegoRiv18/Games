using UnityEngine;

public class CameraFollow : MonoBehaviour
{
    public Transform player;
    public float y_offset;

    void FixedUpdate() // Using FixedUpdate for smoother physics-based updates
    {
        if (player != null)
        {
            transform.position = new Vector3(player.position.x, player.position.y + y_offset, transform.position.z);
        }
    }
}