using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenLid : MonoBehaviour
{
    public GameObject hinge;

    public bool openLid;
    Quaternion startRotation;
    public float desRot = 0f;



    // Start is called before the first frame update
    void Start()
    {
        openLid = false;
        startRotation = hinge.transform.rotation;

    }

    // Update is called once per frame
    void Update()
    {
        print(desRot);

        if (openLid)
        {
            Vector3 newRotation = new Vector3(0, 0, desRot);
            hinge.transform.eulerAngles = newRotation;
            
        }
        else
        {
            hinge.transform.rotation = startRotation;
        }
  
    }

}
