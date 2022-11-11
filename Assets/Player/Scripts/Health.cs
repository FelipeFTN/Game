using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Health : MonoBehaviour
{
    public Image healthBar;
    public float healthAmount = 100;

    void Update()
    {
        if (healthAmount <= 0)
        {
            Debug.Log("You're Dead!");
        }

        // Debug - Health Bar
        if (Input.GetKeyDown(KeyCode.E)) { TakeDamage(20); }
        if (Input.GetKeyDown(KeyCode.F)) { Healing(20); }
    }

    public void TakeDamage(float damage)
    {
        healthAmount -= damage;
        healthBar.fillAmount = healthAmount / 100;
    }

    public void Healing(float healPoints)
    {
        healthAmount += healPoints;
        healthAmount = Mathf.Clamp(healthAmount, 0, 100);

        healthBar.fillAmount = healthAmount / 100;
    }
}
