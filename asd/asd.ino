#include <SoftwareSerial.h>
#define DEBUG true 
SoftwareSerial esp8266(2,3); 
String sendData(String command, const int timeout, boolean debug);
void setup()
{
  Serial.begin(115200);
  esp8266.begin(115200); // your esp's baud rate might be different
  sendData("AT+RST\r\n",2000,DEBUG); // reset module
  delay(2000);
  sendData("AT+CWMODE=3\r\n",1000,DEBUG); // configure as access point
  
  delay(3000);
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); // configure for multiple connections
  delay(2000);
  sendData("AT+CIFSR\r\n",1000,DEBUG); // get ip address
  delay(3000);
  sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); // turn on server on port 80
}
 void loop()
 {
if(esp8266.available()) // check if the esp is sending a message 
  {
    
    if(esp8266.find("+IPD,"))
    {
     delay(2000);
 
     int connectionId = esp8266.read()-48;
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend += "10";
     cipSend +="\r\n";
     
     sendData(cipSend,1000,DEBUG);
     delay(2000);

      String webpage = "bingo !!!!!!";
       sendData(webpage,1000,DEBUG);
 
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId; // append connection id
     closeCommand+="\r\n";
     
     sendData(closeCommand,3000,DEBUG);
    }
  }
}



String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command); // send the read character to the esp8266
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        // The esp has data so display its output to the serial window 
        char c = esp8266.read(); // read the next character.
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.println(response);
    }
    
    return response;
}
 
 
