

void UltraSon(){
  long durF, durL, durR;                  // variable for the duration of sound wave travel
  
  digitalWrite(leftTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(leftTrig, HIGH);          // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(leftTrig, LOW);           // Reads the echoPin, returns the sound wave travel time in microseconds
  durL = pulseIn(leftEcho, HIGH);    // Calculating the distance
  
  digitalWrite(frontTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(frontTrig, HIGH);          // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(frontTrig, LOW);           // Reads the echoPin, returns the sound wave travel time in microseconds
  durF = pulseIn(frontEcho, HIGH);    // Calculating the distance
  
  digitalWrite(rightTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(rightTrig, HIGH);          // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(rightTrig, LOW);           // Reads the echoPin, returns the sound wave travel time in microseconds
  durR = pulseIn(rightEcho, HIGH);    // Calculating the distance
  
  
  
  
  Serial.print(durL);
  Serial.print(" ");
  Serial.print(durF);
  Serial.print(" ");
  Serial.println(durR);
  
}
