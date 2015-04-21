#include "Limb.h"

void Limb::initialize(int pin, int min_val, int max_val) {
  servo.attach(pin);
  MAX = max_val;
  MIN = min_val;
}

void Limb::moveTo(int val) {
  val = constrain(val, MIN, MAX);
  servo.write(val);
}
