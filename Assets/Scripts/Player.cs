using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Player : MonoBehaviour
{
    public float move_speed = 5f;

    public Rigidbody2D rb;

    Vector2 movement;

    // Start is called before the first frame update
    void Start()
    {
        rb = gameObject.GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void Update()
    {
        // Input
        movement.x = Input.GetAxisRaw("Horizontal");
        movement.y = Input.GetAxisRaw("Vertical");

    }

    private void FixedUpdate()
    {
        // Movement
        if (movement.x != 0 || movement.y != 0)
        {
            // rb.MovePosition(rb.position + movement * move_speed * Time.fixedDeltaTime);
            rb.velocity = new Vector2(movement.x * move_speed, movement.y * move_speed);
            Debug.Log("X: " + movement.x + "Y: " + movement.y);
        }
    }
}
