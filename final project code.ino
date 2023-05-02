Servo servo1;
Servo servo2;
void setup() {
  double d = 0; // distance measured by lidar
  int theta1 = 0; // horizonyal angle
  int theta2 = 0; //vertical angle
  int theta1New = 0;
  int theta2New = 0; // used in tracking loop
  double dNew = 0;
  double dddt = 0;
  double dtheta1dt = 0;
  double dtheta2dt = 0;
  int i = 0; //initalize loop
  int j = 0;
  servo1.attach(12);
  servo2.attach(13);
  int dmax = 0; //max range of sensor
  int dmin = 0; //min range of sensor
  int count = 0; // have we iterated through a full pan
  int currentTime = 0;
  int previousTime = 0;
  int theta1Predict = 0;
  int theta2Predict = 0;
  double dPredict = 0;
  timeDiff = 0;
// we mant to detect objects in range dmin<d<dmax
Serial.begin(115200);
servo1.write(i); //initialize servos at zero
servo2.write(j);
}

void loop() {
  // put your main code here, to run repeatedly:
  // panning code
  while (i<180){
 servo1.write(i);
  while(j<180){
    servo2.write(j);
    Serial.print(i);
    Serial.print(j);
    Serial.print(d);
    digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH, 11500); 
 y_k=(1-12*dt)*y_k + 12*dt*distance_cm;
 d = (speedOfSound*duration*1.0e-6)*0.5; 
    if (count>=180 && d<=val){ // one full pan at least before going into tracking
      break
    }
   j+=1; 
   if (j>=179){
     j = 0;
   }
  }
  
  
  //read d
  Serial.print(i);
  Serial.print(j);
  Serial.print(d);
    if (d>=val && d<=val){ // break loop if object is detected
      break
  i += 1;
  count +=1
  if (i>=179){
    i = 0; //reset to original value after full pan
  }
  }

analogWrite(A0, HIGH); // when we detect, break panning loop, turn on light
// could add light warning system, eg lights turn on as it gets closer
 theta1 = servo1.read();
  theta2 = servo2.read(); //get initial position
digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH, 11500); 
 y_k=(1-12*dt)*y_k + 12*dt*distance_cm;
 d = (speedOfSound*duration*1.0e-6)*0.5; while (1>0){// tracking operates constantly until broken by a condition 
  currentTime = millis();

    digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);


 duration = pulseIn(echoPin, HIGH, 11500); 
 y_k=(1-12*dt)*y_k + 12*dt*distance_cm;
 d = (speedOfSound*duration*1.0e-6)*0.5; 
    if (d>=dmax){
      break
    }
   
    timeDiff = previousTime - currentTime;
    
    if (time_diff >= 100){
      //get new position
      theta1New = servo1.read();
      theta2New = servo2.read();
      //dNew = read d
    dddt = (dNew -d)/timeDiff; //get velocity in d direction
    dtheta1dt = (theta1New -theta1)/timeDiff; // 2 angular velocities
    dtheta2dt = (theta1New - theta2)/timeDiff;
    previousTime = currentTime; // reset time
    theta1 = theta1New; //reset position
    theta2 = theta2New; 
    // predict position based on velocity
    theta1Predict = theta1New + dtheta1dt*timeDiff;
    theta2Predict theta2New + dtheta2dt * timeDiff;
    dPredict = dddt * timeDiff + dNew; 
    // manipulate servos to point at new position
    servo1.write(theta1Predict);
    servo2.write(theta2Predict);
// send values to serial monitor to be plotted
    Serial.print(theta1Predict);
    Serial.print(theta2Predict);
    Serial.print(dPredict);
    }



}


}
