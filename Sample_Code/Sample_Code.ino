// Include necessary libraries
#include <QTRSensors.h> // Library for the QTR sensors
#include <L298N.h>      // Library for controlling the L298N motor driver

// Define motor control pins
#define PWMA 3 // PWM control for Motor A speed
#define AIN1 5 // Control pin 1 for Motor A direction
#define AIN2 4 // Control pin 2 for Motor A direction
#define PWMB 9 // PWM control for Motor B speed
#define BIN1 7 // Control pin 1 for Motor B direction
#define BIN2 8 // Control pin 2 for Motor B direction
#define STBY 6 // Standby pin for the motor driver (if applicable)

// Define QTR sensor pins
const uint8_t SensorCount = 8;      // Number of QTR sensors
uint16_t sensorValues[SensorCount]; // Array to store sensor readings

// Initialize motor objects
L298N motorA(PWMA, AIN1, AIN2); // Motor A connected to PWMA, AIN1, AIN2
L298N motorB(PWMB, BIN1, BIN2); // Motor B connected to PWMB, BIN1, BIN2

// Initialize QTR sensor object
QTRSensorsAnalog qtr;

void setup()
{
  Serial.begin(9600); // Start serial communication for debugging

  // Set initial motor speed
  motorA.setSpeed(45.45); // Set initial speed for Motor A

  // Configure the sensors
  qtr.setTypeAnalog();                                                               // Set the sensor type to analog
  qtr.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, SensorCount); // Define sensor pins
  qtr.setEmitterPin(13);                                                             // Set the emitter pin for the sensors

  pinMode(STBY, OUTPUT);           // Set the standby pin as output
  pinMode(LED_BUILTIN, OUTPUT);    // Set the built-in LED pin as output
  digitalWrite(LED_BUILTIN, HIGH); // Turn on the LED to indicate calibration mode
  digitalWrite(STBY, HIGH);        // Disable standby mode on the motor driver

  motorA.runFor(25, L298N::FORWARD); // Run Motor A forward for 25 units of time

  // Calibrate the sensors
  for (uint16_t i = 0; i < 400; i++)
  {
    qtr.calibrate(); // Calibrate the sensors
  }
  digitalWrite(LED_BUILTIN, LOW); // Turn off the LED to indicate calibration is complete

  // Print the calibration minimum values
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  // Print the calibration maximum values
  for (uint8_t i = 0; i < SensorCount; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();

  motorA.stop(); // Stop Motor A after calibration
}

void loop()
{
  // Implement your control system here

  // Read the position of the line
  uint16_t position = qtr.readLineBlack(sensorValues);

  // Example control logic: if a line is detected, set motors to base speed
  if (position > 0)
  {
    motorA.setSpeed(255); // Set Motor A to base speed
    motorB.setSpeed(255); // Set Motor B to base speed
  }
}