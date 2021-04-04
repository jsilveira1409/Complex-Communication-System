#include "arduino_secrets.h"
#include "Constants.h"
#include <SPI.h>
#include <WiFi101.h>

char ssid[] = SECRET_SSID;
char pass[] = SECRET_PASS;
int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup(){
  Serial1.begin(9600);
  pinMode(9,OUTPUT);
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);
    status = WiFi.begin(ssid, pass);
    delay(10000);
  }
  server.begin();
}

void loop(){
    WiFiClient client = server.available(); 
    if(client){
        Serial.println("New Client");
            String currentLine = "";        
    while (client.connected()) {            
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        if (c == '\n') {                 
          if (currentLine.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
            client.print("<!DOCTYPE html>");
            client.print("<html>");
            client.print("<body>");
            client.print("<h1>Complex Communication Server</h1>");
            client.print("<p>Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br></p>");
            client.print("<p>Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br></p>");
            client.print("<p>Click <a href=\"/FWD\">here</a> to go forward<br></p>");
            client.print("<p>Click <a href=\"/BKW\">here</a> to go backwards<br></p>");
            client.print("<p>Click <a href=\"/IDL\">here</a> to stop<br></p>");
            client.print("<p>Click <a href=\"/RTT\">here</a> to turn right<br></p>");
            client.print("<p>Click <a href=\"/LTT\">here</a> to turn left<br></p>");
            client.print("</body>");
            client.print("<a href='https://www.hackster.io/joaquim_silveira/complex-communication-system-e93c70'>Check the Project out!</a>");
            client.print("</html>");
            client.println();
            break;
          }else {
            currentLine = "";
          }
        }
        else if (c != '\r') {   
          currentLine += c;    
        }
        if (currentLine.endsWith("GET /H")) {
            digitalWrite(9, HIGH);
        }
        if (currentLine.endsWith("GET /L")) {
            digitalWrite(9, LOW);
        }
        if (currentLine.endsWith("GET /FWD")) {
            Serial1.write(FWD);          
        }
        if (currentLine.endsWith("GET /BKW")) {
            Serial1.write(BKW);          
        }
        if (currentLine.endsWith("GET /IDL")) {
            Serial1.write(NOP);          
        }
        if (currentLine.endsWith("GET /RTT")) {
            Serial1.write(RTT);          
        }
        if (currentLine.endsWith("GET /LTT")) {
            Serial1.write(LTT);          
        }
      }
    }
    client.stop();
    Serial.println("client disonnected");
  }
}
