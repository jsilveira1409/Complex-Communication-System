#include <SPI.h>
#include <WiFi101.h>
char ssid[] = "Martin Router King";
char pass[] = "legrandinquisiteur";    // your network password (use for WPA, or use as key for WEP)
int keyIndex = 0;                 // your network key Index number (needed only for WEP)
int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  Serial1.begin(9600);      // initialize serial communication with mega
  pinMode(9, OUTPUT);      // set the LED pin mode
  while ( status != WL_CONNECTED) {
    Serial1.print("Attempting to connect to Network named: ");
    Serial1.println(ssid);                   // print the network name (SSID) 
    status = WiFi.begin(ssid, pass);        // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    delay(10000);// wait 10 seconds for connection:
  }
  server.begin();                           // start the web server on port 80
  printWiFiStatus();                        // you're connected now, so print out the status
}

void loop() {
  WiFiClient client = server.available();   // listen for incoming clients
  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character
          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {                        // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            client.println("HTTP/1.1 200 OK");                    // and a content-type so the client knows what's coming, then a blank line:
            client.println("Content-type:text/html");
            client.println();                                     // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> turn the LED on pin 9 on<br>");
            client.print("Click <a href=\"/L\">here</a> turn the LED on pin 9 off<br>");      // The HTTP response ends with another blank line:
            client.println();          // break out of the while loop:
            break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
            currentLine += c;      // add it to the end of the currentLine
        }
        if (currentLine.endsWith("GET /H")) {                 // Check to see if the client request was "GET /H" or "GET /L":
          Serial1.write(HIGH); //Write the serial data
        }
        if (currentLine.endsWith("GET /L")) {
          Serial1.write(LOW); //Write the serial data
        }
      }
    }
    client.stop();                            // close the connection
    Serial.println("client disonnected");
  }
}

void printWiFiStatus() {
  Serial.print("SSID: ");           // print the SSID of the network you're attached to:
  Serial.println(WiFi.SSID());      
  IPAddress ip = WiFi.localIP();    // print your WiFi shield's IP address:
  Serial.print("IP Address: ");
  Serial.println(ip);
  long rssi = WiFi.RSSI();          // print the received signal strength:
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);               // print where to go in a browser:
}
