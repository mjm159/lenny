/**
Code to command the robotic arm via the serial port.

The format is:
{base},{lower arm},{upper arm}.{claw}X with capital 'x' as the line terminator.
ex:
45,32,90,60X
Base      -> 45*
Lower arm -> 32*
Upper arm -> 90*
Claw      -> 60*
*/
#include <Servo.h>
#include "Limb.h"

// Creating limb instances
Limb base;
Limb l_arm;
Limb u_arm;
Limb claw;

// Defining maximums and minimums for servoes
// Base
int B_MIN = 0;
int B_MAX = 179;
// Lower Arm
int L_MIN = 60;
int L_MAX = 120;
// Upper Arm
int U_MIN = 60;
int U_MAX = 60;
// Claw
int C_MIN = 0;
int C_MAX = 60;


void setup() {
  Serial.begin(9600);
  // Setup and initialize the servoes
  base.initialize(5, B_MIN, B_MAX);
  l_arm.initialize(6, L_MIN, L_MAX);
  u_arm.initialize(9, U_MIN, U_MAX);
  claw.initialize(10, C_MIN, C_MAX);
  // Establish connection with the program
  establishConnection();
}

void loop() {
  while(Serial.available() > 0) {
    // Catching new arm positions from serial port
    int base_val = Serial.parseInt(); 
    int l_arm_val = Serial.parseInt(); 
    int u_arm_val = Serial.parseInt(); 
    int claw_val = Serial.parseInt();
    
    // When a capital X is sent, send values to arm servoes
    if(Serial.read() == 'X') {
      base.moveTo(base_val);
      l_arm.moveTo(l_arm_val);
      u_arm.moveTo(u_arm_val);
      claw.moveTo(claw_val);
    }  
  } 
}

// To establish connection and transfer servo boundaries
void establishConnection() {
  while(Serial.available() <= 0) {
    Serial.println("ping");
    delay(300); 
  }
  // Sending base boundaries
  boundaryPrint(B_MIN, B_MAX);
  // Sending lower arm boundaries
  boundaryPrint(L_MIN, L_MAX);
  // Sending upper arm boundaries
  boundaryPrint(U_MIN, U_MAX);
  // Sending Claw boundaries
  boundaryPrint(C_MIN, C_MAX);
  
  // Acknowledging data transfer
  Serial.println("Connection Established...");
}

// So that printing boundary info doesn't require 12 separate print statements...
void boundaryPrint(int x, int y) {
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);
}
