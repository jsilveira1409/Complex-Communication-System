char mystr[10]; //Initialized variable to store recieved data

void setup() {
    //Serial1.begin(9600);
    Serial.begin(9600);
}

void loop() {
  Serial.readBytes(mystr,5); //Read the serial data and store in var
  delay(100);
  Serial.print("Arduino Says : ");
  Serial.println(mystr); //Print data on Serial Monitor
  delay(400);
}
