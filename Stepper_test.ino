/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
int STEPS 100
int up =0;
int down = 0;
int cutter = 0;
int jet = 0;

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;
int displace=0;
void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(200);
  Serial.begin(9600);
}

void loop() {

  // get the sensor value
  Serial.println("Displacement");
  while(Serial.available()==0)
  {
    
  }
  
  displace = Serial.parseInt();
  Serial.print(displace);
  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(displace - previous);

  // remember the previous value of the sensor
  previous = displace;
}
