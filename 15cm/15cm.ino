#include "MeMCore.h"
MeDCMotor motor3(M1);
MeDCMotor motor4(M2);
MeUltrasonicSensor right(PORT_1);
MeUltrasonicSensor left(PORT_4);
int i=200;
int R;
int v;
int F;
int g;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
R=right.distanceCm();
F=left.distanceCm();
v=R-15;
g=v*15;
Serial.print(g);
if(F<=10)
{motor3.run(100);
 motor4.run(250);
 delay(300);
 motor3.run(-200);
 motor4.run(200);
 delay(750);
 motor3.run(-250);
 motor4.run(-100);
 delay(600);
 motor3.run(-200);
 motor4.run(200);
 delay(500);
 motor3.run(100);
 motor4.run(250);
 delay(300);
  }
else if(v>6){
  motor3.run(-200);
  motor4.run(100);
  }
else if(v<-6){
  motor3.run(-125);
  motor4.run(200);
  }
else if(g>=0){
motor3.run(-i-g);
motor4.run(i-g);
  }
else if(g<0){
g=abs(g);
motor3.run(-i+g);
motor4.run(i+g);

  }
}
