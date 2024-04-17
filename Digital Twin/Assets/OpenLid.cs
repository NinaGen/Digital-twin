using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using TMPro;

public class OpenLid : MonoBehaviour
{
    public GameObject hinge;

    public bool openLid;
    Quaternion startRotation;
    public float desRotation = 0f;

    public Slider angleSlider;
    public TextMeshProUGUI sliderText;



    // Start is called before the first frame update
    void Start()
    {
        openLid = false;
        startRotation = hinge.transform.rotation;

        ShowSliderValue();

    }

    // Update is called once per frame
    void Update()
    {
        

        if (openLid)
        {
            Vector3 newRotation = new Vector3(0, 0, desRotation);
            hinge.transform.eulerAngles = newRotation;
            print(desRotation);

        }
        else
        {
            hinge.transform.rotation = startRotation;
        }
  
    }

    public void ShowSliderValue()
    {
        string sliderValue = "" + angleSlider.value;
        sliderText.text = sliderValue;
        desRotation = angleSlider.value;

    }

}
