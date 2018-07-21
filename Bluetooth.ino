
#include<SoftwareSerial.h>
SoftwareSerial mySerial(5,6);
char data = 0;                //Variable for storing received data
void setup() 
{
  mySerial.begin(9600);
  Serial.begin(9600);         //Sets the data 3ate in bits per second (baud) for serial data transmission
  pinMode(8, OUTPUT);        //Sets digital pin 13 as output pin
}
void loop()
{
  if(mySerial.available() > 0)  // Send data only when you receive data:
  {
    data = mySerial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
    if(data == '1')            //Checks whether value of data is equal to 1 
      tone(8, 3000);  //If value is 1 then LED turns ON
    else if(data == '0')       //Checks whether value of data is equal to 0
      noTone(8);   //If value is 0 then LED turns OFF
  }                            
 
}
