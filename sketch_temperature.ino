/* Use a photoresistor (or photocell) to turn on an LED in the dark
   More info and circuit schematic: http://www.ardumotive.com/how-to-use-a-photoresistor-en.html
   Dev: Michalis Vasilakis // Date: 8/6/2015 // www.ardumotive.com */
   

//Constants
const int pResistor = A1; // Photoresistor at Arduino analog pin A1
const int ledPin=10;     // Led pin at Arduino pin 10

//Variables
int value;          // Store value from photoresistor (0-1023)



#define Grove_Water_Sensor 8 // Attach Water sensor to Arduino Digital Pin 8
#define LED 9 // Attach an LED to Digital Pin 9 (or use onboard LED)

#include <dht.h>

dht DHT;

#define DHT11_PIN 7

int val;
int tempPin = 0;

void setup()
{
Serial.begin(9600);
pinMode(Grove_Water_Sensor, INPUT); // The Water Sensor is an Input
   pinMode(LED, OUTPUT); // The LED is an Output
   pinMode(ledPin, OUTPUT);  // Set lepPin - 10 n as an output
 pinMode(pResistor, INPUT);// Set pResistor - A0 pin as an input (optional)
}
void loop()
{
val = analogRead(tempPin);
float mv = ( val/1024.0)*5000; 
float cel = mv/10;
float farh = (cel*9)/5 + 32;

Serial.print("TEMPRATURE = ");
Serial.print(cel);
Serial.print("*C");
Serial.println();
delay(1000);
int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
  delay(5000);
 /* The water sensor will switch LOW when water is detected.
   Get the Arduino to illuminate the LED and activate the buzzer
   when water is detected, and switch both off when no water is present */
   if( digitalRead(Grove_Water_Sensor) == LOW) {
      digitalWrite(LED,HIGH);
   }else {
      digitalWrite(LED,LOW);
   }
value = analogRead(pResistor);
  
  //You can change value "25"
  if (value > 25){
    digitalWrite(ledPin,LOW); // led off
  }
  else{
    digitalWrite(ledPin,HIGH); // led on
  }

  delay(500); //Small delay

}


