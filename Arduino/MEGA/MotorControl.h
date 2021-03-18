#include "Constants.h"

void forward(int speedA = 125, int speedB = 125){
  digitalWrite(MOTA, HIGH);
  digitalWrite(BRA, LOW); 
  analogWrite(3, speedA);   

  digitalWrite(MOTB, HIGH);  //Establishes backward direction of Channel B
  digitalWrite(BRB, LOW);   //Disengage the Brake for Channel B
  analogWrite(11, speedB);    //Spins the motor on Channel B at half speed

}
