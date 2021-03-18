#include "MotorControl.h"
int comOp  = NOP;                 //Command Operation init as no operation

void setup (){
  Serial1.begin(9600);
  pinMode(MOTA, OUTPUT);
  pinMode(MOTB, OUTPUT);
  pinMode(BRA, OUTPUT);
  pinMode(BRB, OUTPUT);
  pinMode(7, OUTPUT);
  
}
int i = 0;
void loop() {
  i = Serial1.read();
  digitalWrite(7,i);
  delay(100);
}
