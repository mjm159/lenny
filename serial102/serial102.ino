// Sweep
// by BARRAGAN <http://barraganstudio.com> 
// This example code is in the public domain.


#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 
int pos = 0;    // variable to store the servo position 
 
void setup() 
{ 
  myservo.attach(3);  // attaches the servo on pin 9 to the servo object 
  Serial.begin(9600);
  establishContact();
} 
 
 
void loop() 
{ 
  if(Serial.available() > 0) {
    int temp = Serial.parseInt();
    myservo.write(temp);
    Serial.write(temp);
  }
} 

void establishContact() {
  while(Serial.available() <= 0) {
    Serial.write("Ready\n");
    delay(300);
  } 
}
