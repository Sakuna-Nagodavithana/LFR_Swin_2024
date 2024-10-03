#include <QTRSensors.h>

#define NUM_SENSORS   8           // Number of QTR sensors
#define EMITTER_PIN   13         // Emitter control pin

// Assign QTR-8 sensors to analog pins A0-A7
const uint8_t SensorPins[NUM_SENSORS] = {A0, A1, A2, A3, A4, A5, A6, A7};

QTRSensors qtr;                            // Create QTRSensors object
unsigned int sensorValues[NUM_SENSORS];   // Array to store sensor readings

const uint16_t CALIBRATION_COUNT = 400;      // Number of calibration iterations
const uint16_t CALIBRATION_DELAY_US = 2500;  // Delay in microseconds between calibrations


void setup() {
  // Initialize Serial Communication for debugging
  Serial.begin(9600);
  
  // Initialize QTR-8 Sensors
  qtr.setTypeRC();                             // Set sensor type to Analog (reflectance)
  qtr.setSensorPins(SensorPins, NUM_SENSORS);  // Assign sensor pins
  qtr.setEmitterPin(EMITTER_PIN);              // Set emitter control pin

  // Turn on emitters
  pinMode(EMITTER_PIN, OUTPUT);
  digitalWrite(EMITTER_PIN, HIGH);
  
  // Indicate calibration is starting by turning on the built-in LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Turn on LED to indicate calibration
  
  // Calibration Phase (approximately 10 seconds)
  Serial.println("Calibrating QTR-8 sensors");
  for (uint16_t i = 0; i < CALIBRATION_COUNT; i++) {
    qtr.calibrate();
    delayMicroseconds(CALIBRATION_DELAY_US);
  }

  // Indicate calibration is complete by turning off the built-in LED
  digitalWrite(LED_BUILTIN, LOW); // Turn off LED after calibration

  // Print Calibration Values for verification
  Serial.println("Calibration Min Values:");
  for (uint8_t i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  Serial.println("Calibration Max Values:");
  for (uint8_t i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println("\nCalibration Complete.\n");
  
}

void loop() {
  // Read the line position (0 to 7000)
  uint16_t position = qtr.readLineBlack(sensorValues);
  
  // Debugging Information
  Serial.print("Position: ");Serial.println(position);

  delay(100);
}
