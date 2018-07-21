#include <SoftwareSerial.h>
#include <TinyGPS.h>

long lat,lon; // create variable for latitude and longitude object
int count=0;

SoftwareSerial mySerial(9,10);
SoftwareSerial gpsSerial(4, 3); // create gps sensor connection
TinyGPS gps; // create gps object

void setup(){
  Serial.begin(9600); // connect serial
  gpsSerial.begin(9600); // connect gps sensor 
}

void loop(){
  while(gpsSerial.available()){ // check for gps data
   if(gps.encode(gpsSerial.read())){ // encode gps data
    gps.get_position(&lat,&lon); // get latitude and longitude
    // display position
    Serial.print("Position: ");
    Serial.print("lat: ");Serial.print(lat);Serial.print(" ");// print latitude
    Serial.print("lon: ");Serial.println(lon); // print longitude
    if(count==0)
    {
     sendTextMessage();
  count++;
    }
   }
  }
}


void sendTextMessage(){
   mySerial.begin(4800); 
  delay(2000);
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+91XXXXXXXXXX\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.print("lat: ");mySerial.print(lat);mySerial.print(" ");// print latitude
  mySerial.print("lon: ");mySerial.println(lon); // print longitude
  delay(100);
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}

