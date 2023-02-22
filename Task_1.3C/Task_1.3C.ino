const int PIR_PIN = 2; // PIR motion sensor input pin
const int MOS_PIN = 3; // Soil moisture sensor input pin

const int LED_PIN1 = 8; // LED output pin
const int LED_PIN2 = 9; // LED output pin

volatile int motionDetected = LOW; // Whether motion was detected or not
volatile int moistureDetected = 0; // If the soil had any moisture or not

void setup()
{
  pinMode(PIR_PIN, INPUT);
  pinMode(MOS_PIN, INPUT);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);

  attachInterrupt(digitalPinToInterrupt(PIR_PIN), motionISR, CHANGE); // attach interrupt to sensor 1 on pin 2
  attachInterrupt(digitalPinToInterrupt(MOS_PIN), soilMoistureISR, CHANGE); // attach interrupt to sensor 2 on pin 3

  Serial.begin(9600); // initialize serial communication
}

void loop()
{
  // do other tasks here while waiting for interrupts
}

void motionISR()
{
  motionDetected = digitalRead(PIR_PIN);
  if (motionDetected == HIGH)
  {                              // If motion was detected
    digitalWrite(LED_PIN1, HIGH); // Turn on the LED
    Serial.println("Motion detected");
  }
  else
  {                             // If motion was not detected
    digitalWrite(LED_PIN1, LOW); // Turn off the LED
  }
}

void soilMoistureISR()
{
  moistureDetected = digitalRead(MOS_PIN);
  //If moisture is more than 0
  if (moistureDetected != 0)
  {
    digitalWrite(LED_PIN2, HIGH);//Turns LED on
    Serial.println("Moisture detected");
  }
  //If there was no moisture
  else
  {
    digitalWrite(LED_PIN2, LOW); //Turns LED off
  }
}
