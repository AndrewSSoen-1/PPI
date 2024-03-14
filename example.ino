SOMETHING// C++ code
//
// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 
LiquidCrystal lcd(1, 2, 4, 5, 6, 7);// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)

const int buzzerPin = 8; // Define the pin for the buzzer
const int trigPin = 9;
const int echoPin = 10;

long duration;
int distanceCm;

void setup() {
  lcd.begin(16, 2); // Initializes the interface to the LCD screen
  pinMode(trigPin, OUTPUT); // Initializes the sensor
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an output
}

void loop() {
  // Ultrasonic sensor distance measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  
  // Update LCD display
  lcd.clear(); // Clear the LCD screen before printing new values
  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  
  // Add buzzer if function to make conditions
  if (distanceCm < 50) {// if less than 50cm
    tone(buzzerPin, 1000);// Activate the buzzer with a frequency of 1000 Hz if less than 75cm
  } else if (distanceCm < 75) {// if less than 75cm
    tone(buzzerPin, 1000);// Activate the buzzer with a frequency of 1000 Hz if less than 75cm
  	delay(5);
    noTone(buzzerPin);
  } else if (distanceCm < 100) {// if less than 100cm
    tone(buzzerPin, 1000);// Activate the buzzer with a frequency of 1000 Hz if less than 75cm
  	delay(10);
    noTone(buzzerPin); 
  } else {
    noTone(buzzerPin); // Turn off the buzzer
  }
  
  delay(10);
}