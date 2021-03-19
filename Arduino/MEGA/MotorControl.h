#include "Constants.h"

void forward(int speedA = 125, int speedB = 125){
  digitalWrite(MOTA, HIGH);
  digitalWrite(BRA, LOW); 
  analogWrite(3, speedA);   

  digitalWrite(MOTB, HIGH); 
  digitalWrite(BRB, LOW);   
  analogWrite(11, speedB);  
}

void backward(int speedA = 125, int speedB = 125){
  digitalWrite(MOTA, LOW);
  digitalWrite(BRA, LOW); 
  analogWrite(3, speedA);   

  digitalWrite(MOTB, LOW);  
  digitalWrite(BRB, LOW);   
  analogWrite(11, speedB);  
}


void leftFwd(int speedA = 125){
  digitalWrite(MOTA, HIGH);
  digitalWrite(BRA, LOW); 
  analogWrite(3, speedA);   

  digitalWrite(MOTB, HIGH);  
  digitalWrite(BRB, HIGH);    
}

void rightFwd(int speedB = 125){
  digitalWrite(MOTA, HIGH);
  digitalWrite(BRA, HIGH); 
  
  digitalWrite(MOTB, HIGH);  
  digitalWrite(BRB, LOW);   
  analogWrite(11, speedB);
}


void breaks(){
  digitalWrite(MOTA, HIGH);
  digitalWrite(BRA, HIGH); 
     
  digitalWrite(MOTB, HIGH); 
  digitalWrite(BRB, HIGH);   
}
