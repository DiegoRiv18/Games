using UnityEngine;

public class Spawn : MonoBehaviour
{
    public GameObject copyPrefab; // Reference to the prefab
    public int x_distance;
    public int y_distance;

    private void OnDestroy()
    {
        Debug.Log("DESTROYING THIS PIPE");

        if (copyPrefab != null)
        {
            Vector3 pos = transform.position + new Vector3(x_distance, Random.Range(-1 * y_distance, y_distance), 0f);
            GameObject newCopy = Instantiate(copyPrefab, pos, Quaternion.identity);
        }
    }
}
