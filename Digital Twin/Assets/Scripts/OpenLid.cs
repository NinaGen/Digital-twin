using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenLid : MonoBehaviour
{
    public GameObject hinge;

    public bool openLid;

    // Start is called before the first frame update
    void Start()
    {
        openLid = false;
    }

    // Update is called once per frame
    void Update()
    {
        if (openLid)
        {
            Vector3 newRotation = new Vector3(0, 0, 10);
            hinge.transform.eulerAngles = newRotation;
        }
        
    }
}
