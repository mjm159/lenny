#include "Arduino.h"
#include <Servo.h>


#ifndef LIMB_H
#define LIMB_H
/**
* Header file to describe a Servo limb
*
* By: Michael
*/

class Limb {
  public:
    int MAX;  // Maximum servo value
    int MIN;  // Minimum servo value
    // Member functions
    void initialize(int, int, int);
    void moveTo(int);
  protected:
    Servo servo;
};

#endif
