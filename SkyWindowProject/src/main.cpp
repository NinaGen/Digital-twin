#include <Arduino.h>

// Encoder pins:
// https://lastminuteengineers.com/rotary-encoder-arduino-tutorial/
constexpr int CLK = 32; // blue
constexpr int DT = 27;  // green - for reading direction

// https://www.tutorialspoint.com/arduino/arduino_dc_motor.htm
constexpr int MOTOR_PIN1 = 17; // INPUT 1 - orange
constexpr int MOTOR_PIN2 = 21; // INPUT 2 - yellow
constexpr int ENABLER_PIN = 4;
// PWM settings
constexpr int ENABLER_CHANNEL = 0;
constexpr int FREQUENCY = 5000;
constexpr int RESOLUTION = 8;

int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";
unsigned long lastButtonPress = 0;

/* Function Declarations*/
void ReadEncoder();
void RunMotorForward();
void RunMotorBack();
void StopMotor();

void setup()
{
  // enable Serial
  Serial.begin(9600);

  // ENCODER - Set pinmode:
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  // MOTOR - Set pinmode:
  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  //  pinMode(ENABLER_PIN, OUTPUT);

  ledcSetup(ENABLER_CHANNEL, FREQUENCY, RESOLUTION);
  ledcAttachPin(ENABLER_PIN, ENABLER_CHANNEL);
}

void loop()
{
  ledcWrite(ENABLER_CHANNEL, 150);

  // Serial.println("********************************");
  // digitalWrite(ENABLER_PIN, HIGH);
  StopMotor();

  delay(2000);

  // ReadEncoder();

  // delay(1000);

  RunMotorForward();
  // digitalWrite(ENABLER_PIN, LOW);

  delay(2000);

  RunMotorBack();
  // ReadEncoder();

  delay(2000);
}

void StopMotor()
{
  Serial.println("stop");
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
}
void RunMotorForward()
{
  Serial.println("forward");
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, LOW);
  // ledcWrite(ENABLER_CHANNEL, 150);
}
void RunMotorBack()
{
  Serial.println("back");
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, HIGH);
  // ledcWrite(ENABLER_CHANNEL, 100);
}

void ReadEncoder()
{
  Serial.println("ReadEncoder");

  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1)
  {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK)
    {
      counter--;
      currentDir = "CCW";
    }
    else
    {
      // Encoder is rotating CW so increment
      counter++;
      currentDir = "CW";
    }

    Serial.print("Direction: ");
    Serial.print(currentDir);
    Serial.print(" | Counter: ");
    Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;

  // Put in a slight delay to help debounce the reading
  delay(1);
}
