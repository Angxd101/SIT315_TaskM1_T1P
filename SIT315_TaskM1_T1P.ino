// Constants
const int PIR_PIN = 2; // PIR motion sensor input pin

// Variables
int motionDetected = 0; // Whether motion was detected or not

void setup() {
  pinMode(PIR_PIN, INPUT); // Configure PIR pin as input
  pinMode(LED_BUILTIN, OUTPUT); // Configure LED pin as output
  Serial.begin(9600);
}

void loop() {
  motionDetected = digitalRead(PIR_PIN); // Read the PIR motion sensor input
  if (motionDetected == HIGH) { // If motion was detected
    digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED
    Serial.println("Motion Detected");
    
    delay(500); // Wait for half a second
  }
  else { // If motion was not detected
    digitalWrite(LED_BUILTIN, LOW); // Turn off the LED
    Serial.println("Motion Not Detected");
  }
}
