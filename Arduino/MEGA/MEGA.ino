#include "MotorControl.h"
#include "Sensors.h"
int comOp  = NOP;                 //Command Operation init as no operation



void setup () {
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

void loop() {
  comOp = Serial1.read();
  Serial.println(comOp, DEC);
  switch (comOp) {
    case NOP:
      breaks();
      break;
    case FWD:
      forward(255, 255);
      break;
    case RTT:
      rightFwd(255);
      break;
    case LTT:
      leftFwd(255);
      break;
    case BKW:
      backward(255, 255);
      break;
  }
delay(50);
}
