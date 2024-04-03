using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OpenLid : MonoBehaviour
{
    public GameObject hinge;

    public bool openLid;
    Quaternion startRotation;

    float zAngle = 0f;
    float min = 0f;
    float max = 20f;
    float speed = 1;
    float zRot;

    // Start is called before the first frame update
    void Start()
    {
        openLid = false;
        startRotation = hinge.transform.rotation;

    }

    // Update is called once per frame
    void Update()
    {

        //zRot = Mathf.Clamp(zAngle, min, max);

        //zAngle = Input.GetAxis("Horizontal") * speed * Time.deltaTime;
        print(zAngle);

        if (Input.GetKey("up"))
        {
            zAngle = speed + Time.deltaTime;

            //addCounter();
        }else if (Input.GetKey("down"))
        {
            zAngle--;
        }


        if (openLid)
        {
            //Vector3 newRotation = new Vector3(0, 0, zAngle);
            //hinge.transform.eulerAngles = newRotation;
            hinge.transform.Rotate(0, 0, zRot);
        }
        else
        {
            hinge.transform.rotation = startRotation;
        }

        
        
    }
    public void addCounter()
    {
        zAngle++;
    }
}
