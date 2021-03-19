#include "MotorControl.h"
#include "Sensors.h"
int comOp  = NOP;                 //Command Operation init as no operation

void setup (){
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(MOTA, OUTPUT);
  pinMode(MOTB, OUTPUT);
  pinMode(BRA, OUTPUT);
  pinMode(BRB, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(frontTrig, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(frontEcho, INPUT); // Sets the echoPin as an INPUT
  pinMode(leftTrig, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(leftEcho, INPUT); // Sets the echoPin as an INPUT
  pinMode(rightTrig, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(rightEcho, INPUT); // Sets the echoPin as an INPUT
  
}
int i = 0;
void loop() {
  forward(255, 255);
  delay(2000);
  backward(255, 255);
  delay(2000);
  rightFwd();
  delay(2000);
  leftFwd();
  delay(2000);
}
