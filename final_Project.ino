#include <Servo.h>
#include <Wire.h>
#include <TFLI2C.h>
TFLI2C tflI2C;
int16_t distance;
int16_t i2c_address = TFL_DEF_ADR;
Servo servo1;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo servo2;
int azimuth = 0;    // variable to store the servo position
int direction = 0;
int elevation ;
void setup() {
  servo1.attach(10);  // attaches the servo on pin 9 to the servo object
  servo2.attach(9);
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
 
  for (elevation = 30; elevation <= 120; elevation +=10){
    if (direction == 1){
  

  for (azimuth = 0; azimuth <= 90; azimuth += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(azimuth);              // tell servo to go to position in variable 'pos'
    if(tflI2C.getData(distance, i2c_address)){
    Serial.print(String(distance));
    Serial.print(' ' + String(elevation));
    Serial.println(' ' + String(azimuth));
       if (distance<=100){
        digitalWrite(11, HIGH);
        }
        else {
          digitalWrite(11, LOW);
        }  

  }
   
    delay(15);                       // waits 15ms for the servo to reach the position
      
  //}
  }
  }
  else {
  for (azimuth =90; azimuth >= 0; azimuth -= 1) { // goes from 0 degrees to 180 degrees
   
      servo1.write(azimuth);              // tell servo to go to position in variable 'pos'
      if(tflI2C.getData(distance, i2c_address)){
    Serial.print(String(distance));
    Serial.print(' ' + String(elevation));
    Serial.println(' ' + String(azimuth));
  }
      delay(15); 
       if (distance<=100){
        digitalWrite(11, HIGH);
        }
        else {
          digitalWrite(11, LOW);
        }
    }
  }
  direction = 1 - direction;
  servo2.write(elevation);
  if(tflI2C.getData(distance, i2c_address)){
    Serial.print( String(distance));
    Serial.print(' ' + String(elevation));
    Serial.println(' ' + String(azimuth));
  }
}

}


  