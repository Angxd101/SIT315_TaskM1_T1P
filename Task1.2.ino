// Constants
const int PIR_PIN = 2; // PIR motion sensor input pin
const int LED_PIN = 13; // LED output pin

// Variables
volatile int motionDetected = LOW; // Whether motion was detected or not

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(PIR_PIN), motion, CHANGE); // Attach motion detection interrupt
}

void loop() {
  // Do nothing in the loop
}

void motion() {
  motionDetected = digitalRead(PIR_PIN);
  if (motionDetected == HIGH) { // If motion was detected
    digitalWrite(LED_PIN, HIGH); // Turn on the LED
  }
  else { // If motion was not detected
    digitalWrite(LED_PIN, LOW); // Turn off the LED
  }
}
