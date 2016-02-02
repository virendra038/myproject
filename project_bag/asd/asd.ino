#include <SoftwareSerial.h>
#define DEBUG true 
SoftwareSerial esp8266(2,3); 
int i=0;
String sendData(String command, const int timeout, boolean debug);
void setup()
{
    pinMode(5,INPUT);
  Serial.begin(115200);
  esp8266.begin(115200); 
  sendData("AT+RST\r\n",2000,DEBUG); 
  delay(2000);
  sendData("AT+CWMODE=3\r\n",1000,DEBUG); 

  
  delay(3000);
  sendData("AT+CIPMUX=1\r\n",1000,DEBUG); 

  delay(2000);
  sendData("AT+CIFSR\r\n",1000,DEBUG); 
  delay(3000);

   sendData("AT+CIPSERVER=1,80\r\n",1000,DEBUG); 
 
}
 void loop()
 {
       
       
       i = i +1 ;
    
    if(esp8266.available() && digitalRead(5)==HIGH )  
  {
    
    if(esp8266.find("+IPD,"))
    {
    // delay(2000);

 
     int connectionId = esp8266.read()-48;
     String cipSend = "AT+CIPSEND=";
     cipSend += connectionId;
     cipSend += ",";
     cipSend += "10";
     cipSend +="\r\n";
     sendData(cipSend,1000,DEBUG);
   
      
      String webpage = "laundry"; 
             webpage += i;    
       sendData(webpage,1000,DEBUG);
        delay(3000);



        
     String closeCommand = "AT+CIPCLOSE="; 
     closeCommand+=connectionId;
     closeCommand+="\r\n";
     sendData(closeCommand,3000,DEBUG);
   
     
    }
  }
}
 



String sendData(String command, const int timeout, boolean debug)
{
    String response = "";
    
    esp8266.print(command);
    
    long int time = millis();
    
    while( (time+timeout) > millis())
    {
      while(esp8266.available())
      {
        
        
        char c = esp8266.read(); 
        response+=c;
      }  
    }
    
    if(debug)
    {
      Serial.println(response);
    }
    
    return response;
}
 
 
