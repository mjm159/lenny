struct Light {
  int pin;
  int value;
};

Light lightArray[3];

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
  for(int i = 0; i < 3; i++) {
    lightArray[i].pin = i + 2;
    lightArray[i].value = LOW;
  }
  
  Serial.begin(9600);
  establishContact();
}

void loop() {
  if(Serial.available() > 0) {
    int temp = Serial.parseInt();
    if(temp == 1) {
      lightArray[0].value = !lightArray[0].value;
    } else if(temp == 2) {
      lightArray[1].value = !lightArray[1].value;
    } else if(temp == 3) {
      lightArray[2].value = !lightArray[2].value;
    }
  }
  for(int i = 0; i < 3; i++) {
    digitalWrite(lightArray[i].pin, lightArray[i].value);
  }
}

void establishContact() {
  while(Serial.available() <= 0) {
    Serial.write("Ready\n");
    delay(300);
  } 
}
