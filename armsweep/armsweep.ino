// Arm_Test
// By: Michael Malocha
// Runs the servos through a loop the check sweep

#include <Servo.h>

class Limb {
  public:
    int MAX;  // Maximum servo value
    int MIN;  // Minimum servo value
    // Member functions
    void initialize(int, int, int);
    void sweep(void);
  protected:
    Servo servo;
};

Limb base;
Limb l_arm;
Limb u_arm;
Limb claw;

void setup() {
  Serial.begin(9600);
  base.initialize(5, 0, 179);
  l_arm.initialize(6, 60, 120);
  u_arm.initialize(9, 60, 120);
  claw.initialize(10, 0, 60);
}

void loop() {
  base.sweep();
  l_arm.sweep();
  u_arm.sweep();
  claw.sweep();
}

void Limb::initialize(int pin, int min_val, int max_val) {
  servo.attach(pin);
  MAX = max_val;
  MIN = min_val;
}

void Limb::sweep() {
  for(int pos = MIN; pos <= MAX; pos += 1) {
    servo.write(pos);
    Serial.println(pos);
    delay(15);
  }
  for(int pos = MAX; pos >= MIN; pos -= 1) {
    servo.write(pos);
    Serial.println(pos);
    delay(15);
  }
}
