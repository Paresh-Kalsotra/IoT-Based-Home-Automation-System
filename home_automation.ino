/*sketch for IoT based home automation system using esp32 controller, PIR sensor and remote control using Blynk app
   created by Paresh Kalsotra*/

//________________________________________________________________//
//including necessary libraries
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

#define BLYNK_TEMPLATE_ID "TMPL3khVnHHHt"
#define BLYNK_TEMPLATE_NAME "home automation"
#define BLYNK_AUTH_TOKEN "udvQwo5t7LD168Sm23XZioYKCKz-WBIv"

char auth[] = BLYNK_AUTH_TOKEN; 
char ssid[] = "WiFi ssid";
char pass[] = "password";

//defining the pins
const int switch1Pin = 32;  
const int switch2Pin = 33; 
const int switch3Pin = 26; 
 int sensor = 34; 
 int val = 0;  

void setup()
{
  Serial.begin(115200);
   
// WIFI set up
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
      

  // Initialize Blynk
  Blynk.begin(auth,ssid,pass);

  // Configuring pin modes
  pinMode(switch1Pin, OUTPUT);
  pinMode(switch2Pin, OUTPUT);
  pinMode(switch3Pin, OUTPUT);
  pinMode(sensor, INPUT); 
 
  //  initial switch states
  digitalWrite(switch1Pin, LOW);
  digitalWrite(switch2Pin, LOW);
  digitalWrite(switch3Pin, LOW);
}

void loop()
{  Blynk.run();
 
 //reading sensor data
 val = digitalRead(sensor);   
  if (val == HIGH) {    
  //trigerring physical pin   
  digitalWrite(switch1Pin, HIGH);
  digitalWrite(switch2Pin, HIGH);
  digitalWrite(switch3Pin, HIGH); 

 //updating virtual pin on blynk app
   Blynk.virtualWrite(V0, HIGH);
   Blynk.virtualWrite(V1, HIGH);
   Blynk.virtualWrite(V2, HIGH);
    delay(200);                
 
  } 
  else {
   //trigerring physical pin
  digitalWrite(switch1Pin, LOW);
  digitalWrite(switch2Pin, LOW);
  digitalWrite(switch3Pin, LOW);

   //updating virtual pin on blynk app
   Blynk.virtualWrite(V0, LOW);
   Blynk.virtualWrite(V1, LOW);
   Blynk.virtualWrite(V2, LOW);
      delay(200);        
  }
}

// Virtual pin handler for bulb 1
BLYNK_WRITE(V0)
{
  int switchState = param.asInt();
  digitalWrite(switch1Pin, switchState);
  Serial.print("Switch 1: ");
  Serial.println(switchState);
}
// Virtual pin handler for bulb 2
BLYNK_WRITE(V1)
{
  int switchState = param.asInt();
  digitalWrite(switch2Pin, switchState);
  Serial.print("Switch 2: ");
  Serial.println(switchState);
}
// Virtual pin handler for bulb 3
BLYNK_WRITE(V2)
{
  int switchState = param.asInt();
  digitalWrite(switch3Pin, switchState);
  Serial.print("Switch 3: ");
  Serial.println(switchState);
}
