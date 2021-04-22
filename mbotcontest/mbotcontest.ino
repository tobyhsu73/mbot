#include "MeMCore.h"
#include <Wire.h>
MeDCMotor motor3(M1);
MeDCMotor motor4(M2);
MeUltrasonicSensor right(PORT_1);
MeUltrasonicSensor left(PORT_4);
MeGyro gyro;
void setup()
{
  Serial.begin(115200);
  gyro.begin();
}
void loop(){
  gyro.update();
  int g=gyro.getAngleZ();
  int r=right.distanceCm();
  int l=left.distanceCm();
  Serial.print("DistanceR : ");
  Serial.print(r);
  Serial.print("DistanceL : ");
  Serial.print(l);
  Serial.print("gyro : ");
  Serial.println(g);

  
  if(l<=10 and r <=10){
    motor3.run(200);
    motor4.run(200);
    
    }
  else if(l<=10){
    motor3.run(-200);
    motor4.run(-150);
    delay(500);
    motor3.run(-200);
    motor4.run(200);
    delay(500);
    motor3.run(150);
    motor4.run(200);
    delay(500);
    }
  else if(r<=10){
    motor3.run(100);
    motor4.run(200);
    }
  //else if(g<=-10){
   // motor3.run(200);
   // motor4.run(200);
   // }
  //else if(g>=10){
   //motor3.run(-200);
   // motor4.run(-200);
   // }
  
  else{  
    motor3.run(-200);
    motor4.run(200);
    }

  delay(10);
  //if((0^(analogRead(A7)>10?0:1))){
       // Serial.print("hello");
  
  }
