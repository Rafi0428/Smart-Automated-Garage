#include <Servo.h>

Servo gateServo;
const int servoPin = 9;

// Sensor Pin Allocations
const int trigOut = 2;
const int echoOut = 3;
const int trigIn = 4;
const int echoIn = 5;

// Distance Thresholds (in cm)
const int thresholdOut = 30; 
const int thresholdIn = 20;  

// Gate state aur Timer variables
bool isGateOpen = false;
unsigned long lastDetectionTime = 0; 
const unsigned long closeDelay = 1000; // 5-second hold time

// Servo Speed Control (Jitna bada number, utna slow gate)
const int servoSpeedDelay = 10; // 15 milliseconds per degree

void setup() {
  Serial.begin(9600);
  
  gateServo.attach(servoPin);
  gateServo.write(0); // Shuru mein gate close rahega

  pinMode(trigOut, OUTPUT);
  pinMode(echoOut, INPUT);
  pinMode(trigIn, OUTPUT);
  pinMode(echoIn, INPUT);
  
  Serial.println("System Online. Continuously scanning for vehicles...");
}

int getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;
  return distance;
}

// Gate ko slowly open karne ka custom function
void openGate() {
  Serial.println("Opening Gate smoothly...");
  for (int pos = 0; pos <= 90; pos += 1) { 
    gateServo.write(pos);              
    delay(servoSpeedDelay); // Har degree ke baad thoda rukega, jisse smooth movement aayegi                      
  }
}

// Gate ko slowly close karne ka custom function
void closeGate() {
  Serial.println("Closing Gate smoothly...");
  for (int pos = 90; pos >= 0; pos -= 1) { 
    gateServo.write(pos);              
    delay(servoSpeedDelay);                       
  }
}

void loop() {
  int distOutside = getDistance(trigOut, echoOut);
  int distInside = getDistance(trigIn, echoIn);

  // Check karna ki kya koi gaadi sensor ki range mein HAI
  bool carIsPresent = ((distOutside > 0 && distOutside <= thresholdOut) || (distInside > 0 && distInside <= thresholdIn));

  if (carIsPresent) {
    // Stopwatch ko update karte raho jab tak gaadi range mein hai
    lastDetectionTime = millis(); 
    
    // Agar gate band hai, toh smooth tariqe se khol do
    if (!isGateOpen) {
      Serial.println("Vehicle Detected!");
      openGate(); 
      isGateOpen = true; 
    }
  } 
  else {
    // Agar gaadi range se bahar chali gayi hai aur 5 seconds ho chuke hain
    if (isGateOpen && (millis() - lastDetectionTime >= closeDelay)) {
      Serial.println("5 seconds passed. Area clear.");
      closeGate();  
      isGateOpen = false; // Gate wapas close state mein mark kar do
    }
  }

  delay(100); // System stability ke liye
}