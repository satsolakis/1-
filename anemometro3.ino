/*
* Ultrasonic Sensor HC-SR04 with Arduino 
*
* by Jayprakash Shet
 
*  <a href="https://iknowvations.in" target="_blank" rel="noopener">iknowvations.in</a>
*/
// First we have to define the Trigeer & Echo pins
const int trigPin1 = 3;
const int echoPin1 = 4;
String label11 = " x :";
String label1= " cms. ";
// Now define the variables for distance & time
long duration1;
int distance1;
const int trigPin2 = 5;
const int echoPin2 = 6;
String label22 = " y :";
String label2= " cms. ";
// Now define the variables for distance & time
long duration2;
int distance2; 
// In the setup, we define the trigger pin as output pin and Echo pin, which has to be monitored for duration measurement. Also we start serial communication to monitor the distance calculated.
const int trigPin3 = 12;
const int echoPin3 = 13;
String label33 = " z :";
String label3= " cms. ";
// Now define the variables for distance & time
long duration3;
int distance3; 
float sp;
float yp;
void setup() {
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(trigPin3, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin3, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
}
 
void loop() {
 
// First we have to clear the trigPin with some delay to stabilize the pin at low level
digitalWrite(trigPin1, LOW);
delayMicroseconds(5);
 
// Now sets the trigPin on HIGH state for 10 micro seconds which will make transuder to emit a burst
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
 
// Read the echoPin, to get the duration in microseconds
duration1 = pulseIn(echoPin1, HIGH);
 
// Now calculating the distance using the formula that will provide the distance in cm
distance1= duration1*0.034/2;
 

 
// put some delay
 
delay(500);

// First we have to clear the trigPin with some delay to stabilize the pin at low level
digitalWrite(trigPin2, LOW);
delayMicroseconds(5);
 
// Now sets the trigPin on HIGH state for 10 micro seconds which will make transuder to emit a burst
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
 
// Read the echoPin, to get the duration in microseconds
duration2 = pulseIn(echoPin2, HIGH);
 
// Now calculating the distance using the formula that will provide the distance in cm
distance2= duration2*0.034/2;
 

 
// put some delay
 
delay(500);
// First we have to clear the trigPin with some delay to stabilize the pin at low level
digitalWrite(trigPin3, LOW);
delayMicroseconds(5);
 
// Now sets the trigPin on HIGH state for 10 micro seconds which will make transuder to emit a burst
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin3, LOW);
 
// Read the echoPin, to get the duration in microseconds
duration3 = pulseIn(echoPin3, HIGH);
 
// Now calculating the distance using the formula that will provide the distance in cm
distance3= duration3*0.034/2;
 

 
// put some delay
 
delay(500);



if (distance1<18)
{ 
   
  if (distance1<2){ sp=34.2;}
else if (distance1<3){ sp=31.3;}
else if (distance1<4){ sp=28.8;}
else if (distance1<5){ sp=26.3;}
else if (distance1<6){ sp=23.8;}
else if (distance1<7){ sp=22.3;}
else if (distance1<8){ sp=21.2;}
else if (distance1<9){ sp=20.2;}
else if (distance1<10){ sp=19.1;}
else if (distance1<11){ sp=17.7;}
else if (distance1<12){ sp=16.2;}
else if (distance1<13){ sp=14.8;}
else if (distance1<14){ sp=13.0;}
else if (distance1<15){ sp=10.8;}
else if (distance1<16){ sp=9.4;}
else if (distance1<17){ sp=6.8;}
else if (distance1<18){ sp=3.9;}
else { sp=0;}
 
Serial.print("anemos = N ");
Serial.print(sp);
Serial.print(" Km/h");
Serial.println();
delay(1000); 
}

if   (distance3<12)
{ 
 
  if (distance3<2){ yp=20.2;}
  else if (distance3<3){ yp=19.1;}
  else if (distance3<4){ yp=17.7;}
  else if (distance3<5){ yp=16.3;}
  else if (distance3<6){ yp=14.8;}
  else if (distance3<7){ yp=13.0;}
  else if (distance3<8){ yp=10.8;}
  else if (distance3<9){ yp=9.4;}
  else if (distance3<10){ yp=6.8;}
  else if (distance3<11){ yp=3.9;}
  else { yp=0;}
  
  Serial.print("anemos = A ");
  Serial.print(yp);
  Serial.print(" Km/h");
  Serial.println();
  delay(1000); 
}
else
{
  
  if (distance3<15){ yp=0.0;}  
  else if (distance3<16){ yp=3.9;}
  else if (distance3<17){ yp=6.8;}
  else if (distance3<18){ yp=9.4;}
  else if (distance3<19){ yp=10.8;}
  else if (distance3<20){ yp=13.0;}
  else if (distance3<21){ yp=14.8;}
  else if (distance3<22){ yp=16.3;}
  else if (distance3<23){ yp=17.7;}
  else if (distance3<24){ yp=19.1;}
  else if (distance3<25){ yp=20.2;}
  else if (distance3<26){ yp=21.2;}
  else if (distance3<27){ yp=22.3;}
  else if (distance3<28){ yp=23.8;}
  else if (distance3<29){ yp=26.3;}
  else if (distance3<30){ yp=28.8;}
  else if (distance3<31){ yp=31.3;}
  else { yp=34.2;}
 
  Serial.print("anemos = D ");
  Serial.print(yp);
  Serial.print(" Km/h");
  Serial.println();
  delay(1000); 
}
{
  if (distance2<10)
  {
   Serial.print("anemos = NA ");
    Serial.println();
  delay(1000);   
  }
  else if (distance2<16)
  { 
Serial.print("anemos = N ");
    Serial.println();
  delay(1000);
  }
    else if(distance2<16)
    { 
  Serial.print("anemos = ND ");
    Serial.println();
  delay(1000);
    }  else {
    
  }
}
}




