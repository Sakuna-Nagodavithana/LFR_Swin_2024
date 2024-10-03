// Include the (new) library
//#include <L298NX2.h>

#include <L298N.h>

#define PWMA 4
#define AIN2 5
#define AIN1 6  // Assign the motor pins
#define STBY 7
#define BIN1 8
#define BIN2 9
#define PWMB 10



// Initialize both motors
//L298NX2 motors(PWMA, AIN1, AIN2, PWMB, BIN1, BIN2);
L298N motorA(PWMA, AIN1, AIN2);
L298N motorB(PWMB, BIN1, BIN2);


float baseSpeed = 255;



void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);

  //motors.setSpeed(baseSpeed);
  motorA.setSpeed(45.45);


  
  pinMode(STBY,OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH); // Turn on Arduino's LED to indicate we are in calibration mode
  digitalWrite(STBY,HIGH);


  motorA.setSpeed(baseSpeed);
  motorB.setSpeed(baseSpeed);

}

void loop() {
  //motors.forwardA();
  //motors.forwardB();
  motorA.forward();
  motorB.forward();
  constrain(baseSpeed,0,255);




  motorA.setSpeed(baseSpeed);
  motorB.setSpeed(baseSpeed);

  motorA.setSpeed(baseSpeed - 90);
  motorB.setSpeed(baseSpeed);

  motorA.setSpeed(baseSpeed);
  motorB.setSpeed(baseSpeed - 90);
  


  printInfo();
  delay(2000);

}

void printInfo()
{
  Serial.print("Motor A Speed = ");
  Serial.println(motorA.getSpeed());

  Serial.print("Motor B Speed = ");
  Serial.println(motorB.getSpeed());
}

